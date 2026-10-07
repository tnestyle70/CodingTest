#include <vector>
#include <set>
#include <iostream>
using namespace std;

// ============================================================
// [해시 2/5] 폰켓몬 (Level 1)
// https://school.programmers.co.kr/learn/courses/30/lessons/1845
//
// N마리 폰켓몬 중 N/2마리를 선택한다. 최대한 다양한 종류의
// 폰켓몬을 선택하는 방법을 찾아, 그때의 종류 개수를 반환.
//
// 제약:
//  - nums 길이 N: 1 ~ 10,000, N은 항상 짝수
//  - 폰켓몬 종류 번호: 1 ~ 200,000
// ============================================================

//한 문장 목표 고정 - N중에서 안 겹치는 숫자 N/2만큼 추려서, 안 겹치는 숫자 개수 return
//제약 어휘 - 1~200,000
//예산 산술 - 200,000 nlogn?
//완전 탐색 기준선 - 모르겠음.
//병목 - 중복 숫자 제거
//선서술 - 중복 숫자 제거하고 그 숫자가 N/2보다 크면 N/2 return, 작거나 같으면 그 숫자 return, set 중복 없이 저장하는 자료구조 사용해서 저장!
//<- 아니 진짜 이렇게 적으니까 확실히 쉬운 것 같은데 ㅋㅋㅋ
//수도 코드니 뭐니 적었는데 이렇게 적으니까 진짜 좋다.

int solution(vector<int> nums)
{
    int N = nums.size();

    set<int> kinds;

    for (auto& kind : nums)
    {
        kinds.insert(kind);
    }

    int answer = 0;
    if (kinds.size() > (N / 2))
    {
        answer = (N / 2);
    }
    else
    {
        answer = kinds.size();
    }

    return answer;
}

// --------------- 로컬 테스트 (프로그래머스 예제 3개) ---------------
int main() {
    struct TC { vector<int> nums; int expected; };
    vector<TC> tcs = {
        {{3, 1, 2, 3}, 2},
        {{3, 3, 3, 2, 2, 4}, 3},
        {{3, 3, 3, 2, 2, 2}, 2},
    };
    for (int i = 0; i < (int)tcs.size(); i++) {
        int got = solution(tcs[i].nums);
        cout << "TC" << i + 1 << ": " << (got == tcs[i].expected ? "PASS" : "FAIL")
             << "  (got: " << got << ", expected: " << tcs[i].expected << ")\n";
    }
    return 0;
}
