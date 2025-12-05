#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

long long polynominal_hash(string& sString)
{
    const int p = 7;
    const long long m = 100000007;
    long long llHashValue = 0;
    for (char cCh : sString)
    {
        llHashValue = (llHashValue * p + cCh) % m;
    }
    return llHashValue;
}

vector<int> solution(int n, vector<string> words) {

    unordered_set<string> uUsedWords; 

    int iBreakIndex = 0; 

    for (int i = 0; i < words.size() - 1; ++i) //words의 i번째 단어의 마지막 글자와 i + 1번째 단어의 첫번째 글자를 비교한다.
    {
        string sPrev = words[i]; 
        string sNext = words[i + 1]; 

        if (sPrev[sPrev.size() - 1] == sNext[0]) //앞 단어의 마지막 글자와 뒷 단어의 첫번째 글자가 동일할 경우 continue; 
        {
            uUsedWords.insert(words[i + 1]);  //사용한 단어를 넣어준다. 
            continue;
        }
        else if(uUsedWords.find(words[i + 1]) != uUsedWords.end()) //앞 뒤 글자가 동일하지 않을 경우 break;
        {
            iBreakIndex = i + 1; //멈춘 인덱스를 저장
            break;
        }
        else //앞 뒤 글자가 동일하지 않을 경우 
        {
            iBreakIndex = i + 1;
            break; 
        }
    }
    //iBreakIndex는 멈춘 인덱스 + 1
    int iPersonNum = 0; //몇 번째 사람인지 
    int iRep = 0; //몇 번째에서 걸렸는지 
    if (iBreakIndex > 0)
    {
        if (iBreakIndex % n != 0)
        {
            iPersonNum = iBreakIndex % n;
        }
        else
        {
            iPersonNum = n;
        }
        iRep = (iBreakIndex + n - 1) / n;
    }
    vector<int> answer;
    answer.push_back(iPersonNum);
    answer.push_back(iRep);

    return answer;
}