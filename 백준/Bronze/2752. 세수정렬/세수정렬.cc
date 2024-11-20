#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n1,n2,n3;
    cin >> n1>>n2>>n3;
    
    vector<int> arr = {n1,n2,n3};
    sort(arr.begin(),arr.end());
    
    for(auto& e : arr){
        cout << e << " ";
    }
    return 0;
}