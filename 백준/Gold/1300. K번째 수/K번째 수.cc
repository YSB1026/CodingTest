#include <iostream>

using namespace std;

typedef long long ll;

ll N, k;

ll count(ll x) {
    ll cnt = 0;
    for (ll i = 1; i <= N; ++i) {
        cnt += min(x / i, N);
    }
    return cnt;
}

void solution()
{
    cin >> N >> k;

    ll left = 1, right = N * N;
    ll answer = 0;

    while (left <= right) {
        ll mid = (left + right) / 2;
        if (count(mid) >= k) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << answer << '\n';
}

int main() {
    solution();

    return 0;
}

