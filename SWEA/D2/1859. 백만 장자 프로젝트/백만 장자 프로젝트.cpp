#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
	int T;
    cin >> T;
    
    // T : 테스트 케이스
    for(int i = 1; i <= T; i++){
    	int N;
        stack<long long> s;
        long long res = 0;
        cin >> N;
        
        vector<long long> v(N); // N크기의 벡터 생성

        // 벡터에 크기 저장
        for(int i = 0; i < N; i++){
            cin >> v[i];
        }

        long long max = v[N-1]; // 가장 뒤의 수를 max로 설정
        // 뒤에서부터 탐색
        for(int k = N-1; k > -1; k--){

            if(v[k] > max){
                max = v[k]; // max값 변경
            } else {
                res += max - v[k];
            }
        }
        cout << "#" << i << " " << res << endl;
    }
    return 0;
}