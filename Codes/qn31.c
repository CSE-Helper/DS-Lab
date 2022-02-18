#include <stdio.h>
#include <stdlib.h>
int *arr;
int top,n;
void push(){
    if(top>=n-1){
        printf("STACK OVERFLOW!\n");
    }
    else{
        int item;
        printf("Enter the item is to be inserted :");
        scanf(" %d",&item);
        top++;
        arr[top]=item;
    }
}
void pop(){
    if(top<=-1){
        printf("STACK UNDERFLOW!\n");

    }
    else{
        int item;
        item=arr[top];
        top--;

    }
}
void peek(){
    printf("\nTHE TOP ELEMENT OF THE STACK IS -> %d\n",arr[top]);
}
void display(){
    for(int w=top;w>=0;w--){
        printf("| %d |",arr[w]);
        if(w==top){
            printf("<-top\n");
        }
        else{
            printf("\n");
        }
    }
}
int main(){
    top=-1;
    printf("\n\t\t\t   STACK OPERATION \n");
    printf("size of the array :");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    int f=1;
    int choose;
    while(f){
        l1:

            printf("\n\t\t\t   STACK OPERATION \n");
            printf("1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\n");
            printf("Enter your choice : ");
            scanf("%d",&choose);
            switch(choose){
                case 1:
                    push();
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    peek();
                    break;
                case 4:
                    display();
                    break;
                case 5:
                    f=0;
                    break;
                default:
                    printf("### Enter valid choose ###");
                    goto l1;
                    break;

            }
    }
}
