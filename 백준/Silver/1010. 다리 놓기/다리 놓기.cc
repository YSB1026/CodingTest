#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;
    
//nCr=(n−1)C(r−1)+(n−1)Cr 이용
ll Combination(const int& n, const int& r) {
    if (r == 0 || r == n) return 1;
    
    vector<vector<ll>> C(n + 1, vector<ll>(r + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, r); j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1; 
            }
            else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }

    return C[n][r];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;

    vector<ll> ans;
    for (int i = 0; i < test_case; i++) {
        int r, n;
        cin >> r >> n;
        if (n / 2 < r) {
            r = n - r;
        }
        ans.push_back(Combination(n, r));
    }

    for (auto& e : ans) {
        cout << e << "\n";
    }

}