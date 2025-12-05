#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

long long polynominal_hash(const string& str)
{
	const int p = 31; 
	const long long m = 1000000007; 
	long long hashValue = 0; 

	for (char cCh : str)
	{
		hashValue = (hashValue * p + cCh) % m; //처음에는 0이 들어가서 값이 쌓여나갈 수록 p^n이 자연스럽게 구현된다. 
	}
	return hashValue; 
}

vector<bool> solution(vector<string> string_list, vector<string> query_list)
{
	unordered_set<long long> hash_set; 

	for (string sString : string_list) //string list에서 string을 하나씩 가지고 나옴 
	{
		long long llHash = polynominal_hash(sString); 
		hash_set.insert(llHash);
	}
	vector<bool> result; 

	for (string sString : query_list)
	{
		long long llQueryHash = polynominal_hash(sString);
		if (hash_set.find(llQueryHash) != hash_set.end())
		{
			result.push_back(true); 
		}
		else result.push_back(false);
	}
	return result;
}