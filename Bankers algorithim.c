#include <stdio.h>
int main()
{
    int process[]= {1,2,3},maxNeed[]= {10,4,9},allocation[]= {5,2,2},available=3,av=available,comSeq[3],currentNeed[3],flag=0,sum=0,total=0,count=0;

    int n=3;
    printf ("Process :");
    for(int i=0; i<n ; i++)
    {
        printf ("%d  ",process[i]);

    }
    printf ("\nMax Need :");
    for(int i=0; i<n ; i++)
    {
        printf ("%d  ",maxNeed[i]);

    }
    printf ("\nAllocation :");
    for(int i=0; i<n ; i++)
    {
        printf ("%d  ",allocation[i]);

    }
    printf ("\nAvailable : %d",available);

    for(int i=0; i<n ; i++)
    {
        total+=allocation[i];
    }
    for(int i=0; i<n ; i++)
    {
        currentNeed[i]=maxNeed[i]-allocation[i];

    }
    printf ("\nCurrent Need :");
    for(int i=0; i<n ; i++)
    {
        printf ("%d   ",currentNeed[i]);
    }
    while(1)
    {
        int i=0;
        for( i=0; i<n ; i++)
        {
            if ((currentNeed[i] <= available) && (allocation[i] != 0))
            {

                available+= allocation[i];
                allocation[i]=0;
                comSeq[flag++]=i+1;
                count++;

            }
        }

        if (count==n)
            break;
    }

    total=av+total;

    if(total==available)
    {
        printf ("\n\nThe system is in safe state:\n\n");

        for(int i=0; i<n ; i++)
        {
            printf ("P%d",comSeq[i]);
            if(i!=n-1)
                printf ("--->");
        }
    }
    printf ("\n");
    return 0;
}

    printf ("\nAllocation :");
    for(int i=0; i<n ; i++)
    {
        printf ("%d  ",allocation[i]);

    }
    printf ("\nAvailable : %d",available);

    for(int i=0; i<n ; i++)
    {
        total+=allocation[i];
    }
    for(int i=0; i<n ; i++)
    {
        currentNeed[i]=maxNeed[i]-allocation[i];

    }
    printf ("\nCurrent Need :");
    for(int i=0; i<n ; i++)
    {
        printf ("%d   ",currentNeed[i]);
    }
    while(1)
    {
        int i=0;
        for( i=0; i<n ; i++)
        {
            if ((currentNeed[i] <= available) && (allocation[i] != 0))
            {

                available+= allocation[i];
                allocation[i]=0;
                comSeq[flag++]=i+1;
                count++;

            }
        }

        if (count==n)
            break;
    }

    total=av+total;

    if(total==available)
    {
        printf ("\n\nThe system is in safe state:\n\n");

        for(int i=0; i<n ; i++)
        {
            printf ("P%d",comSeq[i]);
            if(i!=n-1)
                printf ("--->");
        }
    }
    printf ("\n");
    return 0;
}
