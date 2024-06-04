#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int map[5][5];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

vector<int> v;

// 한 칸에서 만들 수 있는 6개의 숫자를 모두 저장
void recursive(int i, int j, int num, int len){
    if(len == 6){
        v.push_back(num);

        return;
    }

    for(int k=0; k<4; k++){
        // 상하좌우 4가지 방향으로 이동 가능
        int nx = i + dx[k];
        int ny = j + dy[k];

        // x값이 0~4 인 값에 대하여 재귀를 실행
        if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5){
            recursive(nx, ny, num * 10 + map[nx][ny], len+1);
        }
    }
}

int main(){

    // 값을 입력 받음
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> map[i][j];
        }
    }

    // 25개의 칸 하나씩 돔
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            recursive(i, j, map[i][j], 1);
        }
    }
    
    // 중복된 수 삭제
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    cout << v.size();

}