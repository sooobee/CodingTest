#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> arr){
   vector<int> answer;
    queue<int> q;

    for(int i = 0; i < arr.size(); i++){
        
        // 큐가 비어있을 때 넣음
        if(q.empty()){
            q.push(arr[i]);
        } else {
            if(arr[i] != q.back()){
                q.push(arr[i]);
            } else continue;
        }
    }
    
    while(!q.empty()){
        int num = q.front();
        q.pop();
        
        answer.push_back(num);
    }
    
    return answer;
}