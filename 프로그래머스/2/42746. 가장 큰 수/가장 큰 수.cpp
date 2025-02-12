#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(const string &a, const string &b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> v2;
    string answer = "";
    
    for(int i = 0; i < numbers.size(); i++){
        v2.push_back(to_string(numbers[i]));
    }
    
    sort(v2.begin(), v2.end(), cmp);
    
    for(int i = 0; i < v2.size(); i++){
        // cout << v2[i] << " ";
        answer += v2[i];
    }
    
    if(answer[0] == '0'){
        answer = "0";
    }
    
    return answer;  
}