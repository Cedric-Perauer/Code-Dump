#include "LKW.h"

char* LKW::getAttributeName(int n)
{
    switch (n)
    {
    case 0:
        return "Leistung [PS]           ";
    case 1:
        return "Hubruam [ccm]             ";
    case 2:
        return "Nutzlast  [kg]          ";
    case 3:
        return "Verbrauch [l/100km]     ";
    case 4:
        return "Zylinderanzahl          ";
    case 5:
        return "Leergewicht [kg]        ";
    }

}

