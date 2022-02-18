#include <iostream>
#include <algorithm>
#include <vector>

class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    int find(int i)
    {
        if (parent[i] == -1)
            return i;
        else
        {
            return parent[i] = find(parent[i]);
        }
    }
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

struct Edge
{
    int weight;
    int src;
    int dest;
};

class Graph
{
    std::vector<Edge> adj_list;
    int no_of_vertices;

public:
    Graph(int n)
    {
        no_of_vertices = n;
        adj_list.reserve(n);
    }
    void add_edge(int src, int dest, int weight)
    {
        Edge e = {weight, src, dest};
        adj_list.push_back(e);
    }
    int kruskals_mst()
    {
        std::sort(adj_list.begin(), adj_list.end(), [](Edge a, Edge b)
                  { return a.weight < b.weight; });
        int cost = 0;
        DSU s(no_of_vertices);
        for (auto edge : adj_list)
        {
            if (s.find(edge.src) != s.find(edge.dest))
            {
                s.unite(edge.src, edge.dest);
                cost += edge.weight;
            }
        }
        return cost;
    }
};

int main()
{
    Graph g(4);
    g.add_edge(0, 1, 1);
    g.add_edge(1, 3, 3);
    g.add_edge(3, 2, 4);
    g.add_edge(2, 0, 2);
    g.add_edge(0, 3, 2);
    g.add_edge(1, 2, 2);
    std::cout <<"cost of mst : "<< g.kruskals_mst();
}