#ifndef FAHRZEUG_h
#define FAHRZEUG_h

#include <iostream>
#include <string.h>

class Fahrzeug
{
    protected:
        char marke [30];
        char modell [30];
        float variable[6];

    public :
        bool setVariables(char*, char*, float, float, float, float, float, float);
        char* getMarke();
        char* getModell();
        float getVariable(int);
        virtual char* getAttributeName(int);
};

#endif // FAHRZEUG_h



