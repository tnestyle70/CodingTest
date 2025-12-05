#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

long long Polynominal_Hash(string& sString) //string을 매개 변수로 받음
{
    const int iPrime = 31;
    const int iModulus = 100000007; 
    long long llHashValue = 0; 

    for (char cCh : sString) //string의 문자열을 하나씩 분리해서 iPrime 31이라는 소수를 llHashValue에 곱해주고 cCh만큼의 숫자를 더한 값을 iMolulus로 나눈 나머지를 구한다.
    {
        llHashValue = (llHashValue * iPrime + cCh)  % iModulus;
    }
    return llHashValue; 
}
//GPT 풀이 

bool solution(vector<string> phone_book)
{
    vector<string> vecBook = phone_book;

    bool answer = true;

    sort(vecBook.begin(), vecBook.end());  //phonebook을 오름차순으로 쭉 정렬해준다. 

    for (size_t i = 0; i < vecBook.size() - 1; ++i)
    {
        string sPrev = vecBook[i];
        string sNext = vecBook[i + 1];

        size_t minLen = min(sPrev.size(), sNext.size());

        bool bIsDifferent = false;

        for (int i = 0; i < minLen; ++i)
        {
            if (sPrev[i] != sNext[i])
            {
                bIsDifferent = true; 
                break; 
            }
        }
        if (!bIsDifferent)
        {
            answer = false; 
            break; 
        }
    }

    return answer; 
}

//내풀이 
bool solution(vector<string> phone_book) {

    vector<string> vecBook = phone_book; 

    sort(vecBook.begin(), vecBook.end());  //phonebook을 오름차순으로 쭉 정렬해준다. 

    bool answer = true; 

    for (size_t i = 0; i < vecBook.size() - 1; ++i)
    {
        string sPrev = vecBook[i]; 
        string sNext = vecBook[i + 1]; 

        bool bIsSame = false; 

        if (sPrev.size() >= sNext.size()) //앞의 문자열 길이가 더 긴 경우 
        {
            bool bIsDifferent = false; 
            for (size_t k = 0; k < sNext.size(); ++k)
            {
                if (sPrev[k] != sNext[k]) //값이 다르면 break하고 다음으로 이동
                {
                    bIsDifferent = true; 
                    break; 
                }
                else //값이 같다면 continue; for문이 다 끝났을 때를 기준으로 값이 같다면 false
                {
                    continue;
                }
            }
            if (!bIsDifferent)
            {
                answer = false; 
                break; 
            } 
        }
        else //뒤의 문자열 길이가 더 긴 경우
        {
            bool bIsDifferent = false;
            for (size_t k = 0; k < sPrev.size(); ++k)
            {
                if (sPrev[k] != sNext[k]) //값이 다르면 break하고 다음으로 이동
                {
                    bIsDifferent = true;
                    break;
                }
                else //값이 같다면 continue; for문이 다 끝났을 때를 기준으로 값이 같다면 false
                {
                    continue;
                }
            }
            if (!bIsDifferent)
            {
                answer = false;
                break;
            }
        }
    }

    return answer;
}

int main()
{
    // 1번 케이스: ["119", "97674223", "1195524421"]  -> false
    vector<string> tc1 = { "119", "97674223", "1195524421" };

    // 2번 케이스: ["123","456","789"] -> true
    vector<string> tc2 = { "123", "456", "789" };

    // 3번 케이스: ["12","123","1235","567","88"] -> false
    vector<string> tc3 = { "12", "123", "1235", "567", "88" };

    bool r1 = solution(tc1);
    bool r2 = solution(tc2);
    bool r3 = solution(tc3);

    cout << boolalpha; // true/false로 출력되게

    cout << "TestCase 1: [\"119\", \"97674223\", \"1195524421\"]" << endl;
    cout << "  Expected: false" << endl;
    cout << "  Result  : " << r1 << endl << endl;

    cout << "TestCase 2: [\"123\", \"456\", \"789\"]" << endl;
    cout << "  Expected: true" << endl;
    cout << "  Result  : " << r2 << endl << endl;

    cout << "TestCase 3: [\"12\", \"123\", \"1235\", \"567\", \"88\"]" << endl;
    cout << "  Expected: false" << endl;
    cout << "  Result  : " << r3 << endl << endl;

    return 0;
}