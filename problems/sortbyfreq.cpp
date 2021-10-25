#include<iostream>
#include<string>
#include<map>
#include<algorithm>

//  std::string 
std::string frequencySort(std::string s) {
    int freq;
    std::string ans;
    std::map<char,int> map;
    for(auto i: s){
        auto pos = map.find(i);
        if(pos == map.end())
            map.insert(std::make_pair(i,1));
        else{
            pos->second++;
        }
    }
    while(map.size()>0){
         auto pr = std::max_element
    (
        map.begin(),map.end(),
        [] (const std::pair<char,int> & p1, const std::pair<char,int> & p2) {
            return p1.second < p2.second;
        }
    );
    for(int i = 0 ; i!= pr->second;i++){
        ans.push_back(pr->first);
    }
    map.erase(pr);
    }
   
    return ans;
}

int main(){
    std::string s="tree";
    std::string res = frequencySort(s);
    std::cout<<res<<std::endl;
    return 0;
}