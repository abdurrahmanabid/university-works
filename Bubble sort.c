#include <stdio.h>
int main()
{
    int size;
    scanf("%d",&size);
    int a[5];

    for(int i=0;i<size ;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<size ;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if(a[j]<a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1]=temp;
            }

        }
    }
    for(int i=0;i<size ;i++)
    {
        printf("%d    ",a[i]);
    }
    return 0;
}
