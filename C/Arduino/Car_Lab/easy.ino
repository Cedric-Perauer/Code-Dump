const int ledpin_1 =  13;// the number of the LED pin
const int ledpin_2 =  12;// the number of the LED pin
const int ledpin_3 =  10;// the number of the LED pin
const int ledpin_4 =  11;// the number of the LED pin

int pinstate_1 = LOW;
int pinstate_2 = LOW;
int pinstate_3 = LOW;
int pinstate_4 = LOW; 

unsigned int interval_1 = 1000; //milliseconds for blinking  
unsigned long prev_1 = 0; //track prev time

unsigned int interval_2 = 30; //milliseconds for blinking  
unsigned long prev_2 = 0; //track prev time

unsigned int interval_3 = 60; //milliseconds for blinking  
unsigned long prev_3 = 0; //track prev time

unsigned int interval_4 = 20; //milliseconds for blinking  
unsigned long prev_4 = 0; //track prev time

void setup() {
  // set the digital pin as output:
  pinMode(ledpin_1, OUTPUT);
  pinMode(ledpin_2, OUTPUT);
  pinMode(ledpin_3, OUTPUT);
  pinMode(ledpin_4 , OUTPUT);
  Serial.begin(9600);
}

void blinkled(unsigned long &prev, unsigned int interval, const int ledPin,int &pin_state) {
   unsigned long cur = millis();
   if(cur-prev >= interval) {
   Serial.println(1e3/(static_cast<float>(cur-prev)));
    prev = cur;
    if (pin_state == LOW) {
      pin_state = HIGH;
    } else {
      pin_state = LOW;
    }
   digitalWrite(ledPin, pin_state);
   }
  
}

void loop() {
  
  blinkled(prev_1,interval_1,ledpin_1,pinstate_1);
  blinkled(prev_2,interval_2,ledpin_2,pinstate_2);
  blinkled(prev_3,interval_3,ledpin_3,pinstate_3);
  blinkled(prev_4,interval_4,ledpin_4,pinstate_4);
   
}
