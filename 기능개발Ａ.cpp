#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	queue<int> qDays; 

	for (int i = 0; i < progresses.size(); ++i) //남은 날짜를 계산해서 그 날짜를 가지고 while문을 돌려서 iCount++를 해서 answer에다가 값을 넣어주는 것이 핵심이다
	{
		int iRemainProgress = 100 - progresses[i]; //남은 퍼센트
		//올림 나눗셈을 활용해서 남은 진행도에 남은 퍼센트에서 1을 뺀 값을 더해준 값을 퍼센트로 나눠줘서 숫자가 오버되는 일이 없도록 한다. 
		int iRemainDay = (iRemainProgress + speeds[i] - 1) / speeds[i]; 
		qDays.push(iRemainDay); //남은 날을 qDays에 push해준다. 
	}
	//남은 날들을 맨 앞부터 계산해서 해당 일을 뒤의 일들과 비교해서 동일하거나 더 작으면 iCount++를 해서 answer에 밀어넣어준다. 
	vector<int> answer;

	while (!qDays.empty())
	{
		int iFront = qDays.front();
		qDays.pop(); 
		int iCount = 1; //같이 배포되는 기능의 개수 

		while (!qDays.empty() && iFront >= qDays.front()) //항상 비어있는지를 먼저 확인하고 front()를 체크해야 한다.
		{
			qDays.pop(); 
			iCount++; 
		}
		answer.push_back(iCount);
	}
	return answer;
}