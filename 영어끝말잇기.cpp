#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
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

    unordered_map<long long, int> uWords;

    queue<char> sFront; 
    queue<char> sBack;

    for (string sString : words)
    {
        long long llHashValue = polynominal_hash(sString);
        uWords[llHashValue]++; //hashvalue++를 해줌으로써 해당 단어의 해시를 추가해줌으로써 해당 단어가 존재함을 알려준다. 
    }
    
    //words의 단어 stack에 push

    for (string sString : words) 
    {
        sFront.push(sString[0]); 
        sBack.push(sString[sString.size() - 1]); 
    }
    int iBreakIndex = 0; 
    for (int i = 0; i < words.size(); ++i)
    {
        long long llHashValue = polynominal_hash(words[i]);
        sFront.pop(); //맨 앞 단어의 앞글자는 제거 
        if (sBack.front() == sFront.front()) //앞단어의 뒷문자와 뒷단어의 앞문자 비교 
        {
            uWords[llHashValue]--; //일치하는 경우 --
            sBack.pop(); 
        }
        else if(uWords[llHashValue] >= 2) //두 문자가 일치하지 않는 경우 
        {
            iBreakIndex = i + 1;
            break;
        }
        else if (sBack.front() != sFront.front()) //두 문자가 일치하지 않는 경우 
        {
            uWords[llHashValue]++;
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