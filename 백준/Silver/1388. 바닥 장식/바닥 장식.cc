#include<iostream>
using namespace std;

string arr[51];
bool visitt[51][51];

int cnt=0;
int N, M;

// 깊이 우선 탐색 알고리즘
int main(){

    cin >> N >> M; 

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            
            // 방문한 노드인 경우 넘어감
            if(visitt[i][j]) continue;

            if(arr[i][j] == '-'){

                cnt++; 

                // 다음 수가 -일 경우 
                for(int k=j+1; k < M; k++){
                    if(arr[i][k] == '-'){
                        visitt[i][k] = true;
                    }
                    else break;
                }
            }
            else if(arr[i][j] == '|'){
                cnt++;

                for(int q=i+1; q < N; q++){
                    if(arr[q][j] == '|'){
                        visitt[q][j] = true;
                    }
                    else break;
                }
            }

        }
    }
    cout << cnt;

    return 0;
}