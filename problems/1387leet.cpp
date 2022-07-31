#include<iostream>
#include<vector>
#include<algorithm>

int findPower(int n, std::vector<int> &dp) {
	if (dp[n] != -1) {
		return dp[n];
	}
	int ctr = 0;
	while (n > 1) {
		if (n % 2 == 0) {
			n /= 2;
		}
		else {
			n = n * 3 + 1;
		}
			ctr++;
	}
	dp[n] = ctr;
	return ctr;
}

int getKth(int lo, int hi, int k) {
	 std::vector<int> dp(1001,-1);
	 std::vector<std::pair<int,int>> res;
	 for (int i = lo; i <= hi; i++) {
		 res.push_back({ findPower(i,dp),i });
	 }
	 std::sort(res.begin(), res.end());
	 return res[k - 1].second;
}

int main() {
	int ans = getKth(1, 1000, 777);
	std::cout << ans;
}