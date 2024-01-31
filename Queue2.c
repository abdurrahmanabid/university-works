#include <stdio.h>
#define size 5
int que[size];
int front=0,rear=0,count=0;
int main()
{
    enqueue(1);
    enqueue(1);
    enqueue(1);
    enqueue(1);
    enqueue(1);
    enqueue(1);
    return 0;
}
void enqueue(int item)
{
    if(!isFull())
    {
        if(rear!=size)
        {
            rear = rear+1;
            que[rear]=item;
        }
        else
        {
            rear=0;
            que[rear]=item;
        }
    count++;
    }
}

int isFull()
{
    if(count>size)
    {
        return 0;
    }
    else
    {
        printf ("\nQueue is Full");
        return 1;
    }

}
