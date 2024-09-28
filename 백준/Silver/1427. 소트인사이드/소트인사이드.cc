#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	string str;

	cin >> str; // string형은 한 문자씩 배열에 들어감

	sort(str.begin(), str.end(), greater<char>()); // 내림차순으로 정렬(greater~)

	cout << str;
}