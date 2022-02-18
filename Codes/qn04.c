#include <stdio.h>
#include<stdlib.h>
int *a;
int front , rear ,size;
int Isfull(){
    if (rear==size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int Isempty(){
    if (rear<front){
        return 1;
    }
    else if ((rear==-1)&&(front==-1))
    {
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(){
    if (Isfull()){
        printf("You cannot insert element the queue is full \n");
    }
    else{
        if (front == -1){
            front ++;
        }
        int i;
        printf("Enter your element need to be stored: ");
        scanf(" %d",&i);
        rear++;
        a[rear]=i;
    }

}
void dequeue(){
    if (Isempty()){
        printf("You cannot delete element the queue is empty \n");
    }
    else{
        a[front]=0;
        front++;
    }

}
void Display(){
    if (Isempty()){
        printf("Your Queue is empty \n");
    }
    else{
        for(int j=front ; j<=rear ; j++){
            printf("%d ",a[j]);
        }
        printf("\n");
    }
}
int main(){
    puts("\t\t QUEUE OPERATIONS");
    puts("INITIALIZE YOUR QUEUE");
    printf("Enter size of your queue: ");
    scanf(" %d",&size);
    a=(int *)malloc(sizeof(int)*size);
    front = rear =-1;
    puts("Starting QUEUE operations ....");
    int flag=1;
    int choose;
    while (flag){
        l1:
            puts("\nSELECT FROM OPTION :");
            printf("\t1.enqueue()\n\t2.dequeue()\n\t3.Isempty()\n\t4.Isfull()\n\t5.Display()\n\t6.Exit()\n\n");
            printf("Enter your choise(1-6): ");
            scanf(" %d",&choose);
            switch(choose){
                case 1:
                    enqueue();
                    break;
                case 2:
                    dequeue();
                    break;
                case 3:
                    (Isempty())?printf("Your queue is empty\n"):printf("Your queue is not empty\n");
                    break;
                case 4:
                    (Isfull())?printf("Your queue is full\n"):printf("Your queue is not full\n");
                    break;
                case 5:
                    Display();
                    break;
                case 6:
                    flag=0;
                    break;
                default:
                    printf("Enter the valid choise...\n");
                    goto l1;
                    break;


        }

    }
}
