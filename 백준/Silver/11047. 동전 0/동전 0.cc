#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N; 
	int K;
	int num;
	int res=0;
	int arr[11];

	cin >> N >> K;

	// 동전의 종류를 입력받음
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	num = K;
	// 오름차순돼 있으므로 큰 수부터 차례로 탐색
	for (int i = N-1; i > -1; i--) {

		if (num >= arr[i]) {
			res += num/arr[i]; // 몫을 저장
			num = num%arr[i];// 나머지는 num에 저장

			if (num == 0)
				cout << res;
		}	
	}
}