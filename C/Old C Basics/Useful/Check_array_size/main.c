#include<stdio.h>
#include<stdlib.h>

#define FELDGROESSE 521200 // Maximum ca. 2 MB

int main() {
    // Aufgabe 1 und 2



	int size, inkrement, i;
	int *array;



	for (i = 0; i < 10; i++)
    {
        inkrement = 100000000;
        size      = 100000000;
        while (inkrement > 10)
        {
            do
            {
                free(array);
                size += inkrement;

                array = (int *) malloc(size * sizeof(int));

            } while (array != NULL);
            // saving wasn't possible, go  back to the last inkrement
            size -= inkrement;
            // reduce increment by division
            inkrement /= 2;              //divides inkrement by 2

        }
        printf("Durchlauf %2i: Maximale moeglich Array Groesse: %i = %5.1f MB\n",i+1,size,size*4.0/1024/1024);
    }

	return 0;
}
