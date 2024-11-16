#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node {
    int vertex;
    struct Node* next;} Node;
typedef struct Graph {
    int V;
    Node** adjList;} Graph;
Graph* g;
void createGraph(int vertices) {
    g = (Graph*)malloc(sizeof(Graph));
    g->V = vertices;
    g->adjList = (Node**)malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        g->adjList[i] = NULL; }}
void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = g->adjList[u];
    g->adjList[u] = newNode;}
void bfs(int start) {
    bool visited[g->V];
    for (int i = 0; i < g->V; i++) visited[i] = false;
    int queue[g->V], front = 0, rear = -1;
    visited[start] = true;
    queue[++rear] = start;
    printf("BFS starting from vertex %d:\n", start);
    while (front <= rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);
        Node* temp = g->adjList[vertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue[++rear] = adjVertex;  }
            temp = temp->next;} }
    printf("\n");}
void dfsUtil(int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);
    Node* temp = g->adjList[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            dfsUtil(adjVertex, visited);}
        temp = temp->next; }}
void dfs(int start) {
    bool visited[g->V];
    for (int i = 0; i < g->V; i++) visited[i] = false;
    printf("DFS starting from vertex %d:\n", start);
    dfsUtil(start, visited);
    printf("\n");}
int main() {
    createGraph(5);
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    bfs(0);
    dfs(0);
    return 0;
    }
