#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string dEthertype[100]{
"0x0800","Internet Protocol Version 4 (IPV4)","IPV4",
"0x0806","Address Resolution Protocol (ARP)","ARP",
"0x0842","Wake-on-LAN",
"0x22f0","Audio Video Transport Protocol as defined in IEEE Std 1722-2011",
"0x22f3","IETF TRILL Protocol",
"0x6003","DECnet Phase IV",
"0x8035","Reverse Address Resolution Protocol",
"0x80f3","AppleTalk Address Resolution Protocol (AARP)",
"0x8100","VLAN-tagged frame (IEEE 802.1Q) & Shortest Path Bridging IEEE 802.1aq",
"0x8137","IPX",
"0x8138","IPX",
"0x8204","QNX Qnet",
"0x86dd","Internet Protocol Version 6 (IPv6)","IPV6",
"0x8808","Ethernet flow control",
"0x8809","Slow Protocols (IEEE 802.3)",
"0x8819","CobraNet",
"0x8847","MPLS unicast",
"0x8848","MPLS multicast",
"0x8863","PPPoE Discovery Stage",
"0x8864","PPPoE Session Stage",
"0x8870","Jumbo Frames",
"0x887b","HomePlug 1.0 MME",
"0x888e","EAP over LAN (IEEE 802.1X)",
"0x8892","PROFINET Protocol",
"0x889a","HyperSCSI (SCSI over Ethernet)",
"0x88a2","ATA over Ethernet",
"0x88a4","EtherCAT Protocol",
"0x88a8","Provider Bridging (IEEE 802.1ad) & Shortest Path Bridging IEEE 802.1aq",
"0x88ab","Ethernet Powerlink",
"0x88cc","Link Layer Discovery Protocol (LLDP)",
"0x88cd","SERCOS III",
"0x88e1","HomePlug AV MME",
"0x88e3","Media Redundancy Protocol (IEC62439-2)",
"0x88e5","MAC security (IEEE 802.1AE)",
"0x88e7","Provider Backbone Bridges (PBB) (IEEE 802.1ah)",
"0x88f7","Precision Time Protocol (PTP) over Ethernet (IEEE 1588)",
"0x8902","IEEE 802.1ag Connectivity Fault Management (CFM) Protocol / ITU-T Recommendation Y.1731 (OAM)",
"0x8906","Fibre Channel over Ethernet (FCoE)",
"0x8914","FCoE Initialization Protocol",
"0x8915","RDMA over Converged Ethernet (RoCE)",
"0x892f","High-availability Seamless Redundancy (HSR)",
"0x9000","Ethernet Configuration Testing Protocol",
"0xcafe","Veritas Low Latency Transport (LLT) for Veritas Cluster Server"
};

string ProtocolT[1000]{
"0","HOPOPT","IPv6 Hop-by-Hop Option",
"1","ICMP","Internet Control Message Protocol",
"2","IGMP","Internet Group Management Protocol",
"3","GGP","Gateway-to-Gateway Protocol",
"4","IP-in-IP","IP in IP (encapsulation)",
"5","ST","Internet Stream Protocol",
"6","TCP","Transmission Control Protocol",
"7","CBT","Core-based trees",
"8","EGP","Exterior Gateway Protocol",
"9","IGP","Interior Gateway Protocol",
"10","BBN-RCC-MON","BBN RCC Monitoring",
"11","NVP-II","Network Voice Protocol",
"12","PUP","Xerox PUP",
"13","ARGUS","ARGUS",
"14","EMCON","EMCON",
"15","XNET","Cross Net Debugger",
"16","CHAOS","Chaos",
"17","UDP","User Datagram Protocol",
"18","MUX","Multiplexing",
"19","DCN-MEAS","DCN Measurement Subsystems",
"20","HMP","Host Monitoring Protocol",
"21","PRM","Packet Radio Measurement",
"22","XNS-IDP","XEROX NS IDP",
"23","TRUNK-1","Trunk-1",
"24","TRUNK-2","Trunk-2",
"25","LEAF-1","Leaf-1",
"26","LEAF-2","Leaf-2",
"27","RDP","Reliable Datagram Protocol",
"28","IRTP","Internet Reliable Transaction Protocol",
"29","ISO-TP4","ISO Transport Protocol Class 4",
"30 ","NETBLT","Bulk Data Transfer Protocol",
"31","MFE-NSP","MFE Network Services Protocol",
"32","MERIT-INP","MERIT Internodal Protocol",
"33","DCCP","Datagram Congestion Control Protocol",
"34","3PC","Third Party Connect Protocol",
"35","IDPR","Inter-Domain Policy Routing Protocol",
"36","XTP","Xpress Transport Protocol",
"37","DDP","Datagram Delivery Protocol",
"38","IDPR-CMTP","IDPR Control Message Transport Protocol",
"39","TP++","TP++ Transport Protocol",
"40","IL","IL Transport Protocol",
"41","IPv6","IPv6 Encapsulation",
"42","SDRP","Source Demand Routing Protocol",
"43","IPv6-Route","Routing Header for IPv6",
"44","IPv6-Frag","Fragment Header for IPv6",
"45","IDRP","Inter-Domain Routing Protocol",
"46","RSVP","Resource Reservation Protocol",
"47","GRE","Generic Routing Encapsulation",
"48","MHRP","Mobile Host Routing Protocol",
"49","BNA","BNA",
"50","ESP","Encapsulating Security Payload",
"51","AH","Authentication Header",
"52","I-NLSP","Integrated Net Layer Security Protocol",
"53","SWIPE","wIPe 	IP with Encryption",
"54","NARP","NBMA Address Resolution Protocol",
"55","MOBILE","IP Mobility (Min Encap)",
"56","TLSP","Transport Layer Security Protocol",
"57","SKIP","Simple Key-Management for Internet Protocol",
"58","IPv6-ICMP","ICMP for IPv6",
"59","IPv6-NoNxt","No Next Header for IPv6",
"60","IPv6-Opts","Destination Options for IPv6",
"61","AHIP","Any host internal protocol",
"62","CFTP","CFTP",
"63","ALN","Any local network",
"64","SAT-EXPAK","SATNET and Backroom EXPAK",
"65","KRYPTOLAN","Kryptolan",
"66","RVD","MIT Remote Virtual Disk Protocol",
"67","IPPC","Internet Pluribus Packet Core",
"68","ADFS","Any distributed file system",
"69","SAT-MON","SATNET Monitoring",
"70","VISA","VISA Protocol",
"71","IPCU","Internet Packet Core Utility",
"72","CPNX","Computer Protocol Network Executive",
"73","CPHB","Computer Protocol Heart Beat",
"74","WSN","Wang Span Network",
"75","PVP","Packet Video Protocol",
"76","BR-SAT-MON","Backroom SATNET Monitoring",
"77","SUN-ND","SUN ND PROTOCOL-Temporary",
"78","WB-MON","WIDEBAND Monitoring",
"79","WB-EXPAK","WIDEBAND EXPAK",
"80","ISO-IP","International Organization for Standardization Internet Protocol",
"81","VMTP","Versatile Message Transaction Protocol",
"82","SECURE-VMTP","Secure Versatile Message Transaction Protocol",
"83","VINES","VINES",
"84","TTP","TTP",
"84","IPTM","Internet Protocol Traffic Manager",
"85","NSFNET-IGP","NSFNET-IGP",
"86","DGP","Dissimilar Gateway Protocol",
"87","TCF","TCF",
"88","EIGRP","EIGRP",
"89","OSPF","Open Shortest Path First",
"90","Sprite-RPC","Sprite RPC Protocol",
"91","LARP","Locus Address Resolution Protocol",
"92","MTP","Multicast Transport Protocol",
"93","AX.25","AX.25",
"94","IPIP","IP-within-IP Encapsulation Protocol",
"95","MICP","Mobile Internetworking Control Protocol",
"96","SCC-SP","Semaphore Communications Sec. Pro",
"97","ETHERIP","Ethernet-within-IP Encapsulation",
"98","ENCAP","Encapsulation Header",
"99","APES","Any private encryption scheme",
"100","GMTP","GMTP",
"101","IFMP","Ipsilon Flow Management Protocol",
"102","PNNI","PNNI over IP",
"103","PIM","Protocol Independent Multicast",
"104","ARIS","IBM's ARIS (Aggregate Route IP Switching) Protocol",
"105","SCPS","SCPS (Space Communications Protocol Standards)",
"106","QNX","QNX",
"107","A/N","Active Networks",
"108","IPComp","IP Payload Compression Protocol",
"109","SNP","Sitara Networks Protocol",
"110","Compaq-Peer","Compaq Peer Protocol",
"111","IPX-in-IP","IPX in IP",
"112","VRRP","Virtual Router Redundancy Protocol, Common Address Redundancy Protocol",
"113","PGM","PGM Reliable Transport Protocol",
"114","Any","0-hop protocol",
"115","L2TP","Layer Two Tunneling Protocol Version 3",
"116","DDX","D-II Data Exchange (DDX)",
"117","IATP","Interactive Agent Transfer Protocol",
"118","STP","Schedule Transfer Protocol",
"119","SRP","SpectraLink Radio Protocol",
"120","UTI","Universal Transport Interface Protocol",
"121","SMP","Simple Message Protocol",
"122","SM","Simple Multicast Protocol",
"123","PTP","Performance Transparency Protocol",
"124","IS-IS over IPv4","Intermediate System to Intermediate System (IS-IS) Protocol over IPv4",
"125","FIRE","Flexible Intra-AS Routing Environment",
"126","CRTP","Combat Radio Transport Protocol",
"127","CRUDP","Combat Radio User Datagram",
"128","SSCOPMCE","Service-Specific Connection-Oriented Protocol in a Multilink and Connectionless Environment",
"129","IPLT","IPLT",
"130","SPS","Secure Packet Shield",
"131","PIPE","Private IP Encapsulation within IP",
"132","SCTP","Stream Control Transmission Protocol",
"133","FC","Fibre Channel",
"134","RSVP-E2E-IGNORE","Reservation Protocol (RSVP) End-to-End Ignore",
"135","Mobility Header","Mobility Extension Header for IPv6",
"136","UDPLite","Lightweight User Datagram Protocol",
"137","MPLS-in-IP","Multiprotocol Label Switching Encapsulated in IP",
"138","manet","MANET Protocols",
"139","HIP","Host Identity Protocol",
"140","Shim6","Site Multihoming by IPv6 Intermediation",
"141","WESP","Wrapped Encapsulating Security Payload",
"142","ROHC","Robust Header Compression",
"253","Test","Use for experimentation and testing",
"254","Test","Use for experimentation and testing",
"255","Test","Reserved"
};

string hardwareT[100]{
"0","Reserved",
"1","Ethernet",
"2","Experimental Ethernet",
"3","Amateur Radio AX.25",
"4","Proteon ProNET Token Ring",
"5","Chaos",
"6","IEEE 802 Networks",
"7","ARCNET",
"8","Hyperchannel",
"9","Lanstar",
"10","Autonet Short Address",
"11","LocalTalk",
"12","LocalNet (IBM PCNet or SYTEK LocalNET)",
"13","Ultra link",
"14","SMDS",
"15","Frame Relay",
"16","Asynchronous Transmission Mode (ATM)",
"17","HDLC",
"18","Fibre Channel",
"19","Asynchronous Transmission Mode (ATM)",
"20","Serial Line",
"21","Asynchronous Transmission Mode (ATM)",
"22","MIL-STD-188-220",
"23","Metricom",
"24","IEEE 1394.1995",
"25","MAPOS",
"26","Twinaxial",
"27","EUI-64",
"28","HIPARP",
"29","IP and ARP over ISO 7816-3",
"30","ARPSec",
"31","IPsec tunnel",
"32","InfiniBand (TM)",
"33","TIA-102 Project 25 Common Air Interface (CAI)",
"34","Wiegand Interface",
"35","Pure IP",
"36","HW_EXP1",
"37","HFI",
//38-255	Unassigned
"256","HW_EXP2",
//257-65534	Unassigned
"65535","Reserved"
};

string icmp4T[100]{
"0-0","Echo reply","used to ping",
"3-0","Destination Unreachable","Destination network unreachable",
"3-1","Destination Unreachable","Destination host unreachable",
"3-2","Destination Unreachable","Destination protocol unreachable",
"3-3","Destination Unreachable","Destination port unreachable",
"3-4","Destination Unreachable","Fragmentation required, and DF flag set",
"3-5","Destination Unreachable","Source route failed",
"3-6","Destination Unreachable","Destination network unknown",
"3-7","Destination Unreachable","Destination host unknown",
"3-8","Destination Unreachable","Source host isolated",
"3-9","Destination Unreachable","Network administratively prohibited",
"3-10","Destination Unreachable","Host administratively prohibited",
"3-11","Destination Unreachable","Network unreachable for TOS",
"3-12","Destination Unreachable","Host unreachable for TOS",
"3-13","Destination Unreachable","Communication administratively prohibited",
"3-14","Destination Unreachable","Host Precedence Violation",
"3-15","Destination Unreachable","Precedence cutoff in effect",
"5–0","Redirect Message","Redirect Datagram for the Network",
"5-1","Redirect Message","Redirect Datagram for the Host",
"5-2","Redirect Message","Redirect Datagram for the TOS & network",
"5-3","Redirect Message","Redirect Datagram for the TOS & host",
"8-0","Echo request","used to ping",
"11–0","Time Exceeded","TTL expired in transit",
"11-1","Fragment reassembly time exceeded"
};

string icmp6T[100]{
"1-0","Destination Unreachable","No route to destination",
"1-1","Destination Unreachable","Communication with destination administratively prohibited",
"1-2","Destination Unreachable","Beyond scope of source address",
"1-3","Destination Unreachable","Address unreachable",
"1-4","Destination Unreachable","Port unreachable",
"1-5","Destination Unreachable","Source address failed ingress/egress policy",
"1-6","Destination Unreachable","Reject route to destination",
"1-7","Destination Unreachable","Error in source routing header",
"128-0","Echo Request","Echo Request",
"129-0","Echo Reply","Echo Reply",
"133-0","Router solicitation","Router solicitation",
"134-0","Router Advertisement","Router Advertisement",
"135-0","Neighbor Solicitation","Neighbor Solicitation",
"136-0","Neighbor Advertisement","Neighbor Advertisement",
"137-0","Redirect Message","Redirect Message"
};

void verificardE (string s)
{
    for(int i=0; i<100; i++)
    {
        if(dEthertype[i]==s)
        {
            cout<<dEthertype[i]<<" -> "<<dEthertype[i+1];
        }
    }
}

int verificarIPT (string s)
{
    int n;
    bool t=false;
    for(int i=0; i<1000; i++)
    {
        if(ProtocolT[i]==s)
        {
            cout<<endl<<"Protcol: "<<ProtocolT[i]<<" -> "<<ProtocolT[i+2]<<" ("<<ProtocolT[i+1]<<")";
            n=atoi(s.c_str());
            t=true;
        }
    }
    if(!t)
    {
        cout<<endl<<"PROTOCOL UNASSIGNED: valor de 143-252  o inexistente";
    }
    return n;
}

int verificarIPT6 (string s)
{
    int n;
    bool t=false;
    for(int i=0; i<1000; i++)
    {
        if(ProtocolT[i]==s)
        {
            cout<<endl<<"Next Header: "<<ProtocolT[i]<<" -> "<<ProtocolT[i+2]<<" ("<<ProtocolT[i+1]<<")";
            n=atoi(s.c_str());
            t=true;
        }
    }
    if(!t)
    {
        cout<<endl<<"PROTOCOL UNASSIGNED: valor de 143-252  o inexistente";
    }
    return n;
}

void verificarHT (string s)
{
    bool t=false;
    for(int i=0; i<100; i++)
    {
        if(hardwareT[i]==s)
        {
            cout<<endl<<"Hardware Type: "<<hardwareT[i]<<" -> "<<hardwareT[i+1];
            t=true;
        }
    }
    if(!t)
    {
        cout<<endl<<"PROTOCOL UNASSIGNED: valor de 38-255, 257-65534  o inexistente";
    }
}

int verificarIcmp4(string s)
{
    bool t=false;
    for(int i=0; i<100; i++)
    {
        if(icmp4T[i]==s)
        {
            cout<<endl<<"Type-Code: "<<icmp4T[i]<<" -> "<<icmp4T[i+1]<<", "<<icmp4T[i+2];
            t=true;
            if(s[0]=='0')
            {
                return 0;
            }else if(s[0]=='3')
            {
                return 3;
            }else if(s[0]=='8')
            {
                return 8;
            }else if(s[0]=='1')
            {
                return 1;
            }else if(s[0]=='5')
            {
                return 5;
            }
        }
    }
    if(!t)
    {
        cout<<endl<<"TYPE UNASSIGNED.";
    }
    return 0;
}

int verificarIcmp6(string s)
{
    bool t=false;
    for(int i=0; i<100; i++)
    {
        if(icmp6T[i]==s)
        {
            cout<<endl<<"Type-Code: "<<icmp6T[i]<<" -> "<<icmp6T[i+1]<<", "<<icmp6T[i+2];
            t=true;
            if(s[1]=='-'||s[1]=='2')
            {
                if(s[2]=='0')
                {
                    return 0;
                }else if(s[2]=='1')
                {
                    return 1;
                }else if(s[2]=='2')
                {
                    return 2;
                }else if(s[2]=='3')
                {
                    return 3;
                }else if(s[2]=='4')
                {
                    return 4;
                }else if(s[2]=='5')
                {
                    return 5;
                }else if(s[2]=='6')
                {
                    return 6;
                }else if(s[2]=='7')
                {
                    return 7;
                }else if(s[2]=='8')
                {
                    return 8;
                }else if(s[2]=='9')
                {
                    return 9;
                }
            }else
            {
                if(s[2]=='3')
                {
                    return 13;
                }else if(s[2]=='4')
                {
                    return 14;
                }else if(s[2]=='5')
                {
                    return 15;
                }else if(s[2]=='6')
                {
                    return 16;
                }else if(s[2]=='7')
                {
                    return 17;
                }
            }

        }
    }
    if(!t)
    {
        cout<<endl<<"TYPE UNASSIGNED.";
    }
    return 0;
}

#endif // DICCIONARIO_H_INCLUDED
