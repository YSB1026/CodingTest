#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
int main(){
    vector<int> arr(5);

    for(int i=0; i<5; i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());
    int avg = accumulate(arr.begin(),arr.end(),0)/5;
    int med = arr[2];

    cout << avg << "\n" << med;
    
    return 0;
}