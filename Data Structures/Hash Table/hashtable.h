#include <string>
#include <iostream>

bool isprime(int n)
{
     if (n <= 3)
          return true;
     int i = 2;
     while (i * i <= n)
     {
          if (n % i == 0)
               return false;
          i++;
     }
     return true;
}

int findnextprime(int n)
{
     bool res = false;
     while (n++)
     {
          res = isprime(n);
          if (res)
               return n;
     }
     return n;
}

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

     int hashfunc(std::string s)
     {
          int idx = 0;
          int len = s.length();
          int p = 1;
          for (int i = 0; i < len; i++)
          {
               idx = idx + (s[i] * p) % maxsize;
               idx %= maxsize;
               p = (p * 27) % maxsize;
          }
          return idx;
     }

public:
     Hashtable(int n = 7)
     {
          maxsize = n;
          currsize = 0;
          table = new Node<T> *[maxsize];
          for (int i = 0; i != maxsize; i++)
               table[i] = nullptr;
     }

     void insert(std::string s, int val)
     {
          int idx = hashfunc(s);
          Node<T> *n = new Node<T>(s, val);
          n->next = table[idx];
          table[idx] = n;
          currsize++;
          float lf = currsize / (float)maxsize;
          if (lf > 0.7)
          {
               rehash();
          }
     }
     void print()
     {
          for (int i = 0; i < maxsize; i++)
          {
               std::cout << "idx " << i << " -> ";
               Node<T> *temp = table[i];
               while (temp != nullptr)
               {
                    std::cout << temp->val << " -> ";
                    temp = temp->next;
               }
               std::cout << std::endl;
          }
     }
     void rehash()
     {
          std::cout<<"***Rehashing** \n";
          Node<T> **oldtable = table;
          int oldmaxsize = maxsize;
          maxsize = findnextprime(maxsize * 2);
          // maxsize = maxsize * 2;
          currsize = 0;
          table = new Node<T> *[maxsize];
          for (int i = 0; i < maxsize; i++)
               table[i] = nullptr;
          Node<T> *temp;
          for (int i = 0; i < oldmaxsize; i++)
          {
               temp = oldtable[i];
               while (temp != nullptr)
               {
                    insert(temp->key, temp->val);
                    temp = temp->next;
               }
               if (oldtable[i] != nullptr)
                    delete oldtable[i];
          }
          delete[] oldtable;
     }
     T* search(std::string s)
     {
          int idx = hashfunc(s);
          Node<T> *temp = table[idx];
          while (temp != nullptr)
          {
               if (temp->key == s)
                    return &temp->val;
               temp = temp->next;
          }
          return nullptr;
     }
};