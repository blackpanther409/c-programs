 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	struct node* lcptr;
	struct node* rcptr;
	int num;
	char title[100];
	char author[100];
};
struct node* rptr=NULL;
void insert();
void delete();
void inorder(struct node* ptr);
void search();
int main()
{	
	int i;
	A:	
	printf("Select an option\n1.insert\n2.delete\n3.search\n4.print\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:insert();inorder(rptr);goto A;break;
		case 2:delete();;goto A;break;
		case 3:search();goto A;break;
		case 4:printf("\n\nlibrary has\n\n");
		if(rptr!=NULL)
		inorder(rptr);
		else
		printf("nothing\n");
		goto A;break;
	}

	return 0;
}
void insert()
{
	struct node* temp=malloc(sizeof(struct node));
	struct node* ptr=rptr;
	struct node* pptr=NULL;
	if(temp==NULL)
		printf("Sorry library is full of books, cannot add another book\n");
	else
	{	
		temp->lcptr=NULL;
		temp->rcptr=NULL;
		printf("Enter the book title\n");
		scanf("%s",temp->title);
		printf("Enter the author name\n");
		scanf("%s",temp->author);
		printf("Enter the accesory number\n");
		scanf("%d",&temp->num);
		if(rptr==NULL)
		{
			rptr=temp;
		}
		else
		{
			while(ptr!=NULL)
			{
				pptr=ptr;
				if(strcmp(temp->title,ptr->title)<0)
				ptr=ptr->lcptr;
				else
				ptr=ptr->rcptr;
			}
			if(strcmp(temp->title,pptr->title)<0)
			pptr->lcptr=temp;
			else
			pptr->rcptr=temp;
		}
		
	}

}

void inorder(struct node* ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lcptr);
		printf("title:%s\nauthor:%s\naccesory number:%d",ptr->title,ptr->author,ptr->num);
		printf("\n");
		inorder(ptr->rcptr);
	}
}

void delete()
{
	struct node* ptemp=NULL;
	struct node* temp=NULL;
	struct node* ptr=rptr;
	struct node* pptr=ptr;
	char a[100];
	printf("Enter the title of the book\n");
	scanf("%s",a);
	
	 
	while(ptr!=NULL && strcmp(ptr->title,a)!=0)
	{
		pptr=ptr;
		if(strcmp(a,ptr->title)<0)
			ptr=ptr->lcptr;
		else
			ptr=ptr->rcptr;
	}
	if(ptr==NULL)
		printf("Cannot delete\n");
	else if(rptr->rcptr==NULL && rptr->lcptr==NULL)
		{
			rptr=NULL;			
		}
	else if(ptr==rptr && ( rptr->lcptr==NULL || rptr->rcptr==NULL))
		{
			if(rptr->lcptr==NULL)
			rptr=rptr->rcptr;
			else
			rptr=rptr->lcptr;
		}
	else if(ptr->rcptr==NULL && ptr->lcptr==NULL)
		{
			if(strcmp(ptr->title,pptr->title)<0)
			pptr->lcptr=NULL;
			else
			pptr->rcptr=NULL;
		}
	else if((ptr->rcptr==NULL && ptr->lcptr!=NULL)||(ptr->rcptr!=NULL && ptr->lcptr==NULL))
		{
			 

		if( (strcmp(a,pptr->title)<0) && ptr->lcptr!=NULL)
			pptr->lcptr=ptr->lcptr;		
		else if((strcmp(a,pptr->title)<0) && ptr->lcptr==NULL)
			pptr->lcptr=ptr->rcptr;
		else if( (strcmp(a,pptr->title)>0) && ptr->lcptr!=NULL)
			pptr->rcptr=ptr->lcptr;
		else
			pptr->rcptr=ptr->rcptr;   



		}	
		
	else
		{	
			temp=ptr;			
			ptemp=temp;
			temp=ptr->rcptr;
			
			while(temp->lcptr!=NULL)
			{
				ptemp=temp;
				temp=temp->lcptr;
			}
			strcpy(ptr->title,temp->title);
			if(strcmp(temp->title,ptemp->title)<0)
		 		ptemp->lcptr=temp->rcptr;
			else
				ptemp->rcptr=temp->rcptr;
			 
			 
			 
				
			
		}	
		
		printf("The deleted book is:\n");
		printf("title:%s\nauthor:%s\naccesory number:%d\n",ptr->title,ptr->author,ptr->num);
}

void search()
{
	struct node* thptr=rptr;
	char a[100];
	printf("Enter the title of the book to be searched\n");
	scanf("%s",a);
	while(thptr!=NULL)
	{
		if(strcmp(a,(thptr->title))==0)
		{
			printf("The book is present in the library:\n");
			printf("title:%s\nauthor:%s\naccesory number:%d\n",thptr->title,thptr->author,thptr->num);
			break;
		}
		if(strcmp(a,(thptr->title))<0)
			thptr=thptr->lcptr;
		else
			thptr=thptr->rcptr;
	}
	if(thptr==NULL)
	printf("The book is currently not available\n");
	 
}
