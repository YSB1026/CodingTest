#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool visited[100][100];

int destX,destY;

bool isBreak(int x, int y, const vector<string>& board) {
    if (x < 0 || y < 0 || x >= board.size() || y >= board[0].length()) return true;
    if (board[x][y] == 'D') return true;
    return false;
}
int solution(vector<string> board) {
    int answer = 0;

    int sx, sy;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].length(); j++) {
            if (board[i][j] == 'R') {
                sx = i; sy = j;
            }
            if (board[i][j] == 'G') {
                destX = i; destY = j;
            }
        }
    }

    int cnt = 0;
    bool success = false;

    queue<pair<pair<int, int>,int>> q;
    q.push({ { sx,sy },cnt });
    visited[sx][sy] = true;

    while (!q.empty()) {
        pair<pair<int, int>,int> cur = q.front(); q.pop();
        pair<int, int> cur_pos = cur.first;
        int c_cnt = cur.second;

        if (cur_pos.first == destX && cur_pos.second == destY) {
            success = true;
            answer = c_cnt;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur_pos.first + dx[i], ny = cur_pos.second + dy[i];
            if (isBreak(nx, ny, board)) continue;

            while (1) {
                if (isBreak(nx + dx[i], ny + dy[i], board)) break;
                nx += dx[i];
                ny += dy[i];
            }
            if (!visited[nx][ny]) {
                q.push({{ nx,ny },c_cnt+1});
                visited[nx][ny] = true;
            }
        }
    }
    if (!success) {
        answer = -1;
    }

    return answer;
}