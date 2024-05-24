#include<iostream>
using namespace std;

int main()
{
	int A;
	cin >> A;

	int B;
	cin >> B;

	int i = (A/100)*100 + (A%10); // 704
	i = (i%10)*100 + (A-i) + (A/100);

	int k = (B/100)*100 + (B%10);
	k = (k % 10) * 100 +(B-k) + (k / 100);

	if (i > k)
	{
		cout << i;
	}
	else if (i < k)
	{
		cout << k;
	}

	return 0;
}