#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph {
    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int i, int j, bool direction);
    void print();
};

void Graph::addEdge(int i, int j, bool direction) {
    adj[i].push_back(j);
    if(!direction)
        adj[j].push_back(i);
}

void Graph::print() {
    for(auto i:adj){
        cout << i.first << "-> ";
        for(auto j:i.second)
            cout << j << ", ";
        cout << endl;
    }
}

int main() {
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(0,2,0);
    g.addEdge(0,3,0);
    g.addEdge(1,2,0);

    g.print();
    
    return 0;
}