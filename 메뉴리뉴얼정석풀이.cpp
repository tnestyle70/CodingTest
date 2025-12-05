#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

void makeCombination(const string& iMenu, int iIndex, int iMenuSize, string& sCur, unordered_map<string,int>& umapCourseMenu)
{
    if ((int)sCur.size() == iMenuSize)
    {
        //메뉴 사이즈만큼 sCur를 다 채웠을 경우 return;
        umapCourseMenu[sCur]++; 
        return; 
    }
    for (int i = iIndex; i < (int)iMenu.size(); ++i)
    {
        sCur.push_back(iMenu[i]); 
        makeCombination(iMenu, i + 1, iMenuSize, sCur ,umapCourseMenu);
        sCur.pop_back(); 
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {

    //메뉴 정렬 
    for (string& sMenu : orders)
    {
        sort(sMenu.begin(), sMenu.end()); 
    }

    vector<string> answer;
    for (int iMenuSize : course)
    {
        unordered_map<string, int> umapCourseMenu;
        int iMaxCount(0); 

        //모든 주문에서 길이 r짜리 조합 생성
        for (const string& sOrder : orders)
        {
            if ((int)sOrder.size() < iMenuSize) continue; //길이가 더 짧다면 continue; 

            string sCur; 
            makeCombination(sOrder, 0, iMenuSize, sCur, umapCourseMenu); 
        }
        //최소 2번 이상 나온 값 중에서 최댓값 찾기 
        for (auto courseMenu : umapCourseMenu)
        {
            if (courseMenu.second)
            {
                if (iMaxCount < courseMenu.second)
                {
                    iMaxCount = courseMenu.second; 
                }
            }
        }
        if (iMaxCount < 2) continue; //후보 존재하지 않음 
        
        for (auto CourseMenu : umapCourseMenu)
        {
            if (CourseMenu.second == iMaxCount)
            {
                answer.push_back(CourseMenu.first);
            }
        }
    }
    sort(answer.begin(), answer.end()); 
    return answer;
}