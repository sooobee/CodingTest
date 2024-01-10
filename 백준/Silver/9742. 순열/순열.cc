//
//  main.cpp
//  9742
//
//  Created by 김수비 on 1/4/24.
//

#include <iostream>
#include <algorithm>
using namespace std;

int fact[12] = { 1, };

int main() {
    // 순열의 개수를 파악하기 위해
    for (int i=1; i<= 10; i++)
        fact[i] = fact[i-1]*i;
    
    string a; // 집합
    int n; // n번째 수

    while(cin >> a >> n) {
        cout << a << " " << n << " = ";
        
        // 해당하는 순열이 없는 경우: n보다 순열의 개수가 더 작을 경우
        if(n > fact[a.length()]){
            cout << "No permutation" << endl;
            continue;
        }
        
        int cnt = 0;
        do {
            cnt++;
            
            if (cnt == n){
                cout << a << endl;
                break;
            }
        // next_permutation: a를 다음 순열로 바꿈
        } while(next_permutation(a.begin(), a.end()));
    }
    return 0;
}

