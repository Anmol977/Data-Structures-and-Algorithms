#include <iostream>
#include<climits>
#include <algorithm>

int main()
{
    int arr[10] = {-43, -21, 102, 1, -52, 21, 11, -9, 80, -10};
    int cs=0,ms= INT_MIN;
    for (int i = 0; i < 10; i++)
    {
        cs+=arr[i];
        if(cs<0)
            cs = 0;
        std::cout<<cs<<" "<<ms<<std::endl;
        ms = std::max(ms,cs);
    }
    std::cout<<"max subarray sum is: "<<ms<<std::endl;
    return 0;
}