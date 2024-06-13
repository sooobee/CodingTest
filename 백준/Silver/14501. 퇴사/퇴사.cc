#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

static vector<int> D, T, P;

int main(){
    int n;

    cin >> n;

    D.resize(n+2);
    T.resize(n+1);
    P.resize(n+1);
    
    for(int i=1; i<=n; i++){
        cin >> T[i] >> P[i];
    }

    for(int i=n; i>0; i--){
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