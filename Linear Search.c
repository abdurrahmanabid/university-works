#include <stdio.h>
int main()
{
    int a[]={1,2,3,4,5};
    int item = 1;
    for(int i=0;i<7 ;i++)
    {
        if(item==a[i]){
            printf ("Found,\n position %d ",i+1);
            break;
        }
    }
    return 0;
}
