int relay_pin = 8;
int led_pin = 12;

void setup(){
  Serial.begin(9600); 
  pinMode(relay_pin,OUTPUT);
  pinMode(led_pin,OUTPUT);  
  digitalWrite(led_pin,HIGH);
}

void loop(){
  digitalWrite(relay_pin,HIGH);
  delay(3000);
  digitalWrite(relay_pin,LOW);
  delay(3000);
}
