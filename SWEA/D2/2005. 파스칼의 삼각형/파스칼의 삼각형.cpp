#include<iostream>
using namespace std;

int main(){
    int tc, n;
    int map[11][11] = {0, };
    cin >> tc;

    for(int i = 1; i <= tc; i++){
        cin >> n; 

        map[0][0] = 1; // 첫째줄 저장
        // 각 자리에 숫자 저장    
        for(int j = 1; j < n; j++){
            for(int k = 0; k <= j; k++){
                // 각 줄 처음과 끝은 1임
                if(k == 0 || k == j){
                    map[j][k] = 1;
                }else {
                    // 윗 줄 오른쪽, 왼쪽 더함
                    map[j][k] = map[j-1][k-1] + map[j-1][k];
                }
            }
        }

        cout << "#" << i << " " << endl;
        for(int a = 0; a < n; a++){
            for(int b = 0; b <= a; b++){
                cout << map[a][b] << " ";
            }
            cout << endl;
        }
    }
}