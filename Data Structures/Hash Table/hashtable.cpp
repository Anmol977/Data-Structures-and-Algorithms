#include <iostream>
#include "hashtable.h"

int main()
{
     Hashtable<int> h;
     h.insert("lorem", 120);
     h.insert("ipsum", 20);
     h.insert("dolor", 150);
     h.insert("sit", 25);
     h.insert("amet", 40);
     h.insert("consectetur ",101);
     h.print();
     int* res = h.search("amet");
     if(res==nullptr){
          std::cout<<"not found \n";
     }
     else{
          std::cout<<"the val of amet is: "<<*res;
     }
}