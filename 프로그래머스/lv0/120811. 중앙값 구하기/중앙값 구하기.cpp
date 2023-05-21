#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    int temp; 
    
    for(int i=0; i<array.size(); i++){
        for(int k=i+1; k<array.size(); k++){
            if(array[i] > array[k]){
            temp = array[i];
            array[i] = array[k];
            array[k] = temp;}
        }
    }
    
    // 배열은 0부터 시작하니까 +1 해줄 필요 x
    answer = array[array.size()/2];
    return answer;
}