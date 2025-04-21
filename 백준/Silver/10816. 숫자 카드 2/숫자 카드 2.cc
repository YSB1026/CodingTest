#include <iostream>
#include <map>

using namespace std;
 
void solution() {
	map<int, int> dic;

	int num;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		dic[num]++;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		cout << dic[num] << " ";
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();
}