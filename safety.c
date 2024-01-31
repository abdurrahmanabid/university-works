#include <stdio.h>
int main()
{
    printf ("No. of pro: ");
    int pro;
    scanf("%d",&pro);
    printf ("No. resource :");
    int res;
    scanf("%d",&res);
    int ins;
    scanf("%d",&ins);

    int mNeed[pro];
    for(int i=0;i<pro ;i++)
    {
        scanf("%d",&mNeed[i]);
    }

    int alloc[pro];

    return 0;
}
