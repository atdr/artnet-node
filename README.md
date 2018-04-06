# Art-Net node for Arduino

Takes DMX data sent over [Art-Net](http://art-net.org.uk/wordpress/) and pushes it down a cable.

## Requirements

### Hardware

- Arduino board
- DMX shield
- networking (e.g. Ethernet Shield 2)

### Libraries

- [`DmxMaster`](https://github.com/TinkerKit/DmxMaster)
- [`Artnet`](https://github.com/natcl/Artnet)
- something for networking (e.g. `Ethernet2` & `EthernetUdp2`)

## Notes

This is heavily based on the examples in the `Artnet` package, in particular `ArtnetReceive.ino`.

`Artnet.h` **must** be edited to include `Ethernet2` & `EthernetUdp2` ([rather than `Ethernet` & `EthernetUdp`](https://github.com/natcl/Artnet/blob/master/Artnet.h#L40-L41)) when using the [Ethernet Shield 2](https://store.arduino.cc/arduino-ethernet-shield-2) otherwise things don't work.