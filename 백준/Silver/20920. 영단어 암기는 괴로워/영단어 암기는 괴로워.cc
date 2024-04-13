#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


bool compare(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second != b.second) {//1. 자주 나오는 단어일수록 앞에 배치
		return a.second > b.second;
	}

	if (a.first.size() != b.first.size())//2. 해당 단어의 길이가 길수록 앞에 배치
		return a.first.size() > b.first.size();

	return a.first < b.first;//사전순으로 앞에 배치
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	map<string, int> english_words;
	
	string words;
	while (N--)
	{
		cin >> words;
		if (words.length() < M)
			continue;
		english_words[words]++;
	}

	std::vector<pair<string, int>> v(english_words.begin(), english_words.end());
	sort(v.begin(), v.end(), compare);
	for (auto& e : v) {
		cout << e.first <<"\n";
	}

	return 0;
}