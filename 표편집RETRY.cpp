#include <string>
#include <vector>
#include <stack>

using namespace std;

struct DelInfo
{
    int iRow; 
    int iPrevRow; 
    int iNextRow; 
};

string solution(int n, int k, vector<string> cmd) {
    stack<DelInfo> sDeleted; //삭제된 행을 모아두는 stack

    vector<int> vecPrev(n); //위에 있는 행의 번호 존재하지 않으면 - 1
    vector<int> vecNext(n); //아래에 존재하는 행의 번호 존재하지 않으면 + 1

    int iCurrentRow = k; //현재 행 인덱스를 의미한다. 
    
    for (int i = 0; i < n; ++i) //n + 2인 이유는 prev이 -1까지 저장하고 next가 +1을 저장해야 하기 때문이다. 
    {
        vecPrev[i] = i - 1; 
        vecNext[i] = (i == n - 1) ? -1 : i + 1;
    }

    for (auto s : cmd)
    {
        char cCommand = s[0]; //이동 커맨드 문자 저장


        if (cCommand == 'U')
        {
            int iMoveNum = stoi(s.substr(2)); //이동 숫자 저장 
            for (int i = 0; i < iMoveNum; ++i)
            {
                if (vecPrev[iCurrentRow] == -1) //vecPrev이 인덱스 0을 벗어날 경우 break; 
                {
                    break; 
                }
                else iCurrentRow = vecPrev[iCurrentRow];
            }
        }
        else if (cCommand == 'D')
        {
            int iMoveNum = stoi(s.substr(2)); //이동 숫자 저장 
            for (int i = 0; i < iMoveNum; ++i)
            {
                if (vecNext[iCurrentRow] == -1) //vecNext가 n - 1 인덱스를 벗어날 경우 
                {
                    break;
                }
                else iCurrentRow = vecNext[iCurrentRow]; 
            }
        }
        else if (cCommand == 'C')
        {
            int iPrev = vecPrev[iCurrentRow]; 
            int iNext = vecNext[iCurrentRow]; 

            sDeleted.push({ iCurrentRow, iPrev, iNext }); //지워진 정보 모아두는 스택에 deletedinfo 구조체의 정보를 저장 

            //vecprev의 inext번째 노드에 vexnext에서 icurrentrow의 값을 대입, vecnext도 동일하게 수행
            if (iPrev != -1) 
            {
                vecNext[iPrev] = iNext;
            }
            if (iNext != -1)
            {
                vecPrev[iNext] = iPrev;
            }
            //iCurrentRow 이동
            if (iNext != -1)
            {
                iCurrentRow = vecNext[iCurrentRow]; //마지막 줄이 아닐 경우 다음 줄로 변경
            }
            else iCurrentRow = iPrev; //마지막 줄일 경우 이전 줄로 변경
        }
        else if (cCommand == 'Z')
        {
            if (sDeleted.empty())
            {
                continue; 
            }
            //지워진 줄의 icurrentrow, inext, iprev에 대한 정보를 가지고 있음 
            DelInfo info = sDeleted.top(); 
            sDeleted.pop();

            int iRow = info.iRow; 
            int iPrev = info.iPrevRow; 
            int iNext = info.iNextRow; 

            vecPrev[iRow] = iPrev;
            vecNext[iRow] = iNext;

            if (iPrev != -1) vecNext[iPrev] = iRow;
            if (iNext != -1) vecPrev[iNext] = iRow;
        }
    }

    string sResult(n, 'O'); 
    while (!sDeleted.empty())
    {
        sResult[sDeleted.top().iRow] = 'X';
        sDeleted.pop(); 
    }

    string answer = sResult;
    return answer;
}