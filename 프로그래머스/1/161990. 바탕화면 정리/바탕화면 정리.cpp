#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;

    int row_max = -1;
    int row_min = 51;
    int col_max = -1;
    int col_min = 51;

    // 세로 길이
    for(int i = 0; i < wallpaper.size(); i++){
        // 가로 길이
        for(int k = 0; k < wallpaper[i].size(); k++){
            char cur = wallpaper[i][k];

            if(cur == '#'){
                if(i < col_min) col_min = i;
                if(i > col_max) col_max = i;
                if(k < row_min) row_min = k;
                if(k > row_max) row_max = k;
            }
        }
    }
    answer.push_back(col_min);
    answer.push_back(row_min);
    answer.push_back(col_max+1);
    answer.push_back(row_max+1);
    
    return answer;
}