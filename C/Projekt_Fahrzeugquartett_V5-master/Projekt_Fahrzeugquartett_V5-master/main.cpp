#include "Fahrzeug.h"
#include "PKW.h"
#include "Motorrad.h"
#include "LKW.h"
#include "Rennfahrzeuge.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <math.h>
#include <conio.h>
#define len 32
//class Fahrzeug FahrzeugListe[32];
class Fahrzeug* FahrzeugListe;
int FahrzeugeImSpiel = 0;

bool readFile(char* filename)
{
    FILE *fp;
    char buffer[100];
    char *p;
    int i,k;
    char Modell[32];
    char Marke[32];
    float var[6];
    int stelle = 0;

    fp = fopen(filename,"r");
    if (fp == NULL)
        return false;

    printf("\nLese %s\n",filename);

    while (fgets(buffer, 100, fp) !=0 )
    {
        if (strlen(buffer) > 30)
        {
            p = strtok(buffer, ";");
            strcpy(Marke,p);
            p = strtok(NULL, ";");
            strcpy(Modell,p);
            for (k=0; k<6; k++)
            {
                p = strtok(NULL, ";");
                var[k] = atof(p);
            }
            FahrzeugListe[stelle].setVariables(Marke,Modell,var[0],var[1],var[2],var[3],var[4],var[5]);
            printf("Fzg %2i",stelle);
            for (i = 0; i < 6; i++)
                printf("%6.0f", FahrzeugListe[stelle].getVariable(i));
            printf("  %s",FahrzeugListe[stelle].getMarke());
            printf(" %s",FahrzeugListe[stelle].getModell());
            printf("\n");
            stelle++;
        }
    }
    fclose(fp);
    FahrzeugeImSpiel = stelle;
    printf("Fahrzeuge geladen: %i\n",FahrzeugeImSpiel);
}

int Spielauswahl(int c)
{


    switch (c)
    {
    case 1:
        FahrzeugListe = new PKW[32];
        readFile("PKW_Liste.txt");
        break;
    case 2:
        FahrzeugListe = new LKW[16];
        readFile("LKW_Liste.txt");
        break;
    case 3:
        FahrzeugListe = new Motorrad[32];
        readFile("Motorrad_Liste.txt");
        break;
    case 4:
        FahrzeugListe = new Rennfahrzeuge[12];
        readFile("Rennfahrzeuge_Liste.txt");
        break;
    }
 return c;}

void ZeigeFahrzeug(int fzg)
{
    int i;
    printf("\n");
    printf("Marke:               %s\n",FahrzeugListe[fzg].getMarke());
    printf("Modell:              %s\n",FahrzeugListe[fzg].getModell());
    for (i = 0; i < 6; i++)
    {
        printf("%s %6.1f\n", FahrzeugListe[fzg].getAttributeName(i),FahrzeugListe[fzg].getVariable(i));
    }
}





void show_Attributes(int c)
{
      while ((c < 0) || (c > 4));

    switch (c)
    {
    case 1:
        for
(int i =0; i<6;i++)
        {
        printf("\n %i Attribute is : %s",i,FahrzeugListe[1].getAttributeName(i));
        }
        break;
    case 2:
        FahrzeugListe = new LKW[16];
        readFile("LKW_Liste.txt");
        break;
    case 3:
        FahrzeugListe = new Motorrad[32];
        readFile("Motorrad_Liste.txt");
        break;
    case 4:
        FahrzeugListe = new Rennfahrzeuge[12];
        readFile("Rennfahrzeuge_Liste.txt");
        break;
    }

}


void card_delivery(int cards_amount, int *a, int* b)
{


     int N1 = 0;
     int N2 = 32;
    int i , r , temp,j;

    int num[len];


    //Fill array with desired numbers
    for( temp=0,i=N1; temp<len; i++,temp++ )
        num[temp] = i;


    srand( time(NULL) );  //seed rand()  time is needed so the values change

    //Fisher–Yates shuffle algorithm
    for( i=len-1; i>0; i-- ){
        r = rand()%i;   //pop random number
        //swaping using temp
        temp = num[i];
        num[i] = num[r];
       num[r] = temp;

    }

    /*Random Numbers b/w N1-N2 are stored in Array num*/

    //print the array
    for( i=0; i < cards_amount;i++)
    { a[i] = num [i];

    }



     for( i=cards_amount; i <2*cards_amount;i++)
        {  b[i-cards_amount]= num[i];

        }

}
int main()
{    int c = 0;
    printf("---------------------------------------------------------------------------\n");
    printf("---                                                                     ---\n");
    printf("---                         Fahrzeug - Quartett                         ---\n");
    printf("---                                                                     ---\n");
    printf("---------------------------------------------------------------------------\n\n");
    do
    {
        printf("\nWelche Fahrzeug-Kategorie wollen Sie spielen?\n");
        printf(" 1 - PKW\n 2 - LKW\n 3 - Motorrad\n 4 - Rennfahrzeuge\n\nAuswahl: ");
        scanf("%d",&c);
    }
    while ((c < 0) || (c > 4));
    Spielauswahl(c);
    int cards_amount;
    printf("select how many cards to deliver to the players: ");
    scanf("%i",&cards_amount);

    ///////////////////////////////////////////////////////////
    int a[2*cards_amount];
    int b[2*cards_amount];

    card_delivery(cards_amount,a,b);
  //////////////////////////////////////////////////////////
int a_amount = cards_amount;
     int b_amount = cards_amount;
     int runde = 0;
     int win=0;
     int loss = 0;
  for(int i =0;i<cards_amount;i++)                      // game algorithm
  {   printf("\n\nIhre aktuelle Karte ist:");
      printf("\n");
      ZeigeFahrzeug(a[i]);
     int Attribut;


    printf("\n\n Welches Attribut wollen sie spielen ?");
    printf("\n Attribut zwischen 1 und 6 eingeben : ");
    scanf("%d", &Attribut);

   if(((Attribut-1)==0) || ((Attribut-1)==1) || ((Attribut-1)==2) || ((Attribut-1)==3))

   {

    if (FahrzeugListe[a[i]].getVariable(Attribut-1) > FahrzeugListe[b[i]].getVariable(Attribut-1))
    {
       a[a_amount+1] = b[i];
        a_amount = a_amount+1;
        b_amount = b_amount-1;
        printf("\nsie haben folgende Karte Gewonnen:");
        printf("\n");
        ZeigeFahrzeug(b[i]);
        win++;
        }
        else {
         b[b_amount+1] = a[i];
         a_amount = a_amount-1;
        b_amount = b_amount+1;
        printf("\nsie haben folgende Karte verloren:");
        printf("\n");
        ZeigeFahrzeug(a[i]);
        loss++;
        }
        }



    else {

         if (FahrzeugListe[a[i]].getVariable(Attribut-1) < FahrzeugListe[b[i]].getVariable(Attribut-1))
    {
       a[a_amount+1] = b[i];
        a_amount = a_amount+1;
        b_amount = b_amount-1;
        printf("\nsie haben folgende Karte Gewonnen:");
        printf("\n");
        ZeigeFahrzeug(b[i]);
        win++;
        }
        else {
         b[b_amount+1] = a[i];
         a_amount = a_amount-1;
        b_amount = b_amount+1;
        printf("\nsie haben folgende Karte verloren:");
        printf("\n");
        ZeigeFahrzeug(a[i]);
        loss++;

        }


    }

runde++;


printf("\n es ist die %d. Runde, es steht : Sie : %d zu Computer: %d",runde,win,loss);


  }


       if(a_amount >= b_amount)

        {   printf("\nSie haben %i Karten, der Computer hat :%i Karten",a_amount,b_amount);
            printf("\nSie haben gewonnen");
        }
        else
        {   printf("\nSie haben %i Karten, der Computer hat: %i Karten",a_amount,b_amount);
            printf("\nSie haben verloren");

        }







return 0;
}
