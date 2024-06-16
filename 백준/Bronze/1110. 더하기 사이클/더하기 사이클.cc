// 백준 1110 더하기 사이클

#include <iostream>
using namespace std;

int main()
{
	int n; // 입력받을 수 변수 생성
	int num; // n의 값을 받아 줄 변수 생성
	int tmp;  // n과 스왑 할 변수 생성
	int cnt = 0; // count를 세어줄 변수 생성

	cin >> n; // 수 입력

	num = n; // num에 n을 저장

	while (1) // 무한 루프
	{
		tmp = (n % 10) * 10 + (n / 10 + n % 10) % 10; // 수를 조합하는 공식
		cnt++; // 수의 조합을 완료하면 카운트에 +1
		n = tmp; // n에 tmp값 저장
		if (tmp == num) // 만약 tmp와 num값이 같다면 (기존 수와 사이클이 끝난 수가 같다면)
			break; // 멈춤
	}

	cout << cnt << endl; // cnt 출력

	return 0;
}