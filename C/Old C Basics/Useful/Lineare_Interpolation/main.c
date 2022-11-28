#include <stdio.h>
#include <stdlib.h>
#define h 1.e-03

float X[6] = {0.0 , 0.1, 0.3, 0.7 ,0.8 , 1.0};
float Y[6] = {0.1, 0.2, 0.25, 1.1, 1.2, 1.25};
float y, x, deltay, deltax;
int j;

int main ()
{





printf("input x value :");
scanf("%f",&x);
if (x<0 || x>1)

printf("falscher x Wert");

    return;

printf("x value is: %f", x);

for (j=0.0; j <6 ; j++)              // 6 = length(X)
{

    if (X[j+1] >= x && X[j]<=x)
   {

   deltay = (Y[j+1]-Y[j]);
    deltax =(X[j+1]-X[j]);
    y = Y[j] + (x - X[j])* (deltay/deltax);
   }


}
printf("\n the value of y :%f",y);
return 0;
}
