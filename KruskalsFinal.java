package daa;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

class DisjointSet{
	ArrayList<Integer> size= new ArrayList<>();
	ArrayList<Integer> parent = new ArrayList<>();
	public DisjointSet(int V) {
		for(int i = 0; i<V; i++) {
			size.add(1);
			parent.add(i);
		}
	}
	
	public int findUltimateParent(int node) {
		if(node == parent.get(node)) {
			return node;
		}
		int ulimateParent = findUltimateParent(parent.get(node));
		parent.set(node, ulimateParent);
		return parent.get(node);
	}
	
	public void unionBySize(int u, int v) {
		int ultU = findUltimateParent(u);
		int ultV = findUltimateParent(v);
		if(ultU == ultV) return;
		if(size.get(ultU) < size.get(ultV)) {
			parent.set(ultU, ultV);
			size.set(ultV, size.get(ultU) + size.get(ultV));
		}else {
			parent.set(ultV, ultU);
			size.set(ultU, size.get(ultU) + size.get(ultV));
		}
	}
}

class Edge implements Comparable<Edge>{
	int src, dest, weight;
	
	public Edge(int src, int dest, int weight) {
		this.src = src;
		this.dest = dest;
		this.weight = weight;
	}
	
	public int compareTo(Edge e) {
		return this.weight - e.weight;
	}
}

public class KruskalsFinal {
	public static void main(String[] args) {
		
		List<Edge> edges = new ArrayList<Edge>();
		
		System.out.println("Enter the number of vertices ");
		Scanner scanner = new Scanner(System.in);
		int V = scanner.nextInt();
		
		DisjointSet dSet = new DisjointSet(V);
		
		System.out.println("Enter the number of edges: ");
		int numberOfEdges = scanner.nextInt();
		for(int i = 0; i<numberOfEdges; i++) {
			System.out.println("Enter the edge as <V1 V2 WEIGHT>");
			int v1 = scanner.nextInt();
			int v2 = scanner.nextInt();
			int weight = scanner.nextInt();
			edges.add(new Edge(v1, v2, weight));
		}
		
		
		Collections.sort(edges);
		int weight = 0;
		List<Edge> mstEdges = new ArrayList<>();
		
		for(Edge edge: edges) {
			if (dSet.findUltimateParent(edge.src) != dSet.findUltimateParent(edge.dest)) {
				weight += edge.weight;
				dSet.unionBySize(edge.src, edge.dest);
				mstEdges.add(edge);
			}
		}
		System.out.println("Edges in the Minimum Spanning Tree:");
        for (Edge edge : mstEdges) {
            System.out.println("Edge: (" + edge.src + ", " + edge.dest + ") with weight: " + edge.weight);
        }
        System.out.println("Total weight of MST = " + weight);
	}
}
