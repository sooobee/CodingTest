#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> string_idx;
int _sort;

bool cmp(vector<int>& v1, vector<int>& v2){
    return v1[_sort] < v2[_sort];
}
// 데이터, 기준이 되는 값, 그 값의 인덱스
// data에서 조건 만족하는 데이터 추출(조건 : ext < val_ext)
vector<vector<int>> extract(vector<vector<int>> data, int val_ext, int ext_index){
    vector<vector<int>> result;

    for(int i=0; i < data.size(); i++){

        if(data[i][ext_index] < val_ext)
            result.push_back(data[i]);
    }
    return result;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    string_idx["code"] = 0;
    string_idx["date"] = 1;
    string_idx["maximum"] = 2;
    string_idx["remain"] = 3;

    answer = extract(data, val_ext, string_idx[ext]);
    
    _sort = string_idx[sort_by];
    // sort_by 기준 오름차순 정렬
    sort(answer.begin(), answer.end(), cmp);

    return answer;
}
