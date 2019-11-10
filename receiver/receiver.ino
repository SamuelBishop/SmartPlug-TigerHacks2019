#include <VirtualWire.h>

const int led_pin = 3;
const int receive_pin = 12;

byte message[VW_MAX_MESSAGE_LEN];         // a buffer to store the incoming messages
byte messageLength = VW_MAX_MESSAGE_LEN;  // the size of the message
uint8_t on_off = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Device is ready");
  vw_set_rx_pin(receive_pin);
  
  // Initialize the IO and ISR
  vw_setup(2000); // Bits per sec
  vw_rx_start();  // Start the receiver
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

    if(message[0] == 'o'){
      digitalWrite(led_pin, HIGH);      // turn the LED off 
      delay(500);                       // wait for half a second
    }
    if(message[0] == 'f'){
      digitalWrite(led_pin, LOW);       // turn the LED off 
      delay(500);// wait for half a second
    }
    
    Serial.println();
  }
}
