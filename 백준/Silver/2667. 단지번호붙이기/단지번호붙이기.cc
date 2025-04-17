#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int dx[4] = { -1, 1, 0, 0 }; // 상하좌우
int dy[4] = { 0, 0, -1, 1 };

int n;

int DFS(vector<vector<int>>& nodes, vector<vector<bool>>& visited, int x, int y) {
    visited[x][y] = true;
    int count = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (nodes[nx][ny] == 1 && !visited[nx][ny]) {
            count += DFS(nodes, visited, nx, ny);
        }
    }

    return count;
}

int main() {
    cin >> n;
    vector<vector<int>> nodes(n, vector<int>(n));
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++) {
            nodes[i][j] = line[j] - '0';
        }
    }

    vector<int> result;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (nodes[i][j] == 1 && !visited[i][j]) {
                int count = DFS(nodes, visited, i, j);
                result.push_back(count);
            }
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for (int cnt : result) {
        cout << cnt << "\n";
    }

    return 0;
}
