// Max-Heap data structure in C

#include <stdio.h>
int n=0;
int size = 0;
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void heapify(int array[], int size, int i)
{
  if (size == 1)
  {
    printf("Single element in the heap");
  }
  else
  {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;
    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}
void insert(int array[], int newNum)
{
  if (size == 0)
  {
    array[0] = newNum;
    size += 1;
  }
  else
  {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(array, size, i);
    }
  }
}
void deleteRoot(int array[], int num)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(array, size, i);
  }
}
void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}
int main()
{
    int fg=1;
printf("\t\tMax Heap\n\n");

printf("Enter Number Of Element : ");
scanf(" %d",&n);
int e,c;
int array[n];
for (int i=0 ; i<n;i++){
    printf("Enter Data[%d]: ",i);
    scanf(" %d",&e);
    insert(array, e);
}
printf("\nArray Created : \n");
printArray(array, size);
while(fg){
    printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n\n");
    printf("Enter Your Choice:");
    scanf(" %d",&c);
    switch(c){
        case 1:
            printf("Enter The Element:");
            scanf(" %d",&e);
            insert(array, e);
            printf("Element added!\n");
            printArray(array, size);
            printf("\n");
            break;
        case 2:
            printf("Enter The Element To Be Deleted:");
            scanf(" %d",&e);
            deleteRoot(array, e);
            printf("Element Deleted!\n");
            printArray(array, size);
            printf("\n");
            break;
        case 3:
            printArray(array, size);
            printf("\n");
            break;
        case 4:
            fg=0;
            printf("Thank You !\n");
            break;


    }
}


}

