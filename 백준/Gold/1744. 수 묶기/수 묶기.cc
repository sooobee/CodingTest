#include<iostream>
#include<queue>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    priority_queue<int> plusPq; // 양수는 내림차순 정렬
    priority_queue<int, vector<int>, greater<int>> minusPq; // 음수는 오름차순 정렬(곱하면 양수가 되니까 가장 작은 수끼리 곱하면 가장 큰 양수 됨)
    int zero = 0;
    int one = 0;
    int sum = 0;

    for(int i = 0; i < n; i++){
        int num;

        cin >> num;

        if(num == 0) zero++;
        else if(num == 1) one++;
        else if(num < 0) minusPq.push(num);
        else plusPq.push(num);
    }

    // 양수 일 때
    // 가장 큰 것들을 먼저 짝을 지어 더함
    while(plusPq.size() > 1){
        int data1 = plusPq.top();
        plusPq.pop();

        int data2 = plusPq.top();
        plusPq.pop();

        sum = sum + data1 * data2;
    }

    if(!plusPq.empty()) sum += plusPq.top();

    // 음수일 때
    // 짝 지을 수 있는 만큼 지어서 양수로 만듬
    while(minusPq.size() > 1){
        int data1 = minusPq.top();
        minusPq.pop();

        int data2 = minusPq.top();
        minusPq.pop();

        sum = sum + data1 * data2;
    }

    if(!minusPq.empty()){
        // 음수가 하나거나 홀수일때 0이 있는 경우 그 수는 더해주지 않음
        // 음수가 없을 때는 그 수를 더해줌
        if(zero == 0) sum = sum + minusPq.top();
    }

    // 1 처리
    // 1은 다른 수와 곱하면 그 수에 흡수되기 때문에 더해주는 게 가장 큰 결과를 만듬
    sum += one;

    cout << sum;
}