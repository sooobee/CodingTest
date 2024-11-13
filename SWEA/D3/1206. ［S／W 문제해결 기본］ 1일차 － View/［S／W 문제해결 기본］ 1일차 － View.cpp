#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    for(int i = 1; i <= 10; i++){
        long long n; // 건물 수
        vector<long long> v; // 건물의 높이 저장
        long long res = 0;
        cin >> n;

        for(int j = 0; j < n; j++){
            int num;

            cin >> num;
            v.push_back(num); // 건물 높이 저장
        }

        // 조망권 체크
        for(int k = 2; k < n; k++){
            long long max = -1;

            for(int q = k-2; q <= k+2; q++){
                if(q == k) 
                    continue;

                // 오, 왼 2만큼의 거리에서 가장 큰 것 max에 저장
                if(v[q] > max)
                    max = v[q];
            }
            
            // 조망권을 가지는 세대
            long long cha = v[k] - max;

            if(cha > 0){
                res += cha;
            }
        }
        cout << "#" << i << " " << res << endl;
    }
}
