#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
FILE *fp;
char *p;
char buffer[100];
int numNachrichten = 0;

struct can
{

int ID;
int Length;
int Data[8];
int Checksum;

};
/*int calc_checksum(int ID, int L, int *Data)
{
    int checksum= 0, i=0;
    checksum = ID+L;
for(i; i<L;i++)

    checksum+=Data[i];

return checksum;
}*/

int main()
{
  int k;
  int n = 0;

  struct can *canbotschaft;
   canbotschaft = new can[numNachrichten];

    if((fp = fopen("CAN_DBC.txt", "r"))== NULL)
    {


        printf("File could not be opened!");
        return -1;
    }
else
        printf("File opened!\n");

    while (fgets(buffer, 100, fp)!= NULL)
    numNachrichten++;
    fclose(fp);
    printf("amount of messages :%i",numNachrichten);
        if((fp = fopen("CAN_DBC.txt", "r"))== NULL)
    {


        printf("File could not be opened!");
        return -1;
    }
else

    while (fgets(buffer, 100, fp)!= NULL)
    {
        p = strtok(buffer, ":");
        p = strtok(NULL, ",");
        canbotschaft[n].ID = atoi(p);
        p = strtok(NULL,":");
        p = strtok(NULL,",");
        canbotschaft[n].Length = atoi(p);
        p = strtok(NULL, ":");
        printf("\n ID: %i\t Length:%i \t Data:",canbotschaft[n].ID,canbotschaft[n].Length);
        for (k = 0; k < canbotschaft[n].Length; k++)
        {
            p = strtok(NULL, ",");
            canbotschaft[n].Data[k] = atoi(p);
            printf("%4d",canbotschaft[n].Data[k]);
        }
       /* canbotschaft[n].Checksum = calc_checksum(canbotschaft[n].ID,canbotschaft[n].Length,&canbotschaft[n].Data[0]);
        printf(" Checksumme: %6d\n",canbotschaft[n].Checksum);*/
        n++;
    }
    fclose(fp);
   return 0;
}

