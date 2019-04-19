# IPv4






Protocol in C :

```c

struct ipv4 {
    uint8_t version;
    uint8_t internet_header_len;
    uint8_t type_of_service;
    uint16_t total_len;
    uint16_t identifier;
    uint8_t flags;
    uint16_t fragment_offset;
    uint8_t time_to_live;
    uint8_t protocol;
    uint16_t header_checksum;
    uint32_t source_address;
    uint32_t destination_address;
    uint8_t options[0]; // varilable in length
    uint8_t padding[0];
}

```

converting ipv4 string to ipv4 address in 32 bit form : `inet_addr`, `inet_aton`

```c
uint32_t ipaddr_int;

ipaddr_int = inet_addr("192.168.1.1");

```

version is set to 4 for ipv4.



### classes:

1.  multicast: 224.0.0.0 to 239.255.255.255 reserved for multicast
2. 224.0.0.1 - for all systems on this subnet
3. 224.0.0.2 - all routers on this subnet
4. subnetwork broadcast addresses - 192.168.0.255 (direct boradcast addresses)

in linux, to send a packet to the subnet broadcast address, the `SO_BROADCAST` socket option need to be set.





