#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer;
    int w_max = 0;
    int h_max = 0;
    
    for(int i = 0; i < sizes.size(); i++){
        
        // 가로가 더 길게 배치
        if(sizes[i][0] < sizes[i][1]){
            int tmp;
            tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
        
        if(sizes[i][0] > w_max) w_max = sizes[i][0];
        if(sizes[i][1] > h_max) h_max = sizes[i][1];
        
    }
    
    answer = w_max * h_max;
//     vector<int> v;
    
    
//     for(int i = 0; i < sizes.size(); i++){

//         v.push_back(sizes[i][0]);
//         v.push_back(sizes[i][1]);
//     }
    
//     sort(v.begin(), v.end());
//     reverse(v.begin(), v.end());
    
//     answer = v[0] * v[0 + sizes.size()];
    
    return answer;
}