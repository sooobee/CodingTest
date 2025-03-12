#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> winner;
    int size = answers.size();
    int first[5] = {1, 2, 3, 4, 5};
    int sec[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int third[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> cnt(3);
    int sc = 0;
    int tc = 0;
    
    for(int i = 0; i < size; i++){
        if(answers[i] == first[i % 5]) cnt[0]++;
        if(answers[i] == sec[i % 8]) cnt[1]++;
        if(answers[i] == third[i % 10]) cnt[2]++;
    }
    cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
    // max 뽑음
    int max = 0;
    for(int i = 0; i < 3; i++){
        if(cnt[i] >= max){
            max = cnt[i];
        }
        
    }
    cout << max << " ";
    
    for(int i = 0; i < 3; i++){
        if(cnt[i] == max){
            winner.push_back(i+1);
        }
    }
                              
                    
    return winner;
}