#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10000;
int sugar[2] = { 3,5 };

int solution(const int& n) {
	vector<int> dp(n + 1, MAX);
	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			if (i - sugar[j] >= 0 && sugar[i - sugar[j]] != MAX) {
				dp[i] = min(dp[i], dp[i - sugar[j]] + 1);
			}
		}
	}


	return dp[n] == MAX ? -1 : dp[n];
}

int main()
{
	int n;
	cin >> n;

	cout << solution(n) << "\n";

	return 0;
}