# ARP

The Address Resolution Protocol lets the machines connected on a network to know their mac addresses.

The ARP protocol is defined in rfc: https://tools.ietf.org/html/rfc826.

**protocol**

```

0<---- 2bytes----><--2bytes->|<--1 byte----------><-----1byte----->|<--2bytes->|
|----------------|-----------|-------------------|----------------|------------|
|  Hardware type | protocol  | Hardware addr len | proto addr len | op code    |
|----------------|-----------|-------------------|----------------|------------|

|<-------------6 bytes------------>|<--------4 bytes----------->|
|----------------------------------|----------------------------|
| source hardware address          | source protocol address    |
|----------------------------------|----------------------------|

|<-------------6 bytes------------>|<--------4 bytes------------>|
|----------------------------------|-----------------------------|
| target hardware address          | target protocol address     |
|----------------------------------|-----------------------------|


```

**C header**

```c

#define ARP_REQUEST 1
#define ARP_REPLY 2

#define ARP_HRDTYPE_ETHERNET 1

struct arp_header {
    unsigned short int hardware_type;
    unsigned short int protocol_type;
    unsigned char hardware_addr_len;
    unsigned char protocol_addr_len;
    unsigned short int op;
    unsigned char source_hardware_addr[6];
    unsigned int source_protocol_addr;
    unsigned char target_hardware_addr[6];
    unsigned int target_protocol_addr;
};

```



### gratituous ARP



