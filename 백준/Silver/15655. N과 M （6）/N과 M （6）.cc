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
int input[MAX]; // 입력으로 주어지는 수(배열이 될)
int arr[MAX]; // 배열
int isused[MAX];

void bfs(int cnt, int num){
    if(cnt == m){
        for(int i=0; i<m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        
        return;
    }
    
    for(int i= num; i<n; i++){
        if(!isused[i]){
            arr[cnt] = input[i];
            isused[i] = true;
            
            bfs(cnt+1, i+1); // i+1한 값을 num으로 넘겨주면, input의 인덱스로 들어가 앞의 자리수(input[i])보다 더 큰 값(input[i+1])이 뒤에 온다.
            isused[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i<n; i++){
        cin >> input[i];
    }
    
    sort(input, input+n); // 배열을 오름차순으로 정리
    
    bfs(0, 0); // 비교값을 같이 보냄

    return 0;
}

