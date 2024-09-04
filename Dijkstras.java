package daa;

import java.util.Scanner;

public class Dijkstras {
	static int step;
	public static void printing(int[] dist, int u, int[] visited, int vertices) {
	    System.out.print(step + "\t");  // STEP number

	    // Print visited nodes
	    System.out.print("{");
	    for (int i = 0; i < vertices; i++) {
	        if (visited[i] == 1) {
	            System.out.print(i + ",");
	        }
	    }
	    System.out.print("}\t");

	    // Print current vertex 'u'
	    if (u != -1) {
	        System.out.print(u + "\t");
	    } else {
	        System.out.print("-\t");
	    }

	    // Print distance array
	    for (int i = 0; i < vertices; i++) {
	        if (dist[i] == 10000) {
	            System.out.print("∞\t");  // Displaying infinity as ∞
	        } else {
	            System.out.print(dist[i] + "\t");
	        }
	    }
	    System.out.println();
	}
    
    public static int choose(int[] dist, int[] visited, int vertices) {
        int min = 10000;  
        int mini = -1;  

        for (int i = 0; i < vertices; i++) {
            if (visited[i] == 0 && dist[i] < min) {
                min = dist[i];
                mini = i;
            }
        }

        return mini;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of vertices: ");
        int vertices = scanner.nextInt();
        int[][] cost = new int[vertices][vertices];
        int[] visited = new int[vertices]; 
        int countVisited = 0;
        int distance[] = new int[vertices];

        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (i != j) {
                    cost[i][j] = 10000;
                }
            }
        }

        System.out.print("Enter the number of edges: ");
        int edges = scanner.nextInt();

        System.out.println("Enter the edges in the format: <source> <destination> <weight>");
        for (int i = 0; i < edges; i++) {
            int source = scanner.nextInt();
            int destination = scanner.nextInt();
            int weight = scanner.nextInt();

            cost[source][destination] = weight;
        }

        System.out.println("Enter the starting and ending node: ");
        int start = scanner.nextInt();

        for (int i = 0; i < vertices; i++) {
            distance[i] = cost[start][i];
        }

        visited[start] = 1;  
        countVisited++;

        while (countVisited < vertices) {
            int u = choose(distance, visited, vertices);
            if (u == -1) break;  

            visited[u] = 1;  
            countVisited++;

            for (int i = 0; i < vertices; i++) {
                if (visited[i] == 0) {
                    if (distance[u] + cost[u][i] < distance[i]) {
                        distance[i] = distance[u] + cost[u][i];
                    }
                }
            }
            step++;
            printing(distance, u, visited, vertices);
        }

        System.out.println("Shortest distances from starting node:");
        for (int i = 0; i < vertices; i++) {
            System.out.println("Distance to vertex " + i + " is " + distance[i]);
        }

        scanner.close();
    }
}
