#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
int main()
{
	ll val,maxrev=INT64_MIN;
	int cnt;
	std::vector<ll> lvec, pvec;
	std::cin >> cnt;
	int i=cnt;
	while (i-- && std::cin >> val){
		lvec.push_back(val);
	}
	std::sort(lvec.begin(), lvec.end());
	for (int i = 0; i <= cnt; i++){
		pvec.push_back((cnt-i) * lvec[i]);
	}
	for (auto j = pvec.begin();j!=pvec.end();j++){
		maxrev=std::max(maxrev,*j);
	}
	std::cout<<maxrev;
}