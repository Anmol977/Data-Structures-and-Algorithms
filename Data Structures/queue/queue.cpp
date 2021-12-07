#include <iostream>

class Queue
{
public:
     int *arr;
     int front, rear, currsize, maxsize;

     Queue(int n)
     {
          arr = new int[n];
          currsize = 0;
          maxsize = n;
          front = 0;
          rear = maxsize - 1;
     }

     inline bool full()
     {
          return currsize == maxsize;
     }

     inline bool empty()
     {
          return currsize == 0;
     }

     void push(int val)
     {
          if (!full())
          {
               rear = (rear + 1) % maxsize;
               arr[rear] = val;
               currsize++;
          }
     }

     void pop()
     {
          if (!empty())
          {
               front = (front + 1) % maxsize;
               currsize--;
          }
     }

     int get_front()
     {
          return arr[front];
     }

     ~Queue()
     {
          if (arr != nullptr)
          {
               delete[] arr;
               arr = nullptr;
          }
     }
};

int main()
{
     int n, val;
     std::cin >> n;
     Queue q(n);
     for (int i = 0; i < n; i++)
     {
          std::cin >> val;
          q.push(val);
     }
     q.pop();
     q.push(101);
     while (!q.empty())
     {
          std::cout << q.get_front() << " ";
          q.pop();
     }
}