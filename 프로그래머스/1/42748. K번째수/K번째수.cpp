#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    
    vector<int> answer;
    vector<int> array2;
    
    // commands의 수만큼 반복
    for(int i = 0; i < commands.size(); i++){
        array2.clear();
        
        int start = commands[i][0];
        int end = commands[i][1];
        int target = commands[i][2];
        
        // 시작 ~ 끝까지의 수 array2 넣음
        for(int k = start-1; k < end; k++){
            array2.push_back(array[k]);
        }
        sort(array2.begin(), array2.end());
        answer.push_back(array2[target-1]);
    }
    return answer;
}