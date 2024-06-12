#include<iostream>
using namespace std;

int D[1000001];

int main(){
    int n;
    cin >> n;
    D[1] = 0;

    // D[i]: i에서 1로 갈 때 연산을 사용하는 횟수의 최솟값
    for(int i=2; i<=n; i++){
        D[i] = D[i-1]+1;

        if(i % 2 == 0) D[i] = min(D[i], D[i/2]+1);
        if(i % 3 == 0) D[i] = min(D[i], D[i/3]+1);
    }

    cout << D[n];
}