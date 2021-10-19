#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> nextGreaterElement(std::vector<int> nums1, std::vector<int> nums2)
{
    int found;
    std::vector<int> nums3;
    for (auto i = 0; i != nums1.size(); i++)
    {
        found = 0;
        auto pos = std::find(nums2.begin(), nums2.end(), nums1[i]);
        for (auto j = pos + 1; j != nums2.end(); j++)
        {
            if (*j > nums1[i])
            {
                nums3.push_back(*j);
                found = 1;
                break;
            }
        }
        if (found == 0)
            nums3.push_back(-1);
    }
    return nums3;
}

int main()
{
    std::vector<int> nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};
    std::vector<int> nums4 = nextGreaterElement(nums1, nums2);
    for (auto i : nums4)
        std::cout << i << " \n";
    return 0;
}