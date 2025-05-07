#include <iostream>
using namespace std;
#define V 5  
#define INF 99999
int minDistance(int dist[], bool visited[]) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}
void dijkstra(int graph[V][V], int src) {
    int dist[V];      // Output array: shortest distance from src to i
    bool visited[V];  // True if vertex is included in shortest path
    for (int i = 0; i < V; i++)
        dist[i] = INF, visited[i] = false;

    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INF
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print result
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t" << dist[i] << "\n";
}
int main() {
    int graph[V][V] = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}
    };
    dijkstra(graph, 0); // Source vertex is 0
    return 0;
}



/*
i/p
Enter number of vertices: 5
Enter the adjacency matrix:
0 10 0 0 5
0 0 1 0 2
0 0 0 4 0
7 0 6 0 0
0 3 9 2 0

Enter source vertex: 0

*/