#ifndef __ETHERNET_H__
#define __ETHERNET_H__

struct ethernet_header {
    uint8_t dst[6];
    uint8_t src[6];
    uint16_t ethertype;
};

#endif

