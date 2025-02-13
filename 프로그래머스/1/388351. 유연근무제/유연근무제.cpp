#include <string>
#include <vector>

using namespace std;

int convertTime(int n) {
    int h = n / 100;
    int m = n % 100;
    return h * 60 + m;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int i=0; i<timelogs.size(); i++){
        int hope_time = convertTime(schedules[i]);
        int day = startday;
        bool isGetAward = true;

        for(int j=0; j<7; j++){
            //주중에 지각한경우
            if(day<6 && convertTime(timelogs[i][j]) > hope_time+10){
                isGetAward = false;
                break;
            }
            
            day = (day%7)+1;
        }
        if(isGetAward) answer++;
    }
    
    return answer;
}
