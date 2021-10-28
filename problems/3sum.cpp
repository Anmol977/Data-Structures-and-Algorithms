#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (unsigned int i=0; i<nums.size(); i++) {
        if ((i>0) && (nums[i]==nums[i-1]))
            continue;
        int l = i+1, r = nums.size()-1;
        while (l<r) {
            int s = nums[i]+nums[l]+nums[r];
            if (s>0) r--;
            else if (s<0) l++;
            else {
                res.push_back(vector<int> {nums[i], nums[l], nums[r]});
                while (l + 1 < r && nums[l]==nums[l+1]) l++;
                while (r - 1 > l && nums[r]==nums[r-1]) r--;;
                l++; r--;
            }
        }
    }
    return res;
}

int main()
{
    std::vector<int> ivec = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> res = threeSum(ivec);
    for (auto i : res)
    {
        for (auto j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
