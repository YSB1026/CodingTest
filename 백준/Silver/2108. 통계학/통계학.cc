#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> v;
    unordered_map<int,int> m;
    int T;
    cin>>T;
    
    int i;
    while(T--){
        cin>>i;
        v.push_back(i);
        m[i]++;
    }
    sort(v.begin(),v.end());
    
    double a_m = accumulate(v.begin(), v.end(), 0.0)/v.size();
    int arithmetic_mean = floor(a_m+0.5);
    
    int median = v[v.size()/2];
    
    vector<pair<int, int>> tmp(m.begin(), m.end());
	sort(tmp.begin(), tmp.end(), [](auto const& l, auto const& r)
		{
			return l.second != r.second ? l.second > r.second : l.first < r.first;
		});

	int mode = tmp[0].first;

	if (tmp.size() > 1 && tmp[0].second == tmp[1].second)
		mode = tmp[1].first;

    
    int range = v.back()-v[0];
    
    printf("%d\n%d\n%d\n%d",arithmetic_mean,median,mode,range);
    
    return 0;
}
