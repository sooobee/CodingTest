#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> q;
    
    for(int i=0; i < arr.size(); i++){
        
        if(q.empty()){
            q.push(arr[i]);
        
        // q가 비어 있지 않을 때    
        } else {
            // 중복되는 숫자가 아닐 경우 push
            if(arr[i] != q.back())
                q.push(arr[i]);
        }
    }
    
    while(!q.empty()){
        answer.push_back(q.front());
        q.pop();
    }
    
    return answer;
}