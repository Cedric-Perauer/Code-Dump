#include "stdlib.h"
#include "Fahrzeug.h"

bool Fahrzeug::setVariables(char * ma, char * mo, float v1, float v2, float v3, float v4, float v5, float v6)
{
    strcpy(marke, ma);
    strcpy(modell, mo);
    variable[0] = v1;
    variable[1] = v2;
    variable[2] = v3;
    variable[3] = v4;
    variable[4] = v5;
    variable[5] = v6;
    return true;
}

char* Fahrzeug::getMarke()
{
    return &marke[0];
}

char* Fahrzeug::getModell()
{
    return &modell[0];
}

float Fahrzeug::getVariable(int n)
{
    return variable[n];
}

char* Fahrzeug::getAttributeName(int n)
{
    switch (n)
    {
    case 0:
        return "Attribut 1";
    case 1:
        return "Attribut 2";
    case 2:
        return "Attribut 3";
    case 3:
        return "Attribut 4";
    case 4:
        return "Attribut 5";
    case 5:
        return "Attribut 6";
    }

}
