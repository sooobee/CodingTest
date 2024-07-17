#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int res;
    vector<pair<int, int>> v; // start, end 저장
    priority_queue<int, vector<int>, greater<int>> pq; // end저장 -> 오름차순

    cin >> n;

    for(int i=0; i<n; i++){
        int start, end;
        cin >> start >> end;
        
        v.push_back(make_pair(start, end));
    }
    // 빠르게 시작하는 수업 별로 정렬
    sort(v.begin(), v.end());

    pq.push(v[0].second);
    for(int i = 1; i < n; i++){
        // 시작 시간이 더 크거나 같으면 같은 강의실을 공유할 수 있음
        if(v[i].first >= pq.top()){
            pq.pop();
            pq.push(v[i].second);
        }
        else pq.push(v[i].second);
    }
    cout << pq.size();
}