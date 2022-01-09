#include <iostream>
#include <algorithm>

using namespace std;

int getminstepstopdown(int n, int *dp)
{
     if (n == 1)
          return 0;
     if (dp[n] != 0)
          return dp[n];
     int divbyone, divbytwo, divbythree;
     divbyone = divbytwo = divbythree = INT8_MAX;
     if (n % 3 == 0)
     {
          divbythree = getminstepstopdown(n / 3, dp) + 1;
     }
     if (n % 2 == 0)
     {
          divbytwo = getminstepstopdown(n / 2, dp) + 1;
     }
     divbyone = getminstepstopdown(n - 1, dp) + 1;
     int ans = min(min(divbyone, divbytwo), divbythree);
     return ans;
}

int getminstepsbottomup(int n, int *dp)
{
     int divbyone, divbytwo, divbythree;
     for (int i = 2; i <= n; i++)
     {
          divbyone = divbytwo = divbythree = INT8_MAX;
          if (i % 3 == 0)
               divbythree = dp[i / 3] + 1;
          if (i % 2 == 0)
               divbytwo = dp[i / 2] + 1;
          divbyone = dp[i - 1] + 1;
          dp[i] = min(min(divbyone, divbytwo), divbythree);
     }
     return dp[n];
}

int main()
{
     int choice;
     cout << "1 for top-down, 2 for bottom up \n";
     cin >> choice;
     switch (choice)
     {
     case 1:
     {
          int dp[1000] = {0};
          int res = getminstepstopdown(100, dp);
          cout << "min steps req : " << res << endl;
          break;
     }
     case 2:
     {
          int dp[1000] = {0};
          int res = getminstepsbottomup(100, dp);
          cout << res << endl;
          break;
     }
     }
}