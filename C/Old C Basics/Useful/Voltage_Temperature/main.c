#include <stdio.h>
#include <stdlib.h>

//Schaltung Messtechnik

float R2[]= {28000, 10000, 1000, 500, 200};
float T[] = {-30,-10, 46 ,82, 100};
float deltaT, deltaR2, r2,t, U2,resolution,Temp,Temp_Range=130;
unsigned char t_digit;
float R1 = 2300.0; //Ohm
float Uref = 5.0; // Volt
int j;
int main()

{  resolution= Temp_Range/256;
printf("resolution is %.2f",resolution);
  printf("\n input the Voltage U2 between 0 and 5 Volts : ");
  scanf("%f",&U2);

  if (U2 <0.4 || U2>4.62)
    {printf("the input doesn't match the circuit properties");
  return; }
  if (U2==0)
    {printf("R1 is open or R2 is short circuited ");
  return;}
  if (U2==5)
    {printf("R2 is open or R2 is short circuited ");
  return;}

r2 = ((U2/Uref)*R1) / (1- U2/Uref);
printf("calculating Temperature for r= %.2f Ohm", r2);
printf("\n\n<><><><><><><><><><><><><><><><><><><><><><><><>");

for (j=0; j <5 ; j++)              // 5 = length()
{

    if (R2[j] >= r2 && R2[j+1]<=r2)
   {

   deltaT = (T[j+1]-T[j]);
    deltaR2 =(R2[j+1]-R2[j]);
    t = T[j] + (r2 - R2[j])* (deltaT/deltaR2) ;
   }

t_digit = ((t+30) /130) * 255;
}


printf("\n the digital value is = : %i", t_digit);
printf("\n\n accurate calculation is not possible");

printf("\n\n the Temperature is :%f Celsius",t);
return 0;
}
