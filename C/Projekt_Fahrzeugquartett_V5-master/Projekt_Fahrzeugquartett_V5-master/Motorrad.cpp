#include "Motorrad.h"

char* Motorrad::getAttributeName(int n)
{
    switch (n)
    {
    case 0:
        return "Leistung [PS]           ";
    case 1:
        return "Vmax [km/h]             ";
    case 2:
        return "Drehmoment              ";
    case 3:
        return "Reichweite [kg]         ";
    case 4:
        return "Preis [Euro]            ";
    case 5:
        return "Beschleunigung [l/100km]";
    }

}


