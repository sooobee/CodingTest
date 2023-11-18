#include <iostream>
using namespace std;

int N, M;
int arr[10]; // 수열을 저장하는 배열
bool isused[10]; // 이미 사용한 숫자인지 체크하는 배열

void func(int k) {
    
    // 수열의 길이가 M과 같으면 출력
    if(k == M) {
        for(int i=0; i<M; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    // 백트래킹
    for(int i = 1; i<=N; i++){
        if(!isused[i]){
            arr[k] = i;
            isused[i] = 1; // 사용됐음을 표시
            func(k+1); // 출력 후 여기로 리턴
            
            isused[i]=0; // 새 수열이 시작될 때 전에 자리에 있던 것은 0으로 처리 됨
        }
    }
}

int main() {
    cin >> N >> M;
    
    func(0);
}