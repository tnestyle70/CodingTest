#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int iLen = s.size(); 

    bool isValid = true;
    int iResult; 

    stack<char> cStack;
    stack<char> cStackTemp;

    for (char c : s) {
        cStack.push(c);
        cStackTemp.push(c);
    }

    while (!cStackTemp.empty())
    {
        char cPrev;
        char cNext;

        for (int i = 0; i < iLen - 1; ++i) {
            if (s[i] == s[i + 1]) {
                cPrev = s[i];
                cNext = s[i + 1];
                isValid = true; 
                break;
            }
            else isValid = false; 
        }
        if (isValid) {
            //임시 stack에 동일한 인접 원소 제거한 stack 저장
            while (!cStack.empty()) {
                char cTemp = cStack.top();
                cStack.pop();
                if (cTemp != cPrev && cTemp != cNext) {
                    cStackTemp.push(cTemp);
                }
            }
            //다시 정렬
            for (int i = 0; i < cStackTemp.size(); ++i) {
                char cTemp = cStackTemp.top();
                cStackTemp.pop();
                cStackTemp.push(cTemp);
            }
        }
        else iResult = -1;
    }
    if (!cStackTemp.empty()) {
        iResult = 1;
    }

    return iResult;
}

int main() {
    solution("cdcd"); 

    return 0; 
}