#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <map>
using namespace std;

long long polynominal_hash(string& sString)
{
    int iPrime = 31; 
    long long llModulus = 100000007; 
    long long llHashValue = 0; 
    for (string::iterator it = sString.begin(); it != sString.end(); ++it)
    {
        char cCh = *it; 

        llHashValue = (llHashValue * iPrime + cCh) % llModulus; 
    }
    return llHashValue; 
}

vector<string> solution(vector<string> record) {

    vector<string> vecCommand; //명령어 
    vector<string> vecId; //ID
    vector<string> vecName; //Name

    vecCommand.resize(record.size()); 
    vecId.resize(record.size());
    vecName.resize(record.size());

    int iIndex = 0;

    for (vector<string>::iterator it = record.begin(); it != record.end(); ++it)
    {
        string sRecord = *it; 

        string sTemp;

        int iBreakIndex = 0;

        int iTempIndex = 0;

        for (char cCh : sRecord) //기록된 값에서 cCh를 분리해서 '\0' 공백을 기준으로 명령어 컨테이너를 구분한다.
        {
            if (cCh == ' ') //공백 문자를 만났을 경우 breakIndex의 값에 따라서 다른 vector<string> container에 value를 넣어준다. 
            {
                if (iBreakIndex == 0) //commnad 문자 - enter, leave, change
                {
                    vecCommand[iIndex] = sTemp;
                    sTemp = ""; 
                }
                else if (iBreakIndex == 1) //id 
                {
                    vecId[iIndex] = sTemp;
                    sTemp = "";
                }
                else if (iBreakIndex == 2)//name
                {
                    vecName[iIndex] = sTemp;
                    sTemp = "";
                }
                iBreakIndex++;
                continue;
            }
            sTemp.push_back(cCh);
            iTempIndex++; 
        }
        if (!sTemp.empty()) //Name 대입
        {
            if (iBreakIndex == 0) vecCommand[iIndex] = sTemp;
            else if (iBreakIndex == 1) vecId[iIndex] = sTemp;
            else if (iBreakIndex == 2) vecName[iIndex] = sTemp;
        }
        iIndex++;
    }
    multimap<string, string> mmIdName;
    //Id와 Name을 저장하는 부분과 전체 이름과 아이디 명령어를 저장하는 vector를 분리해서 생각을 한다.
    for (size_t i = 0; i < record.size(); ++i)
    {
        if (vecCommand[i] == "Leave") //Leave일 경우에는 vecName인덱스가 비어져있기 때문에 continue; 
        {
            continue; 
        }
        mmIdName.insert({ vecId[i], vecName[i] }); //중복을 허용하는 multimap에 id와 이름을 insert해준다. 
    }
    //change Enter 명령어가 나왔을 경우 Id의 이름들 전부 다 vecName[i]로 변경 
    for (size_t i = 0; i < vecCommand.size(); ++i)
    {
        auto Range = mmIdName.equal_range(vecId[i]); //해당 아이디의 모든 이름 찾아서 해당 이름으로 변경 

        if (vecCommand[i] == "Change" || vecCommand[i] == "Enter") //Change 명령어가 나왔을 경우 
        {
            if (Range.first == Range.second)
            {
                // 이 uid가 처음 등장한 경우 → 새로 추가
                mmIdName.insert({ vecId[i], vecName[i]});
            }
            else
            {
                for (auto it = Range.first; it != Range.second; ++it)
                {
                    it->second = vecName[i]; //모든 id들의 이름을 vecName[i]로 변경 
                }
            }
        }
    }
    //Change enter에 따라서 변경된 Id, Name 쌍을 통해서 Command에 따른 Result 대입 
    vector<string> answer;
    answer.reserve(record.size());
    for (size_t i = 0; i < vecCommand.size(); ++i)
    {
        if (vecCommand[i] == "Enter")
        {
            auto it = mmIdName.find(vecId[i]);

            if (it != mmIdName.end())
            {
                answer.push_back(it->second + "님이 들어왔습니다.");
                iIndex++; 
            }
        }
        else if (vecCommand[i] == "Leave")
        {
            auto it = mmIdName.find(vecId[i]);

            if (it != mmIdName.end())
            {
                answer.push_back(it->second + "님이 나갔습니다.");
                iIndex++;
            }
        }
    }
    return answer;
}

