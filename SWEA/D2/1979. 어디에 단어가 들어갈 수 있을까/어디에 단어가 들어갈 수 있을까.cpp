#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int map[15][15];
int dx[2] = {1, 0};
int dy[2] = {0, 1};
int n, k;
int res;

int main(){
    int tc;
    cin >> tc;

    for(int i = 1; i <= tc; i++){
        res = 0; // res 초기화
        cin >> n >> k;

        // 좌표에 입력
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                cin >> map[j][k];
            }
        }

        // 가로 탐색
        for(int a = 0; a < n; a++){
            int cnt = 0;

            for(int b = 0; b < n; b++){
                if(map[a][b] == 1){
                    cnt++;

                    // k보다 크면 다시 시작
                    if(cnt > k)
                        cnt = 0;

                    // 적절한 칸 찾았을 때
                    if(b == n-1 && cnt == k){
                        res++;
                    }
  
                } else {
                    if(cnt == k)
                        res++;
                    cnt = 0;
                }
            }
        }
        // 세로 탐색
        for(int a = 0; a < n; a++){
            int cnt = 0;

            for(int b = 0; b < n; b++){
                if(map[b][a] == 1){
                    cnt++;

                    // k보다 크면 다시 시작
                    if(cnt > k)
                        cnt = 0;

                    // 적절한 칸 찾았을 때
                    if(b == n-1 && cnt == k){
                            res++;
                    }
  
                } else {
                    if(cnt == k)
                        res++;

                    cnt = 0;
                }
            }
        }

        cout << "#" << i << " " << res << endl;
    }
}
