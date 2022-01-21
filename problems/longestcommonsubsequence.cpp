#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int lcs(std::string s1, std::string s2, int i, int j, std::vector<std::vector<int>> dp)
{
     if (i == s1.length() or j == s2.length())
          return 0;
     if (dp[i][j] != -1)
     {
          return dp[i][j];
     }
     if (s1[i] == s2[j])
          return dp[i][j] = 1 + lcs(s1, s2, i + 1, j + 1, dp);
     int subprob1 = lcs(s1, s2, i + 1, j, dp);
     int subprob2 = lcs(s1, s2, i, j + 1, dp);
     return dp[i][j] = std::max(subprob1, subprob2);
}

int main()
{
     std::string string1 = "ABCDGH";
     std::string string2 = "AEDFHR";
     int n1 = string1.length();
     int n2 = string2.length();
     std::vector<std::vector<int>> dp(n1,std::vector<int>(n2,-1));
     int ans = lcs(string1,string2,0,0,dp);
     std::cout<<"lcs is : "<<ans<<std::endl;
}