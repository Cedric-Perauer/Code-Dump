const int servo = 2;

int Potentiometer = 0;

int motorSpeed= 0;
int upper = 254;
int lower = 1;
int MotorspeedMax = 254;
void setup() 
{Serial.begin(9600);// set all the motor control pins to 
pinMode(servo, OUTPUT);
Serial1.begin(9600);
}

void loop() {
  
  char RPM[4];
  
  //Motorspeed is basically the Motor position
 Potentiometer = analogRead(0);
 motorSpeed = Potentiometer/4.0;  //max 255
 
  String(motorSpeed).toCharArray(RPM,3);  
  if (motorSpeed > MotorspeedMax)
  {motorSpeed = MotorspeedMax;}
  if (motorSpeed < 1){motorSpeed = 1;}
  analogWrite(servo, motorSpeed);
  
   Serial.println(String(motorSpeed));
  
//  Serial1.write(254);                 // wait for a second
//  Serial1.write(128);
//  Serial1.write("                ");
//  Serial1.write("                ");
//  Serial1.write(254);                 // wait for a second
//  Serial1.write(128);
//  Serial1.write("Temperatur :");
//  Serial1.write(tempa);
//  Serial1.write(" C");
//  Serial1.write("RPM :");
//  Serial1.write(RPM);
//  Serial1.write("U/min");
//  
//  

  
}
