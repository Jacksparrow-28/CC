#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v)
    {
        adj[u].push_back(u);
        adj[v].push_back(v);
    }

    void DFSUtil(int v, vector<bool> &vistied)
    {
        vistied[v] = tr
    }
}