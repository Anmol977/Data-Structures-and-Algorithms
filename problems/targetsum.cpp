#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[1000];
    int n, tgt,i=0,currsum=0,reqsum;
    cin >> n;
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin>>reqsum;
    std::sort(arr, arr + n, [](int a, int b)
              { return a < b; });
    while(i<j){
        currsum = arr[i]+arr[j];
        if(currsum > reqsum){
            j--;
        } else if (currsum < reqsum){
            i++;
        } else if (currsum = reqsum){
            cout<<arr[i]<<" and "<<arr[j]<<endl;
            i++;
            j--;
        }
    }
    return 0;
}