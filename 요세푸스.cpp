#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, int k) //전체 사람의 수 n이 주어지고, 건너뛰어서 없앨 사람의 인덱스를 정하는 k가 주어진다. 
{
	queue<int> qQueue; //n개 사이즈의 queue를 초기화

	for (int i = 0; i < n; ++i)
	{
		qQueue.push(i + 1); //qQueue에 i + 1 을 n개만큼 초기화를 시킨다. 
	}
	//queue를 기준으로 시계 방향으로 k번째에 있는 사람을 인덱스에서 팝해야 한다. 
	//인덱스를 기준으로 k로 나눴을 때 1이 되는 지점만
	while (qQueue.size() > 1) //1명이 남을 때까지 반복을 해야 한다. k를 기준으로
	{
		for (int i = 0; i < k; ++i) //n까지 반복문을 돌리는데 인덱스에 해당하는 n이 k와 동일할 경우에만 해당 부분을 팝 시킨다. 
		{
			if (i + 1 == k)//인덱스가 k와 동일할 경우에만 큐에서 pop을 해준다.
			{
				qQueue.pop();
			}
			else //k 인덱스에 해당하지 않을 경우 qQueue에서 팝을 해서 그 값을 다시 rear에 밀어넣는다.
			{
				int iTemp = qQueue.front();
				qQueue.pop(); //큐의 front제거하기 
				qQueue.push(iTemp); //큐의 rear에 밀어넣기 
			}
		}
	}
	int iResult = qQueue.front();
	return iResult;
}

int main()
{
	int answer = solution(5, 2);

	cout << answer;

	return 0;
}