
void intro() {

  LCD.drawBitmap(118, 2, 200, 79, logo_hs_Esslingen_1);
  LCD.print("Labor Automotive", CENTER, 120);
  LCD.print("Microcontrollers", CENTER, 140);

}

void panelDigitalIn() {
  Li = digitalRead(Li_Pin);  // Light
  b_l = digitalRead(b_l_Pin);  //left blinker
  b_r = digitalRead(b_r_Pin);  // right blinker
  G = digitalRead(G_Pin); // gear
  ES = digitalRead(ES_Pin); //Engine start
   
}

void ControlSteering()
{
 analogWrite(St_Pin_out,static_cast<int>((S/8.15)+100)); 
}


void ControlEngine()
{ 
    if(state == 1)
    {
      if(G==0) {
        analogWrite(5,static_cast<int>((FP/16.3)+187));
      }
      else {
        analogWrite(5,static_cast<int>(188-(FP/16.4)));
      }

    }
    else{
      analogWrite(5,static_cast<int>(187));
}
  //analogWrite(5,static_cast<int>(130));
}


int speed_value(int t)
{
  
}


void NEFZ () {
  
    int max_value = 202;
    for(int i = 0; i < sizeof(NEFZ_t)/sizeof(NEFZ_t[0]);i++)
    { int value = static_cast<int>((NEFZ_v[i]/8)+187);

      if(value > max_value) {
        value = max_value;
      }
      analogWrite(5,value);
      delay(NEFZ_t[i]);
      if(state!=3)
      {
        break;
      }
      
    }
    
}





/*
void ControlEngine()
{ if(state ==1)
   {
   if(G==0) {
   
   if(rpm < x) {
   analogWrite(5,static_cast<int>((FP/16.4)+188));  //forward from 187 to 255
   }
   }
   else {
   if (rpm < x) {
   analogWrite(5,static_cast<int>(188-(FP/16.4)));  //reverse from 187 to 125
   }
   }
   }
   
   
   
  analogWrite(3,static_cast<int>(195));
 //analogWrite(5,static_cast<int>((FP/16.4)+188));  //forward from 187 to 255
// analogWrite(5,static_cast<int>(188-(FP/16.4)));  //reverse from 187 to 125
}
*/
void panelAnalogIn() {
  FP = analogRead(FP_Pin);  // pedal
  B =  analogRead(B_Pin) ;  //brake
  S =  analogRead(S_Pin);  //steering
  C =  analogRead(C_Pin); //Capacitor Voltage, not used rn
  T =  analogRead(T_Pin); //Tempomat
  rpm =  analogRead(Rpm_in); //

}

void fzgLicht() {
  if(Li == 0) {
    analogWrite(SW_pin,0);
     if(B < 7) {
     analogWrite(Hw_Pin,0);
  }
   if (B > 7)
    {
      analogWrite(Hw_Pin, 255);
    }   

  }
 
  if (Li == 1) {
    analogWrite(SW_pin,255);
    analogWrite(Hw_Pin, 125);
     if (B > 7)
    {
      analogWrite(Hw_Pin, 255);
    }   

    if (B < 7)
    {
      analogWrite(Hw_Pin, 125);
    }
  }
}

void readModeSwitch() {
  int modus;
  for (int i = 0; i < 4; i++)
  {
    modus = digitalRead(M_Pin[i]);
    if (modus == 0)
    {
      M = i + 1;
    }
  }
}

void displayStatusInfo() {
  sprintf(Buffer, "Light Pin %d", Li);
  LCD.print(Buffer, 0, 0);
  sprintf(Buffer, "Left blinker Pin %d", b_l);
  LCD.print(Buffer, 0, 20);
  sprintf(Buffer, "Right blinker Pin %d", b_r);
  LCD.print(Buffer, 0, 40);
  sprintf(Buffer, "Gear Pin %d", G);
  LCD.print(Buffer, 0, 60);
  sprintf(Buffer, "Mode Pin %d", M);
  LCD.print(Buffer, 0, 80);
  sprintf(Buffer, "Engine On %d", state);
  LCD.print(Buffer, 0, 100);
  sprintf(Buffer, "Pedal %3d", (FP*100)/1023);
  LCD.print(Buffer, 0, 120);
  sprintf(Buffer, "Brake %3d", (B*100)/1023);
  LCD.print(Buffer, 0, 140);
  sprintf(Buffer, "Steering %3d", (S*100)/1023 -50);
  LCD.print(Buffer, 0, 160);
  sprintf(Buffer, "Gas Ansteuerung %3d", static_cast<int>(FP/16.3)+187);
  LCD.print(Buffer, 0, 180);
  sprintf(Buffer, "RPM %3d", (rpm*100)/1023);
  LCD.print(Buffer, 0, 200);


}

//normal blinker
/* 
void fzgBlinker() {
  if (b_l == 0)
  {
    digitalWrite(b_l_oPin, HIGH);
    delay(micros() % 1000);
    digitalWrite(b_l_oPin, LOW);
  }
  if (b_r == 0)
  {
    digitalWrite(b_r_oPin, HIGH);
    delay(micros() % 1000);
    digiralWrite(b_r_oPin, LOW);
  }

}
*/

//sine wave blinker
void fzgBlinker() {
  if (b_l == 0)
  {
    analogWrite(b_l_oPin, 512*sin(2*3.14*millis()));
  }
  if (b_r == 0)
  {
    analogWrite(b_r_oPin, 512*sin(2*3.14*millis()));
  
  }
  if(b_l ==1)
  {
    analogWrite(b_l_oPin,0);
  }
  if(b_r ==1)
  {
    analogWrite(b_r_oPin,0);
  }
}



void rms() {
  delay(millis()*20);
  readModeSwitch();
}

ISR(PCINT1_vect) {
  readModeSwitch();
  
}



ISR(PCINT2_vect) {
  if (digitalRead(ES_Pin) == 1)
  {
    state = !state;
  }
}
