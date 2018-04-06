# Art-Net node for Arduino

Takes DMX data sent over [Art-Net](http://art-net.org.uk/wordpress/) and pushes it down a cable.

## Requirements

- Arduino board
- DMX shield
- networking (e.g. Ethernet shield)

### Libraries

- [`DmxMaster`](https://github.com/TinkerKit/DmxMaster)
- [`Artnet`](https://github.com/natcl/Artnet)
- something for networking (e.g. `Ethernet2` & `EthernetUdp2`)
