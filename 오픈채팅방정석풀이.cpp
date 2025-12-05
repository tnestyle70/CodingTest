#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
	map<string, string> mIdName; //id랑 이름만 저장해두는 공간 
	vector<pair<string, string>> vecLogs; //출력용 command, id 모아두는 공간
	vector<string> answer;

	for (vector<string>::iterator it = record.begin(); it != record.end(); ++it)
	{
		string sRecord = *it; 

		stringstream ss(sRecord); 

		string sCommand, sId, sName; 

		ss >> sCommand >> sId; 

		if (sCommand == "Enter") //들어왔을 경우에 명령어 이름 아이디 다 저장 
		{
			ss >> sName; 
			mIdName[sId] = sName;
			vecLogs.push_back({ sCommand, sId }); 
		}
		else if (sCommand == "Leave") //나갔을 경우에는 명령어랑 id만 push해서 나중에 출력
		{
			vecLogs.push_back({ sCommand, sId });
		}
		else if (sCommand == "Change") //change일 경우 로그는 찍히지 않으므로 이름이랑 아아디만 저장 
		{
			ss >> sName;
			mIdName[sId] = sName;
		}

		for (auto log : vecLogs)
		{
			string sCommand = log.first; 
			string sId = log.second; 
			string sName = mIdName[sId]; 

			if (sCommand == "Enter")
			{
				answer.push_back(sName + "님이 들어왔습니다.");
			}
			else if (sCommand == "Leave")
			{
				answer.push_back(sName + "님이 나갔습니다."); 
			}
		}
	}
	return answer; 
}