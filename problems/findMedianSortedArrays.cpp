#include <vector>
#include <iostream>

float findMedianSortedArrays(std::vector<int> l, std::vector<int> m)
{
    std::vector<int> a;
    int i = 0, j = 0, k = 0;
    while (i < l.size() && j < m.size())
    {
        if (l[i] < m[j])
        {
            a.push_back(l[i]);
            i++;
        }
        else
        {
            a.push_back(m[j]);
            j++;
        }
    }
    while (i < l.size())
    {
        a.push_back(l[i]);
        i++;
    }
    while (j < m.size())
    {
        a.push_back(m[j]);
        j++;
    }
    if (a.size() % 2 == 0)
    {
        return ((float)(a[a.size()/ 2] + a[a.size()/2 -1]) / 2);
    }
    else
    {
        return a[a.size()/ 2];
    }
}

int main()
{
    std::vector<int> a1 = {2};
    std::vector<int> a2 = {};
    float a3 = findMedianSortedArrays(a1, a2);
    std::cout << a3;
    return 0;
}