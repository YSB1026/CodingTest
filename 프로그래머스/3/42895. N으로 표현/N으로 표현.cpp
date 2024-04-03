#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    vector<unordered_set<int>> dp(9);
    
    int cur = 0;
    for (int i = 1; i <9; i++) {
        cur = cur * 10 + N;
        dp[i].insert(cur);
    }
    
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j < i; j++) {
            int k = i - j;
            for (int x : dp[j]) {
                for (int y : dp[k]) {
                    dp[i].insert(x + y);
                    dp[i].insert(x - y);
                    dp[i].insert(x * y);
                    if (y != 0) dp[i].insert(x / y);
                }
            }
        }
        if (dp[i].count(number)) return i;
    }

    return -1;
}
