#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>

#define MAX 1000
#define COL first // 행
#define ROW second // 열

using namespace std;

int N, M; // N행 M열
int map[MAX][MAX]; // x, y
int visited[MAX][MAX][2]; // x, y, 거리 (index 0: 벽을 부수지 않은 경우, 1: 벽을 부순 경우)
queue<pair<pair<int, int>, bool>> q;

int dc[4] = { -1, 1, 0, 0 };
int dr[4] = { 0, 0, -1, 1 };

int BFS() {
    q.push({ {0, 0}, false }); // {col, row}, {벽을 부순 유무}
    visited[0][0][0] = 1; // 시작점도 거리에 포함
    visited[0][0][1] = 1; // 시작점도 거리에 포함

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int cur_col = cur.first.COL; // 현재 행
        int cur_row = cur.first.ROW; // 현재 열
        bool isBrokeWall = cur.second;

        if (cur_col == N - 1 && cur_row == M - 1)
            return visited[cur_col][cur_row][isBrokeWall];

        for (int i = 0; i < 4; i++) {
            int next_col = cur_col + dc[i];
            int next_row = cur_row + dr[i];

            if (next_col < 0 || next_row < 0 || next_col >= N || next_row >= M) continue; // 맵 밖

            // 현재 이동 상태에 맞는 방문 확인
            if (visited[next_col][next_row][isBrokeWall] || (isBrokeWall && visited[next_col][next_row][0])) continue;

            // 탐색
            if (isBrokeWall && map[next_col][next_row] == 1) continue; // 벽을 부수고 벽을 탐색하는 경우
            else if (!isBrokeWall && map[next_col][next_row] == 1) { // 처음으로 벽을 부수는 경우
                q.push({ {next_col, next_row}, true });
                visited[next_col][next_row][1] = visited[cur_col][cur_row][isBrokeWall] + 1;
            }
            else if(map[next_col][next_row] == 0){ // 벽을 부수지 않고 0, 벽을 부수고 0 
                q.push({ {next_col, next_row}, isBrokeWall });
                visited[next_col][next_row][isBrokeWall] = visited[cur_col][cur_row][isBrokeWall] + 1;
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));

    cin >> N >> M;

    for (int i = 0; i < N; i++) { // N행
        string _; cin >> _;
        for (int j = 0; j < M; j++) { // M열
            map[i][j] = _[j] - '0';
        }
    }

    cout << BFS();

    return 0;
}
