#include<stdio.h>
#include<stdlib.h>
#define max 6
typedef struct node
{
	int x;
	int AccNo,amount;
	struct node* next;
}node;
node* a[max];
char arr[][50]={"Cash withdrawals or deposits", "Checks", "Online payments", "Debit card charges", "Wire transfers","Loan payments"};
void insert()
{
    int d;
    l1:

        printf("\nTypes Of Bank Transaction:\n");
        printf("1.Cash Withdrawls or Deposits \n2.Checks \n3.Online Payments \n4.Debit Card \n5.Loan Payments \n6.Wired Transfers\n");
        printf("\nEnter type of Transaction : ");
        scanf("%d",&d);
        if(d<1 || d>6){
            printf("Enter Valid Choose:");
            goto l1;
        }
	int x=d-1;
	node* newnode=(node*)malloc(sizeof(node));
	printf("\nEnter Account Number:");
	scanf(" %d",&newnode->AccNo);
	printf("Enter Amount:");
	scanf(" %d",&newnode->amount);
	newnode->next=NULL;
	if(a[x]==NULL)
		a[x]=newnode;
	else
	{
		node *ptr;
		ptr=a[x];
		int flag=1;
		while(ptr->next!=NULL)
		{
			if(ptr->x==d)
				flag=0;
			ptr=ptr->next;
		}
		if(ptr->x==d)
				flag=0;
		if(flag==1)
			ptr->next=newnode;
		else
			printf("Element already exists !");
	}
}
void search()
{
    l2:
    printf("\nTypes Of Bank Transaction:\n");
    printf("1.Cash Withdrawls or Deposits \n2.Checks \n3.Online Payments \n4.Debit Card \n5.Loan Payments \n6.Wired Transfers\n");
    printf("Enter type of Transaction : ");
    int x;
    scanf(" %d",&x);
    if(x<1 || x>6){
            printf("Enter Valid Choose:");
            goto l2;
        }
	printf("\nEnter the account number you want to check :");
	int d;
	scanf("%d",&d);
	x--;
	node* ptr=a[x];
	int flag=0;
	while(ptr!=NULL)
	{
		if(ptr->AccNo==d){
			flag=1;
			break;
		}
		ptr=ptr->next;
	}
	if(flag==1)
		printf("Element present");
	else
		printf("Element not found");
}
void display()
{
	for(int i=0;i<max;i++)
	{
		node* ptr=a[i];
		printf("%d.%s - ",i+1,arr[i]);
		while(ptr!=NULL)
		{
			printf("[AccNO:%d | Rs:%d], ",ptr->AccNo,ptr->amount);
			ptr=ptr->next;
		}
		printf("\n");
	}
}
void deposit(){
    l2:
    printf("\nTypes Of Bank Transaction:\n");
    printf("1.Cash Withdrawls or Deposits \n2.Checks \n3.Online Payments \n4.Debit Card \n5.Loan Payments \n6.Wired Transfers\n");
    printf("Enter type of Transaction : ");
    int x;
    scanf(" %d",&x);
    if(x<1 || x>6){
            printf("Enter Valid Choose:");
            goto l2;
        }
	printf("\nEnter the account number you want to Deposit :");
	int d,rs;
	scanf("%d",&d);
	printf("\nEnter amount you want to Deposit :");
	scanf("%d",&rs);
	x--;
	node* ptr=a[x];
	int flag=0;
	while(ptr!=NULL)
	{
		if(ptr->AccNo==d){
			flag=1;
			ptr->amount=ptr->amount+rs;
			break;
		}
		ptr=ptr->next;
	}
	if(flag!=1)
		printf("Element not found");

}
void withdrawl(){
    l2:
    printf("\nTypes Of Bank Transaction:\n");
    printf("1.Cash Withdrawls or Deposits \n2.Checks \n3.Online Payments \n4.Debit Card \n5.Loan Payments \n6.Wired Transfers\n");
    printf("Enter type of Transaction : ");
    int x;
    scanf(" %d",&x);
    if(x<1 || x>6){
            printf("Enter Valid Choose:");
            goto l2;
        }
	printf("\nEnter the account number you want to Withdrawl :");
	int d,rs;
	scanf("%d",&d);
	printf("\nEnter amount you want to Withdrawl :");
	scanf("%d",&rs);
	x--;
	node* ptr=a[x];
	int flag=0;
	while(ptr!=NULL)
	{
		if(ptr->AccNo==d){
			flag=1;
			if(ptr->amount>rs){
			ptr->amount=ptr->amount-rs;
			}
			else
                printf("In sufficient Balance \n");
			break;
		}
		ptr=ptr->next;
	}
	if(flag!=1)
		printf("Element not found");

}
void main()
{

	for(int i=0;i<max;i++)
		a[i]=NULL;
    printf("\t\tBank Transaction\n\n");

	while(1)
	{
	    printf("\n\tMENU\n1.Create\n2.Search\n3.Display\n4.Deposit\n5.Withdrawl\n6. Exit");
		printf("\nEnter your choice :");
		int ch;
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert();
				break;
			case 2:search();
				break;
			case 3:
			    printf("\n");
			    display();
				break;
            case 4:deposit();
				break;
            case 5:withdrawl();
				break;
			case 6:exit(1);
			default:printf("Wrong choice\n");
		}
	}
}
