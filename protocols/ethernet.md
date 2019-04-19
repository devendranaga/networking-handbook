
# Ethernet

## format

```

0                        5                    11            13
|------------------------|---------------------|------------|
| destination mac        |source mac           |ethertype   |
|------------------------|---------------------|------------|

```

## in C

```c

struct ethernet_protocol {
    uint8_t dest[6];
    uint8_t src[6];
    uint16_t ethertype;
};

```

1. broadcast mac: `0xff:0xff:0xff:0xff:0xff:0xff`
2. zero mac: `0x00:0x00:0x00:0x00:0x00:0x00`
3. multicast mac: the higher order bit in the first octet is set to 1 
