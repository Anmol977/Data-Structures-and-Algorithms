#include <iostream>
#include <vector>
#include <algorithm>

bool dfs(std::vector<int> graph[], int curr_node, int parent, int *visited, int color)
{
    visited[curr_node] = color;
    bool res;
    for (auto nbr : graph[curr_node])
    {
        if (visited[nbr] == 0)
        {
            res = dfs(graph, nbr, curr_node, visited, 3 - color);
            if (res == false)
                return false;
        }
        else if (nbr != parent && color == visited[curr_node])
            return false;
    }
    return true;
}

bool check_bipartite(std::vector<int> graph[], int no_of_nodes)
{
    int visited[no_of_nodes] = {0};
    int color = 1;
    bool res = dfs(graph, 0, -1, visited, color);
    return res;
}

int main()
{
    int no_of_nodes, no_of_edges;
    std::cin >> no_of_nodes >> no_of_edges;
    int u, v;
    std::vector<int> adj_list[no_of_nodes];
    while (no_of_edges--)
    {
        std::cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    bool ans = check_bipartite(adj_list, no_of_nodes);
    std::cout << std::boolalpha << ans;
}