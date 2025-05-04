#include <iostream>
using namespace std;

const int MAX_VERTICES = 100;

class GraphMatrix {
private:
    int adj[MAX_VERTICES][MAX_VERTICES];
    int numVertices;

public:
    GraphMatrix(int n) {
        if (n > MAX_VERTICES) n = MAX_VERTICES;
        numVertices = n;
        for (int i = 0; i < numVertices; ++i)
            for (int j = 0; j < numVertices; ++j)
                adj[i][j] = 0;
    }

    void insertEdge(int u, int v) {
        if (u >= numVertices || v >= numVertices || u < 0 || v < 0) {
            cout << "Invalid vertex number!\n";
            return;
        }
        adj[u][v] = 1;
        adj[v][u] = 1; // For undirected graph
    }

    void deleteEdge(int u, int v) {
        if (u >= numVertices || v >= numVertices || u < 0 || v < 0) {
            cout << "Invalid vertex number!\n";
            return;
        }
        adj[u][v] = 0;
        adj[v][u] = 0;
    }

    bool searchEdge(int u, int v) {
        if (u >= numVertices || v >= numVertices || u < 0 || v < 0) {
            return false;
        }
        return adj[u][v] == 1;
    }

    void display() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int n, choice, u, v;
    cout << "Enter number of vertices: ";
    cin >> n;
    GraphMatrix g(n);

    do {
        cout << "\n1. Insert Edge\n2. Delete Edge\n3. Search Edge\n4. Display\n5. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter two vertices to connect: ";
                cin >> u >> v;
                g.insertEdge(u, v);
                break;
            case 2:
                cout << "Enter two vertices to disconnect: ";
                cin >> u >> v;
                g.deleteEdge(u, v);
                break;
            case 3:
                cout << "Enter two vertices to search: ";
                cin >> u >> v;
                cout << (g.searchEdge(u, v) ? "Edge exists.\n" : "Edge does not exist.\n");
                break;
            case 4:
                g.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
