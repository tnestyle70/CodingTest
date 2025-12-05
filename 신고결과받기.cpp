#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    //유저와 신고한 유저 저장 컨테이너 
    map<string, vector<string>> mapUserReport; 
    //신고 당한 유저의 누적 횟수
    map<string, int> mapReportedUser;
    
    //유저와 신고한 유저 vector<string> 저장, 중복 없이 저장 
    for (const string& name : report)
    {
        istringstream iss(name);

        string sReportUser, sReportedUser; 
        //공백 기준으로 단어 나누기 
        iss >> sReportUser >> sReportedUser;
        //신고한 유저가 이미 신고를 했는지 확인 
        vector<string>& vecReported = mapUserReport[sReportUser]; 
        //유저가 해당 유저를 처음 신고하는 경우에만 카운트 증가 
        //vector<string>의 처음부터 끝까지 sReportedUser가 있는지 쭉 찾고 vecReported end()의 값이 결과라면 존재하지 않는 것이므로 push_back
        if (find(vecReported.begin(), vecReported.end(), sReportedUser) == vecReported.end())
        {
            //참조로 받은 값에 sReportedUser를 push_back한다.
            vecReported.push_back(sReportedUser);
            //신고당한 ID 누적 신고 횟수 증가 
        }
    }

    //신고 당한 유저의 누적 횟수 저장 
    for (pair<string, vector<string>> vecReported : mapUserReport)
    {
        const string& sUser = vecReported.first; 

        vector<string>& vecReportedUser = vecReported.second;   

        for (string sReported : vecReportedUser)
        {
            mapReportedUser[sReported]++; 
        }
    }

    //k번 이상 신고 당하여 정지 당한 ID 저장 
    vector<string> vecBanned;

    for (auto& reported : mapReportedUser)
    {
        if (mapReportedUser[reported.first] >= k)
        {
            vecBanned.push_back(reported.first);
        }
    }

    //각 유저가 몇 개의 메일을 받게 되는지 카운트 
    map<string, int> mapMail;

    for (pair<string, vector<string>> UserReportedUser : mapUserReport)
    {
        const string& sReportUser = UserReportedUser.first; 

        const vector<string>& vecReported = UserReportedUser.second;

        int iReportCount(0);

        for (size_t i = 0; i < vecBanned.size(); ++i)
        {
            if (find(vecReported.begin(), vecReported.end(), vecBanned[i]) != vecReported.end())
            {
                ++iReportCount;
            }
        }
        mapMail[sReportUser] = iReportCount; 
    }

    //mapUserReport와 vecBanned의 값을 비교해서 vector<int> answer에 push해준다. 
    vector<int> answer;

    answer.reserve(id_list.size()); 

    for (string sString  : id_list)
    {
        answer.push_back(mapMail[sString]);
    }
    return answer;
}