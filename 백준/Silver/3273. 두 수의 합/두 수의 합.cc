#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;
bool arr[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, a;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr[a] = true;
    }

    cin >> x;
    int ans = 0;

    for (int i = 1; i < (x + 1) / 2; i++)
    {
        if(x-i < MAX && arr[i] && arr[x-i]) ans++;
    }
    cout << ans;

    return 0;
}