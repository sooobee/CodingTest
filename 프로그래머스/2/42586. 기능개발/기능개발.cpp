#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> t;
    stack<int> st;
    
    
    for(int i = 0; i < progresses.size(); i++){
        int num;
        
        if((100 - progresses[i]) % speeds[i] > 0){
            num = (100 - progresses[i]) / speeds[i] + 1;
        } else {
            num = (100 - progresses[i]) / speeds[i]; // 남은 시간    
        }

        t.push_back(num);
    }
    
    int cnt = 0;
    int max_num = t[0];
    for(int i = 0; i < t.size(); i++){
        // 비어 있을 경우 일단 넣음
        if(t[i] <= max_num){

                cnt++;
        } 
        else { // 더 크면 cnt를 answer에 저장, cnt리셋
            answer.push_back(cnt); 
            cnt = 0;
        

            max_num = t[i];
            cnt++;
        }
    }

    
    if(cnt > 0){
        answer.push_back(cnt);
    }
    
    return answer;
}