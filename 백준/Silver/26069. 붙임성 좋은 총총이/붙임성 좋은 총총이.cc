#include <stdio.h>
#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cnt;
    cin>>cnt;
    string A,B;
    unordered_set<string> rainbow_dance;
    rainbow_dance.insert("ChongChong");
    while(cnt--){
        cin>>A>>B;
        if(rainbow_dance.count(A))
            rainbow_dance.insert(B);
        else if(rainbow_dance.count(B))
            rainbow_dance.insert(A);
    }
    
    cout << rainbow_dance.size();
    
    return 0;
}