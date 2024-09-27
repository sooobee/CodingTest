#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(const string &a, const string &b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    
    for(int i=0; i<numbers.size(); i++){
        v.push_back(to_string(numbers[i]));
    }
        
    // 두 수를 조합했을 때 더 큰 것을 앞으로 두는 정렬 수행
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0; i < v.size(); i++){
        answer += v[i];
    }
    
    if(answer[0] == '0')
        answer = "0";
 
    return answer;
}