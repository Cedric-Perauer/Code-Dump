#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 10
     // size of array




void kx2k(float x, float *array)

{      for (int i=1; i<=n;i++)                      //calculation of array elements i*x^2*i
        {   array[i] = pow(x,2*i)*i;

}
}

void sum(float *array, float *sum_array)
{
   *sum_array= 0;                               //addition of array elements
    for  (int i=1; i<=n;i++)
    {
         *sum_array = array[i] + *sum_array;
    }

}


int main()
{
          float num;             //number (input by user)
          int i = 1;
          float sum_element[n];   //array for single results (variable num)
          float numbers[n];       // array for num to print out result
          int j= i;


          while (num!=0)
   {

    printf("\n input number u want to calculate : ");
     scanf("%f",&num);
     numbers[i] = num;                         //array fort single inouts
     printf("\ncalculating for %.2f", num);
      float array_kx2k[n];
     float summe;

      kx2k(num, &array_kx2k);

     sum(array_kx2k,&summe);
     sum_element[i] =summe;

     i ++;}              // i count for single calculations

     printf("\nend of calculation");

         printf("\n\tnumber of calculation") ;
         printf("\t---------------x------------",num);
         printf("\t result of the calculation is :");

         for (int j=1 ;j<i-1;j++)
         {
            printf("\n \t\t%i", j ); printf("\t\t %.2f",numbers[j] ); printf("\t\t\t\t %.2f", sum_element[j]);
              //print loop

         }


    return 0;
}
/* TEST

int main()
{
    float x = 5.2;
    float *array;
    array = (int*) malloc(n*sizeof(int));
    for (int i=1; i<n;i++)
        {   array[i] = pow(x,2*i)*i;
        printf("\n%4.2f",array[i]);
}
return 0;}
*/
