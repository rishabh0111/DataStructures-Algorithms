#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V; // No. of vertices
    vector<list<int>> adj;

    public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int i, int j);
    void BFS(int s);
};

void Graph::addEdge(int i, int j){
    adj[i].push_back(j);
}

void Graph::BFS(int v) {
    // Mark all vertices as not visited
    vector<bool> visited;
    visited.resize(V, false);

    queue<int> q;
    // Mark the current node as visited and enqueue it
    visited[v] = true;
    q.push(v);

    while(!q.empty()) {
        // Dequeue a vertex from queue and print it
        v = q.front();
        cout << v << " ";
        q.pop();

        // Get all adjacent vertices of the dequeued
        // vertex v. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for(auto adjacent:adj[v]) {
            if(!visited[adjacent]) {
                visited[adjacent] = true;
                q.push(adjacent);
            }
        }
    }
    cout << endl;
}

int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Breadth First Traversal (starting from vertex 2)" << endl;
    g.BFS(2);
    
    return 0;
}

/*
Time Complexity: O(V+E)
Auxiliary Space: O(V)
*/