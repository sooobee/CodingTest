//
//  main.cpp
//  15663
//
//  Created by 김수비 on 11/29/23.
//

#include <iostream>
#include <algorithm>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX];
int input[MAX];
int isused[MAX];

void bfs(int cnt){
    
    if(cnt == m){
        for(int i=0; i<m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    int num = 0;
    
    for(int i=0; i<n; i++){
    
        // 2. 그 값과 비교해서 같지 않으면 추가함(
        if(!isused[i] && input[i] != num){
            
            arr[cnt] = input[i];
            
            num = input[i]; // 1. 여기서 수를 저장하고
            isused[i] = true;
            
            bfs(cnt+1);
            
            isused[i] = false;
        }
    }
}

int main() {
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin >> input[i];
    }
    
    sort(input, input+n);
    
    bfs(0);
    
    return 0;
}

