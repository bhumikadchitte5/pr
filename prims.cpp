#include <iostream>
using namespace std;

const int INF = 999999; // A large value instead of INT_MAX

int minKey(int key[], bool mstSet[], int V) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void primMST(int graph[100][100], int V) {
    int key[100], parent[100];
    bool mstSet[100];

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
}

int main() {
    int V;
    int graph[100][100];

    cout << "Enter number of vertices (max 100): ";
    cin >> V;

    cout << "Enter the adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    primMST(graph, V);
    return 0;
}


//ip
/*
Enter number of vertices: 5
Enter the adjacency matrix:
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
*/