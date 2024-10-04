#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> math = {{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
    vector<int> cnt = {0, 0, 0};
    
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == math[0][i % math[0].size()]) cnt[0]++;
        if(answers[i] == math[1][i % math[1].size()]) cnt[1]++;
        if(answers[i] == math[2][i % math[2].size()]) cnt[2]++;
    }
    
    int m = *max_element(cnt.begin(), cnt.end());
    
    if(m == cnt[0]) answer.push_back(1);
    if(m == cnt[1]) answer.push_back(2);
    if(m == cnt[2]) answer.push_back(3);
    
    if(answer.size() > 1){
        sort(answer.begin(), answer.end());
    }
    return answer;
}