#include<iostream>
using namespace std;

int main(){
    int T;
    cin >> T;

    for(int tc=1; tc<=T; tc++) {
        int N;
        int cnt = 1; // (0,0) 하나 포함

        cin >> N;

        int N2 = N*N; // N^2

        for(int i=0; i<=N; i++){
            for(int j=0; j<=N; j++){
                if(i*i + j*j <= N2)
                {   if(i * j == 0) cnt += 2;
                    else { 
                        cnt += 4; 
                    }
                }
            }
        }

        cout << "#" << tc << " " << cnt-2 << endl;
    }

    return 0;
}