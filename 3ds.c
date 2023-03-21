#include<stdio.h>
#include<stdlib.h>
struct node
{
	int co,exp;
	struct node *next;
};
struct node * create(struct node * head,int co,int exp)
{
	struct node *temp,*flag;
	if(head==NULL)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->co=co;
		temp->exp=exp;
		temp->next=NULL;
		head=temp;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		flag=(struct node*)malloc(sizeof(struct node));
		flag->co=co;
		flag->exp=exp;
		flag->next=NULL;
		temp->next=flag;
	}
	return head;
}
struct node* polyadd(struct node *p1,struct node *p2,struct node *sum)
{
	struct node *poly1=p1,*poly2=p2,*res;
	if(poly1!=NULL  && poly2==NULL)
	{
		sum=poly1;
		return sum;
	}
	else if(poly1==NULL)
	{
		sum=poly2;
		return sum;
	}
	while(poly1!=NULL && poly2!=NULL)
	{
		if(sum==NULL)
		{
			sum=(struct node*)malloc(sizeof(struct node));
			res=sum;
		}
		else
		{
			res->next=(struct node*)malloc(sizeof(struct node));
			res=res->next;
		}
		if(poly1->exp > poly2->exp)
		{
			res->co=poly1->co;
			res->exp=poly1->exp;
			poly1=poly1->next;
		}
		else if(poly1->exp < poly2->exp)
		{
			res->co=poly2->co;
			res->exp=poly2->exp;
			poly2=poly2->next;
		}
		else if(poly1->exp==poly2->exp)
		{
			res->co=poly1->co+poly2->co;
			res->exp=poly1->exp;
			poly1=poly1->next;
			poly2=poly2->next;
		}
	}
	while(poly1!=NULL)
	{
		res->next=(struct node*)malloc(sizeof(struct node));
		res=res->next;
		res->co=poly1->co;
		res->exp=poly1->exp;
		poly1=poly1->next;
	}
	while(poly2!=NULL)
	{
		res->next=(struct node*)malloc(sizeof(struct node));
		res=res->next;
		res->co=poly2->co;
		res->exp=poly2->exp;
		poly2=poly2->next;
	}
	res->next=NULL;
	return sum;
}
void display(struct node* head)
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d^%d+",temp->co,temp->exp);
		temp=temp->next;
	}
	printf("\n");
}
void main()
{
	struct node *p1=NULL,*p2=NULL,*sum=NULL;
	int ch,co,exp;
	int loop=1;
	while(loop)
	{
		printf("1.addp1\n");
		printf("2.addp2\n");
		printf("3.peradd\n");
		printf("4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter coefficient\n");
			       scanf("%d",&co);
			       printf("enter exponent\n");
			       scanf("%d",&exp);
			       p1=create(p1,co,exp);
			       break;
			case 2:printf("enter coefficient\n");
			       scanf("%d",&co);
			       printf("enter exponent\n");
			       scanf("%d",&exp);
			       p2=create(p2,co,exp);
			       break;
			case 3:sum=polyadd(p1,p2,sum);
			       printf("\n p1\n");
			       display(p1);
			       printf("\n p2\n");
			       display(p2);
			       printf("\nsum:\n");
			       display(sum);
			       break;
			case 4:loop=0;
			       break;
			default:printf("wrong choice\n");
			        break;
	    }
	  }
}
			       
			  
			      
			

