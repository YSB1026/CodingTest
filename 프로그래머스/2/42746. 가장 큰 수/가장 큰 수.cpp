#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& s1, const string& s2){
    string str1 = s1 + s1 + s1 + s1;
    string str2 = s2 + s2 + s2 + s2;
    str1 = str1.substr(0, 4);
    str2 = str2.substr(0, 4);
    return str1 > str2;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> s_num;
    
    for(int i=0; i<numbers.size(); i++){
        s_num.push_back(to_string(numbers[i]));
    }
    
    sort(s_num.begin(), s_num.end(),cmp);
    
    for(int i=0; i<s_num.size(); i++){
        answer+=s_num[i];
    }
    
    if(answer[0] == '0')
        return "0";
    
    return answer;
}