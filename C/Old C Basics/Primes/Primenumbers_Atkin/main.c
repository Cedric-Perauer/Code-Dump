#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 //sieve of Atkin
 /*
  The algorithm completely ignores any numbers divisible by two, three, or five.
  All numbers with an even modulo-sixty remainder are divisible by two and not prime.
  All numbers with modulo-sixty remainder divisible by three are also divisible by three and not prime.
  All numbers with modulo-sixty remainder divisible by five are divisible by five and not prime.
  All these remainders are ignored."*/

int main() {
    int limit;
    int wlimit, max;
    int i, j, k, x, y, z, count = 0;
    unsigned char *sieb;

    printf("Please insert amount of primes to calculate: ");
    scanf("%d", &max);
    limit = 16*max;
wlimit = sqrt(limit);
    int *primes;
     primes = (int *)malloc(max* sizeof(int));
    sieb = (unsigned char *) calloc(limit, sizeof(unsigned char));

 long tStart = clock();

    for (x = 1; x <= wlimit; x++)
        {
        for (y = 1; y <= wlimit; y++)
        {
            z = 4 * x * x + y * y;
            if (z <= limit && (z % 60 == 1 || z % 60 == 13 || z % 60 == 17 || z% 60 == 29 || z % 60 == 37 || z % 60 == 41 || z % 60 == 49
                    || z % 60 == 53))
                    {
                sieb[z] = !sieb[z];}
            z = 3 * x * x + y * y;
            if (z <= limit && (z % 60 == 7 || z % 60 == 19 || z % 60 == 31 || z
                    % 60 == 43)) {
                sieb[z] = !sieb[z];

            }
            z = 3 * x * x - y * y;
            if (x > y && z <= limit && (z % 60 == 11 || z % 60 == 23 || z % 60
                    == 47 || z % 60 == 59)) {
                sieb[z] = !sieb[z];

            }
        }
    }

    for (i = 5; i <= wlimit; i++) {
        if (sieb[i] == 1) {
            for (j = 1; j * i * i <= limit; j++) {
                sieb[j * i * i] = 0;

            }
        }
    }

   // printf("The following primes have been calculated:\n2\n3\n5");
   primes[1] = 2;
   primes[2] = 3;
   primes[3] = 5;

    count = 3;
    for (i = 5; i <= limit; i++) {
        if (sieb[i] == 1) {
           // printf("\n%d", i);
             count++;

             primes[count] = i;
             if (count == max)
             {break;}
}
}
long tEnde = clock();
    printf("\n the %d. prime number is : %d",count,i);
   //printf("\n the prime is : %d",primes[10]);
    printf("\n Operating time: %3.3fs", (tEnde-tStart)*0.001);
    return 0;
}
