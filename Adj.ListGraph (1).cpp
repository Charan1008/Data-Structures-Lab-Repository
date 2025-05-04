#include <iostream>
#include <list>
#include <vector>
using namespace std;

class GraphList {
private:
    vector<list<int>> adj;
    int numVertices;

public:
    GraphList(int n) {
        numVertices = n;
        adj.resize(n);
    }

    void insertEdge(int u, int v) {
        if (u >= numVertices || v >= numVertices || u < 0 || v < 0) {
            cout << "Invalid vertex number!\n";
            return;
        }
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    void deleteEdge(int u, int v) {
        if (u >= numVertices || v >= numVertices || u < 0 || v < 0) {
            cout << "Invalid vertex number!\n";
            return;
        }
        adj[u].remove(v);
        adj[v].remove(u);
    }

    bool searchEdge(int u, int v) {
        if (u >= numVertices || v >= numVertices || u < 0 || v < 0) {
            return false;
        }
        for (int neighbor : adj[u]) {
            if (neighbor == v)
                return true;
        }
        return false;
    }

    void display() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < numVertices; ++i) {
            cout << i << ": ";
            for (int neighbor : adj[i])
                cout << neighbor << " ";
            cout << "\n";
        }
    }
};

int main() {
    int n, choice, u, v;
    cout << "Enter number of vertices: ";
    cin >> n;
    GraphList g(n);

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
