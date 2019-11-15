#include <SPI.h>
#include <WiFiNINA.h>

#define led 12

char ssid[] = "tigerSpot2019";
char pass[] = "nothing1";
int keyIndex = 0;

int status = WL_IDLE_STATUS;
WiFiServer server(80);

String readString;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);

  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(10000);
  }
  server.begin();

  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}

void loop() {
  WiFiClient client = server.available();
  if (client)
  {
    Serial.println("new client");

    while (client.connected())
    {
      if (client.available())
      {
        char c = client.read();
        if (readString.length() < 100)
        {
          readString += c;
          Serial.write(c);
          
          if (c == '\n') {
            client.println("<a href=\"/?lighton\"\">Turn On Light</a>");
            client.println("<br />");
            client.println("<br />");
            client.println("<a href=\"/?lightoff\"\">Turn Off Light</a><br />");     

            delay(1);
            
            if(readString.indexOf("?lighton") > 0)
            {
              digitalWrite(led, HIGH);
              delay(50);
            }
            else{
              if(readString.indexOf("?lightoff") > 0)
              {
                digitalWrite(led, LOW);    
                delay(50);
              }
            }           
            readString="";

            delay(1);
            client.stop();
            Serial.println("client disonnected");
          }
        }
      }
    }
  }
}
