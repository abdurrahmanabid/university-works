#include <stdio.h>
int main()
{
    char str[] = "LAILAtulBORAT";
    int a[]={1,2,3};
    char cap[20],sma[20];

    int size = sizeof(str)/sizeof(char);
    for(int i=0;i<14 ;i++)
    {
        if(str[i]<='Z' && str[i]>='A'){
            cap[i]=str[i];
        }
        else if(str[i]<='z' && str[i]>='a'){
            sma[i]=str[i];
        }
    }
    printf("%s\t%s",cap);

    return 0;
}





