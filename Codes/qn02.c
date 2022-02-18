#include <stdio.h>
#include <stdlib.h>
int size=0;

struct node {
    int SSN,PhNo;
    float sal;
    char Name[50],Dept[70],Designation[100];
    struct node* prev;
    struct node* next;
}*head;
void SEARCH(){
    int item;
    printf("Enter SSN of Employee: ");
    scanf("%d",&item);
    struct node* ptr = head;
    int i =0 , flag=0;
    if(ptr==NULL){
        printf("\nEmpty List\n");
    }
    else{
        while(ptr!=NULL){
            if(ptr->SSN==item){
                printf("Item found at location %d",i+1);
                flag=0;
                break;
            }
            else{
                flag=1;
            }
            i++;
            ptr=ptr->next;
        }
        if(flag){
            printf("Item not found\n");
        }
    }
}
void in_f(){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* temp=head;
    printf("\nEnter SSN: ");
    scanf(" %d",&ptr->SSN);
    printf("Enter Name: ");
    scanf(" %[^\n]s",ptr->Name);
    printf("Enter Dept: ");
    scanf(" %[^\n]s",ptr->Dept);
    printf("Enter Designation :");
    scanf(" %[^\n]s",ptr->Designation);
    printf("Enter Salary :");
    scanf(" %f",&ptr->sal);
    printf("Enter Phone Number :");
    scanf(" %d",&ptr->PhNo);
    ptr->next=head;
    head=ptr;
    temp->prev=ptr;
    size++;
}

void in_e(){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter SSN: ");
    scanf(" %d",&ptr->SSN);
    printf("Enter Name: ");
    scanf(" %[^\n]s",ptr->Name);
    printf("Enter Dept: ");
    scanf(" %[^\n]s",ptr->Dept);
    printf("Enter Designation :");
    scanf(" %[^\n]s",ptr->Designation);
    printf("Enter Salary :");
    scanf(" %f",&ptr->sal);
    printf("Enter Phone Number :");
    scanf(" %d",&ptr->PhNo);
    ptr->next=NULL;
    struct node * pos = head;
    if (head== NULL) {
        head = ptr;
        return;
    }
    while (pos->next != NULL) {
        pos = pos->next;
    }
    pos->next=ptr;
    ptr->prev=pos;
    size++;
    return;
}
void del_b(){
    struct node* ptr=head;
    head =ptr->next;
    struct node* tmp=head;
    tmp->prev=NULL;
    size--;
}
void del_e(){
    struct node * pos = head,* temp;

    while (pos->next != NULL) {
        temp = pos;
        pos = pos->next;
  }
  temp->next=NULL;
  size--;

}
void create(){
    int n;
    printf("Enter Number of input: ");
    scanf(" %d",&n);
    for(int i=0 ; i<n;i++){
        printf("\nEmployee: %d\n",i+1);
        in_e();
    }
}
void DISPLAY(){
    struct node * pos = head;
    int count=1;
    while (pos != NULL) {
        printf("Employee: %d\n",count);
        printf("SSN:%d\n",pos->SSN);
        printf("Name: %s\n",pos->Name);
        printf("Department: %s\n",pos->Dept);
        printf("Designation: %s\n",pos->Designation);
        printf("Salary: %.2f\n",pos->sal);
        printf("Phone Number: %d\n",pos->PhNo);
        printf("\n");
        pos = pos->next;
        count++;
    }
}
int main(){

    head = NULL;
    int op =1,i=0;
    printf("\n\tCreate Your List\n");
    create();

    while(op){
        if (size ==0)
            head=NULL;
        int choose;
        m1:

            puts("\n*******************************************************************************");
            puts("\n\t\t\t\tMENU: \n\n\t\t1.INSERT At Front \n\t\t2.INSERT At End \n\t\t3.DISPLAY \n\t\t4.DELETE At Front \n\t\t5.DELETE At End \n\t\t6.EXIT\n");
            puts("\n*******************************************************************************");
            printf("\n\tSELECT YOUR OPTION FROM MENU :");
            scanf("%d",&choose);
            switch(choose){
            case 1:
                in_f();
                break;
            case 2:
                in_e();
                break;
            case 3:
                DISPLAY();
                break;
            case 4:
                del_b();
                DISPLAY();
                break;
            case 5:
                del_e();
                DISPLAY();
                break;
            case 6:
                op=0;
                break;
            default:
                puts("Please Enter the valid choice : ");
                goto m1;
                break;
        }
    }
}
