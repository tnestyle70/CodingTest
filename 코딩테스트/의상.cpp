#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// ============================================================
// [해시 4/5] 의상 (Level 2)
// https://school.programmers.co.kr/learn/courses/30/lessons/42578
//
// 코니는 매일 다른 옷 조합으로 외출한다. 가진 의상들이
// [의상 이름, 의상 종류] 쌍으로 주어질 때, 서로 다른 옷 조합의
// 수를 반환. 최소 한 개의 의상은 입는다. 같은 종류는 하루에
// 최대 1개만 착용 가능.
//
// 제약:
//  - clothes 길이: 1 ~ 30
//  - 원소 = [이름, 종류], 알파벳 소문자와 '_'만
//  - 같은 이름의 의상은 존재하지 않는다
// ============================================================

//한 문장 목표 - 서로 다른 옷의 조합 수를 return해야 한다. 

//제약 어휘 표시 - 최소 한 개의 의상은 입어야 한다. 종류 별로 최대 1가지만 착용 가능하다. 같은 의상은 존재하지 않는다. 

//예산 산술 - unordered_map에 삽입, 탐색 O(1) 평균

//완전탐색 기준선 - 4중 for문을 사용해서 O(N^4)로 돈다. 

//병목 -> 유형 선택 - unordered_map에 key value로 종류와 개수를 저장하고, for문을 돌면서 value 곱셈으로 answer 구하기

//선서술 - unordered_map으로, 평균 O(1)으로 kind - value를 매칭 시키고, 그냥 직관적으로 조합 계산 맞나? 정확한 수식으로 도출은 못하겠는데 0 포함 곱셈으로 돌려서 3 * 2 - 1 = 5. 종류 3개에 value 1개면 2^3 - 1 = 7.  이렇게 계산 clothes 파싱 후 
//unordered_map에 넣은 다음에, 도출한 수식으로 계산

//Edge - 의상 딱 1벌 - 경우의 수 1. 한 종류에 전부 몰빵 - 30, 모든 종류 1벌씩 - 2^30 - 1

using namespace std;

int solution(vector<vector<string>> clothes) {

    unordered_map<string, int> mapClothes;

    for (auto& cloth : clothes)
    {
        mapClothes[cloth[1]]++;
    }

    int answer = 1;

    for (auto& [key, value] : mapClothes)
    {
        answer *= value + 1;
    }

    return answer - 1;
}

// --------------- 로컬 테스트 (프로그래머스 예제 2개 + Edge는 직접 추가) ---------------
int main() {
    struct TC { vector<vector<string>> clothes; int expected; };
    vector<TC> tcs = {
        {{{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}}, 5},
        {{{"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"}}, 3},
        // Edge 게이트: 직접 만든 반례 최소 2개 (기대값 손 계산) — 없으면 제출 불허
    };
    for (int i = 0; i < (int)tcs.size(); i++) {
        int got = solution(tcs[i].clothes);
        cout << "TC" << i + 1 << ": " << (got == tcs[i].expected ? "PASS" : "FAIL")
             << "  (got: " << got << ", expected: " << tcs[i].expected << ")\n";
    }
    return 0;
}
