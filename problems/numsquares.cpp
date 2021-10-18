#include<vector>
#include<algorithm>

class Solution 
{
public:
    int numSquares(int n) 
    {
        if (n <= 3)
        {
            return n;
        }
        
        std::vector<int> sq(n + 1, __INT_MAX__);
        sq[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j*j <= i; j++)
            {
                sq[i] = std::min(sq[i], sq[i - j*j] + 1);
            }
        }
        
        return sq[sq.size() - 1];
    }
};