#include <vector>
#include <iostream>
#include <algorithm>

int cutRod(std::vector<int> p, int n, std::vector<int> &r)
{
    for (int j = 1; j <= n; j++)
    {
    int q = INT8_MIN;
        for (int i = 1; i <= j; i++)
        {
            q = std::max(q, p[i] + r[j - i]); 
        }
        r[j]=q;
    }
    return r[n];
}

int main()
{
    int pieces;
    std::cout << "enter no of pieces of the rod(max 8) \n";
    std::cin >> pieces;
    std::vector<int> price = {0, 1, 5, 8, 9, 10, 17, 17, 24, 30};
    std::vector<int> mem;
    mem.reserve(pieces);
    mem[0]=0;
    int maxp = cutRod(price, pieces, mem);
    std::cout << "maximum revenue of cutting rod: " << maxp << '\n';
}