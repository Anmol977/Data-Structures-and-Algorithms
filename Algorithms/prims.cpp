#include <iostream>
#include <vector>
#include <queue>

class Graph
{
    int no_of_vertices;
    std::vector<std::pair<int, int>> *adj_list;

public:
    Graph(int v)
    {
        this->no_of_vertices = v;
        adj_list = new std::vector<std::pair<int, int>>[no_of_vertices];
    }
    void add_edge(int src, int dest, int weight)
    {
        adj_list[src].push_back(std::make_pair(dest, weight));
    }
    int prims_mst()
    {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
        bool *visited = new bool[no_of_vertices]{0};
        int cost = 0;
        q.push({0, 0});
        while (!q.empty())
        {
            auto best = q.top();
            q.pop();
            if (visited[best.first])
            {
                continue;
            }
            else
            {
                cost += best.second;
                visited[best.first] = 1;
                for (auto edge : adj_list[best.first])
                {
                    if (visited[edge.first] == 0)
                        q.push(edge);
                }
            }
        }
        delete[] visited;
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
    std::cout << "cost of mst : " << g.prims_mst();
}