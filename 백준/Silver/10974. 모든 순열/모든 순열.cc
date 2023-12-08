//
//  main.cpp
//  10974
//
//  Created by 김수비 on 12/8/23.
//

#include <iostream>
using namespace std;
#define MAX 9
int n;
int arr[MAX];
bool isused[MAX];

void bfs(int cnt){
    if(cnt == n){
        for(int i=0; i<n; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i=1; i<=n; i++){
        if(isused[i] != true){
            arr[cnt] = i;
            isused[i] = true;
            
            bfs(cnt+1);
            isused[i] = false;
        }
    }
    

}

int main() {
    cin >> n;
    
    bfs(0);
    return 0;
}
