#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int n;
vector<int>work[21];
vector<int>dp;
int inf = 987654321;

void make_works()
{
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			int w;
			cin >> w;
			work[i].push_back(w);
		}
	}
}

int count_bit(int num)
{
	int cnt = 0;
	while (num) {
		cnt += (num & 1);
		num >>= 1;
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	make_works();
	
	for (int i = 0; i < pow(2, n); i++) {
		dp.push_back(inf);
	}
	dp[0] = 0;

	for (int i = 0; i < pow(2, n); i++) {
		int x = count_bit(i);
		for (int j = 0; j < n; j++) {
			if (!(i & (1 << j))) {
				dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + work[x][j]);
			}
		}
	}

	cout << dp[dp.size() - 1];
}