# Deep Dive into the Communication Layer

## A. ROS 1 vs ROS 2 Architectural Shift

### The ROS 1 Master (roscore) and Single Point of Failure (SPOF)

- In the ROS 1, the ROS Master (launched via roscore) is a centralised name-registration and lookup service.
- In ROS 1, roscore drives a client/server (or slave/master) architecture. Every node in the system must register its publishers, subscribers, and services with the Master.
- The Master uses XML-RPC to broker introductions: when a subscriber needs data, it contacts the Master, which returns the publisher's address so a direct peer-to-peer data connection can be established
- Also, the master is only involved in setting up connections, not in actual data exchange.
- Critical flaw in roscore is a single point of failure:
  -  Even if the compute node running `roscore` recovers, it may have lost all rosgraph data as it is only stored in memory. Rebooting the failing compute node will result in a network partition where the `roscore` forgets about the remaining compute nodes, even though they may actually still be in a working state.
  - The only solution to this messy outcome is to reboot all computers or restart the ROS software.
  - In mobile robots and assembly lines, poor failure recovery behaviors can be dangerous.
- While existing connections between nodes continue to work after a Master crash, no new connections can be formed, and the system cannot recover gracefully.

### ROS 2's Decentralized Architecture 

- ROS 2 eliminates the Master entirely by adopting DDS (Data Distribution Service) as its communication middleware.
- DDS middleware does not need a broker to distribute data. In addition, applications in the DDS middleware dynamically discover each other through special DDS topics.
- As a result ROS 2 switched to decentralised architecture using DDS.
- So, in the new architecture, the Roscore service has been retired.
- Let's see how it works:
  - DDS is fully decentralized. There is no broker, no master, or any other centralized service. Every participant handles discovery, negotiation, and communication on their own.
  - When a node wants to publish or subscribe to a topic, it creates a DomainParticipant. This is the core object in DDS. It represents a node joining a specific domain, which can be thought of as a namespace.
  - Each participant describes their communication preferences. This includes the topic name, QoS policy, and finally, the message types.
  
- So no more single point of failure.

### Data Transport: TCPROS/UDPROS (ROS 1) vs. DDS Wire Protocol (ROS 2):

- In ROS 1 the implementation of these communication concepts was built on custom protocols (e.g., TCPROS). For ROS 2 the decision has been made to build it on top of an existing middleware solution (namely DDS).
- Unlike ROS 1, which primarily only supported TCP, ROS 2 benefits from the flexibility of the underlying DDS transport in environments with lossy wireless networks where a "best effort" policy would be more suitable, or in real-time computing systems where the right Quality of Service profile is needed to meet deadlines.
- Since DDS is implemented, by default, on UDP, it does not depend on a reliable transport or hardware for communication. This means that DDS has to reinvent the reliability wheel (basically TCP plus or minus some features), but in exchange DDS gains portability and control over the behavior.

## B. DDS (Data Distribution Service)

### The Discoverability Mechanism: Simple Discovery Protocol & Multicast UDP

- When two ROS 2 nodes on separate laptops on the same Wi-Fi network start up, they find each other without any central server using DDS's Simple Discovery Protocol (SDP):

- The Simple Discovery Protocol is the standard protocol defined in the DDS standard.
- The process works in two phases:

  1. Participant Discovery Phase (PDP):  Discovery traffic is traffic sent between DDS domain participants (in the case of ROS 2, a node) to find each other. It is sent out by one participant when it starts and potentially periodically after that to announce their existence and to find other participants. The ideal way to do this is by doing a UDP multicast, which sends the message to everyone on the same subnet.

  2. Endpoint Discovery Phase (EDP): Once participants know about each other (via multicast announcements), they exchange information about their DataWriters and DataReaders via unicast, matching on topic name, data type, and compatible QoS policies.

- By default ROS 2 is using the simple discovery protocol for node, topic and service discovery via UDP multicast communication. 
- According to this, RTI Connext in ROS 2 uses four ports for UDP transport. Each port has its own purpose: discovery multicast, user multicast, discovery unicast, and user unicast.

### 
