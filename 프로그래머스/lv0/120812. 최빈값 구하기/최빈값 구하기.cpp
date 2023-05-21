#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    vector<int> arr2(1001);
    int max=0; // 배열 값에 대한 카운트
    int max_index=0; // 그 때의 index
    int count; // 최빈값이 여러개인지 카운트
    
    // 배열값을 index로 받고 +1 해줌
    for(int i=0; i<array.size(); i++){
        arr2[array[i]]++;
    }
    
    for(int i=0; i<arr2.size(); i++){
        if(arr2[i]>max){
            max = arr2[i]; // 최댓값을 구함
            max_index = i;
        }
    }
    
    // 최빈값이 여러개 있는 경우 count+1
    for(int i=0; i<arr2.size(); i++){
        if(arr2[i] == max)
            count++;
    }
    if(count > 1)
        return -1;
    
    answer = max_index;
    return answer;
}