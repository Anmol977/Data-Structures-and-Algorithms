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
          std::cout << "inserted " << data << std::endl;
     }
     t top()
     {
          return heap[1];
     }
     void pop()
     {
          int last = heap.size() - 1;
          std::swap(heap[1], heap[last]);
          heap.pop_back();
          heapify(1);
     }
     void heapify(int idx)
     {
          int left = 2 * idx, right = 2 * idx+ 1;
          int last = heap.size() - 1;
          if (isminheap)
          {
               if (heap[idx] > heap[left] and left <= last)
               {
                    std::swap(heap[idx], heap[left]);
               }
               if (heap[idx] > heap[right] and right <= last)
               {
                    std::swap(heap[idx], heap[right]);
               }
            
          } else {
               if (heap[idx] < heap[left] and left <= last)
               {
                    std::swap(heap[idx], heap[left]);
               }
               if (heap[idx] < heap[right] and right <= last)
               {
                    std::swap(heap[idx], heap[right]);
               }
          }
     }
     bool empty(){
          return heap.size() == 1;
     }
};

int main()
{
     Heap<int> h1;
     h1.insert(10);
     h1.insert(20);
     h1.insert(15);
     h1.insert(14);
     h1.insert(11);
     h1.insert(90);
     while(!h1.empty()){
          std::cout<<h1.top()<<std::endl;
          h1.pop();
     }
}