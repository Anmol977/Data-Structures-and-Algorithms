#include <vector>
#include <iostream>
#include <algorithm>

int cutRod(std::vector<int> p, int n, std::vector<int> &r)
{
    int q;
    if (r[n] >= 0)
    {
        return r[n];
    }
    if (n == 0)
    {
        q = 0;
    }
    else
    {
        q = INT8_MIN;
    }
    for (int i = 1; i <= n; i++)
    {
        q = std::max(q, p[i] + cutRod(p, n - i, r));
    }
    r[n] = q;
    return q;
}

int main()
{
    int pieces;
    std::cout << "enter no of pieces of the rod(max 8) \n";
    std::cin >> pieces;
    std::vector<int> price = {0, 1, 5, 8, 9, 10, 17, 17, 24, 30};
    std::vector<int> mem(pieces, -1);
    int maxp = cutRod(price, pieces, mem);
    std::cout << "maximum revenue of cutting rod: " << maxp << '\n';
}