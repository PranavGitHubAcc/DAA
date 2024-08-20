package daa;

import java.util.Scanner;

public class Prims {

    public static int choose(int[] key, boolean[] mstSet, int vertices) {
        int min = Integer.MAX_VALUE;
        int minIndex = -1;

        for (int i = 0; i < vertices; i++) {
            if (!mstSet[i] && key[i] < min) {
                min = key[i];
                minIndex = i;
            }
        }

        return minIndex;
    }

    public static void primMST(int[][] graph, int vertices) {
        int[] parent = new int[vertices]; // Array to store constructed MST
        int[] key = new int[vertices]; // Key values used to pick minimum weight edge in cut
        boolean[] mstSet = new boolean[vertices]; // To represent set of vertices included in MST

        // Initialize all keys as INFINITE
        for (int i = 0; i < vertices; i++) {
            key[i] = Integer.MAX_VALUE;
            mstSet[i] = false;
        }

        // Include first vertex in MST by setting its key value to 0
        key[0] = 0;
        parent[0] = -1; // First node is always the root of MST

        for (int count = 0; count < vertices - 1; count++) {
            // Pick the minimum key vertex from the set of vertices not yet included in MST
            int u = choose(key, mstSet, vertices);

            // Add the picked vertex to the MST Set
            mstSet[u] = true;

            // Update key and parent index of the adjacent vertices of the picked vertex
            for (int v = 0; v < vertices; v++) {
                // graph[u][v] is non-zero only for adjacent vertices of u
                // mstSet[v] is false for vertices not yet included in MST
                // Update the key only if graph[u][v] is smaller than key[v]
                if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

        // Print the constructed MST
        System.out.println("Edge \tWeight");
        for (int i = 1; i < vertices; i++) {
            System.out.println(parent[i] + " - " + i + "\t" + graph[i][parent[i]]);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of vertices: ");
        int vertices = scanner.nextInt();
        int[][] graph = new int[vertices][vertices];

        System.out.println("Enter the adjacency matrix of the graph:");
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                graph[i][j] = scanner.nextInt();
            }
        }

        primMST(graph, vertices);

        scanner.close();
    }
}
