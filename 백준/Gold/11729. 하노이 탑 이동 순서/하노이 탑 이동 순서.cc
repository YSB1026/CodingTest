#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> arr;
void Print(int start, int end) {
	arr.push_back(to_string(start) + " " + to_string(end));
}
void Hanoi(int n, int start, int to, int via) {
	if (n == 1) {
		Print(start, to);
	}
	else {
		Hanoi(n - 1, start, via, to);
		Print(start, to);
		Hanoi(n - 1, via, to, start);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	Hanoi(n, 1, 3, 2);

	cout << arr.size() << "\n";
	for (auto& str : arr) {
		cout << str << "\n";
	}
	return 0;
}