
int enableMotor = 3;
int in3 = 5;
int in4 = 4;
int Potentiometer = 0;
int motorStep = 0;
int motorSpeed= 0;
int ADCMax = 1023;
int MotorspeedMax = 255;
void setup() 
{Serial.begin(9600);// set all the motor control pins to 
pinMode(enableMotor, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
motorStep = ADCMax/MotorspeedMax;
Serial1.begin(9600);
}

void loop() {
  int temp = analogRead(A4);
  char tempa[4];
  char RPM[4];
  
 
 
  float Tempvalue = (5*100 * temp/1024); 
 // String
  
  String(Tempvalue).toCharArray(tempa,3);
  
 // Potentiometer = analogRead(0);
  motorSpeed = (Tempvalue *(255/100));  //max 255
  String(motorSpeed).toCharArray(RPM,3);  
  if (motorSpeed > MotorspeedMax)
  {motorSpeed = MotorspeedMax;}
  if (motorSpeed < 0){motorSpeed = 0;}
  analogWrite(enableMotor, motorSpeed);
  
  Serial.println(String(temp));
  
  Serial1.write(254);                 // wait for a second
  Serial1.write(128);
  Serial1.write("                ");
  Serial1.write("                ");
  Serial1.write(254);                 // wait for a second
  Serial1.write(128);
  Serial1.write("Temperatur :");
  Serial1.write(tempa);
  Serial1.write(" C");
  Serial1.write("RPM :");
  Serial1.write(RPM);
  Serial1.write("U/min");
  
  
  delay(1000);
  
}
