#include<iostream>
#include<vector>
#include<algorithm>

int removeDuplicates(std::vector<int>& nums) {
    auto it = std::unique(nums.begin(),nums.end());  
    nums.erase(it, nums.end());
    return nums.size();
}

int main(){
    std::vector<int> nums = {1,1,2};
    int res = removeDuplicates(nums);
    std::cout<<res;
}