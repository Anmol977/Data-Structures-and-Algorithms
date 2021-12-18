#include <vector>
#include <iostream>
#include <algorithm>

template <typename t>
class Heap
{
     std::vector<t> heap;
     bool isminheap;

public:
     Heap(int defsize = 10, bool ismin = true)
     {
          heap.reserve(defsize);
          heap.push_back(-1);
          isminheap = ismin;
     }
     void insert(int data)
     {
          heap.push_back(data);
          int pos = heap.size() - 1;
          int parent = pos / 2;
          if (isminheap)
          {
               while (pos > 1 && heap[pos] < heap[parent])
               {
                    std::swap(heap[pos], heap[parent]);
                    pos = parent;
                    parent = pos / 2;
               }
          }
          else
          {
               while (pos > 1 && heap[pos] > heap[parent])
               {
                    std::swap(heap[pos], heap[parent]);
                    pos = parent;
                    parent = pos / 2;
               }
          }
          std::cout<<"inserted "<<data<<std::endl;
     }
};

int main(){
     Heap<int> h1;
     h1.insert(1);
     h1.insert(2);
     h1.insert(3);
     h1.insert(4);
}