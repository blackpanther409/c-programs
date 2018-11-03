#include<stdio.h>
#include<stdlib.h>	
struct Tnode
{
	int data;
	struct Tnode *lcptr;
	struct Tnode *rcptr;
};
struct Tnode *rptr=NULL;
void Inorder(struct Tnode *ptr);
void preorder(struct Tnode *ptr);
void levelorder(struct Tnode *ptr);
int height(struct Tnode *ptr);
void presentlevel(struct Tnode *ptr,int level);
void insert()
{
	int x;
	printf("Enter the number to insert\n");
	scanf("%d",&x);	
   	struct Tnode *tmp=malloc(sizeof(struct Tnode));
	tmp->data=x;
	tmp->lcptr=NULL;
   	tmp->rcptr=NULL;
   if(rptr==NULL)
	{	
		rptr=tmp;
	}
	else
	{
		struct Tnode *ptr=rptr;
		struct Tnode *pptr=NULL;
      		while(ptr!=NULL)
		{
			pptr=ptr;
         		if(x<ptr->data)
			{
				ptr=ptr->lcptr;	
			}
			else
			{
				ptr=ptr->rcptr;
			}
		}
		if(x<pptr->data)
			pptr->lcptr=tmp;
		else
			pptr->rcptr=tmp;	
	}	

}
void Inorder(struct Tnode *ptr)
{
	if(ptr!=NULL)
	{
		Inorder(ptr->lcptr);
		printf("%d ",ptr->data);
		Inorder(ptr->rcptr);
	}
}

void preorder(struct Tnode *ptr)
{
	if(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		preorder(ptr->lcptr);
		preorder(ptr->rcptr);
	}
}

void levelorder(struct Tnode *ptr)
{
	int h=height(ptr);
	for(int i=0;i<=h;i++)
		presentlevel(ptr,i);
}

void presentlevel(struct Tnode *ptr,int level)
{
	if(ptr==NULL)
	return;
	if(level==0)
	printf("%d ",ptr->data);
	else if(level>0)
	{
		presentlevel(ptr->lcptr,level-1);
		presentlevel(ptr->rcptr,level-1);	
	}

}

int height(struct Tnode *ptr)
{
	if(ptr==NULL)
		return -1;
	else if(height(ptr->lcptr)>height(ptr->rcptr))
		return height(ptr->lcptr)+1;
	else
		return height(ptr->rcptr)+1;
		
} 
void delete( )
{
	int x;
    printf("Enter the number to be deleted\n");
	scanf("%d",&x);
	int b=-666;	
   	struct Tnode *ptmp=NULL;
	struct Tnode *ptr=rptr;
	struct Tnode *pptr=NULL;	
	while(ptr!=NULL && ptr->data!=x)
	{
		pptr=ptr;		
		if(x>=ptr->data)
			ptr=ptr->rcptr;	
		else 
			ptr=ptr->lcptr;
	}	
	if(ptr==NULL)
	{
		printf("\n Deletion Fails");
	}
	else if(rptr->lcptr==NULL && rptr->rcptr==NULL)
	{
		b=rptr->data;		
		rptr=NULL;	
	}
	else if(ptr==rptr && ( rptr->lcptr==NULL || rptr->rcptr==NULL))
		{
			b=rptr->data;
			if(rptr->lcptr==NULL)
			rptr=rptr->rcptr;
			else
			rptr=rptr->lcptr;
			
		}
	else if(ptr->lcptr==NULL && ptr->rcptr==NULL) //Case 1:Delete Leaf Node
	{
		b=ptr->data;		
		if(x<pptr->data)
			pptr->lcptr=NULL;
		else
			pptr->rcptr=NULL;
	}
	else if(ptr->lcptr==NULL && ptr->rcptr!=NULL || ptr->lcptr!=NULL && ptr->rcptr==NULL)
	{
		b=ptr->data;		
		if(x<pptr->data && ptr->lcptr!=NULL)
			pptr->lcptr=ptr->lcptr;		
		else if(x<pptr->data && ptr->lcptr==NULL)
			pptr->lcptr=ptr->rcptr;
		else if(x>=pptr->data && ptr->lcptr!=NULL)
			pptr->rcptr=ptr->lcptr;
		else
			pptr->rcptr=ptr->rcptr;   
	}
	else
	{		
		struct Tnode *tmp=ptr;
     		ptmp=tmp;		
		tmp=tmp->rcptr;
      
		while(tmp->lcptr!=NULL)
		{
        		ptmp=tmp;
			tmp=tmp->lcptr;
		}
		b=ptr->data;		
		ptr->data=tmp->data;	
			

		//To delete suc node pointed to by tmp, and its parent is ptmp
      
       if(tmp->data < ptmp->data)
         ptmp->lcptr=tmp->rcptr;
       else
         ptmp->rcptr=tmp->rcptr;

	}
	printf("deleted data is %d\n",b);
	//return b;
}

void max()
{
	if(rptr!=NULL)
{    int b;
  	struct Tnode *thptr=rptr;
	while(thptr!=NULL)
	{
		b=thptr->data;		
		thptr=thptr->rcptr;	
	}
	printf("The maximum number is %d\n",b);
}
else
printf("tree is empty\n");
}



void min()
{	
	if(rptr!=NULL)
{    int b;
  	struct Tnode *thptr=rptr;
	while(thptr!=NULL)
	{
		b=thptr->data;		
		thptr=thptr->lcptr;	
	}
	printf("The minimum number is %d\n",b);
}
else
printf("tree is empty\n");
}




int main()
{	
	int i;
	A:	
	printf("Select an option\n1.insert\n2.delete\n3.print(inorder)\n4.max\n5.min\n6.print(preorder)\n7.print(levelorder)\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:insert();Inorder(rptr);goto A;break;
		case 2:delete();;goto A;break;
		//case 3:search();goto A;break;
		case 3:printf("\n\ntree has\n\n");
		if(rptr!=NULL)
		{Inorder(rptr);
 		printf("\n\n");}
		else
		printf("nothing\n");
		goto A;break;
		case 4:max();goto A;break;
		case 5:min();goto A;break;
		case 6:preorder(rptr);goto A;break;
		case 7:levelorder(rptr);goto A;break;
	}

	return 0;
}
