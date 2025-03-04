#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(int i = 0; i < commands.size(); i++){
        int start = commands[i][0];
        int end = commands[i][1];
        int target = commands[i][2];
        vector<int> v;

        // 자른 숫자들을 다시 v에 넣음
        for(int j = start-1; j < end; j++){

            v.push_back(array[j]);
        }
        sort(v.begin(), v.end());
        answer.push_back(v[target-1]);

        
    }
    return answer;
}