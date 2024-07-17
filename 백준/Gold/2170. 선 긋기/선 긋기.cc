#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<pair<int, int> > arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a,b));
    }
    sort(arr.begin(), arr.end());
    int ans=0;
    int start = arr[0].first, end = arr[0].second;
    for(int i=1 ; i<n ; i++) {
        int s = arr[i].first, e = arr[i].second;
        if(end>=s) {
            if(end<e) {
                end = e;
            } 
        } else {
            ans += end-start;
            start = s, end = e;
        }
    }
    ans += end-start;
    cout << ans << "\n";

    return 0;
}