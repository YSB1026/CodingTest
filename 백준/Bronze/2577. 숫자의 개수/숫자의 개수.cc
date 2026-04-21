#include <iostream>

using namespace std;
int main() {
	int A, B, C;
	int multi_num;
	int arr[10]={0};

	cin >> A >> B >> C;
	multi_num = A * B * C;
	
	for (int i = multi_num; i > 0; i /= 10) {
		arr[i % 10]++;
	}
	for (int i = 0; i < 10; i++)
		cout << arr[i] << endl;

	return 0;
}