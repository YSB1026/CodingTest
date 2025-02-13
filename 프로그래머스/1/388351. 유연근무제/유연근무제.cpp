#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int i=0; i<timelogs.size(); i++){
        int hope_time = schedules[i];
        int day = startday;
        bool isGetAward = true;
        cout << "직원 " << i+1 <<"\n";
        for(int j=0; j<7; j++){
            //주중에 지각한경우
            if(day<6 && timelogs[i][j] > hope_time+10){
                isGetAward = false;
                break;
            }
            cout << day <<"요일 " << timelogs[i][j] - hope_time <<"분 \n";
            day = (day%7)+1;
        }
        if(isGetAward) answer++;
    }
    
    return answer;
}