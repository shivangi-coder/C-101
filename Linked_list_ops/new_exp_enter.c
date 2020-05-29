//Program to insert an expression in an polynomial expression
#include<stdio.h>
#include<stdlib.h>
typedef struct data
{
	int cons;
        int power;
	struct data *next;
}node;

node *start,*temp;

void read();
void sort();
void display();
void insert();

main()
{
	char ch='Y';
	int i;
	while(ch=='Y'||ch=='y')
	{
		read();
		printf("\n Wanna Enter more \n");
		scanf(" %c",&ch);
	}

	sort();

	display();
	printf("\n Wanna Add More \n");
	scanf(" %c",&ch);
	while(ch=='Y'||ch=='y')
	{
		insert();
		printf("\n Wanna Add more \n");
		scanf(" %c",&ch);
	}
	display();

}

void read()
{

	if(start==NULL)
	{
	temp=(node *)malloc(sizeof(node));

	printf("\n Enter the Constant\n");
	scanf("%d",&(temp->cons));
	printf("\n Enter the Power \n");
	scanf("%d",&(temp->power));
		start=temp;
	}
	else
	{
		temp->next=(node *)malloc(sizeof(node));
		temp=temp->next;
                printf("\n Enter the Constant\n");
		scanf("%d",&(temp->cons));
		printf("\n Enter the Power \n");
	        scanf("%d",&(temp->power));

	}
}

void display()
{
	temp=start;
	do
	{
		printf(" (%d x^%d)+ ",temp->cons,temp->power);
		temp=temp->next;
	}while(temp!=NULL);
	printf("0");
}


void sort()
{
	node *temp1,t;
	int n,i,j;
	temp=start;
	for(n=0;temp!=NULL;n++)
	{
		temp=temp->next;
	}

	for(i=0;i<n-1;i++)
	{
		temp=start;
		temp1=start->next;
		for(j=0;j<n-i-1;j++)
		{
			if((temp->power)<(temp1->power))
			{
				t.cons=temp->cons;
				t.power=temp->power;
				temp->cons=temp1->cons;
				temp->power=temp1->power;
				temp1->cons=t.cons;
				temp1->power=t.power;
			}
			temp=temp->next;
			temp1=temp1->next;
		}
	}

	temp=start;
	temp1=start->next;
	for(i=0;temp1!=NULL;i++)
	{
	
		do
		{
		if(temp->power==temp1->power)
		{
			temp->cons=temp->cons+temp1->cons;
			node *t1;
			t1=temp1;
			temp->next=temp1->next;
			temp1=temp1->next;
			t1->next=NULL;
			free(t1);
		}
		else
			break;
		}while(temp->power==temp1->power);
		temp=temp->next;
		temp1=temp1->next;
	}


}


void insert()
{
	node *temp1;

	temp1=(node *)malloc(sizeof(node));
	printf("\n Enter the constant \n");
	scanf("%d",&(temp1->cons));
	printf("\n Enter the power of x \n");
	scanf("%d",&(temp1->power));

	temp=start;

	if((temp1->power)>(start->power))
	{
		temp1->next=start;
		start=temp1;
	}

	else
	{
		if(temp1->power==start->power)
			start->cons=start->cons+temp1->cons;

		else
		{
			while(temp->next!=NULL)
			{
				if((temp1->power)>(temp->next->power))
				{
					temp1->next=temp->next;
					temp->next=temp1;
					break;
				}
				else
				{
					if((temp1->power)==(temp->next->power))
					{
						temp->next->cons=(temp->next->cons)+(temp1->cons);
						break;
					}
					else
						temp=temp->next;
				}
			}
		}
	}
}




