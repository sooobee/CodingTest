#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string arr[20001];

int compare(string a, string b){
    
    // 길이가 같은 경우 사전 순 정렬
    if(a.length() == b.length())
        return a < b;
    
    // 길이가 다른 경우 길이 순으로
    else
        return a.length() < b.length();
}

int main(int argc, const char * argv[]){
    int N;
    cin >> N;
    
    // 값 입력
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    // 사전 순 정렬
    sort(arr, arr + N, compare);
    
    // 길이 비교 정렬
    for(int i=0; i<N; i++){
        
        // 같을 경우 출력 안함
        if(arr[i] == arr[i-1])
            continue;
        
        cout << arr[i] << endl;
        
    }
    
}
