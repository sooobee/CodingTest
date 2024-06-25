#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    int arr[502][502];
    int big = 0;
    cin >> n; 


    for(int index=1; index<=n; index++){
        for(int j=1; j<=index; j++){
            int temp;
            cin >> temp;

            // 초기화
            if(index == 1) {
                arr[index][j] = temp;
                big = temp;
                continue;
            }

            // 부모 중 큰 것과 자신을 합한 값
            // 부모가 하나밖에 없는 노드는 그것만 더해줌
            if(j == 1) 
                arr[index][j] = arr[index-1][1] + temp;
            else if(j == index) 
                arr[index][j] = arr[index-1][j-1] + temp;
            else 
                arr[index][j] = max(arr[index-1][j-1], arr[index-1][j])+temp;

            if(arr[index][j] > big) 
                big = arr[index][j];
        }
    }

    cout << big;
}