#include <SPI.h>


volatile boolean RECEIVED_VAL;
volatile uint16_t SLAVE_RECEIVED;
void setup()
{
  Serial.begin(9600);
  pinMode(MISO,OUTPUT);                  
  pinMode(10,INPUT);
  digitalWrite(10,LOW);
  SPCR |= _BV(SPE);                      
  RECEIVED_VAL = false;
  SPI.attachInterrupt();
  Serial.print("SYSTEM BOOTING>...........");
  delay(2000);
  Serial.print("SYSTEM READY");  
}

ISR(SPI_STC_vect)
{
  SLAVE_RECEIVED = SPDR;
  RECEIVED_VAL = true;
}
void loop()
{
  if (RECEIVED_VAL)
  {
    if (SLAVE_RECEIVED < 32)
    {
      RECEIVED_VAL = false;
      Serial.println("Low Temperature"); 
      delay(100);
    }
    else if(SLAVE_RECEIVED < 64)
    {
      RECEIVED_VAL = false;
      Serial.println("Moderate Temperature");
      delay(100);
    }
    else
    {
      RECEIVED_VAL = false;
      delay(100);
    }
  }
}
