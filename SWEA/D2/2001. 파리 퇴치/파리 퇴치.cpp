#include<iostream>
using namespace std;

int map[16][16];

int main(){
    int tc;
    cin >> tc;

    for(int i = 1; i <= tc; i++){
        int n, m;

        cin >> n >> m;

        // n*n을 입력받음
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                cin >> map[j][k];
            }
        }

        int max = -1;

        // m*m 중 가장 큰 것을 선택
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int res = 0;

                for(int a = m-1; a > -1; a--){
                    for(int b = m-1; b >-1; b--){
                        res += map[i + a][j + b];
                    }
                }
                // 가장 큰 m*m을 max에 저장
                if(res > max) max = res;
            }
        }
        cout << "#" << i << " " << max << endl;
    }
}