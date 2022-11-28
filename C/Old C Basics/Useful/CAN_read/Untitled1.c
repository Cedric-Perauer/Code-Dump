#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Einlesen von CAN_DBC.txt


//ID = 0...2047 | Length:0-8 | Data: Length x 1 Byte
//Checksum= Sum ID +Length + Datenbytes

void calc2checksum(int a, int b, int c, int *sum_ID)
{*sum_ID = a +b +c;

}






int main()
{   char buffer[400];
    FILE *CAN;
    char name[200];
    int Length,ID;
    int Data[10];
    char *p;
    int Dataresult = 0;
    int Checksum;


if((CAN = fopen("CAN_DBC.txt","r")) == NULL)
    {printf("File can not be opened\n");}
else
    {printf("File can be opened\n");}

int n = 1;

    while ((fgets(buffer,200,CAN)) != NULL);
    {
    p = strtok(buffer,":");
    p = strtok(NULL,",");
    ID = atoi(p);

    p = strtok(NULL,":");
    p = strtok(NULL,",");
      Length= atoi(p);

      p = strtok(NULL,":");
    strcpy(name,p);

    printf("\n ID is %i", ID);
    printf("\nLength is : %i",Length);

for(int j = 1; j<= 6;j++)
  {

 p = strtok(NULL,",");
    Data[j] = atoi(p);
    printf("\nData %i is : %i", j, Data[j]);
     Dataresult = Data[j] + Dataresult;
  }







    calc2checksum(ID,Length,Dataresult,&Checksum);
    printf("\nchecksum is :%i",Checksum);
    }
    fclose(CAN);

    return 0;
}
