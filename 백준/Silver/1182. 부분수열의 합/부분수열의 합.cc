//
//  main.cpp
//  1182
//
//  Created by 김수비 on 12/12/23.
//

#include <iostream>
using namespace std;
#define MAX 21

int n,s;
int input[MAX];
int isused[MAX];
int cnt;

void dfs(int i, int hap){
    // 모든 수를 다 더하면 리턴
    if (i==n) return;
    
    //지금까지의 합에서 현재를 더함 > 정답이면 카운트 1
    if(hap+input[i] == s) cnt++;
    
    //아니면 dfs를 계속 돌림
    dfs(i+1, hap);
    
    // sum = sum+현재값
    dfs(i+1, hap+input[i]);
}


int main() {
    
    cin >> n >> s;
    
    for(int i=0; i<n; i++){
        cin >> input[i];
    }
    
    dfs(0,0);
    cout << cnt << endl;
    
    return 0;
}
