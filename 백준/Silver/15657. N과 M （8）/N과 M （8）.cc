#include <iostream>
#include <algorithm>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX];
int input[MAX];
int isused[MAX];

void bfs(int cnt, int num){
    
    if(cnt == m){
        for(int i=0; i<m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i=num; i<n; i++){
    
        arr[cnt] = input[i];
        isused[i] = true;
        
        bfs(cnt+1, i);
        
        isused[i] = false;
    }
}

int main() {
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin >> input[i];
    }
    
    sort(input, input+n);
    
    bfs(0, 0);
    
    return 0;
}
