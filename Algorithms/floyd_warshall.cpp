#include <iostream>
#include <vector>

std::vector<std::vector<int>> floyd_warshall(std::vector<std::vector<int>> graph, int no_of_edges)
{
    std::vector<std::vector<int>> dist(graph);
    for (int k = 0; k < no_of_edges; k++)
    {
        for (int i = 0; i < no_of_edges; i++)
        {
            for (int j = 0; j < no_of_edges; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    return dist;
}

int main()
{
    std::vector<std::vector<int>> graph = {
        {0, 100000, -2, 100000},
        {4, 0, 3, 100000},
        {100000, 100000, 0, 2},
        {100000, -1, 100000, 0}
    };
    auto dist = floyd_warshall(graph, 4);

    for(auto i : dist){
        for(auto j : i){
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
}