#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct Node {
public:
	Node() {}
	Node(int _x, int _y, int h, bool visit)
		: x(_x), y(_y), height(h), isVisited(visit) {}

	friend ostream& operator<< (std::ostream& out, const Node& n) {
		out << n.x << "," << n.y << " : " << n.height << " ";

		return out;
	}

public:
	int x,y,height;
	bool isVisited;
};

struct CompareNode {
	bool operator()(Node* a, Node* b) {
		return a->height > b->height;
	}
};

int N, M, ans = 0;
priority_queue<Node*, std::vector<Node*>, CompareNode> pq;
vector<vector<Node>> map;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void DFS(const Node* cur, const int& max_height) {
	for (int i = 0; i < 4; i++) {
		int nx = cur->x + dx[i];
		int ny = cur->y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny].isVisited) continue;
		Node* next = &map[nx][ny];
		next->isVisited = true;
		if (next->height > max_height) pq.push(next);
		else {
			//cout << *cur <<  " " << ans << "\n";
			ans += max_height - (next->height);
			DFS(next, max_height);
		}
	}
}

void solution() {
	cin >> N >> M;
#pragma region 맵 할당
	map = vector<vector<Node>>(N,vector<Node>(M));
	int height;

	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			cin >> height;
			bool isVisit = (x == 0 || y == 0 || x == N - 1 || y == M - 1) ? true : false;
			map[x][y] = Node(x, y, height, isVisit);
			if (isVisit) pq.push(&map[x][y]);
		}
	}
#pragma endregion 맵 할당

	while (!pq.empty()) {
		const Node* cur = pq.top(); pq.pop();
		DFS(cur,cur->height);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	solution();

	cout << ans;

	return 0;
}