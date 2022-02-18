// Floyd-Warshall Algorithm in C

#include <stdio.h>

// defining the number of vertices
#define nV 4

#define INF 999
int n=0;
void printMatrix(int matrix[][n]);

// Implementing floyd warshall algorithm
void floydWarshall(int graph[][n]) {
  int matrix[n][n], i, j, k;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      matrix[i][j] = graph[i][j];

  // Adding vertices individually
  for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printf ("The following matrix shows the shortest distances"
            " between every pair of vertices \n");
  printMatrix(matrix);
}

void printMatrix(int matrix[][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == INF)
        printf("%4s", "INF");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int i,j,u;
    printf("\t\tFloyd's Algorithm\n\n");
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    int G[n][n];
    printf("NOTE: Use (-1) for Infinity\n");
    printf("\nEnter the adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            int t;
            scanf(" %d",&t);
            if(t!=-1){
                G[i][j]=t;
            }
            else
                G[i][j]=INF;
        }
    }
    printf("\n");
    floydWarshall(G);
}

