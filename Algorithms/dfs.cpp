#include <map>
#include <list>
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
     void helper_func(T src,std::map<T,bool>visited){
          std::cout<<" "<<src;
          visited[src] = true;
          for(auto nbr : adj_list[src]){
               if(visited[nbr] !=true){
                    helper_func(nbr,visited);
               }
          }
     }
     void dfs(T src)
     {
          std::map<T, bool> visited;
          for(auto u : adj_list){
               T curr_node = u.first;
               visited[curr_node] = false;
          }
          helper_func(src,visited);
     }
};

int main(){
     Graph<int> g1;
     g1.add_edge(0, 1);
     g1.add_edge(1, 2);
     g1.add_edge(2, 3);
     g1.add_edge(2, 4);
     g1.add_edge(3, 5);
     g1.dfs(0);
}