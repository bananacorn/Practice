/* Breadth First Search: Shortest Reach challenge posted by pranav9413 on
   Hackerrank.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Global variable declarations
int **graph;
int *distances;

/* Recursive function that performs breadth-first and updates distances
   appropriately.
*/
void bfs(int s_vertex, int vertices);

int main(){
  // Variable declarations
  int i, j, queries, vertices, edges, start, v1, v2;

  // Collect input
  scanf("%d", &queries);
  for (i = 0; i < queries; i++) {
    scanf("%d %d", &vertices, &edges);

    // Create adjacency matrix from input edges
    graph = (int **) malloc(vertices*sizeof(int *));
    for (j = 0; j < vertices; j++) {
      graph[j] = (int *) calloc(vertices, sizeof(int *));
    }
    for (j = 0; j < edges; j++) {
      scanf("%d %d", &v1, &v2);
      v1--;  // remove if vertices start at 0
      v2--;

      graph[v1][v2] = 1;
      graph[v2][v1] = 1;
    }

    // Get start vertex
    scanf("%d", &start);
    start--;  // remove if vertices start at 0

    // Initialize distances array
    distances = (int *) malloc(vertices*sizeof(int));
    for (j = 0; j < vertices; j++) {
      distances[j] = -1;
    }
    distances[start] = 0;

    // Call to bfs()
    bfs(start, vertices);

    // Print result
    for (j = 0; j < vertices; j++) {
      if (j != start) {
        printf("%d ", distances[j]);
      }
    }
    printf("\n");

    // Clean up for next query
    for (j = 0; j < vertices; j++) {
      free(graph[j]);
    }
    free(graph);
    free(distances);
  }
  return 0;
}

void bfs(int s_vertex, int vertices){
  // Variable declarations
  int i, *next, index = 0;

  // Record of vertices to traverse through next
  next = (int *) malloc(vertices*sizeof(int));

  // Update distances of adjacent vertices
  for (i = 0; i < vertices; i++) {
    if (graph[s_vertex][i]) {
      if (distances[i] < 0 || distances[i] >= distances[s_vertex] + 6) {
        distances[i] = distances[s_vertex] + 6;
        next[index] = i;
        index++;
      }
    }
  }

  // Recursive call
  for (i = 0; i < index; i++) {
    bfs(next[i], vertices);
  }

  // Clean up
  free(next);
}
