#include "Rennfahrzeuge.h"

char* Rennfahrzeuge::getAttributeName(int n)
{
    switch (n)
    {
    case 0:
        return "Hoechstgeschwindigkeit [km/h]   ";
    case 1:
        return "Beschleunigung [s]              ";
    case 2:
        return "Leergewicht [kg]]               ";
    case 3:
        return "Rennsiegquote [%]               ";
    case 4:
        return "Leistung [PS]                   ";
    case 5:
        return "Baujahr                         ";
    }

}


