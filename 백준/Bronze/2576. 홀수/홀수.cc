#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int min_odd = 100, sum = 0;
    int num;
    for(int i=0; i<7; i++){
        cin>>num;
        if(num%2){
            sum+=num;
            min_odd = min(num,min_odd);
        }
    }
    if(sum==0) cout << -1;
    else{
        cout << sum <<"\n" << min_odd;
    }
    return 0;
}