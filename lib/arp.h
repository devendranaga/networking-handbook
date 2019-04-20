#ifndef __NL_ARP_H__
#define __NL_ARP_H__

// operations
#define NL_ARP_REQUEST 1
#define NL_ARP_REPLY 2

// hardware type definition
#define NL_ARPHRDR_ETHERNET 1

struct nl_arp_hdr {
    uint16_t hardware_type;
    uint16_t protocol_type; // protocol must be of ethertype
    uint8_t halen;
    uint8_t palen;
    uint8_t sha[6];
    uint32_t spa;
    uint8_t tha[6];
    uint32_t tpa;
};

#endif


