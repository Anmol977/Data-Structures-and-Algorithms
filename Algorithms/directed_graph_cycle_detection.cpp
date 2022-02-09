#include <iostream>
#include <map>
#include <list>

class Graph
{
    std::map<int, std::list<int>> adj_list;
    int v;

public:
    Graph(int v)
    {
        this->v = v;
    }
    void add_edge(int src, int dest)
    {
        adj_list[src].push_back(dest);
    }
    void print_adj_list()
    {
        for (auto node : adj_list)
        {
            std::cout << "vertex " << node.first << " -> ";
            for (auto u : node.second)
            {
                std::cout << u << ", ";
            }
            std::cout << std::endl;
        }
    }
    bool cycle_helper(int node, bool *visited, bool *stack)
    {
        visited[node] = true;
        stack[node] = true;
        for (auto curr_node : adj_list[node])
        {
            if (stack[curr_node])
                return true;
            else if (!visited[curr_node])
            {
                bool detected = cycle_helper(curr_node, visited, stack);
                if (detected)
                    return true;
            }
        }
        stack[node] = false;
        return false;
    }
    bool detect_cycle(int src)
    {
        bool visited[v], stack[v];
        for (int i = 0; i != v; i++)
        {
            stack[i] = false;
            visited[i] = false;
        }
        return cycle_helper(0, visited, stack);
    }
};

int main()
{
    Graph g1(7);
    g1.add_edge(0, 1);
    g1.add_edge(1, 2);
    g1.add_edge(1, 5);
    g1.add_edge(2, 3);
    g1.add_edge(3, 4);
    g1.add_edge(4, 5);
    g1.add_edge(5, 6);
    g1.print_adj_list();
    std::cout << std::boolalpha << g1.detect_cycle(0);
}