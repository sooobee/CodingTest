//
//  main.cpp
//  15654
//
//  Created by 김수비 on 11/25/23.
//

#include <iostream>
#include <algorithm>
#define MAX 9
using namespace std;

int n, m;
int num[MAX]; // 입력으로 주어지는 수(배열이 될)
int arr[MAX]; // 배열
int isused[MAX];

void bfs(int cnt){
    if(cnt == m){
        for(int i=0; i<m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        
        return;
    }
    
    for(int i=0; i<n; i++){
        if(!isused[i]){
            arr[cnt] = num[i]; // Num수를 수열로 넘겨줌
            isused[i] = true;
            
            bfs(cnt+1);
            isused[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i<n; i++){
        cin >> num[i];
    }
    
    sort(num, num+n); // 배열을 오름차순으로 정리
    
    bfs(0);

    return 0;
}
