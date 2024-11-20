#include <iostream>
#include <string>
using namespace std;
int main(){
    string 윷놀이[5] = { "E", "A", "B", "C", "D" }; //모 도 개 걸 윷

    for(int i=0; i<3; i++){
        int 배 = 0;
        int tmp;
        for(int j=0; j<4; j++){
            cin>>tmp;
            if(tmp == 0) 배++;
        }
        cout << 윷놀이[배]<< " ";
    }
    return 0;
}