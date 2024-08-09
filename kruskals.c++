#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    Edge *edges;
};

struct Subset
{
    int parent;
    int rank;
};

Graph *createGraph(int V, int E)
{
    Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edges = new Edge[E];
    return graph;
}

int find(Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool compareEdges(Edge a, Edge b)
{
    return a.weight < b.weight;
}

void KruskalMST(Graph *graph)
{
    int V = graph->V;
    Edge *result = new Edge[V];
    int e = 0;
    int i = 0;

    sort(graph->edges, graph->edges + graph->E, compareEdges);

    Subset *subsets = new Subset[V];
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E)
    {
        Edge next_edge = graph->edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    cout << "Following are the edges in the constructed MST:\n";
    for (i = 0; i < e; ++i)
        cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;

    delete[] subsets;
    delete[] result;
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph *graph = createGraph(V, E);

    cout << "Enter the edges (src, dest, weight) for each edge:\n";
    for (int i = 0; i < E; i++)
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph->edges[i].src = src;
        graph->edges[i].dest = dest;
        graph->edges[i].weight = weight;
    }

    KruskalMST(graph);

    delete[] graph->edges;
    delete graph;

    return 0;
}