// Binary Search Tree operations in C
#include <stdio.h>
#include <stdlib.h>
struct node {
     int key;
     struct node *left, *right;
};
// Create a node
struct node *newNode(int item) {
     struct node *temp = (struct node *)malloc(sizeof(struct node));
     temp->key = item;
     temp->left = temp->right = NULL;
     return temp;
}
// Inorder Traversal
void inorder(struct node *root) {
     if (root != NULL) {
         // Traverse left
         inorder(root->left);
         // Traverse root
         printf("%d ", root->key);
         // Traverse right
         inorder(root->right);
     }

}
void postorder(struct node *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }

}
void preorder(struct node *root){
    if(root){
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }

}
// Insert a node
int arr[]={0,0,0,0,0,0,0,0,0,0};
int level=1;
struct node *insert(struct node *node, int key) {
     // Return a new node if the tree is empty
     if (node == NULL){
     arr[level]+=key;
     level=1; return newNode(key);}
     // Traverse to the right place and insert the node
     if (key < node->key){
        ++level;
     node->left = insert(node->left, key);

     }
     else{
         ++level;
     node->right = insert(node->right, key);

     }

     return node;
}
// Find the inorder successor
struct node *minValueNode(struct node *node) {
     struct node *current = node;
     // Find the leftmost leaf
     while (current && current->left != NULL)
     current = current->left;
     return current;
}

// Driver code
void result(){
    int sum=0;
    for(int i=0;i<10;i++){
        if(i%2 ==0){
            sum-=arr[i];
        }
        else
            sum+=arr[i];
    }
    printf("Result= %d",sum);
}
int main() {
     struct node *root = NULL;
     int choose,sz;
     int key;
     int f = 1;
     printf("\t\tBinary Search Tree\n\n");
     printf("Enter number of elements :");
     scanf(" %d",&sz);
     for(int i=0;i<sz;i++){
        int data;
        printf("Data[%d]: ",i+1);
        scanf(" %d",&data);
        root=insert(root ,data);
    }
    printf("\nINORDER\n");
    inorder(root);
    printf("\nPREORDER\n");
    preorder(root);
    printf("\nPOSTORDER\n\n");
    postorder(root);
    printf("\n");
     result();
}

