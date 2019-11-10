#include <VirtualWire.h>

const int led_pin = 3;
// const int transmit_pin = 12;
const int receive_pin = 12;
// const int transmit_en_pin = 3;

byte message[VW_MAX_MESSAGE_LEN]; // a buffer to store the incoming messages
byte messageLength = VW_MAX_MESSAGE_LEN; // the size of the message
uint8_t on_off = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Device is ready");
  vw_set_rx_pin(receive_pin);
  // Initialize the IO and ISR
  vw_setup(2000); // Bits per sec
  vw_rx_start(); // Start the receiver
  pinMode(led_pin, OUTPUT);
}

void loop()
{
  if (vw_get_message(message, &messageLength)) // Non-blocking
  {
    Serial.print("Received: ");
    for (int i = 0; i < messageLength; i++)
    {
      Serial.write(message[i]);
    }
    Serial.println();
    if (on_off == 1){
      digitalWrite(led_pin, LOW);    // turn the LED off 
      on_off = 0;
      delay(500);// wait for half a second
    }
    else if (on_off == 0){
      digitalWrite(led_pin, HIGH);    // turn the LED off 
      on_off = 1;
      delay(500);                       // wait for half a second
    }
  }
}
