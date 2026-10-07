#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// [해시 3/5] 전화번호 목록 — AC 2026-07-26 (정확성 20/20 + 효율성 4/4, 최대 46.5ms)
// 제출 당시 코드 그대로 보존 (사후 미화 금지). right가 매 반복 복사되는 비효율 잔존 —
// 실측 46.5ms로 통과했으므로 그대로 둔다. 참조(auto&)로 바꾸는 개선은 Reviewed에서 비교.

bool solution(vector<string> phone_book) {

    //사전순으로 정렬 - O(n log n) 연산
    sort(phone_book.begin(), phone_book.end());

    //왼쪽과 오른쪽만 비교 O(N - 1) 연산
    int N = phone_book.size();

    bool answer = true;

    for (int i = 0; i < N - 1; ++i)
    {
        string right = phone_book[i + 1];

        if (!right.compare(0, phone_book[i].size(), phone_book[i]))
        {
            answer = false;
            break;
        }
    }

    return answer;
}
