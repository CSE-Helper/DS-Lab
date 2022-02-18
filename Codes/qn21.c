#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
   int data;
   struct node* left;
   struct node* right;
};
struct node *root;
void printKDistant(struct node *root , int k)
{
   if(root == NULL|| k < 0 )
      return;
   if( k == 0 )
   {
      printf( "%d ", root->data );
      return ;
   }

      printKDistant( root->left, k-1 ) ;
      printKDistant( root->right, k-1 ) ;

}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

/* Driver program to test above functions*/
int main()
{
    int K=2,ch=0;
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \    /
    4     5  8
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->right->left = newNode(5);
  root->right->right = newNode(6);
  loop:
  printf("Do you want to access any elements at K level of the binary tree:\n1.)Yes\n2.)No\n");
  scanf("%d", &ch);
  while (ch!=2){
    printf("Enter the value of K: ");
    scanf("%d",&K);
    printKDistant(root,K);
    printf("\n");
    goto loop;
  }
  getchar();
  return 0;
}
