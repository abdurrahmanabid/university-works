#include <stdio.h>
int arrT[]={0,1,2,3};
int brT[]={8,4,9,5};
int main()
{
    int size = 4,endProcess=0;
    int tempA[4],check=0,first=0,iD[0];

    while(size!=endProcess){
        if(check==0){
            check++;
            tempA[0]=arrT[0];
            brT[0]--;
        }
        else{
            for(int i=0;i<4 ;i++)
            {
                if(check==arrT[i] || check>size){
                    tempA[check]=arrT[check];
                    for(int j=0;j<=check;j++)
                    {
                        if(brT[j]<brT[j+1]){
                            brT[j]--;
                            check++;
                            if(brT[j]==0){

                                iD[endProcess++]=j;
                            }
                        }else{
                            brT[j+1]--;
                            check++;
                            if(brT[j+1]==0){

                                iD[endProcess++]=j+1;
                            }
                        }

                    }
                }
            }
        }
    }
    for(int i=0;i<4 ;i++)
    {
        printf ("%d  ",iD[i]);
    }
    return 0;
}
