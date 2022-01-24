#include <map>
#include <list>
#include <queue>
#include <iostream>

template <typename T>
class Graph
{
     std::map<T, std::list<T>> adj_list;

public:
     void add_edge(T u, T v)
     {
          adj_list[u].push_back(v);
          adj_list[v].push_back(u);
     }
     void bfs(T src)
     {
          std::map<T, bool> visited;
          std::queue<T> q;
          q.push(src);
          visited[src] = true;
          while (!q.empty())
          {
               T curr_node = q.front();
               std::cout<<curr_node<<" ";
               q.pop();
               for (auto nbr : adj_list[curr_node])
               {
                    if (!visited[nbr])
                    {
                         q.push(nbr);
                         visited[nbr] = true;
                    }
               }
          }
     }
};

int main(){
     Graph<int> g1;
     g1.add_edge(0, 1);
     g1.add_edge(1, 2);
     g1.add_edge(2, 3);
     g1.add_edge(2, 4);
     g1.add_edge(3, 5);
     g1.bfs(2);
}