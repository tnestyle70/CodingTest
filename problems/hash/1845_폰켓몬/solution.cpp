#include <vector>
#include <set>
using namespace std;

// [해시 2/5] 폰켓몬 — AC 2026-07-26 (정확성 100/100, 테스트 20/20, 최대 0.87ms)
// 제출 당시 코드 그대로 보존 (사후 미화 금지). C4267 부호 변환 경고 2건 포함 상태로 제출됨.

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
