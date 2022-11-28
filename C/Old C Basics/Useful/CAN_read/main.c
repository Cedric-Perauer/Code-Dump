#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Einlesen von CAN_DBC.txt


//ID = 0...2047 | Length:0-8 | Data: Length x 1 Byte
//Checksum= Sum ID +Length + Datenbytes

void calc2checksum(int a, int b, int c, int *sum_ID)
{  sum_ID = a +b +c;

}






int main()
{   char buffer[400];
    FILE *CAN;
    char Information[200];
    int Length[2],ID[2];
    int Data[10];
    char *p;
    int Dataresult = 0;
    int Checksum;


if((CAN = fopen("CAN_DBC.txt","r")) == NULL)
    {printf("File can not be opened\n");}
else
    {printf("File can be opened\n");}



    while ((fgets(buffer,200,CAN)) != NULL);
    {
    p = strtok(buffer,":");
    strcpy(Information,p);
    p = strtok(NULL,",");
   ID[1] = atoi(p);

    p = strtok(NULL,":");
    strcpy(Information,p);
    p = strtok(NULL,",");
      Length[1]= atoi(p);

      p = strtok(NULL,":");
    strcpy(Information,p);
    p = strtok(NULL,",");
    Data[1] = atoi(p);
p = strtok(NULL,",");
Data[2] = atoi(p);
p = strtok(NULL,",");
Data[3] = atoi(p);
p = strtok(NULL,",");
Data[4] = atoi(p);



printf("\n ID is %i", ID[1]);
    printf("\nLength is : %i",Length[1]);

    for (int i= 1;i<=4;i++)
    {

     printf("\nData %i is : %i", i, Data[i]);
     Dataresult = Data[i] + Dataresult;

    }
    calc2checksum(ID[1],Length[1],Dataresult,&Checksum);
    printf("\nchecksum is :%i",Checksum);
     }
    fclose(CAN);












    return 0;
}
