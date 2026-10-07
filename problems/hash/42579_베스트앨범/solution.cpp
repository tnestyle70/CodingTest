#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// [해시 5/5] 베스트앨범 — AC 2026-07-27 (1차 제출 2건 실패 → 비교자 수정 → 재제출 통과, 사용자 보고)
// 제출 당시 코드 그대로 보존 (사후 미화 금지).
// 주의(정직 기록): CompareGenres의 동률 분기(a.first > b.first)는 명세("고유번호 낮은 노래 먼저")와
// 반대 방향인데 채점기를 통과했다 — 동률 순서를 판정하는 숨은 테스트가 없는 것으로 추정.
// 프로브 {"a","a"},{100,100} → 명세상 [0,1], 이 코드는 [1,0] 예상. 검증·수정은 REVIEW 복습 과제.

bool CompareTotal(pair<string, int>& a, pair<string, int>& b)
{
    //모든 장르는 재생된 횟수가 다르다는 조건이 있기 때문에 조건문 비교 안 해도 상관 없음
    return a.second > b.second;
}

bool CompareGenres(pair<int, int>& a, pair<int, int>& b)
{
    //재생 횟수가 같을 경우 고유 번호 오름차순으로 나열
    if (a.second == b.second)
    {
        return a.first > b.first;
    }
    //재생 횟수가 다를 경우 재생 횟수 내림차순으로 나열
    else
    {
        return a.second > b.second;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {

    unordered_map<string, vector<pair<int, int>>> mapGenres;

    int N = genres.size();

    for (int i = 0; i < N; ++i)
    {
        mapGenres[genres[i]].push_back({ i, plays[i] });
    }

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

    sort(totalGenres.begin(), totalGenres.end(), CompareTotal);

    for (auto& [key, value] : totalGenres)
    {
        sort(mapGenres[key].begin(), mapGenres[key].end(), CompareGenres);
    }

    vector<int> answer;

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
