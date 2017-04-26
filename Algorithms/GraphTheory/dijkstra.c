/* Dijkstra: Shortest Reach 2 challenge posted by pranav9413 on Hackerrank.
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

// Global variable declarations
int vertices, *distances, *v_list, **graph;

/* Recursive function that uses dijkstra's algorithm to update distances from
   the start vertex.
*/
void dijkstra(int size);

int main(){
  // Variable declarations
  int i, j, tests, edges, start, v1, v2, w;

  // Collect input
  scanf("%d", &tests);
  for (i = 0; i < tests; i++) {
    scanf("%d %d", &vertices, &edges);

    // Create adjacency matrix from input edges
    graph = (int **) malloc(vertices*sizeof(int *));
    for (j = 0; j < vertices; j++) {
      graph[j] = (int *) calloc(vertices, sizeof(int *));
    }
    for (j = 0; j < edges; j++) {
      scanf("%d %d %d", &v1, &v2, &w);
      v1--;  // Remove if vertices start at 0
      v2--;

      if (graph[v1][v2] == 0 || graph[v1][v2] > w) {
        graph[v1][v2] = w;
        graph[v2][v1] = w;
      }
    }

    // Get start vertex
    scanf("%d", &start);
    start--;  // Remove if vertices start at 0

    // Initialize distances array and vertex list
    distances = (int *) malloc(vertices*sizeof(int));
    v_list = (int *) malloc(vertices*sizeof(int));
    for (j = 0; j < vertices; j++) {
      distances[j] = -1;
      v_list[j] = j;
    }
    distances[start] = 0;

    // Call to djikstra()
    dijkstra(vertices);

    // Print result
    for (j = 0; j < vertices; j++) {
      if (j != start) {
        printf("%d ", distances[j]);
      }
    }
    printf("\n");

    // Clean up for next test
    for (j = 0; j < vertices; j++) {
      free(graph[j]);
    }
    free(graph);
    free(distances);
    free(v_list);
  }
  return 0;
}

void dijkstra(int size){
  int i, temp, v, weight, min_v, min = INT_MAX;

  // Find vertex in the list with the smallest distance from the start vertex
  for (i = 0; i < size; i++) {
    v = v_list[i];
    if (distances[v] >= 0 && distances[v] < min) {
      min = distances[v];
      min_v = v;
    }
  }

  // Return if no more vertices can be reached
  if (min == INT_MAX) {
    return;
  }

  // Update distances of adjacent vertices
  for (i = 0; i < vertices; i++) {
    if ( (weight = graph[min_v][i]) ) {

      if (distances[i] < 0 || distances[i] > distances[min_v] + weight) {
        distances[i] = distances[min_v] + weight;
      }
    }
  }

  // Remove minimum vertex from list and repeat for the rest of the list
  i = 0;
  while (v_list[i] != min_v) { i++; }
  temp = v_list[size-1];
  v_list[size-1] = v_list[i];
  v_list[i] = temp;
  if (size > 1) {
    dijkstra(size-1);
  }
}
