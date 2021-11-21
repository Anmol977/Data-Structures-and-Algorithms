#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    int j = nums.size() - 1, currsum, ans = nums[0] + nums[1] + nums[2], diff, k;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++)
    {
        j = i + 1;
        k = nums.size() - 1;
        diff = target - INT8_MIN;
        while (j < k)
        {
            currsum = nums[i] + nums[j] + nums[k];
            if (currsum < target)
            {
                j++;
            }
            else if (currsum > target)
            {
                k--;
            }
            else if (currsum == target)
            {
                if (i != j && j != k)
                {
                    return currsum;
                }
                j++;
                k--;
            }
            if (abs(target - currsum)< abs(target - ans))
            {
                ans = currsum;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> ivec = {1, 1, 1, 0};
    int res = threeSumClosest(ivec, -100);
    cout << res;
}