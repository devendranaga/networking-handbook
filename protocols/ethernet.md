
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

## List of ethernet types:

| **Ethertype** | **description** |
|---------------|-------------|
| 0x800 |  IP protocol |
| 0x0806 | ARP |
| 0x8035 | DRARP, RARP |
| 0x814c | SNMP |
| 0x86dd | IPV6 |
| 0x880b | PPP |
| 0x880c | GSMP |
| 0x8847 | MPLS unicast |
| 0x8848 | MPLS multicast |
| 0x8863 | PPPoE discovery stage |
| 0x8864 | PPoE PPP session stage |
| 0x886f | network load balancing |
| 0x888E | EAPOL EAP over LAN |
| 0x88A4 | EtherCAT |
| 0x88CA | TIPC |
| 0x88BB | LWAPP |
| 0x88CC | LLDP |


