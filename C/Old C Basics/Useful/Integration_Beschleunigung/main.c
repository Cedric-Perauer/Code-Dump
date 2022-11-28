#include <stdio.h>
#include <stdlib.h>
#define h 1.e-03

double t, v0, t1, t2,t3,v0,a0, v1,v2,v3,s1,s2,s3,a0 = -10;


double a1(double t )
{
    return 0.0;
}

double a2(double t, double t1)
{
    return (-10/0.2)* (t-t1);
}

double a3( double t)
{
    return a0;
}
int main()

{
printf("Eingabe der Reaktionszeit");
printf("\n\nGeben Sie die Reaktionszeit im Bereicg von 0.7 bis 1.3s ein:  ");
scanf("%lf", &t1);
printf("die Reaktionszeit ist : %lf", t1);
printf("\n\nGeben Sie die Anfangsgeschwindigkeit zwischen 0 bis 250 km/h ein :  ");
scanf("%lf",&v0);
v1 = v0/3.6;
printf("die geschwindigkeit ist : %lf", v0);
t2 =t1+0.2;

s1 = 0;

for(t=0;t<t1; t = t+h)
{
    v1 = v1 + a1(t)*h;
    s1 = s1 + v1*h;
}

v2=v1;
s2= s1;

for(t=t1; t<t2;t = t+h)

{
    v2 = v2 + a2(t,t1)*h;
    s2 = s2 + v2*h;
}
v3=v2;
s3 = s2;


while(v3 >= 0)
{
v3= v3 + a3(t) *h;
s3= s3 + v3*h;
t = t+h;

}

if (s3<0)
{printf("\n Sie haben die Momenten gleichhung versemmelt");
}

printf("\n der Bremsweg ist : %.2lf", s3);
printf("\n die Gesamtszeit beträgt : %.2lf", t);


return 0;
}










