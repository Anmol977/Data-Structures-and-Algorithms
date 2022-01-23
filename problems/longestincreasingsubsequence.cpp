#include <iostream>
#include <algorithm>
#include <vector>

void find_lis(std::vector<int> ivec, std::vector<int> &dp)
{
     int ilen = ivec.size();
     for (int i = 0; i != ilen; i++)
     {
          dp[i]= 1;
          for (int j = 0; j < i; j++)
          {
               if (ivec[j] < ivec[i])
               {
                    dp[i] = std::max(dp[i], dp[j] + 1);
               }
          }
     }
}

int main()
{
     std::vector<int> ivec = {1, 5, 2, 3, 4, 9, 6, 10};
     std::vector<int> dp(ivec.size(), 0);
     find_lis(ivec,dp);
     int ans = 0;
     for(auto i : dp)
          ans = std::max(ans,i);
     std::cout<<ans;
}