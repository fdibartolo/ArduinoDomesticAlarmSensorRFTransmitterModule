#include <VirtualWire.h>

const int pinInputSensor1 = 2;
const int pinInputSensor2 = 3;
const int pinOutputLed = 13;

void setup() {                
  pinMode(pinInputSensor1, INPUT);     
  pinMode(pinInputSensor2, INPUT);     
  pinMode(pinOutputLed, OUTPUT);  

  vw_setup(2000); //Bits per sec  

  digitalWrite(pinOutputLed, LOW);
}

void loop() {
  if (IsSensorTriggered()){
    digitalWrite(pinOutputLed, HIGH);
    SendMessageToReceiver();
    digitalWrite(pinOutputLed, LOW);
  }  
}

boolean IsSensorTriggered(){
  if ((digitalRead(pinInputSensor1) == HIGH) || ((digitalRead(pinInputSensor2) == HIGH)))
    return true;
  else
    return false;
}

void SendMessageToReceiver(){
    const char *msg = "boom";

    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx(); // Wait until the whole message is gone
    delay(200);
}

