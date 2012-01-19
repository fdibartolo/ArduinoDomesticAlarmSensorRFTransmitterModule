#include <VirtualWire.h>

const int pinInputSensor = 2;
const int pinOutputLed = 13;

void setup() {                
  pinMode(pinInputSensor, INPUT);     
  pinMode(pinOutputLed, OUTPUT);  

  vw_setup(2000); //Bits per sec  
}

void loop() {
  if (digitalRead(pinInputSensor) == HIGH) {
    digitalWrite(pinOutputLed, HIGH);
    SendMessageToReceiver();
    digitalWrite(pinOutputLed, LOW);
  }  
  else
    digitalWrite(pinOutputLed, LOW);
}

void SendMessageToReceiver(){
    const char *msg = "boom";

    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx(); // Wait until the whole message is gone
    delay(200);
}

