#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;

using namespace std;


void solution() {
	int k, n;
	cin >> k >> n;

	vector<int> arr(k);
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}

	ll left = 1, right = *max_element(arr.begin(), arr.end());
	int result = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		int tot = 0;
		for (int i = 0; i < k; i++) {
			tot += arr[i] / mid;
		}
		if (tot >= n) {
			left = mid + 1;
			result = mid;
		}
		else {// tot < n
			right = mid - 1;
		}
	}

	cout << result;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	solution();

	return 0;
}