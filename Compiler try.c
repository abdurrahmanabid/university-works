#include <stdio.h>
int main()
{
    float principal;
    printf ("Enter the amount of PRINCIPAL : ");
    scanf("%f",&principal);

    float interest;
    printf ("Enter the amount of interest : ");
    scanf("%f",&interest);
    interest /=100;

    float time;
    printf ("Enter the amount of time : ");
    scanf("%f",&time);


    while(time!=10){

        printf ("%0.0f\t %0.2f\n",time,(principal));
        principal+=(principal*interest*time);
    time++;
    }


    return 0;
}
