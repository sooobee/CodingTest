#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    int T;

    //freopen("input.txt", "r", stdin);

    cin >> T; // 테스트케이스의 수를 입력

    for(int i=0; i<T; i++){
        int arr[101] = {0, };

        int case_num;
        cin >> case_num; // 각 테스트 케이스를 입력받음
        //cout << "case_num: " << case_num; // 각 테스트 케이스를 입력받음

        // 입력
        for(int i=0; i<1000; i++){
            int index;
            cin >> index;
            arr[index]++;
        }


        int max = 0;
        int res = 0;

        // 최빈값 구하기
        for(int i=1; i<101; i++){
            if(arr[i] >= max){
                max = arr[i];
                res = i;
            } 
        }
        // 출력
        cout << "#" << case_num << " " << res << endl;
    }
    return 0;
}