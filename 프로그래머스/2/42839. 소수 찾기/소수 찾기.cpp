#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <set>
#include <algorithm>
using namespace std;

// 소수 판별 함수
bool isPrime(int a){
    if(a < 2) return false;
        
    for(int i = 2; i <= sqrt(a); i++){
        if(a % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> v;
    vector<int> num;
    
    for(int i = 0; i < numbers.length(); i++){
        // 숫자를 잘라서 num에 넣음
        v.push_back(numbers[i]);
    }
    sort(v.begin(), v.end());
    
    // 모든 조합 만들어질 때까지 반복
    do {
        string temp = "";
        
       for(int i = 0; i < v.size(); i++){
           temp += v[i];

           num.push_back(stoi(temp));  
       }
        
    } while(next_permutation(v.begin(), v.end()));
    
    sort(num.begin(), num.end());
    // 중복 제거
    num.erase(unique(num.begin(), num.end()), num.end());
    
    
    for(int i = 0; i < num.size(); i++){
        if(isPrime(num[i])) answer++;
    }
    return answer;
}