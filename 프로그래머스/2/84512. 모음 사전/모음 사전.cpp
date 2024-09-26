#include <string>
#include <vector>

using namespace std;

string target = "";
string a = "AEIOU";
int answer = 0;
int cnt = -1;

void dfs(string word){    
    cnt++;

    if(word == target){
        answer = cnt;
        return;
    }
    
    if(word.length() >=5) return; 
    
    for(int i=0; i<5; i++){
        dfs(word + a[i]);
    }    
}

int solution(string word) {
    
    target = word;
    
    dfs("");
    
    return answer;
}