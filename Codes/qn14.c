// Min-Heap data structure in C

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
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] < array[smallest])
      smallest = l;
    if (r < size && array[r] < array[smallest])
      smallest = r;
    if (smallest != i)
    {
      swap(&array[i], &array[smallest]);
      heapify(array, size, smallest);
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
void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}
int main()
{
    int fg=1;
printf("\t\tMin Heap\n\n");

printf("Enter Number Of Element : ");
scanf(" %d",&n);
int e,c;
int array[n];
for (int i=0 ; i<n;i++){
    printf("Enter Data[%d]: ",i);
    scanf(" %d",&e);
    insert(array, e);
}
printf("\nBinary Heap : \n");
printArray(array, size);

}





