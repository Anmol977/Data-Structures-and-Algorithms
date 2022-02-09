#include <map>
#include <list>
#include <queue>
#include <iostream>

class Graph
{
    std::map<int, std::list<int>> adj_list;
    int v;

public:
    void add_edge(int src, int dest)
    {
        adj_list[src].push_back(dest);
        adj_list[dest].push_back(src);
    }
    bool is_tree(int src, int v)
    {
        int parent[v];
        bool visited[v];
        std::queue<int> q;
        for (int i = 0; i != v; i++)
        {
            visited[i] = false;
            parent[i] = i;
        }
        q.push(src);
        while (!q.empty())
        {
            int curr_node = q.front();
            q.pop();
            for (auto i : adj_list[curr_node])
            {
                if (visited[i] and parent[curr_node] != i)
                {
                    return false;
                }
                else if (!visited[i])
                {
                    q.push(i);
                    parent[i] = curr_node;
                    visited[i] = true;
                }
            }
        }
        return true;
    }
};

int main()
{
    Graph g1;
    g1.add_edge(0, 1);
    g1.add_edge(1, 2);
    g1.add_edge(2, 3);
    g1.add_edge(2, 4);
    g1.add_edge(3, 5);
    g1.add_edge(5, 4);
    std::cout << std::boolalpha << g1.is_tree(0,5);
}