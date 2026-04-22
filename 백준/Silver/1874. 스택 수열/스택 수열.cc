#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a;
    queue<int> q;
    stack<int> s;
    string ans;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        q.push(a);
    }

    for (int i = 1; i <= n; i++)
    {
        s.push(i);
        ans+="+\n";

        while (!s.empty() && !q.empty() && s.top() == q.front())
        {
            s.pop();
            q.pop();
            ans += "-\n";

            if(!s.empty() && !q.empty() && q.front() < s.top()){
                cout << "NO";
                return 0;
            }
        }
    }
    
    cout << ans;

    return 0;
}