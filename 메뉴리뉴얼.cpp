#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {

    vector<char> vecOrders; //주문한 메뉴 목록 

    for (string& sOrders : orders) //메뉴 목록 컨테이너 채우기 
    {
        for (char& cOrder : sOrders)
        {
            //기존에 존재하지 않는 메뉴일 경우에만 메뉴 목록에 push
            if (find(vecOrders.begin(), vecOrders.end(), cOrder) == vecOrders.end())
            {
                vecOrders.push_back(cOrder);
            }
        }
    }

    //메뉴 알파벳 순서대로 정렬
    sort(vecOrders.begin(), vecOrders.end());

    vector<string> vecCandidates; //가능한 메뉴 순서쌍 후보  
    //가능한 모든 순서쌍 만들기 
    for (int i = 0; i < vecOrders.size(); ++i)
    {
        for (int k = i + 1; k < vecOrders.size(); ++k)
        {
            string sCandidates;

            sCandidates.push_back(vecOrders[i]);
            sCandidates.push_back(vecOrders[k]);

            vecCandidates.push_back(sCandidates);
        }
    }

    //메뉴 순서쌍과 일치하는 코스 메뉴 mapCourseMenu에 iCount와 함께 대입
    map<string, int> mapCourseMenu;

    //손님 주문 목록과 일치하는 메뉴 순서쌍 후보 추출, 2명 이상의 손님과 일치하면 mapCourseMenu에 넣어줌. 
    for (string& sCandidateMenu : vecCandidates)
    {
        int iCount(0);

        if (find(orders.begin(), orders.end(), sCandidateMenu) != orders.end())
        {
            ++iCount;
        }
        mapCourseMenu.emplace(sCandidateMenu, iCount);
    }
    /*
    //vecCourseMenu를 알파벳 순서대로 정렬
    sort(mapCourseMenu.begin(), mapCourseMenu.end(),
        [](const pair<string, int>& sPrex, const pair<string, int>& sNext)
        {
            return sPrex.first < sNext.first;
        });
    */
    vector<string> answer;
    //course와 일치하는 경우와 2이상인 경우만 answer에 대입
    for (int iIndex : course)
    {
        for (pair<string, int> sCourse : mapCourseMenu)
        {
            if (sCourse.second == iIndex && sCourse.second >= 2)
            {
                answer.push_back(sCourse.first);
            }
        }
    }
    return answer;
}