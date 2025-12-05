#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {

    vector<int> vTemp; 
    stack<int> iStack; //삭제한 열에 대한 정보 
    stack<char> cStack; 

    for (int i = 0; i < n; ++i)
    {
        vTemp.push_back(i);
    }

    for (int i = 0; i < n; ++i)
    {
        vTemp[i] = i;
    }

    for (auto s : cmd)
    {
        string sCmd = s;

        char cOp = sCmd[0];
        int iNum = 0;

        if (sCmd.size() > 1) //두 개 이상의 문자가 존재할 경우 
        {
            iNum = stoi(sCmd.substr(sCmd[2]));
        }
        if (cOp == 'D') //경계체크하면서 인덱스 증가 -----
        {
            if (k + iNum > n - 1) //경계를 넘어갈 경우 가장 위 행 대입
            {
                k = n - 1; 
            }
            else k += iNum; //경계를 넘지 않을 경우 k 숫자만큼 인덱스 증가 
        }
        else if (cOp == 'U') //인덱스 감소 
        {
            if (k - iNum < 0) //0보다 작을 경우 0 대입
            {
                k = 0;
            }
            else k -= iNum; //아닐 경우 iNum만큼 감소 
        }
        else if (cOp == 'C') //k가 있는 행 삭제 행은 변화 X 마지막 행일 경우만 행 - 1, 만약 k = n - 1일 경우 삭제 후 위로 이동 
        {
            if (vTemp.empty()) //전체 컨테이너가 비워져있다면 continue
            {
                continue; //해당 반복만 종료 
            }
            //비워져있지 않은 경우 
            if (k == n - 1) //k가 마지막 행일 경우 k 위로 올림
            {
                iStack.push(k); //스택에 지워진 인덱스 저장 
                vTemp.pop_back(); //vector의 전체 크기를 줄인다. 
                k -= 1; //k의 행을 위로 올린다. 
            }
            else //마지막 행이 아닐 경우 아래로 내림 
            {
                iStack.push(k); //스택에 해당 열 저장 
                vTemp.pop_back();  //vector의 전체 크기 줄이기 
                //k는 변화 없음 
            }
        }
        else if (cOp == 'Z') //이전에 삭제했던 행 복구
        {
            if (iStack.empty()) //스택이 비어있는 경우 break; 
            {
                continue;
            }

            int iDel = iStack.top(); //이전에 삭제했던 행 

            vTemp.insert(vTemp.begin() + iDel, iNum); //이전에 삭제했던 행에 해당 행 밀어넣기 

            if (iDel <= k) //이전에 삭제했던 행이 k보다 작을 경우 k 인덱스 한 칸 앞으로 밀어주기 
            {
                k++; 
                iStack.pop(); //스택 pop 
            }
            else //삭제했던 행이 더 클 경우 k 인덱스 변화 없음 
            {
                iStack.pop(); //스택 pop 
                break;
            }
        }
    }
    //원본 vector와 temp vector, 스택에 쌓인 값들을 비교해서 answer에다가 밀어넣어줌

    stack<char> sTempResult;
    vector<char> vTempResult; 
    for (int i = 0; i < n; ++i)
    {
        vTempResult.push_back('O'); 
    }
    for (int i = n - 1; i >= 0; ++i) //cStack에 원본 행을 기준으로 지워진 인덱스들이 들어있음. 해당 인덱스를 원본 인덱스랑 비교하면서 그 인덱스와 동일하면 그 인덱스에 X를 밀어넣는다. 
    {
        if (iStack.empty())
        {
            break; 
        }
        if (i == iStack.top())  //iStack에 들어있는 인덱스가 vTempResult의 값과 동일할 떄 X를 밀어넣어줌. vTempResult의 순서를 나중에 변경해준다. 
        {
            vTempResult[i] = 'X';
        }
        else {
            continue; 
        }
    }
    string answer(vTempResult.begin(), vTempResult.end());

    return answer;
}