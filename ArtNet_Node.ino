#include <Artnet.h> // edit includes to use -2 ethernet libraries (as below)
#include <Ethernet2.h>
#include <EthernetUdp2.h>
#include <SPI.h>
#include <DmxSimple.h>

Artnet artnet;

// Change ip and mac address for your setup
byte ip[] = {192, 168, 1, 200};
byte mac[] = {0x90, 0xA2, 0xDA, 0x11, 0x13, 0xC5}; // specific to the Shield v2 (see sticker underneath)

void setup()
{
  Serial.begin(115200);
  Ethernet.begin(mac, ip); // added this =
  artnet.begin(mac, ip);
  Serial.print("Open on ");
  Serial.println(Ethernet.localIP());
}

void loop()
{
  if (artnet.read() == ART_DMX) {
    // choose things to do
    sendDMX();
    //printVerbose();
    printSimple();
  }
}

void sendDMX() {
  for (int i = 0 ; i < artnet.getLength() ; i++) {  // 0-511 typically for 512 channels
    int v = artnet.getDmxFrame()[i];
    int c = i+1;                                    // can't have channel 0 so move range up to 1-512
    DmxSimple.write(c, v);
  }
}

void printVerbose() {
  Serial.print("universe number = ");
  Serial.print(artnet.getUniverse());
  Serial.print("\tdata length = ");
  Serial.print(artnet.getLength());
  Serial.print("\tsequence n0. = ");
  Serial.println(artnet.getSequence());
  Serial.print("DMX data: ");
  for (int i = 0 ; i < artnet.getLength() ; i++) {
    Serial.print(artnet.getDmxFrame()[i]);
    Serial.print("  ");
  }
  Serial.println();
  Serial.println();
}

void printSimple() {
  for (int i = 0 ; i < artnet.getLength() ; i++) {
    Serial.print(artnet.getDmxFrame()[i]);
    Serial.print("  ");
  }
  Serial.println();
}