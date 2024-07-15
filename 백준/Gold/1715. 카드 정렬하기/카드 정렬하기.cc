#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n;
int num;
priority_queue<int, vector<int>, greater<int>> pq; // 오름차순 정렬
int res;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        pq.push(num);
    }
    
    int data1, data2;

    //pq의 사이즈가 1이 될 때까지 반복함
    while(pq.size() != 1){
        data1 = pq.top();
        pq.pop();

        data2 = pq.top();
        pq.pop();
        
        res += data1 + data2;
        pq.push(data1 + data2);
    }

    cout << res;
}