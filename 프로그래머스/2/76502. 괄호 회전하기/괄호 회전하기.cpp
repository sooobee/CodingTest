#include <string>
#include <vector>
#include <stack>
#include<iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    
    for(int i=0; i<s.length(); i++){
        stack<char>st;
        bool flag = false;
        
        for(int j=0; j<s.length(); j++){
            if(s[j] == '[' || s[j] == '(' || s[j] == '{'){
                st.push(s[j]);
                flag = true;
            }
                
            
            else {
                if(s[j] == ']' && st.top() == '[')
                    st.pop();
                
                
                if(s[j] == ')' && st.top() == '(')
                    st.pop();
                
                if(s[j] == '}' && st.top() == '{')
                    st.pop();
            }
        }
        // 모두 짝이 맞는 경우
        if(flag && st.empty()){
            answer++;

        }
            
        
        char temp = s.front();
        s.erase(s.begin());
        s.push_back(temp);


    }
    
    return answer;
}