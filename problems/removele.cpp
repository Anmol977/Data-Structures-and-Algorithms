#include<iostream>
#include<vector>
#include<algorithm>

int removeElement(std::vector<int>& nums, int val) {
    while(std::find(nums.begin(),nums.end(),val) != nums.end()){
        auto it = std::find(nums.begin(),nums.end(),val);
        nums.erase(it);
    }
    return nums.size();
}

int main(){
    std::vector<int> nums = {3,2,2,3};
    int res = removeElement(nums,3);
    std::cout<<res;
}