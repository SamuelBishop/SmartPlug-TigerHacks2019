#include "RH_ASK.h"   // Include the RH_ASK library
#include <SPI.h>      // Not actually used but needed to compile the RH_ASK library 

const int transmit_pin = 12;
RH_ASK radio(2000, 11, 12); // speed, reception, transmission

void setup()
{

  // radio inits
  Serial.begin(9600);   // Use this for debugging
  if (!radio.init())
    {
         Serial.println("Radio module failed to initialize");
    }
  // Initialize the IO and ISR
  // vw_set_tx_pin(transmit_pin);
  // vw_setup(2000); // Bits per sec
}

void loop()
{
  const char *msg = "Packet Sent";
  radio.send((uint8_t*)msg, strlen(msg));
  radio.waitPacketSent();
  delay(1000);
  Serial.println("Data Sent");
}

//void send (char *message)
//{
//  vw_send((uint8_t *)message, strlen(message));
//  vw_wait_tx(); // Wait until the whole message is gone
//}
