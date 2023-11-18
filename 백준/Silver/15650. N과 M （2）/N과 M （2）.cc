//
//  main.cpp
//  15650
//
//  Created by 김수비 on 11/18/23.
//

#include <iostream>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX];
bool isused[MAX];

void bfs(int num, int cnt){
    
    // m과 수열 길이가 같으면 출력
    if(cnt == m){
        for(int i=0; i<m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    // 백트래킹
    for(int i=num; i<=n; i++){
        
        // i가 사용되지 않았다면
        if(!isused[i]){
            
            // cnt 자리에 i를 넣음
            arr[cnt] = i;
            isused[i]= true;
            
            // i+1을 넘겨줘서, 다음 for문이 돌 때 앞 자리 수보다 큰 값부터 시작하게 함
            bfs(i+1,cnt+1);
            
            isused[i] = false;
        }
    }
    
}
// 첫번째 자리를 정하는 건 for문의 i값
// 두번째 자리를 정하는 건 bfs함수, 이때 앞의 수인 i보다 큰 수를 num으로 넘김

int main() {
    cin >> n >> m;
    // num을 같이 넘겨줌
    bfs(1, 0);
    
}
