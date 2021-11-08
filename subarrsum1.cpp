#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int arr[1000] = {0};
    int cs[1000] = {0};
    int n, currsum = 0, maxsum = INT_MIN, left, right;
    cin >> n;
    cin >> arr[0];
    cs[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
        cs[i] = cs[i - 1] + arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // currsum = 0;
            currsum = cs[j] - cs[i - 1];
            if (currsum > maxsum)
            {
                maxsum = currsum;
                left = i;
                right = j;
            }
        }
    }
    cout << "max sum is : " << maxsum << endl;
    for (int i = left; i <= right; i++)
    {
        cout << arr[i] << ", ";
    }
    return 0;
}