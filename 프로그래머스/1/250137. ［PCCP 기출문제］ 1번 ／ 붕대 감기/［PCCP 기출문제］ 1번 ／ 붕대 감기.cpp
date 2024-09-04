#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int t = bandage[0];
    int x = bandage[1];
    int y = bandage[2];
    int cha = 0;
    int max = health;

    for(int i = 0; i < attacks.size(); i++){
        // 첫 공격 시 
        if(i == 0){
            health += x * (attacks[i][1] - 1) + y * (attacks[i][1] / t);
        } else {
            int cha = attacks[i][0] - attacks[i-1][0] -1;
            // 경과시간 만큼 + 
            health += x * cha + y * (cha / t);
        }
        // 30보다 큰 경우 여전히 30으로
        if(health > max){
            health = max;
        }
        health -= attacks[i][1];
        
        if(health < 1){
            health = -1;
            break;
        }
    }
    answer = health;
    return answer;
}