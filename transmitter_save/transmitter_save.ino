// NOTE: The transmitter is the slave arduino for the wifi arduino

#include <VirtualWire.h>
#include <string.h>

const int transmit_pin = 12;
const int inPin = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(inPin, INPUT_PULLUP);
  vw_set_tx_pin(transmit_pin);
  vw_setup(2000); // Bits per sec
}

void loop()
{
  if( digitalRead(inPin) ){
    Serial.print(digitalRead(inPin) );
    Serial.println("ON");
    send("o");
    delay(1);
  }
  else{
    Serial.println("OFF");
    Serial.print(digitalRead(inPin) );
    send("f");
    delay(1);
  }
  delay(100);
}

void send (char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); // Wait until the whole message is gone
}
