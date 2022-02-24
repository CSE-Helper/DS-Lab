#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

struct Vertex {
   char label;
   bool visited;
};

//queue variables

int queue[MAX];
int rear = -1;
int front = 0;
int queueItemCount = 0;

//graph variables

//array of vertices
struct Vertex* lstVertices[MAX];

//adjacency matrix
int adjMatrix[MAX][MAX];

//vertex count
int vertexCount = 0;

//queue functions

void insert(int data) {
   queue[++rear] = data;
   queueItemCount++;
}

int removeData() {
   queueItemCount--;
   return queue[front++];
}

bool isQueueEmpty() {
   return queueItemCount == 0;
}

//graph functions

//add vertex to the vertex list
void addVertex(char label) {
   struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
   vertex->label = label;
   vertex->visited = false;
   lstVertices[vertexCount++] = vertex;
}

//add edge to edge array
void addEdge(int start,int end) {
   adjMatrix[start][end] = 1;
   adjMatrix[end][start] = 1;
}

//display the vertex
void displayVertex(int vertexIndex) {
   printf("%c ",lstVertices[vertexIndex]->label);
}

//get the adjacent unvisited vertex
int getAdjUnvisitedVertex(int vertexIndex) {
   int i;

   for(i = 0; i<vertexCount; i++) {
      if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false)
         return i;
   }

   return -1;
}

void breadthFirstSearch() {
   int i;

   //mark first node as visited
   lstVertices[0]->visited = true;

   //display the vertex
   displayVertex(0);

   //insert vertex index in queue
   insert(0);
   int unvisitedVertex;

   while(!isQueueEmpty()) {
      //get the unvisited vertex of vertex which is at front of the queue
      int tempVertex = removeData();

      //no adjacent vertex found
      while((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1) {
         lstVertices[unvisitedVertex]->visited = true;
         displayVertex(unvisitedVertex);
         insert(unvisitedVertex);
      }

   }

   //queue is empty, search is complete, reset the visited flag
   for(i = 0;i<vertexCount;i++) {
      lstVertices[i]->visited = false;
   }
}

int main() {
   int i, j;

   for(i = 0; i<MAX; i++) // set adjacency {
      for(j = 0; j<MAX; j++) // matrix to 0
         adjMatrix[i][j] = 0;


   addVertex('A');   // 0
   addVertex('B');   // 1
   addVertex('C');   // 2
   addVertex('D');   // 3
   addVertex('E');   // 4

   addEdge(0, 1);    // A - B
   addEdge(0, 2);    // A - C
   addEdge(0, 3);    // A - D
   addEdge(1, 3);    // B - D
   addEdge(2, 4);    // C - E
   addEdge(3, 4);    // D - E

   printf("\nBreadth First Search: ");

   breadthFirstSearch();
   printf("\n");

   return 0;
}

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 10


struct vertex {
   char data;
   int visited;
};

struct vertex *v[max];
int arr[max][max];
int no_v=0;

int queue[max];
int front=0;
int rear=-1;
int no_q=0;

void add_vertex(char ch){
    struct vertex* vtx=(struct vertex*)malloc(sizeof(struct vertex));
    vtx->data=ch;
    vtx->visited=0;
    v[no_v++]=vtx;
}

void add_edge(int start ,int end){
    arr[start][end]=1;
    arr[end][start]=1;
}


void  display(int num){
    printf("%c ",v[num]->data);
}

void insert(int data){
    queue[++rear]=data;
    no_q++;
}

int dequeue(){
    no_q--;
    return queue[++front];
}

int isEmpty(){
    if(no_q==0){
        return 1;
    }
    else{
        return 0;
    }
}

int get_adg_vertex(int num){
    for(int i=0;i<no_v;i++){
        if((arr[num][i]==1) && (v[i]->visited == 0)){
            return i;
        }
    }
    return -1;
}

void bfs(){
    v[0]->visited=1;
    display(0);
    insert(0);
    int pos;
    while(isEmpty !=0){
         int st = dequeue();

        while((pos=get_adg_vertex(st)) != -1){
            v[pos]->visited=1;
            display(pos);
            insert(pos);
        }
    }
}

int main(){

    add_vertex('A');
    add_vertex('B');
    add_vertex('C');
    add_vertex('D');
    add_vertex('E');

    add_edge(0,1);
    add_edge(0,2);
    add_edge(0,3);
    add_edge(1,3);
    add_edge(2,4);
    add_edge(3,4);

    bfs();
}
