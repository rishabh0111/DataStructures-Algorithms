#include <iostream>
using namespace std;

class Graph {
    private:
    bool** adj;
    int vertices; // number of vertices

    public:
    Graph(int vertices) {
        this->vertices = vertices;
        adj = new bool*[vertices];
        for (int i = 0; i < vertices; i++) {
            adj[i] = new bool[vertices];
            for (int j = 0; j < vertices; j++)
                adj[i][j] = false;
        }
    }

    void addEdge(int i, int j);
    void removeEdge(int i, int j);
    void print();

    ~Graph() {
        for(int i = 0; i < vertices; i++)
            delete[] adj[i];
        delete[] adj;
    }
};

void Graph::addEdge(int i, int j) {
    adj[i][j] = true;
    adj[j][i] = true;
}

void Graph::removeEdge(int i, int j) {
    adj[i][j] = false;
    adj[i][j] = false;
}

void Graph::print() {
    for (int i = 0; i < vertices; i++){
        cout << i << " : ";
        for (int j = 0; j < vertices; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}

int main() {
    Graph g(4);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    
    g.print();

    g.removeEdge(0,2);
    g.removeEdge(2,3);

    cout << "After removal of edges:" << endl;
    g.print();
    return 0;
}