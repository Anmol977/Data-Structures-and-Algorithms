#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[1000];
    int n, reqsum, currsum, j, k;
    cin >> n;
    k = n - 1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> reqsum;
    sort(arr, arr + n, [](int a, int b)
         { return a < b; });
    for (int i = 0; i < n; i++)
    {
        j = i +1;
        k = n - 1;
        while (j < k)
        {
            // cout << "i,j and k " << arr[i] << " " << arr[j] << " " << arr[k] << endl;
            currsum = arr[i] + arr[j] + arr[k];
            // cout << "currsum : " << currsum << endl;
            if (currsum < reqsum)
            {
                j++;
            }
            else if (currsum > reqsum)
            {
                k--;
            }
            else if (currsum == reqsum)
            {
                if (i != j && j != k)
                    cout << arr[i] << ", " << arr[j] << " and " << arr[k] << endl;
                j++;
                k--;
            }
        }
    }
    return 0;
}