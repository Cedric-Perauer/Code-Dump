File *fp
char buffer[300];
 char *p;
 Fahrzeug PWK_Liste[32];
 int i, k;


int einlese_PKW()
{


    if((fp = fopen("CAN_DBC.txt", "r"))== NULL)
    {


        printf("Datei konnte nicht geöffnet werden!");
        return -1;
    }
else


    while (fgets(buffer, 100, fp)!= NULL)
    {
        p = strtok(buffer, ":");
        p = strtok(NULL, ";");
        strcpy(PKW[i].Marke,p);
        p = strtok(NULL,":");
        p = strtok(NULL,";");
        strcpy(PKW[i].Modell,p);
       p = strtok(NULL, ":");

        for (k = 0; k < 6; k++)
        {
            p = strtok(NULL, ";");
            PKW[i].Variable[k] = atof(p);

        }

        i++;
    }
    fclose(fp);
   return 0;
}

