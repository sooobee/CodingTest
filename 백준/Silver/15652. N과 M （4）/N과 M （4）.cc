//
//  main.cpp
//  15652
//
//  Created by 김수비 on 11/21/23.
//

#include <iostream>
using namespace std;
#define max 9

int n, m;
int arr[max];
bool isused[max];

void bfs(int cnt, int num){
    
    if(cnt == m){
        for(int i=0; i<m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i= num; i<=n; i++){
        
        arr[cnt] = i;
        isused[i] = true;
        
        // 두번째 자리가 i부터 시작되도록 함
        bfs(cnt+1, i);
        
        isused[i] = false;
    }
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    
    bfs(0, 1);
}
