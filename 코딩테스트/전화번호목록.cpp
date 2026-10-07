#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

//한 문장 목표 고정 - phone_book의 어떤 번호가 다른 번호의 접두사인 경우가 있을 경우 false,  없을 경우 true를 return한다. 

//제약 어휘 표시 - phone_book 길이 1이상 1,000,000dlgk, 전화 번호의 길이 1이상 20이하. 같은 전화번호가 중복해서 들어있지 않다. 

//예산 서술 - 10^6  * 10^6 = 10^12, 10^12 / 10^8 = 10^4. 10,000초로 초과하기 때문에 hash O(1)비교로 끝낼 수 있는 방법을 찾아야 한다. 
//아 설마 하나씩 뽑으면서 set에 넣는다? <- 이거다, 이게 한 번도 떠오르지 않았던 아이디어!!! 그러니까 phone_book의 숫자를 하나씩 뽑아서 set에 넣은 다음에 map? map인가? 그게 겹치는 게 있으면 map의 카운트를 증가 시키는 건가? 아이디어 자체는 숫자를 세로로 쌓았을 때 기준으로 잘라서 넣는 건데.. 
//set에 넣는거 <- 이게 정렬이다. sort로 정렬을 하는 게 아니라 set으로 정렬을 하는 것이다. 확인했음.
//트리 계열(map/set) : 트리 구조 red black tree 내부 정렬 O(n log n), 해시 계열(unordered_map, unordered_set) : 해시 구조, 
//내부 O(1). 최악은 cluster로 O(N). 

//병목 -> 유형선택 - 이중 for문을 돌면 10^12 n * (n-1) = n^2으로 시간 복잡도에서 터지기 때문에, 다른 방법을 고려해야 한다. 핵심 질문은 어떻게 문자열의 비교를 O(N)선에서 끝내게 할 것이냐 인데, while? 

//선서술 - A가 B의 접두사이고, 정렬에서 A < C < B인  C가 끼어있다면 C는 A로 시작할 수 밖에 없음. A가 어떤 번호의 접두사라면 정렬 후 AI의 바로 다음 원소도 A로 시작한다. 
//왼쪽을 그냥 오른쪽만 비교하면 된다. 어차피 사전순이니까. <- 사전순인 이유. 정렬 n log n + 왼쪽과 오른쪽의 비교 연산 n - 1. 그러면 그냥 set에 넣을 필요도 없이, vector 정렬하고, for문 돌면서 index + 1 sstream 내가 계속 알려달라고하는 API로 비교만 하면 n log n + (n - 1)로 끝나는 거 아님? 

using namespace std;

bool solution(vector<string> phone_book) {

    //사전순으로 정렬 - O(n log n) 연산
    sort(phone_book.begin(), phone_book.end());

    //왼쪽과 오른쪽만 비교 O(N - 1) 연산
    int N = phone_book.size();

    bool answer = true;

    for (int i = 0; i < N - 1; ++i)
    {
        //compare API
        string right = phone_book[i + 1];

        if (!right.compare(0, phone_book[i].size(), phone_book[i]))
        {
            answer = false;
            break;
        }
        //substr API
        //string left = phone_book[i];
        //int leftSize = left.size();

        //string right = phone_book[i + 1];
        //string compareRight = right.substr(0, leftSize);
        ////이 right를 sstream으로 leftSize만큼 문자열을 비교한다.
        //if (left == compareRight)
        //{
        //    answer = false;
        //    break;
        //}
    }

    return answer;
}

// --------------- 로컬 테스트 (프로그래머스 예제 3개 + Edge는 직접 추가) ---------------
int main() {
    struct TC { vector<string> book; bool expected; };
    vector<TC> tcs = {
        {{"119", "97674223", "1195524421"}, false},
        {{"123", "456", "789"}, true},
        {{"12", "123", "1235", "567", "88"}, false},
        // Edge 게이트: 여기에 직접 만든 반례를 최소 2개 추가할 것 (기대값은 손으로 계산)
    };
    for (int i = 0; i < (int)tcs.size(); i++) {
        bool got = solution(tcs[i].book);
        cout << "TC" << i + 1 << ": " << (got == tcs[i].expected ? "PASS" : "FAIL")
             << "  (got: " << (got ? "true" : "false")
             << ", expected: " << (tcs[i].expected ? "true" : "false") << ")\n";
    }
    return 0;
}























