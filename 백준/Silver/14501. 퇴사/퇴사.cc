#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int n;
    int T[16] = {0, };
    int P[16] = {0, };
    int D[17] = {0, };
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> T[i] >> P[i];
    }

    for(int i=n; i>=1; i--){
        // 퇴사일을 넘을 경우
        if(i+T[i] > n+1){
            D[i] = D[i+1];
        } // 퇴사일 넘지 않을 경우
        else {
            D[i] = max(D[i+1], P[i]+D[i+T[i]]);
        }
    }

    cout << D[1];
}