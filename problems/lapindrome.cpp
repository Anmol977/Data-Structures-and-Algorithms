#include <map>
#include <string>
#include <vector>
#include <iostream>

int main()
{
    int cnt, len;
    std::cin >> cnt;
    std::string la;
    std::vector<std::string> svec;
    std::map<char, int> map1, map2;
    while (cnt-- && std::cin>>la)
    {
        svec.push_back(la);
    }
    for (auto i : svec)
    {
        map1.clear();
        map2.clear();
        auto mid = i.begin()+i.size()/2;
            if (i.size() % 2 == 0)
            {
                //std::cout<<"even length \n";
                for(auto iter=i.begin();iter!=mid;iter++){
                    auto it=map1.find(*iter);
                    if (it != map1.end()) {
                        it->second++; 
                    }
                    else {
                        map1.insert(std::make_pair(*iter, 1));
                    }
                } 
                for(auto iter=mid;iter!=i.end();iter++){
                    auto it=map2.find(*iter);
                    if (it != map2.end()) {
                        it->second++; 
                    }
                    else {
                        map2.insert(std::make_pair(*iter, 1));
                    }
                }    
            }
            else
            {
                // std::cout<<"odd length \n";
                for(auto iter=i.begin();iter<mid;iter++){
                    auto it=map1.find(*iter);
                    if (it != map1.end()) {
                        it->second++; 
                    }
                    else {
                        map1.insert(std::make_pair(*iter, 1));
                    }
                } 
                for(auto iter=mid+1;iter!=i.end();iter++){
                    auto it=map2.find(*iter);
                    if (it != map2.end()) {
                        it->second++; 
                    }
                    else {
                        map2.insert(std::make_pair(*iter, 1));
                    }
                }    
            }
            if(map1==map2)
                std::cout<<"YES \n";
            else
                std::cout<<"NO \n";
    }

}