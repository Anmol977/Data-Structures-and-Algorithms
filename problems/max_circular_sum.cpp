#include <iostream>
#include <algorithm>

using namespace std;

int kadanes(int *arr, int n)
{
    int max_sum = INT_MIN;
    int currsum = 0, res;
    for (int i = 0; i != n; i++)
    {
        currsum += arr[i];
        max_sum = max(currsum, max_sum);
        cout<<max_sum<<endl;
        if (currsum < 0)
        {
            currsum = 0;
        }
    }
    return max_sum;
}

int main()
{
    int t, n, ans[1000],arr_sum=0,min_sum=0;
    cin >> t;
    for (int j = 0; j != t; j++)
    {
        int arr[1000] = {0};
        cin >> n;
        for (int i = 0; i != n; i++)
        {
            cin >> arr[i];
        }
        for(int i = 0 ; i != n ; i++){
            arr_sum += arr[i];
            arr[i] = -arr[i];
        }
        min_sum = kadanes(arr, n);
        ans[j] = arr_sum + min_sum;
    }
    for (int j = 0; j != t; j++)
    {

        cout << ans[j] << endl;
    }
}