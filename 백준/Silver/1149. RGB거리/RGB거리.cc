#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    // static vector<int> r;
    // static vector<int> g;
    // static vector<int> b;
    static int d[1001][4];
    // static int res[1001][4];

    // int g[1001];
    // int b[1001];
    // int d[1001]; // n~1까지의 집을 색칠할 때의 최소 비용

    cin >> n;
    // r.resize(n+1);
    // g.resize(n+1);
    // b.resize(n+1);
    

    // 입력
    for(int i=1; i<n+1; i++){
        cin >> d[i][1] >> d[i][2] >> d[i][3];
    }

    for(int i=n; i>0; i--){
        if(i == n) continue; // 첫번째 집

        else{
            // 2번째 집부터 red가 지어질 때, 전 집이 green, blue 중 작은 것이어야함
            d[i][1] += min(d[i+1][2], d[i+1][3]);

            // 2번째 집부터 green이 지어질 때, 전 집이 red, blue 중 작은 것이어야함
            d[i][2] += min(d[i+1][3], d[i+1][1]);
            
            // 2번째 집부터 blue가 지어질 때, 전 집이 green, red 중 작은 것이어야함
            d[i][3] += min(d[i+1][1], d[i+1][2]);
        }
    }

    cout << min(min(d[1][1], d[1][2]), d[1][3]);

    
}