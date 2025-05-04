#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& e) const {
        return weight < e.weight;
    }
};

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj; // vertex -> [(neighbour, weight)]
    vector<Edge> edges; // for Kruskal

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        edges.push_back({u, v, w});
    }

    void primMST() {
        vector<bool> selected(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int totalCost = 0;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, u] = pq.top(); pq.pop();
            if (selected[u]) continue;

            selected[u] = true;
            totalCost += cost;

            for (auto [v, w] : adj[u]) {
                if (!selected[v]) {
                    pq.push({w, v});
                }
            }
        }

        cout << "Prim's MST total cost: " << totalCost << endl;
    }

    int find(int u, vector<int>& parent) {
        if (parent[u] != u) parent[u] = find(parent[u], parent);
        return parent[u];
    }

    void kruskalMST() {
        sort(edges.begin(), edges.end());
        vector<int> parent(V);
        for (int i = 0; i < V; ++i) parent[i] = i;

        int totalCost = 0;
        cout << "Kruskal's MST Edges:\n";
        for (auto [u, v, w] : edges) {
            int pu = find(u, parent);
            int pv = find(v, parent);
            if (pu != pv) {
                parent[pu] = pv;
                totalCost += w;
                cout << u << " - " << v << " : " << w << endl;
            }
        }
        cout << "Total cost: " << totalCost << endl;
    }

    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            for (auto [v, w] : adj[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Dijkstra's shortest paths from vertex " << src << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "To " << i << " : " << dist[i] << endl;
        }
    }
};

int main() {
    int V, choice;
    cout << "Enter number of vertices: ";
    cin >> V;
    Graph g(V);

    do {
        cout << "\n1. Add Edge\n2. Prim's MST\n3. Kruskal's MST\n4. Dijkstra's Algorithm\n5. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int u, v, w;
                cout << "Enter edge (u v weight): ";
                cin >> u >> v >> w;
                g.addEdge(u, v, w);
                break;
            }
            case 2:
                g.primMST();
                break;
            case 3:
                g.kruskalMST();
                break;
            case 4: {
                int src;
                cout << "Enter source vertex: ";
                cin >> src;
                g.dijkstra(src);
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
