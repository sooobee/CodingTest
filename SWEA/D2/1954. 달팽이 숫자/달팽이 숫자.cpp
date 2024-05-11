#include <iostream>

using namespace std;
#define MAX 11
int main(int argc, char** argv)
{
    int T;
    cin >> T;

    for(int t=0;t<T;t++){
        int n;
        cin >> n;
        int snail[MAX][MAX] = {0,};
        
        string direction = "right"; //첫 시작 방향 오른쪽
        
        int x=-1, y=0;
        int cnt = 0;
        int N = n;
        for(int i=1;i>=0;i++){
            
            if(cnt == n && direction == "up"){
                direction = "right";
                cnt = 0;
            } else if(cnt == n && direction == "right"){
                direction = "down";
                cnt = 0;
                n--;
            } else if(cnt == n && direction == "down"){
                direction = "left";
                cnt = 0;
            } else if(cnt == n && direction == "left"){
                direction = "up";
                cnt = 0;
                n--;
            }
            
            if(direction == "right") x++;
            else if(direction == "left") x--;
            else if(direction == "down" ) y++;
            else if(direction == "up") y--;
            
            snail[y][x] = i;
            cnt++;
            
            if(i == N*N) break;
        }
        
        //출력
        cout << "#" << t+1 << "\n";
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) {
                cout << snail[i][j];
                if(j != N-1) cout << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}