#include <stdio.h>
#include <stdlib.h>




float prod(float ar[5])
{  float product = 1;
char i =0;
for(i;i<=4;i++)
    product= product *ar[i]
return product;
}

float maxima(float ar[5])
{
  float mx = ar[0];
  for(int z=1; z<=4; z++)

if (mx<ar[z])
    mx=ar[z];
    return mx;
}


float arith(float ar[5])
{ float sum = 0;
char i=0;
for(i;i<=4;i++)
    sum = ar[i]+sum;
 return sum/i;
}



int main()
{
    float ar[5];
    float l;
    float k;
    float n;
    char j;

    for(j = 0; j<=4; j++)
    {

        printf("\nGeben Sie eine Zahl ein:\n");
        scanf("%f", &ar[j]);
        printf("Sie haben %.2f eingetragen\n",ar[j]);


    }
    printf("Array beinhaltet:%f\n", ar);


        printf("\nDas Produkt betraegt:%.2f ", prod(ar));

        printf("\nDas Maximum betraegt:%.2f", maxima(ar));

        printf("\nDer Mittelwert betraegt:%.2f", arith(ar));

}
