#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int board[101];
int dist[101];
bool visited[101];

void BFS()
{
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
         
        for (int dice = 1; dice <= 6; dice++) {
            int next = now + dice;
            if (next > 100) continue;

            int dest = board[next];

            if (!visited[dest]) {
                visited[dest] = true;
                dist[dest] = dist[now] + 1;
                q.push(dest);
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M; 

    for (int i = 1; i <= 100; i++) {
        board[i] = i;
    }

    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        board[u] = v;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        board[u] = v;
    }

    BFS();

    cout << dist[100] << '\n';
    return 0;
}
