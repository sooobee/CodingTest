#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    vector<pair<int, int>> flower;

    cin >> n;

    for(int i = 0; i < n; i++){
        int sm, sd, em, ed;

        cin >> sm >> sd >> em >> ed;
        flower.push_back({100 * sm + sd, 100 * em + ed});
    }
    sort(flower.begin(), flower.end());

    int t = 301, res = 0, idx = 0;

    while (t < 1201)
    {
        int nxt = t;
        for (int i = idx; i < n; i++)
        {
            // 더 빨리 피고 더 늦게 지는 꽃일 경우
            if (flower[i].first <= t && flower[i].second > nxt)
            {
                nxt = flower[i].second;
                // 탐색하던 인덱스부터 다시 탐색할 수 있도록
                idx = i;
            }
            // 시작점이 t보다 큰 경우
            else if (flower[i].first > t) break;
        }
        // 연결이 끊길 때
        if(nxt == t){
            cout << "0" << '\n';
            return 0;
        }

        // 시작점 재설정
        t = nxt;
        res++;
    }

    cout << res << "\n";
}