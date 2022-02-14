#include <iostream>
#include <vector>

class Graph
{
    int no_of_vertices;
    std::vector<std::pair<int, int>> adj_list;

public:
    Graph(int n)
    {
        no_of_vertices = n;
        adj_list.reserve(n);
    }
    void insert_edge(int src, int dest)
    {
        adj_list.push_back(std::make_pair(src, dest));
    }
    bool detect_cycle()
    {
        int *parent_arr = new int[no_of_vertices];
        for (int i = 0; i < no_of_vertices; i++)
            parent_arr[i] = -1;
        for (auto vertex : adj_list)
        {
            int p1 = find_set_parent(vertex.first, parent_arr);
            int p2 = find_set_parent(vertex.second, parent_arr);
            if (p1 != p2)
            {
                create_union(p1, p2, parent_arr);
            }
            else
            {
                return true;
            }
        }
        delete[] parent_arr;
        return false;
    }
    int find_set_parent(int member, int *parent_array)
    {
        if (parent_array[member] == -1)
        {
            return member;
        }
        else
        {
            return find_set_parent(parent_array[member], parent_array);
        }
    }
    void create_union(int mem1, int mem2, int *parent_array)
    {
        int parent1 = find_set_parent(mem1, parent_array);
        int parent2 = find_set_parent(mem2, parent_array);
        if (parent1 != parent2)
        {
            parent_array[parent1] = parent2;
        }
    }
};

int main()
{
    Graph g1(4);
    g1.insert_edge(1, 2);
    g1.insert_edge(2, 3);
    g1.insert_edge(3, 4);
    g1.insert_edge(4, 1);
    std::cout << std::boolalpha << g1.detect_cycle();
}