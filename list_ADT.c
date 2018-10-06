#include<stdio.h>

struct list
{ 	int a[20];
  	int lsize;
};
void insert( struct list *pl,int pos,int x);
void print(struct list l);
void delete( struct list *pl,int pos);
void search( struct list *pl,int x);
void isEmpty(struct list l);
void isFull(struct list l);

int main()
{	int pos,x;
  	int c;
  	struct list l;
  	l.lsize=0;
  	A:
  	printf("enter 1 to insert \n 2 to delete\n 3 to search \n 4 to check is_empty? \n 5 to check is_full?\n");
  	fflush(stdin);
  	scanf("%d",&c);
  	if(c==1)
  		{ printf("Enter position and value to be inserted\n");
    	  fflush(stdin);
    	  scanf("%d%d",&pos,&x);
    	  if(pos>=0 && pos<20 && pos<=(l.lsize))
    		{ insert(&l,pos,x);
     		  print(l);}
    	  else
    		printf("Invalid position to insert into the array please try again\n");goto A;
  		}

  	else if(c==2)
  		{ if(l.lsize>0)
     		{ printf("Enter the position of the array to be deleted\n");
       		  scanf("%d",&pos);
       	  if(pos>=0 && pos<=20 && pos<l.lsize)
      		{ delete(&l,pos);
       		  print(l);}
       	  else
       		printf("deleting is not possible ,please try again\n");goto A;
     		}
     else
       printf("deleting is not possible as array is empty ,please try again\n");goto A;
  		}
  else if(c==3)
 	 { if(l.lsize>0)
    	{ printf("enter value to be searched\n");
      	  scanf("%d",&x);
          search(&l,x);
  	    }
  	   else
    	printf("searching is not possible as array is empty ,please try again\n"); goto A;
  	 }
  else if(c==4)
  	  isEmpty(l);goto A;
  else if(c==5)
  	{   isFull(l);
    	goto A;
  	}
  return 0;
}
void insert( struct list *pl,int pos,int x)
{

  int i;
  for(i=pl->lsize;i>=pos;i--)
  	 pl->a[i+1]=pl->a[i];
  pl->a[pos]=x;
  pl->lsize++;
}

void delete( struct list *pl,int pos)
{ 	if(pl->lsize==0)
		printf("Sorry no elements in the list, cannot delete");
 	else 
		{for(int i=pos;i<(pl->lsize)-1;i++)
  			pl->a[i]=pl->a[i+1];
  		 pl->lsize--;
		}
}

void print(struct list l)
{ if(l.lsize==0)
		printf("Sorry no elements in the list, cannot delete");
  else
  		{ for(int i=0;i<l.lsize;i++)
  		  	printf("%d  ",l.a[i]);
  		  printf("\n");
		}
}

void search( struct list *pl,int x)
{ int k=0;
  for(int i=0;i<(pl->lsize);i++)
   	{if(pl->a[i]==x)
     k=k+1;}
  if(k>0)
  	printf("the element is present in the array\n");
  else
  	printf("the element is not present in the array\n");
}

void isEmpty(struct list l)
{
	if(l.lsize==0)
 		printf("\nthe list is empty\n\n");
	else
		printf("\nthe list is not empty\n\n");

}


void isFull(struct list l)
{
	if(l.lsize==20)
 		printf("\nthe list is full\n\n");
	else
		printf("\nthe list is not full\n\n");

}



