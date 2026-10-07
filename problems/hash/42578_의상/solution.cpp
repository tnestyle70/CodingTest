#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// [해시 4/5] 의상 — AC 2026-07-27 (정확성 100/100, 28/28)
// 제출 당시 코드 그대로 보존 (사후 미화 금지).
// 공식 (개수+1) 곱 − 1은 사용자 자가 유도, +1 누락 버그도 자가 발견 후 수정.

int solution(vector<vector<string>> clothes) {

    unordered_map<string, int> mapClothes;

    for(auto& cloth : clothes)
    {
        mapClothes[cloth[1]]++;
    }

    int answer = 1;

    for(auto& [key, value] : mapClothes)
    {
        answer *= (value + 1);
    }

    return answer - 1;
}
