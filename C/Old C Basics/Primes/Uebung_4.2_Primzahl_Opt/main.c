#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printPrimzahl(int n, int p)
{
    n+=1;
    int v;
    for (v=1;v<=n;v*=2)
    {
        if (v==n)
        {
        printf("The  %d. prime number is: %d\n",n,p);
        return;
        }
    }


}

int main()
{   int calc = 1000000;
    int numbers2check = calc*100;
    int *primzahlenliste;
    primzahlenliste = (int *)malloc(numbers2check* sizeof(int));
    int anzahlprimzahlen = 0;
    int count = 1;
    int t=2;
    long tStart = clock();
    while (count<numbers2check)
    {
        count++;
        if (count%t!=0)
        {
            int i = 0;
            do
                i++;
            while ((i<=anzahlprimzahlen) && (count%primzahlenliste[i]!=0));

                if (i>anzahlprimzahlen/2)
                {
                    primzahlenliste[i]=count;
                    anzahlprimzahlen++;
                    printPrimzahl(anzahlprimzahlen,count);
                }
              if (anzahlprimzahlen==calc)
              {
                  printf("the %d. prime number is : %d",anzahlprimzahlen,primzahlenliste[i]);
                  break;
              }

        }

    }
    long tEnde = clock();
    printf("\nAmount of primes: %i\n", anzahlprimzahlen);
    printf("Operating time: %3.3fs", (tEnde-tStart)*0.001);
    return 0;
}
