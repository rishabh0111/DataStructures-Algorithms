#include <iostream>
#include <map>
#include <list>
using namespace std;

class Graph {
    public:
    map<int, list<int>> adj;
    map<int, bool> visited;

    void addEdge(int i, int j);
    void DFS(int v);
};

void Graph::addEdge(int i, int j) {
    adj[i].push_back(j);
}

void Graph::DFS(int v) {
    // Mark current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

int main() {
    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Depth First Traversal (starting from vertex 2) " << endl;
 
    g.DFS(2);
    cout << endl;
    
    return 0;
}