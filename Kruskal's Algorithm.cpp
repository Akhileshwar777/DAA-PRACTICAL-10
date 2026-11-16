
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int parent[100];

int find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    int a = find(x);
    int b = find(y);

    parent[a] = b;
}

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    Edge edges[100];

    cout << "Enter source destination weight:\n";

    for (int i = 0; i < E; i++) {
        cin >> edges[i].src
            >> edges[i].dest
            >> edges[i].weight;
    }

    // Sort edges by weight
    sort(edges, edges + E, compare);

    // Initialize parent array
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int minCost = 0;
    int count = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        if (find(u) != find(v)) {
            cout << u << " - " << v
                 << " : " << edges[i].weight << endl;

            minCost += edges[i].weight;

            unite(u, v);
            count++;
        }
    }

    if (count != V - 1) {
        cout << "Graph is disconnected!";
    }
    else {
        cout << "\nMinimum Cost = " << minCost;
    }

    return 0;
}
