#include <string>
#include <iostream>

template <typename T>
class Node
{
public:
     std::string key;
     T val;
     Node<T> *next;

     Node(std::string key, T val)
     {
          this->key = key;
          this->val = val;
          next = nullptr;
     }
     ~Node()
     {
          if (next != nullptr)
               delete next;
     }
};

template <typename T>
class Hashtable
{
     Node<T> **table;
     int currsize;
     int maxsize;

     int hashfunc(std::string s){
          int idx = 0;
          int len = s.length();
          int p = 1;
          for(int i = 0 ; i < len ; i++){
               idx = (idx + (s[idx]*p)%maxsize)%maxsize;
               p = (p*27)%maxsize;
          }
          return idx;
     }

public:
     Hashtable(int n = 9)
     {
          maxsize = n;
          currsize = 0;
          table = new Node<T> *[maxsize];
          for (int i = 0; i != maxsize; i++)
               table[i] = nullptr;
     }

     void insert(std::string s, int val){
          int idx = hashfunc(s);
          Node<T>* n = new Node<T>(s,val);
          n->next = table[idx];
          table[idx] = n;
          currsize++;
     }
     void print(){
          for(int i = 0 ; i < maxsize ; i++){
               std::cout<<"idx "<<i<<" -> ";
               Node<T>* temp = table[i];
               while(temp != nullptr){
                    std::cout<<temp->val<<" -> ";
                    temp = temp->next;
               }
               std::cout<<std::endl;
          }
     }
};