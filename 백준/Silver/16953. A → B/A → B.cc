#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

int a, b;
int cnt;
bool flag;

void bfs(int a, int b){
    queue<int> q;

    q.push(b);

    while(!q.empty()){
        int num = q.front();

        // 목표값에 도달한 경우 bfs나감
        if(num == a){
            flag = true; 
            return;
        }
        if(num < a){
            flag = false;
            return;
        }

        q.pop();

        // 1의자리 수가 1일때
        if(num % 10 == 1){
            int nxt = (num-1)/10;
            q.push(nxt);
            cnt += 1;

        // 2의 배수일 때
        } else if(num % 2 == 0) {
            int nxt = num/2;
            q.push(nxt);
            cnt += 1;

        } else {
            flag = false;
            return;
        }
    }
}

int main(){
    cin >> a >> b;

    bfs(a, b);

    if(flag){
        cout << cnt+1;
    } else {
        cout << "-1";
    }
    return 0;
}