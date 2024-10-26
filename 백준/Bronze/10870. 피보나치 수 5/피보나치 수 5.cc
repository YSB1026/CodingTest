#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;


ll Fibo(vector<ll> &v, const int& n) {
	if (n <= 1) return n;  // n이 1 이하일 때는 바로 반환

	v[1] = 1; v[2] = 1;
	for (int i = 3; i <= n; i++) {
		v[i] = v[i - 1] + v[i - 2];
	}
	return v[n];
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<ll> v(n + 1, 0);

	cout << Fibo(v,n);

	return 0;
}