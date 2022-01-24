#include <list>
#include <string>
#include <iostream>
#include <unordered_map>

class Graph
{
     std::unordered_map<std::string, std::list<std::pair<std::string, int>>> adj_list;

public:
     void add_edge(std::string u, std::string v, bool is_bidir, int wt)
     {
          adj_list[u].push_back(std::make_pair(v, wt));
          if (is_bidir)
          {
               adj_list[v].push_back(std::make_pair(u, wt));
          }
     }
     void print_adj_list()
     {
          for (auto node : adj_list)
          {
               std::cout << "vertex " << node.first << " -> ";
               for (auto u : node.second)
               {
                    std::cout << "( " << u.first << ", " << u.second << " ), ";
               }
               std::cout << std::endl;
          }
     }
};

int main()
{
     Graph g1;
     g1.add_edge("a", "b", true, 20);
     g1.add_edge("a", "c", true, 40);
     g1.add_edge("b", "d", false, 10);
     g1.add_edge("c", "d", true, 2);
     g1.add_edge("a", "d", false, 8);
     g1.print_adj_list();
}