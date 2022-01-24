#include <map>
#include <list>
#include <queue>
#include <iostream>

class Graph
{
     std::map<int, std::list<int>> adj_list;

public:
     void add_edge(int u, int v)
     {
          adj_list[u].push_back(v);
          adj_list[v].push_back(u);
     }
     int find_shortest_path(int src, int dest)
     {
          std::map<int, int> distance;
          std::map<int,int> path;
          std::queue<int> q;
          for (auto node : adj_list)
          {
               int curr_node = node.first;
               distance[curr_node] = INT32_MAX;
          }
          q.push(src);
          distance[src] = 0;
          path[src] = src;
          while (!q.empty())
          {
               int curr_node = q.front();
               q.pop();
               for (auto nbr : adj_list[curr_node])
               {
                    if (distance[nbr] == INT32_MAX)
                    {
                         q.push(nbr);
                         distance[nbr] = distance[curr_node] + 1;
                         path[nbr] = curr_node;
                    }
               }
          }
          int temp = dest;
          while(temp!=src){
               std::cout<<temp<<" -> ";
               temp = path[temp];
          }
          std::cout<<src<<std::endl;
          return distance[dest];
     }
};

int main()
{
     int arr[50] = {0};
     arr[2] = 13;
     arr[5] = 2;
     arr[9] = 18;
     arr[18] = 11;
     arr[17] = -13;
     arr[20] = -14;
     arr[24] = -8;
     arr[25] = 10;
     arr[32] = -2;
     arr[25] = -22;
     Graph g;
     for (int u = 0 ; u <= 36 ; u++)
     {
          for (int dice = 1; dice <= 6; dice++)
          {
               int v = u + dice;
               v+= arr[v];
               if (v <= 36){
                    g.add_edge(u, v);
               }
          }
     }
     int ans = g.find_shortest_path(0, 36);
     std::cout << "shortest dist from 0 to 36 is : " << ans << "\n";
}