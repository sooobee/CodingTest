#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int n = commands.size();
    
    for(int a = 0; a < n; a++){
        vector<int> v;
        
        // i부터 j까지 수를 v에 넣음
        // i: 2, j: 5
        for(int b = commands[a][0]-1; b < commands[a][1]; b++){
            v.push_back(array[b]);
        }
        
        // 정렬
        sort(v.begin(), v.end());
        answer.push_back(v[commands[a][2] - 1]);
    }
    
    
    
    
    return answer;
}