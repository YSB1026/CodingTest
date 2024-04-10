#include <iostream>
#include <unordered_set>
#include <string>
#include <stdio.h>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin>>N;
    
    string s;
    unordered_set<string> people;
    int cnt = 0;
    for(int i=0; i<N; i++){
        cin>>s;
        if(s=="ENTER"){
            cnt+=people.size();
            unordered_set<string> n_people;
            people.swap(n_people);
            continue;
        }
        else{
            people.insert(s);    
        }
    }
    cnt+= people.size();
    cout << cnt;
    return 0;
}