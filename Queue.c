#include <stdio.h>
#define CAP 5
int queue[CAP];
int front =0,rear=-1,total=0;
int dequeue()
{
    if(isEmpty()){
        printf ("Empty\n");
    }
    else{
        int frontItem = queue[front];
        front=(front+1)%CAP;
        total--;
        return frontItem;
    }
}

void enqueue(int item)
{
    if(isFull())
    {
        printf ("Sorry\n");
    }else{
    rear=(rear+1)%CAP;
    queue[rear]=item;
    total++;
    }
}


int isFull()
{
    if(total==CAP){
        return 1;
    }
    return 0;
}
int  isEmpty()
{
    if (total==0){
        printf ("True\n");
    }
}

int main()
{
    enqueue(6);
    enqueue(5);
    enqueue(7);
    enqueue(9);
    enqueue(87);
    enqueue(65);

    printf ("%d detetion\n",dequeue());
    for(int i=0; i<CAP ; i++)
    {
        printf ("%d ",queue[i]);
    }
    enqueue(65);
    printf ("%d detetion\n",dequeue());
    for(int i=0; i<CAP ; i++)
    {
        printf ("%d ",queue[i]);
    }
    return 0;
}
