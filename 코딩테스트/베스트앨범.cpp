#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map> 
#include <algorithm>
using namespace std;

// ============================================================
// [해시 5/5] 베스트앨범 (Level 3 — 해시 최종 보스)
// https://school.programmers.co.kr/learn/courses/30/lessons/42579
//
// 노래 i의 장르 = genres[i], 재생 횟수 = plays[i] (i = 고유번호).
// 베스트 앨범 수록 규칙:
//  1. 속한 노래가 많이 재생된 장르를 먼저 수록한다.
//  2. 장르 내에서는 많이 재생된 노래를 먼저 수록한다.
//  3. 장르 내 재생 횟수가 같으면 고유번호가 낮은 노래를 먼저.
// 장르별로 최대 2곡. 수록 순서대로 고유번호 배열을 반환.
//
// 제약 (문제 페이지에서 확인된 것):
//  - genres/plays 길이 같음, 1 ~ 10,000
//  - 장르 종류 < 100
//  - 장르에 속한 곡이 1개면 1곡만 선택
//  - 모든 장르의 총 재생 횟수는 서로 다르다
//  - 재생 횟수의 값 범위: 문제 페이지에서 직접 추출할 것
//    (값의 범위 vs 개수 훈련 — 총합의 오버플로 판정에 필요)
// ============================================================
// 
//한 문장 목표 고정 - 가장 많이 재생된 장르로 나열 -> 가장 많이 재생된 노래 2개 고유 번호 순서 및 장르 순서로 vector에 담아 return

//제약 어휘 표시 - geners와 play의 길이는 같으며 1~10,000이다. 장르의 종류는 100개 미만이다. 

//예산 산술 - O(20,000) genres, plays에서 for문을 돌면서, unordered_map에 장르 key, value로 pair<int, int> 고유 번호와 play 횟수 평균 O(1)로 삽입 -> 장르별로 정렬한 이후에 

//완전탐색 기준선 - 

//병목 -> 유형 선택 - "어떤 질문의 답을 선불하면 이 병목이 사라지나?"

//선서술 - 한 문장 목표 + 문제의 불변식 

//plays의 play수에 따른 고유 번호를 plays를 통해서 알 수 있다. 
//핵심 질문 - 어떻게 장르 별로 plays를 묶을 수 있을까? 
//key - genres, value - pair<int, int> 고유번호, 재생횟수로 묶기. 
//compare를 사용해서 total plays 순으로 나열. 이후 고유 번호 순으로 나열 

//한 문장 목표 고정 - 가장 많이 재생된 장르로 나열 -> 가장 많이 재생된 노래 2개 고유 번호 순서 및 장르 순서로 vector에 담아 return

//제약 어휘 표시 - geners와 play의 길이는 같으며 1~10,000이다. 장르의 종류는 100개 미만이다. 

//예산 산술 - O(20,000) genres, plays에서 for문을 돌면서, unordered_map에 장르 key, value로 pair<int, int> 고유 번호와 play 횟수 평균 O(1)로 삽입 -> 장르별로 정렬한 이후에 

//완전탐색 기준선 - 

//병목 -> 유형 선택 - "어떤 질문의 답을 선불하면 이 병목이 사라지나?"

//선서술 - 한 문장 목표 + 문제의 불변식 

//plays의 play수에 따른 고유 번호를 plays를 통해서 알 수 있다. 
//핵심 질문 - 어떻게 장르 별로 plays를 묶을 수 있을까? 
//key - genres, value - pair<int, int> 고유번호, 재생횟수로 묶기. 
//compare를 사용해서 total plays 순으로 나열. 이후 고유 번호 순으로 나열 

//예제풀이 - 장르별 {고유번호, plays} 묶음. 많이 재생된 장르 순서대로 나열. 장르 내부 재생 횟수 대로 나열. 장르별 2곡 씩 고유번호 answer에 담아서 return

bool CompareTotal(pair<string, int>& a, pair<string, int>& b)
{
    //모든 장르는 재생된 횟수가 다르다는 조건이 있기 때문에 조건문 비교 안 해도 상관 없음
    //재생 횟수 기준으로 내림차순으로 정렬 - 로직을 풀어서 쓰면 a와 b가 있을 때, b.second가 더 클 경우에 정렬을 한다. 
    //정렬이라는 뜻은 a b 0 1 순서대로 있으면 위치를 바꾼다는 뜻이다. a - 0, b - 1 순서 고정이고, b가 더 크면 자리 바꾸기
    //반대 조건이면 a가 더 크면 자리 바꾸기로 오름차순으로 정렬되는 방식이다. 
    return a.second > b.second;
}

bool CompareGenres(pair<int, int>& a, pair<int, int>& b)
{
    //재생 횟수가 같을 경우 고유 번호 오름차순으로 나열
    if (a.second == b.second)
    {
        //a가 더 클 경우 순서 바꾸기. a - 0, b - 1 이 순서에서 크기 비교해서 a가 더 크면 b와 자리 바꾸는 로직이다. 
        return a.first > b.first;
    }
    //재생 횟수가 다를 경우 재생 횟수 내림차순으로 나열
    else
    {
        // < 작은 게 오른쪽으로, 즉 왼쪽으로 큰 값을 나열한다. 
        return a.second > b.second;
    }
}

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    //genres별 total을 어떻게 담을 수 있을까? 
    //장르별로 최대값을 비교해야 하고, 장르 내부에서 최대 play횟수를 찾아야 한다. 
    //unordered_map<string, tuple<int, int, int>> mapGenres; 
    unordered_map<string, vector<pair<int, int>>> mapGenres;

    int N = genres.size();

    for (int i = 0; i < N; ++i)
    {
        mapGenres[genres[i]].push_back({ i, plays[i] });
    }

    //많이 재생된 순서에 따른 map 컨테이너를 하나 더 만든 다음에 그것을 가지고 mapGneres에 활용을 한다. 
    vector<pair<string, int>> totalGenres;

    for (auto& [key, value] : mapGenres)
    {
        int totalPlays = 0;
        for (auto& numPlays : value)
        {
            totalPlays += numPlays.second;
        }
        totalGenres.push_back({ key, totalPlays });
    }

    //compare가 두 개 있어야 한다. total용, mapGenres용
    sort(totalGenres.begin(), totalGenres.end(), CompareTotal);

    for (auto& [key, value] : totalGenres)
    {
        sort(mapGenres[key].begin(), mapGenres[key].end(), CompareGenres);
    }

    vector<int> answer;
    //재생횟수 순서대로 정렬된 장르 기준, 재생 횟수와 고유 번호 순서대로 이미 나열된 mapGenres에서 상위 2개 고유 번호 answer에 push_back 
    for (auto& [key, value] : totalGenres)
    {
        if (mapGenres[key].size() == 1)
        {
            answer.push_back(mapGenres[key][0].first);
        }
        else
        {
            for (int i = 0; i < 2; ++i)
            {
                answer.push_back((mapGenres[key])[i].first);
            }
        }
    }

    return answer;
}

// --------------- 로컬 테스트 (프로그래머스 예제 1개 + Edge는 직접 추가) ---------------
int main() {
    struct TC { vector<string> genres; vector<int> plays; vector<int> expected; };
    vector<TC> tcs = {
        {{"classic", "pop", "classic", "classic", "pop"}, {500, 600, 150, 800, 2500}, {4, 1, 3, 0}},
        // Edge: 직접 만든 반례 (예: 장르 1개뿐, 곡 1개뿐인 장르, 재생수 동률 → 고유번호 순)
    };
    auto vecToStr = [](const vector<int>& v) {
        string s = "[";
        for (int i = 0; i < (int)v.size(); i++) { if (i) s += ","; s += to_string(v[i]); }
        return s + "]";
        };
    for (int i = 0; i < (int)tcs.size(); i++) {
        vector<int> got = solution(tcs[i].genres, tcs[i].plays);
        cout << "TC" << i + 1 << ": " << (got == tcs[i].expected ? "PASS" : "FAIL")
            << "  (got: " << vecToStr(got) << ", expected: " << vecToStr(tcs[i].expected) << ")\n";
    }
    return 0;
}
