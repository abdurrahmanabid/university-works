#include <stdio.h>
int main()
{
    int Arrival[20],Brust[20],size;
    printf ("Enter number of process : ");
    scanf("%d",&size);
    printf ("Enter arrival time for %d Processes :",size);
    for(int i=0;i<size ;i++)
    {
        scanf("%d",&Arrival[i]);
    }
    printf ("Enter burst time for %d Processes :",size);
    for(int i=0;i<size ;i++)
    {
        scanf("%d",&Brust[i]);
    }

    completionTime(Arrival , Brust,size);

    return 0;
}

void completionTime(int a[] , int b[],int n){
    int temp;
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
        {
            if(a[i]>a[j])
            {
                printf ("%d  ",j+1);
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        for(int i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
}
