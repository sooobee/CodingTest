#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = -1;
    
    int mok = num1/num2; // 몫
    answer = num1-num2*mok;
    return answer;
}