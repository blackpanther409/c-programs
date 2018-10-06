#include<stdio.h>
struct circular
{   int a[100];
    int front;
    int rear;
};
void enqueue(struct circular *q);
void dequeue(struct circular *q);
void search(struct circular cq);
void print(struct circular cq);
void isfull(struct circular cq);
void isempty(struct circular cq);
int main()
{   struct circular cq;
    cq.front=cq.rear=-1;
    int i;
    A:
    printf("Select an option \n1.enqueue\n2.dequeue\n3.search\n4.print\n5.isfull\n6.isempty\n7.Exit\n");
    scanf("%d",&i);
    switch(i)
    {   case 1:enqueue(&cq);goto A;break;
        case 2:dequeue(&cq);goto A;break;
        case 3:search(cq);goto A;break;
        case 4:print(cq);goto A;break;
        case 5:isfull(cq);goto A;break;
        case 6:isempty(cq);goto A;break;
        case 7:return 0;
    }
   
   
}

void enqueue(struct circular *q)                //enqueue function to insert an element at the rear
 {  int k;
    printf("Enter the number to be equeue\n");
    scanf("%d",&k);
    if(q->front==(q->rear+1)%100)              //when queue is full
        printf("Sorry, the queue is full cannot enqueue\n"); 
    else if(q->front==-1)                      //when queue is empty
    {   q->front=q->front+1;
        q->rear=q->rear+1;
        q->a[0]=k;
    }
    else
    {   q->rear=q->rear+1;
        q->a[q->rear]=k;
    }
 }

void dequeue(struct circular *q)                //dequeue function to delete an element at the front 
{    if(q->rear==-1)                            //when queue is empty
        printf("Sorry, the queue is empty cannot dequeue\n"); 
    else if(q->front==q->rear)                  //when queue has only one element
        q->front=q->rear=-1;
    else
        q->front=q->front+1;
}

void search(struct circular cq)                //search function to check if a given number is present in the queue
{   int k,p=0;
    if(cq.rear==-1)                            //when queue is empty
        printf("Sorry, the queue is empty cannot search\n");
    else                                       
    {   printf("Enter the number to be searched\n");
        scanf("%d",&k); 
        for(int i=cq.front;i<=cq.rear;i=(i+1)%100) //for loop to search for the number and fetch it's positon
           {if(cq.a[i]==k)
               {p=1;k=i;}}
        if(p==1)
            printf("%d is present in the queue at position  %d in queue\n",cq.a[k],k+1);
        else
           printf("%d is not present in the queue\n",cq.a[k]);
    }
}

void print(struct circular cq)                 //print function
{   if(cq.rear==-1)
        printf("Sorry, the queue is empty nothing to print\n");
    elseif(cq.rear>=cq.front)                  //when rear comes after front
        { printf("the queue is "); 
          for(int i=cq.front;i<=cq.rear;i=i++)
             printf("%d ",cq.a[i]);
          printf("\n");
        }
    else
        { printf("the queue is ");            //when rear comes before front
          for(int i=cq.front;i<100;i++)
             printf("%d ",cq.a[i]);
          for(int i=0;i<=cq.rear;i++)
             printf("%d ",cq.a[i]); 
          printf("\n");
        }
}
void isfull(struct circular cq)                 //isfull function
{   if(cq.front==(cq.rear+1)%100)
        printf("the queue is full\n");
    else
        printf("the queue is not full\n");
}

void isempty(struct circular cq)                //isempty function
{  if(cq.rear==-1)
        printf("the queue is empty \n");
   else
        printf("the queue is not empty \n");
}






