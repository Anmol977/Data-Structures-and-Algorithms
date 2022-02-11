#include <set>
#include <list>
#include <string>
#include <iostream>
#include <unordered_map>

class Graph
{
    std::unordered_map<std::string, std::list<std::pair<std::string, int>>> adj_list1;

public:
    void add_edge(std::string src, std::string dest, int weight, bool is_bi = true)
    {
        adj_list1[src].push_back(std::make_pair(dest, weight));
        if (is_bi)
            adj_list1[dest].push_back(std::make_pair(src, weight));
    }
    void print_graph()
    {
        for (auto src : adj_list1)
        {
            std::cout << src.first << " => ";
            for (auto dest_node : src.second)
            {
                std::cout << "( " << dest_node.first << ", " << dest_node.second << " ), ";
            }
            std::cout << std::endl;
        }
    }
    void find_shortest_path(std::string src) //djikstras
    {
        std::unordered_map<std::string, int> dist;

        for (auto i : adj_list1)
            dist[i.first] = INT16_MAX;

        std::set<std::pair<int, std::string>> queue;
        queue.insert(std::make_pair(0, src));
        dist[src] = 0;
        while (!queue.empty())
        {
            std::pair<int, std::string> front = *(queue.begin());
            queue.erase(queue.begin());
            for (auto children : adj_list1[front.second])
            {
                int newdist = front.first + children.second;
                if (newdist < dist[children.first])
                {
                    auto iter = queue.find(std::make_pair(dist[children.first], children.first));
                    if (iter != queue.end())
                        queue.erase(iter);
                    queue.insert(std::make_pair(newdist, children.first));
                    dist[children.first] = newdist;
                }
            }
        }
        for (auto d : dist)
        {
            std::cout << d.first << " at a dist of " << d.second << " from source \n";
        }
    }
};

int main()
{
    Graph gmap;
    gmap.add_edge("delhi", "mumbai", 5);
    gmap.add_edge("delhi", "kerala", 7);
    gmap.add_edge("delhi", "rajasthan", 1);
    gmap.add_edge("mumbai", "JK", 3);
    gmap.add_edge("rajasthan", "gujarat", 4);
    gmap.add_edge("rajasthan", "odisha", 6);
    gmap.print_graph();
    gmap.find_shortest_path("delhi");
}