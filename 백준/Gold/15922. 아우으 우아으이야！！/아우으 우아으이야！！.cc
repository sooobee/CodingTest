#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<pair<int, int>> v;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x, y;

        cin >> x >> y;

        v.push_back({x, y});
    }

    int start = v[0].first;
    int end = v[0].second;
    int res = 0;

    for(int i = 1; i < n; i++){
        int s = v[i].first;
        int e = v[i].second;

        if(s <= end){
            if(e > end){
                end = e;
            }
        }else {
            res += end - start;
            start = s;
            end = e;
        }
    }
    res += end - start;

    cout << res;
    return 0;
}