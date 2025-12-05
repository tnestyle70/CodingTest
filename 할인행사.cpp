#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

long long polynominal_hash(string& sString)
{
    int iPrime = 31; 
    int iModulus = 10000000007; 
    long long llHashValue = 0;
    for (string::iterator it = sString.begin(); it != sString.end(); ++it)
    {
        char cCh = *it; 

        llHashValue = (llHashValue * iPrime + cCh) % iModulus; 
    }
    return llHashValue;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {

    unordered_map<long long, int> mapHash;

    int iIndex = 0; 

    for (vector<string>::iterator it = want.begin(); it != want.end(); ++it)
    {
        string sWant = *it; //원하는 물품 

        long long llHashValue = polynominal_hash(sWant); 

        mapHash[llHashValue] = number[iIndex]; //해당 문자의 key에 개수를 대입시켜준다. 해당 물품이 몇 개가 들어있는지를 파악한다. 

        iIndex++;
    }

    int iResult = 0; 

    for (int i = 0; i <= discount.size() - 10; ++i) //discount size에서 10 뻰 반복 횟수로 계산
    {
        unordered_map<long long, int> mapTemp = mapHash;

        bool bIsSame = true; 

        for (int k = i; k < 10 + i; ++k)
        {
            long long  llHashValue = polynominal_hash(discount[k]);

            if (mapTemp[llHashValue] == 0) //해당 string의 value를 확인한 다음 0일 경우 10일 간의 세일 목록에 원하는 물품이 존재하지 않는 것이므로 return; 
            {
                bIsSame = false;
                break;
            }
            else
            {
                mapTemp[llHashValue]--; //0이 아니고 해당 물품이 원하는 물품에 존재할 경우 --로 hash 값을 감소 시킨다. 
            }
        }
        if (bIsSame)
        {
            iResult++; 
        }
    }
    int answer = iResult;
    return answer;
}