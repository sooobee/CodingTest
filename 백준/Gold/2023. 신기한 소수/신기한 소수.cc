#include<iostream>
using namespace std;

int N;
int sosu[4] = {2, 3, 5, 7};

// num 숫자, cnt 자릿수
void dfs(int num, int cnt){

    // 자릿수가 동일한 경우 출력
    if(cnt == N){
        cout << num << '\n';
    }

    // 뒤에 붙는 수
    for(int i=0; i<10; i++){
        bool flag = true;

        // 새롭게 만든 수
        int newN = num*10 + i;
       
        // 짝수인 경우
        if(newN%2 == 0){
            flag = false;
            continue;
        }

        // 소수가 아닌 경우(2~본인/2까지의 값으로 나눠질 경우)
        for(int i=2; i<=newN/2; i++){
            if(newN%i == 0){
                flag = false;  
                break;
            }
        }

        if(flag){
            dfs(newN, cnt+1);
        }
        
    }
}

int main(){
    cin >> N;

    // 1. 2, 3, 5, 7 에 대해 dfs탐색 진행
    for(int i=0; i<4; i++){
        dfs(sosu[i], 1);
    }
    return 0;
}