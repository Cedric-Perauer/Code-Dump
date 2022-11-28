#include "PKW.h"

char* PKW::getAttributeName(int n)
{
    switch (n)
    {
    case 0:
        return "Leistung [PS]           ";
    case 1:
        return "Vmax [km/h]             ";
    case 2:
        return "Sitzplaetze             ";
    case 3:
        return "Reichweite [km]         ";
    case 4:
        return "Preis [Tsd.Euro]        ";
    case 5:
        return "Beschleunigung [0-100km/h]";
    }

}

