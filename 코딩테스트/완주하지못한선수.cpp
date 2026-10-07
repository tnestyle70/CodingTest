#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// ============================================================
// [해시 1/5] 완주하지 못한 선수 (Level 1)
// https://school.programmers.co.kr/learn/courses/30/lessons/42576
//
// 마라톤 참가자(participant) 중 단 한 명이 완주하지 못했다.
// 완주자 명단(completion)이 주어질 때, 완주하지 못한 선수의 이름을 반환.
//
// 제약:
//  - participant 길이: 1 ~ 100,000
//  - completion 길이 = participant 길이 - 1
//  - 동명이인이 있을 수 있다  ← 핵심!
// ============================================================

//무엇을 반환하는가? 완주하지 못한 선수의 이름
//제약 어휘 표시 
//예산 산술 - 1~100,000 
//완전탐색 기준선 - participant 기준으로 선수들의 이름을 하나하나 대조하면서 비교한다. 
//병목 -> 유형 선택 - 선수들의 이름과 나온 횟수를 미리 자료구조 내부에 저장하면 해당 병목이 사라진다. 
//선서술 - map - key value를 가지는 자료구조에 key - 참가자 이름 value에 등장한 횟수를 participant, completion으로 넣어주고, 빼서 남는 이름 하나 찾아서 return한다.

string solution(vector<string> participant, vector<string> completion) {

    unordered_map<string, int> mapParticipant{};

    for (auto& name : participant)
    {
        //이거 컴파일 에러?
        mapParticipant[name]++;
    }

    //뭐 어떻게 비교해야 함? 책 봐야 하나? 개념이라도 읽어야 하나?
    //뭐 봐야 해? 개념 몰라서 그런가? 
    for (auto& name : completion)
    {
        mapParticipant[name]--;
    }
    //participant 중에 1인애 이름 return
    string answer = "";
    for (auto& [key, value] : mapParticipant)
    {
        if (value == 1)
        {
            answer = key;
            break;
        }
    }

    return answer;
}

// --------------- 로컬 테스트 (프로그래머스 예제 3개) ---------------
int main() {
    struct TC { vector<string> p, c; string expected; };
    vector<TC> tcs = {
        {{"leo", "kiki", "eden"}, {"eden", "kiki"}, "leo"},
        {{"marina", "josipa", "nikola", "vinko", "filipi"}, {"josipa", "filipi", "marina", "nikola"}, "vinko"},
        {{"mislav", "stanko", "mislav", "ana"}, {"stanko", "ana", "mislav"}, "mislav"},  // 동명이인 케이스
    };
    for (int i = 0; i < (int)tcs.size(); i++) {
        string got = solution(tcs[i].p, tcs[i].c);
        cout << "TC" << i + 1 << ": " << (got == tcs[i].expected ? "PASS" : "FAIL")
             << "  (got: \"" << got << "\", expected: \"" << tcs[i].expected << "\")\n";
    }
    return 0;
}
