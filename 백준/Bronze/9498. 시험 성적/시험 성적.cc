#include <iostream>
#include <string>
using namespace std;

string GetGrade(const int& score) {
	if (score >= 90)  return"A";
	else if (score >= 80) return "B";
	else if (score >= 70) return "C";
	else if (score >= 60) return "D";
	return "F";
}
int main() {
	int score;
	cin >> score;
	
	string grade = GetGrade(score);

	cout << grade;

	return 0;
}