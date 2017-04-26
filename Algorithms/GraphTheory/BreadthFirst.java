/* Breadth First Search: Shortest Reach challenge posted by pranav9413 on
   Hackerrank.
*/

import java.io.*;
import java.util.*;

public class BreadthFirst {
  public static void main(String[] args) {
    // Variable declarations
    int i, j, queries, vertices, edges, start, v1, v2;

    // Collect input
    Scanner scanner = new Scanner(System.in);
    queries = scanner.nextInt();
    for (i = 0; i < queries; i++) {
      vertices = scanner.nextInt();
      edges = scanner.nextInt();

      // Create adjacency list from input edges
      List<List<Integer>> graph = new ArrayList<List<Integer>>();
      for (j = 0; j < vertices; j++) {
        graph.add(new ArrayList<Integer>());
      }
      for (j = 0; j < edges; j++) {
        v1 = scanner.nextInt();
        v2 = scanner.nextInt();
        v1--;  // Remove if vertices start at 0
        v2--;

        if (!graph.get(v1).contains(Integer.valueOf(v2))) {
          graph.get(v1).add(Integer.valueOf(v2));
        }
        if (!graph.get(v2).contains(Integer.valueOf(v1))) {
          graph.get(v2).add(Integer.valueOf(v1));
        }
      }

      // Get start vertex
      start = scanner.nextInt();
      start--;  // Remove if vertices start at 0

      // Create distances array
      int distances[] = new int[vertices];
      for (j = 0; j < vertices; j++) {
        distances[j] = -1;
      }
      distances[start] = 0;

      // Call to bfs()
      bfs(start, distances, graph);

      // Print result
      for (j = 0; j < vertices; j++) {
        if (j != start) {
          System.out.print(distances[j] + " ");
        }
      }
      System.out.println();
    }
  }

  public static void bfs(int s_vertex, int distances[],
                         List<List<Integer>> graph){
    // Variable declarations
    int i, v, index = 0;

    // Next vertices for traversal
    List<Integer> next = new ArrayList<Integer>();

    // Update distances of adjacent vertices
    for (i = 0; i < graph.get(s_vertex).size(); i++) {
      v = graph.get(s_vertex).get(i).intValue();
      if (distances[v] < 0 || distances[v] > distances[s_vertex] + 6) {
        distances[v] = distances[s_vertex] + 6;
        next.add(Integer.valueOf(v));
      }
    }

    // Recursive call
    Iterator<Integer> iter = next.iterator();
    while (iter.hasNext()) {
      bfs(iter.next().intValue(), distances, graph);
    }
  }
}
