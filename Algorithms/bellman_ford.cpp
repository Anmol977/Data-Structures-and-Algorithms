#include <iostream>
#include <vector>

struct Edge
{
    int src;
    int dest;
    int weight;
};

class Graph
{
    int no_of_vertices;
    std::vector<Edge> adj_list;

public:
    Graph(int n)
    {
        this->no_of_vertices = n;
        adj_list.reserve(n);
    }
    std::vector<Edge> get_adj_list()
    {
        return adj_list;
    }
    void add_edge(int u, int v, int w)
    {
        Edge e = {u, v, w};
        adj_list.push_back(e);
    }
    std::vector<int> bellman_ford(int src)
    {
        std::vector<int> dist(no_of_vertices + 1, INT16_MAX);
        dist[src] = 0;
        for (int i = 0; i < no_of_vertices - 1; i++)
        {
            for (auto edge : adj_list)
            {
                if (dist[edge.src] != INT32_MAX && dist[edge.dest] > dist[edge.src] + edge.weight)
                    dist[edge.dest] = dist[edge.src] + edge.weight;
            }
        }
        for (auto edge : adj_list)
        {
            if (dist[edge.src] != INT32_MAX && dist[edge.dest] > dist[edge.src] + edge.weight)
            {
                std::cout << " negative weight cycles present \n\n";
                exit(0);
            }
        }
        return dist;
    }
};

int main()
{
    Graph g(9);
    g.add_edge(1, 2, 4);
    g.add_edge(1, 3, 2);
    g.add_edge(2, 3, 3);
    g.add_edge(2, 4, 2);
    g.add_edge(2, 5, 3);
    g.add_edge(3, 2, 1);
    g.add_edge(3, 4, 4);
    g.add_edge(3, 5, 5);
    g.add_edge(5, 4, -5);
    /*
    test case for negative weight cycle
    */
    // g.add_edge(0, 1, 1);
    // g.add_edge(1, 2, 1);
    // g.add_edge(2, 3, 3);
    // g.add_edge(3, 4, -3);
    // g.add_edge(4, 0, -3);
    std::vector<int> res = g.bellman_ford(1);
    // for (int i = 1 ; i < 6 ; i++)
    //     std::cout <<res[i] << std::endl;
    for (int i = 1; i < 5; i++)
        std::cout << res[i] << std::endl;
}