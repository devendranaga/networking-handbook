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







