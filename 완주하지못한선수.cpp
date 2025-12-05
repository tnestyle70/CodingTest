#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

long long polynominal_hash(const string& str)
{
    const int p = 31; 
    const long long m = 1000000007; 
    long long hashValue = 0; 

    for (char cCh : str)
    {
        hashValue = (hashValue * p + cCh) % m;//받은 문자를 p를 곱하고 다시 hashValue를 사용해서 값을 누적 시킨다. 
    }
    return hashValue; 
}

string solution(vector<string> participant, vector<string> completion) {

    unordered_map<long long, int> uCountHash; 
    
    for (string sString : participant)
    {
        long long llHash = polynominal_hash(sString);
        uCountHash[llHash]++; //그냥 1이 아니라 동명이인의 경우 +1로 처리를 해준다.
    }
    for (string sString : completion)
    {
        long long llHash = polynominal_hash(sString);
        uCountHash[llHash]--; //참가자들을 ++해주고 완주자들을 --해줘서 1인 값만 return을 하면 된다. 
    }
    string sResult;
    for (string sString : participant) //참가자들을 완주한 사람들의 해쉬값들이랑 비교를 해서 존재하면 ok, 존재하지 않으면 해당 문자열 sResult에 대입 
    {
        long long llHash = polynominal_hash(sString);
        if (uCountHash[llHash] == 1)
        {
            sResult = sString;
            break;
        }
        else continue; 
    }
    string answer = sResult;
    return answer;
}