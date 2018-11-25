#include <SPI.h>        
#include <Ethernet.h>
#include <EthernetUdp.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {  
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(10, 0, 0, 18);

IPAddress sendto(255 ,255, 255,255);


unsigned int localPort = 8832;      // local port to listen on
unsigned int remotPort = 8832;      // local port to listen on

// An EthernetUDP instance to let us send and receive packets over UDP
EthernetUDP Udp;

char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,

void setup() {
  // start the Ethernet and UDP:
  Ethernet.begin(mac,ip);
  Udp.begin(localPort);

}

void loop() {
  Udp.beginPacket(sendto, remotPort);
    Udp.write("magic");
    Udp.endPacket();


    delay(100);

  Udp.beginPacket(sendto, remotPort);
    Udp.write("hello");
    Udp.endPacket();


    delay(100);
}
