Misce#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



class datum
{
public:
    bool setDatum(int t, int m, int j)
    {
    if ((t>1) && (t<365) && (m>1) && (m<=12) && (j>190) && (j<=2018))

       { Jahr = j;
         Monat = m;
         Tag = t;
         return true;
        } else return false;


    }
    int getTag() {return Tag;}
        int getMonat() {return Monat;}
        int getJahr() {return Jahr;}
public:
    int Jahr;
    int Monat;
    int Tag;
    friend class student;

};

class student {

public:
    bool setMatrikelnummer(int num)
    {
        if((num>= 1) && (num<= 9999))
       { Matrikelnummer = num;
         return true;
        }
        else
            return false;
}


bool setName(char *Firstname, char *Lastname)
    {
        if((strlen(Firstname)< 20) && (strlen(Lastname)< 20))
       {strcpy(Vorname,Firstname);
        strcpy(Nachname,Lastname);
         return true;
        }
        else
            return false;
}


int  getMatrikelnummer() {return Matrikelnummer;}


char* getVorname()  {return &Vorname[0];}
char* getNachname()  {return &Nachname[0];}
private :
    char Nachname[20];
    char Vorname[20];
    int Matrikelnummer;
    friend bool datum::setDatum(int t, int m, int j);

    friend class datum Geburtsdatum;

    };

    student Musterstudent[200];

    student Fahrzeugtechnik[200];



   int main()
   {


            Musterstudent[0].setName("Peter", "gedoens");
            Musterstudent[0].Geburtsdatum.setDatum(12,10,2016);
            Fahrzeugtechnik[0].setMatrikelnummer(42);
            Musterstudent[1].setName("dhkjsahf", "gedoens");
            Musterstudent[1].Geburtsdatum.setDatum(12,12,2016);
               Fahrzeugtechnik[1].setMatrikelnummer(199);
            Musterstudent[2].setName("kjasd", "gedoens");
            Musterstudent[2].Geburtsdatum.setDatum(12,12,2016);
               Fahrzeugtechnik[2].setMatrikelnummer(302);
            Musterstudent[3].setName("klsadfj", "gsajfd");
            Musterstudent[3].Geburtsdatum.setDatum(12,12,2001);
               Fahrzeugtechnik[3].setMatrikelnummer(122);
            Musterstudent[4].setName("sjda", "mnsand");
            Musterstudent[4].Geburtsdatum.setDatum(10,10,2000);
               Fahrzeugtechnik[4].setMatrikelnummer(132);


printf("\nNumber:"); printf("\t Matriculation Number:"); printf("\t Name:"); printf("\t\t\t Birthdate:");
for (int i=0;i<=4;i++)

{
            printf("\n %i",i+1);
            printf("\t %i",Fahrzeugtechnik[i].getMatrikelnummer());
            printf("\t\t\t  %s %s",Musterstudent[i].getVorname(),Musterstudent[i].getNachname());

            printf("\t\t %i.%i.%i",Musterstudent[i].Geburtsdatum.getTag(),Musterstudent[i].Geburtsdatum.getMonat(),Musterstudent[i].Geburtsdatum.getJahr());}
            printf("\n");
         return 0;
   }








