#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std; 

//arr에서 두 수를 뽑아서 target의 값이 되면 true, target이 되지 않으면 false를 반환

void mapping(vector<int>& hash, vector<int>& arr, int target) //hash를 원본 값으로 받는다. 
{
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] > target) //arr[i]의 값이 target보다 클 경우 continue
		{
			continue; 
		}
		hash[arr[i]] = 1; //해당 값이 존재함음 알려주므로 1 대입
	}
}

bool solution(vector<int> arr, int target)
{
	vector<int> vecHash(target + 1, 0); //vector의 크기를 target보다 1크게 초기화 

	for (int i = 0; i < arr.size(); ++i)
	{
		int iNeed = target - arr[i]; 

		if (arr[i] == iNeed)
		{
			continue; 
		}
		if (iNeed < 0)
		{
			continue; 
		}
		if (vecHash[iNeed])
		{
			return true; 
		}
	}
	return false; 
}