#include <stdio.h>
#include <stdlib.h>



int prime(long int i)
{
    long int j;
    int state = 1;
    for(j=2;j<i;j++)
    {
        if((i%j)==0){state=0;break;}
    }
    return state;
}

int main()
{
    int t;
    long int m,n,i;
    printf("input test cases\n");
    scanf("%f", &t);
    while(t--) {
            printf("\ninput range starting with m :");
            scanf("%f" , &m);
     printf("\ninput range ending with n :");
        scanf("%f",&n);
        for(i=m;i<=n;i++)
        {
            if(i==1){
                //do nothing for 1
            } else{
                if(prime(i))printf("%d\n",i);
            }
        }
    }
    return 0;
}
