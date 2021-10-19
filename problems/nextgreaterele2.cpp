#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> nextGreaterElements(std::vector<int> nums)
{
    int i = 0, j = 0,cnt;
    std::vector<int> newnums(nums.begin(), nums.end()), ans(nums.size(), -1);
    for (auto i : nums)
    {
        newnums.push_back(i);
    }
    while (j < nums.size() && i < newnums.size())
    {
        i = j + 1;
        cnt = 0;
        while (cnt < nums.size() )
        {
            // std::cout<<"nums :"<<nums[j]<<" j: "<<j<<" \n";
            // std::cout<<"newnums :"<<newnums[i]<<" i: "<<i<<" \n";
            if (newnums[i] > nums[j])
            {
                ans.at(j) = newnums[i];
                // std::cout<<"ans "<<ans.at(j)<<" \n";
                break;
            }
            i++;
            cnt++;
        }
        j++;
    }
    return ans;
}

int main()
{
    std::vector<int> nums1 = {1,2,3,4,3};
    std::vector<int> nums4 = nextGreaterElements(nums1);
    for (auto i : nums4)
        std::cout << i << " \n";
    return 0;
}