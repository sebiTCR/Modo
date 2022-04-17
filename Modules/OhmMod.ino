#define MEASUREMENT "Ohms"

int analogPin=0;
int x=0;
float Vout=0;
float R=9900;
float resistor=0;
float buffer=0;

void sendData(float m_value){
    m_value *= -1;
    char fchar[5];
    itoa(m_value, fchar, 10);
    
    Serial.write(fchar);
    delay(500);
}

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  x=analogRead(analogPin);
  buffer=x*5;
  Vout=(buffer)/1024.0;
  buffer=(5/Vout)-1;
  resistor=R*buffer;
  sendData(resistor);
  delay(500);
}
