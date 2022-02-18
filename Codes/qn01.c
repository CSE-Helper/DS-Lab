#include <stdio.h>
#include <stdlib.h>
int size=0;
struct node {
    int Rollno,PhoneNo;
    char Name[50],Branch[100];
    struct node* next;
}*head;
void SEARCH(){
    int item;
    printf("Enter Roll Number: ");
    scanf("%d",&item);
    struct node* ptr = head;
    int i =0 , flag=0;
    if(ptr==NULL){
        printf("\nEmpty List\n");
    }
    else{
        while(ptr!=NULL){
            if(ptr->Rollno==item){
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
void del_e(){
    struct node * pos = head,* temp;
    int item;
    printf("Enter Roll Number: ");
    scanf("%d",&item);
    int i =0 , flag=0;
    if(pos==NULL){
        printf("\nEmpty List\n");
    }
    else{
        while(pos!=NULL){
            if(pos->Rollno==item){
                printf("Item found at location %d",i+1);
                flag=0;
                break;
            }
            else{
                flag=1;
            }
            i++;
            temp = pos;
            pos = pos->next;
        }
        temp->next=pos->next;
        size--;
        printf("\nData Has Been Deleted!\n");
    }
}
void in_e(){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the Roll Number: ");
    scanf(" %d",&ptr->Rollno);
    printf("Enter Name: ");
    scanf(" %[^\n]s",ptr->Name);
    printf("Enter Branch: ");
    scanf(" %[^\n]s",ptr->Branch);
    printf("Enter Phone Number :");
    scanf(" %d",&ptr->PhoneNo);
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
    size++;
    return;
}
void INSERT(){
    int item,choice;
    if(head==NULL){
        puts("\n\tYou can only insert at the beginning");
        struct node* ptr = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter the Roll Number: ");
        scanf(" %d",&ptr->Rollno);
        printf("Enter Name: ");
        scanf(" %[^\n]s",ptr->Name);
        printf("Enter Branch: ");
        scanf(" %[^\n]s",ptr->Branch);
        printf("Enter Phone Number :");
        scanf(" %d",&ptr->PhoneNo);
        ptr->next=head;
        head=ptr;
        size++;
    }
    else{
        in_e();
    }
}
void DELETE(){
    int item,choice;
    if(head==NULL){
        puts("THERE IS NO NODE IS PRESENT TO DELETE");
    }
    else if(size==1){
        printf("There is only one node in the list ");
        head=NULL;
    }
    else{
        del_e();
    }
}
void DISPLAY(){
    struct node * pos = head;
    int count=1;
    while (pos != NULL) {
        printf("Student: %d\n",count);
        printf("Roll Number:%d\n",pos->Rollno);
        printf("Name: %s\n",pos->Name);
        printf("Branch: %s\n",pos->Branch);
        printf("Phone Number: %d\n",pos->PhoneNo);
        printf("\n");
        pos = pos->next;
        count++;
    }
}
int main(){
 head = NULL;
 int op =1,i=0;
 while(op){
    if (size ==0)
        head=NULL;
    int choose;
    m1:

    puts("\n*******************************************************************************");
    puts("\n\t\t\t\tMENU: \n\n\t\t1.INSERT \n\t\t2.DELETE \n\t\t3.SEARCH\n\t\t4.DISPLAY \n\t\t5.EXIT");

    puts("\n*******************************************************************************");
    printf("\n\tSELECT YOUR OPTION FROM MENU :");
    scanf("%d",&choose);
    switch(choose){
        case 1:
            INSERT();
            break;
        case 2:
            DELETE();
            break;
        case 3:
            SEARCH();
            break;
        case 4:
            DISPLAY();
            break;
        case 5:
            op=0;
            break;
        default:
            puts("Please Enter the valid choice : ");
            goto m1;
            break;
    }
 }
}
