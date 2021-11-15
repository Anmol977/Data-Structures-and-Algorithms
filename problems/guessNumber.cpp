class Solution {
public:

int guessNumber(int n)
{
    int left = 0, right = n, mid;
    while (left <= right)
    {
        mid =  left + (right-left)/2;
        int res = guess(mid);
        if(res == 1)
            left = mid +1;
        else if( res == -1)
            right = mid-1;
        else if(res == 0)
            break;
    }
        return mid;
}
};
