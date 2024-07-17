#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
    int n, m;
    long long int res = 0;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        pq.push(num);
    }

    while(m--){
        long long int data1 = pq.top();
        pq.pop();
        long long int data2 = pq.top();

        pq.pop();

        long long int new_card = data1 + data2;
        pq.push(new_card);
        pq.push(new_card);
    }

    while(n--){
        res += pq.top();
        pq.pop();
    }

    cout << res;
}