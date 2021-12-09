#include <iostream>
#include <queue>
#include <algorithm>

template <typename t>
class Stack
{
public:
     std::queue<t> q1, q2;

     void push(t val)
     {
          q1.push(val);
     }

     void pop(){
          while(q1.size()!=1){
               t front = q1.front();
               q2.push(front);
               q1.pop();
          }
          q1.pop();
          std::swap(q1,q2);
     }

     t front(){
          while(q1.size()>1){
               t front = q1.front();
               q2.push(front);
               q1.pop();
          }
          t front = q1.front();
          q1.pop();
          q2.push(front);
          std::swap(q1,q2);
          return front;
     }

     int size(){
          return q1.size()+q2.size();
     }
};

int main()
{
     Stack<int> s1;
     s1.push(10);
     s1.push(11);
     s1.push(12);
     s1.push(13);
     s1.push(14);
     s1.pop();
     while(s1.size()>0){
          std::cout<<s1.front()<<" ";
          s1.pop();
     }

}