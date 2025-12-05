#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {

    //장르 + 노래 번호, 재생 횟수(최대 2개) 저장할 map container 생성 
    map<string, vector<pair<int, int>>> mapGenreSong;
    map<string, int> mapTotal;
    vector<string> vecGenres;
    for (size_t i = 0; i < genres.size(); ++i)
    {
        mapGenreSong[genres[i]].emplace_back(i, plays[i]);
        //장르별 실행 횟수 누적 
        mapTotal[genres[i]] += plays[i]; 

        //해당 장르가 이전에 존재했다면 break; 아니면 push해주기
        bool bExist = false; 
        for (auto genre : vecGenres)
        {
            //해당 장르가 이전에 존재했었다면 emplace_back
            if (genre == genres[i])
            {
                bExist = true; 
                break; 
            }
        }
        if (!bExist)
        {
            vecGenres.push_back(genres[i]);
        }
    }
    //장르별 재생수 많은 수대로 정렬
    sort(vecGenres.begin(), vecGenres.end(),
        [&](const string& a, const string& b)
        {
            return mapTotal[a] > mapTotal[b];
        });

    //재생수대로 정렬된 vecGenres를 가지고 재생수 많은 순서대로 노래별 재생수대로 정렬
    for (size_t i = 0; i < vecGenres.size(); ++i)
    {
        vector<pair<int, int>>& vecSong = mapGenreSong[vecGenres[i]]; 
        //재생수 내림차순, 같으면 index 오름차순으로 정렬 
        //여기서 자동으로 다음 것을 추출하는 건가?
        sort(vecSong.begin(), vecSong.end(),
            [](const pair<int, int>& a, const pair<int, int>& b)
            {
                //a, b가 같을 경우 재생수 내림차순 정렬
                if (a.second != b.second)
                    return a.second > b.second; //재생수 내림차순 
                return a.first < b.first;
            }); 
    }
    vector<int> answer;

    for (const auto& genre : vecGenres)
    {
        const auto& vecSong = mapGenreSong[genre]; 
        //1등곡
        if (!vecSong.empty())
        {
            answer.push_back(vecSong[0].first); 
        }
        //2등곡
        if (vecSong.size() > 1)
        {
            answer.push_back(vecSong[1].first);
        }
    }

    return answer;
}