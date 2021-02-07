#include <UTFT.h>
extern uint8_t BigFont[];
char Buffer[64];
extern uint16_t logo_hs_Esslingen_1[];
UTFT LCD(ITDB32S,38,39,40,41);
//PIN Position Digital
int b_r; //right Blinker 
int b_l; //left Blinker
int Richtung; //Reverse
int Li; //Light 
int PS; //Position
int G; //Gear
int M; //Mode
int ES; //Engine Start
int state = 0; //Engine state
int rpm; //RPM
int NEFZ_t[] = {0,10,15,24,28,50,60,85,95,120,145,155,165,175,190,195,200,210,215,224,228,250,260,285,295,320,345,355,365,375,380,390,395,404,408,430,440,465,475,500,525,535,545,555,560,570,575,584,588,610,620,645,655,680,705,715,725,765,805,855,865,935,945,995,1030,1060,1080,1090,1125,1145};
int NEFZ_v[] = {0,0,16,16,0,0,32,32,0,0,50,50,35,35,0,0,16,16,0,0,32,32,0,0,50,50,35,35,0,0,16,16,0,0,32,32,0,0,50,50,35,35,0,0,16,16,0,0,32,32,0,0,50,50,35,35,0,0,70,70,50,50,70,70,100,100,120,120,0,0};
//PIN Position Digital
uint32_t FP; //pedal
uint32_t B; //brake
uint32_t S;//steering
uint32_t T; //cuise control
int C; //Capacitor
//PIN Port Def Analog
const int SW_pin = 13;
const int Hw_Pin = 46;
const int FP_Pin = A1;
const int B_Pin = A2;
const int T_Pin = A3;
const int S_Pin = A4;
const int C_Pin = A5;
const int St_Pin_out = 3; 
const int Engine_out = 5;
const int Rpm_in = 48;
//PIN Port Def Digital
const int Li_Pin = 66;
const int b_l_Pin = 61;
const int b_r_Pin = 65;
const int G_Pin = 67;
const int M_Pin[] = {18,15,14,49}; // 0 : m1_pin,  1 : m2_pin ,  2 : m3_pin,  3 : m4_pin
const int ES_Pin = 68;
const int b_l_oPin = 12; //left blinker outnput
const int b_r_oPin = 11 ;//right blinker output
void setup() {
  // Setup the LCD
  LCD.InitLCD();
  LCD.setFont(BigFont);
  LCD.clrScr();
  pinMode(Li_Pin,INPUT); //Light
  pinMode(b_l_Pin,INPUT);  //left Blinker
  pinMode(b_r_Pin,INPUT);  // right Blinker 
  pinMode(G_Pin,INPUT);  //Gear
  pinMode(ES_Pin,INPUT); //Engine Start
  pinMode(b_r_oPin,OUTPUT); //right Blinker output
  pinMode(b_l_oPin,OUTPUT); //left Blinker output
  pinMode(St_Pin_out,OUTPUT); //Steering out
  pinMode(Rpm_in, INPUT); //RPM Measuring
  pinMode(5, OUTPUT); 
  pinMode(3, OUTPUT); 
  LCD.setColor(255,255,255);
  LCD.setBackColor(0,0,0);
  LCD.fillScr(0,0,0);  
  attachInterrupt(digitalPinToInterrupt(18),rms,CHANGE);  //external inerrupt attached
  PCICR = PCICR | 0x06; //activate group 2 and 3
  PCMSK2 = PCMSK2 | 0x40; //activate PCINT22
  PCMSK1 = PCMSK1 | 0x06; //activate PCINT9 and PCINT10
  analogWrite(5,static_cast<int>(187));
  delay(100);
  
}

void loop() {
  
 //static int count_time = millis();
 //unsigned long total_time = millis()-count_time;
 panelDigitalIn();
 panelAnalogIn();
 fzgLicht();
 fzgBlinker(); 
 ControlSteering();
 if(state == 1 && M ==3)
 {
 NEFZ(); 
 }
 
 
 //analogWrite(5,static_cast<int>(187));
//if(total_time <= 15000)
//{intro();}
// else if (total_time < 15500 && total_time > 15000)
  

 displayStatusInfo();


}
