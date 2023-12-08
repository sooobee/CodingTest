//
//  156666.cpp
//  15665
//
//  Created by 김수비 on 12/8/23.
//

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 8

int n, m;
int input[MAX]; // 입력받은 배열
int arr[MAX]; // 저장할 배열

void bfs(int cnt, int k){
    
    if(cnt == m){
        for(int i=0; i<m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    int num = 0;

    for(int i=k; i<n; i++){
        if(input[i] != num){
            arr[cnt] = input[i];
            num = input[i]; // 같은 수가 중복 안되게
            
            bfs(cnt+1, i); // k자리에 i를 넘겨서 i부터 시작하게
        }
    }
}

int main() {
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin >> input[i];
    }
    
    sort(input, input+n); // 정렬
    
    bfs(0,0); // 0번째부터 탐색
 
    return 0;
}
