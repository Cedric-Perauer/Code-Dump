#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main()


    {
    int min =1;
    int z=20;
    int primzahlenliste [z/10+1000];
    int anzahlprimzahlen = 0;
    int count = 1;
    int t=2;

    int k = 5;
    int CP;

    while (count<=z)
    {
        count++;
        if (count%t!=0)
        {
            int PZ = 0;                                         //PZ counts
            do
                PZ++;
            while ((PZ<=anzahlprimzahlen) && (count%primzahlenliste[PZ]!=0));

                if (PZ>anzahlprimzahlen)
                {
                    primzahlenliste[PZ]=count;
                    anzahlprimzahlen++;
                }
        }

    }

    printf("\nAnzahl Primzahlen: %i\n", anzahlprimzahlen);

 CP=z-primzahlenliste[anzahlprimzahlen-1];

 if (CP > k)
  {

  CP = min;

  }

  if (z == 3)
  {
      CP = 2;
  }

  if (z == 2)
  {
      CP = 1;
  }



  printf("Der Computer nimmt %i Streichhoelzer weg",CP);
    z = z - CP;

    printf("\n es sind noch %i Streichhoelzer uebrig",z);

return 0;}
