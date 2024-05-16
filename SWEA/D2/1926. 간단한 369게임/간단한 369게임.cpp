#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        // 1~10까지 중 각각의 수
        string num = to_string(i);
        int cnt = 0;

        for (int k = 0; k < num.length(); k++)
        {   
            // 3의 배수가 있을 cnt 추가
            if (num[k] != '0' && num[k] % 3 == 0)
            {
                cnt++;
            }
        }
        

        if(cnt == 0){
            cout << i;
        } else {
            for(int i=0; i<cnt; i++){
                cout << "-";
            }
        }

        if(i != N){
            cout << " ";
        }
        
    }
    return 0;
}