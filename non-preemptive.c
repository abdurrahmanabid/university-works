#include <stdio.h>
int main()
{
    int bArray[] = {6,8,7,3};

    int size = sizeof(bArray)/sizeof(bArray[0]);
    int brArray[size];
    for(int i=0; i<size ; i++)
    {
        brArray[i]=bArray[i];
    }
    int iArray[size];
    int gChart[size];
    for(int i=0; i<size ; i++)
    {
        iArray[i]=i;

    }
    for(int i=0; i<size-1 ; i++)
    {
        for(int j=0; j<size-1-i; j++)
        {
            if(bArray[j]>bArray[j+1])
            {

                int temp = bArray[j];
                bArray[j]=bArray[j+1];
                bArray[j+1]=temp;

                int temp2 = iArray[j];
                iArray[j]=iArray[j+1];
                iArray[j+1]=temp2;
            }
        }
    }
    int sum =0;
    for(int i=0; i<size ; i++)
    {
        sum+=brArray[iArray[i]];
        gChart[i]=sum;
    }
    cTime(iArray,gChart,size,brArray);


    return 0;
}
void cTime(int iArray[],int gChart[],int size,int brArray[])
{

    for(int i=0; i<size-1 ; i++)
    {
        for(int j=0; j<size-1-i; j++)
        {
            if(iArray[j]>iArray[j+1])
            {

                int temp = iArray[j];
                iArray[j]=iArray[j+1];
                iArray[j+1]=temp;

                int temp2 = gChart[j];
                gChart[j]=gChart[j+1];
                gChart[j+1]=temp2;
            }
        }
    }
    printf ("\nCompletion Time : ");
    for(int i=0; i<size ; i++)
    {
        printf ("  %d",gChart[i]);
    }
    printf ("\nTurnarroun Time : ");
    int avgTT=0;
    for(int i=0; i<size ; i++)
    {
        printf ("  %d",gChart[i]);
        avgTT+=gChart[i];
    }
    wTime(gChart,brArray,size,avgTT);
}

void wTime(int gChart[],int brArray[],int size,int avgTT)
{
    int wArray[size];
    printf ("\nWaiting time: ");
    int avgWT=0;
    for(int i=0; i<size ; i++)
    {
        wArray[i]=gChart[i]-brArray[i];
        printf ("  %d",wArray[i]);
        avgWT+=wArray[i];
    }
    printf ("\nAverage Waiting time : %d\nAverage Turnaround time :%d",avgWT/size,avgTT/size);
}



