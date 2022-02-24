#include<stdio.h>
#include<conio.h>
int a[20][20],reach[20],n;
char arr[]={'A','B','C','D','E','F','G','H','I','J','K','L'};
void dfs(int v) {
	int i;
	reach[v]=1;
	for (i=1;i<=n;i++)
	  if(a[v][i] && !reach[i]) {
		printf("\n %c->%c",arr[v-1],arr[i-1]);
		dfs(i);
	}
}
void main() {
	int i,j,count=0;
    printf("\t\tDepth First Search\n\n");
	printf("\n Enter number of vertices:");
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		reach[i]=0;
		for (j=1;j<=n;j++)
		   a[i][j]=0;
	}
	printf("\n Enter the adjacency matrix:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	   scanf("%d",&a[i][j]);
	dfs(1);
	printf("\n");
	for (i=1;i<=n;i++) {
		if(reach[i])
		   count++;
	}
	if(count==n)
	  printf("\n Graph is connected"); else
	  printf("\n Graph is not connected");
	getch();
}

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include<stdio.h>
 
void DFS(int);
int G[10][10],visited[10],n;    //n is no of vertices and graph is sorted in array G[10][10]
void main()
{
    int i,j;
    printf("Enter number of vertices:");
  
scanf("%d",&n);
    //read the adjecency matrix
printf("\nEnter adjecency matrix of the graph:");
  
for(i=0;i<n;i++)
       for(j=0;j<n;j++)
scanf("%d",&G[i][j]);
    //visited is initialized to zero
   for(i=0;i<n;i++)
        visited[i]=0;
    DFS(0);
}
void DFS(int i)
{
    int j;
printf("\n%d",i);
    visited[i]=1;
for(j=0;j<n;j++)
       if(!visited[j]&&G[i][j]==1)
            DFS(j);
}
