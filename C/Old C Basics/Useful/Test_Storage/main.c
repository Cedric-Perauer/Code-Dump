// Dynamic storage allocation check
 #include <stdio.h>
 #include <stdlib.h>
 #define size 394485000
int main()
{    int *array, i;
    array = (int *) malloc(size * sizeof(int));

    if (array == NULL)
   {
    printf("Not enough storage space!\n");
    return -1;
    }
    return 0;}






