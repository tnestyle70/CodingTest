#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> qProgress;
    queue<int> qSpeed;

    vector<int> qResult;

    for (int i = 0; i < progresses.size(); ++i)
    {
        qProgress.push(progresses[i]);
        qSpeed.push(speeds[i]);
    }

    int iCount(1);

    while (qProgress.size() > 0)
    {
        for (int i = 0; i < progresses.size(); ++i)
        {
            progresses[i] += speeds[i] * iCount; //날짜가 지날 수록 모든 값이 다 늘어나게 설계. 
        }

        int iResult(0);
        qProgress.front() += qSpeed.front() * iCount;
        int iSpeed = qSpeed.front();
        int iProgress = qProgress.front();
        bool bPush = false;

        while (iProgress >= 100) //qProgress가 비어있지 않을 때까지 반복문을 돌린다. 
        {
            qProgress.pop(); //제거를 한 다음에 다음 원소에도 동일하게 값 적용을 해준 다음에 조건을 판단한다. 
            qSpeed.pop();

            iResult++;
            bPush = true;

            if (qProgress.empty()) //pop 진행 후에 비어있으면 break;로 탈출
            {
                break;
            }
            iProgress = qProgress.front() + qSpeed.front() * iCount;
        }
        if (bPush)
        {
            qResult.push_back(iResult);
        }
        iCount++;
    }
    vector<int> answer = qResult;
    return answer;
}

void PrintVector(const vector<int>& v)
{
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i];
        if (i != v.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main()
{
    // 테스트 케이스들
    vector<vector<int>> testProgresses = {
        {93, 30, 55},
        {95, 90, 99, 99, 80, 99}
    };

    vector<vector<int>> testSpeeds = {
        {1, 30, 5},
       {1, 1, 1, 1, 1, 1}
    };

    // 기대 결과(정답) – 디버깅할 때 비교용
    vector<vector<int>> expected = {
        {2, 1},
        {1, 3, 2}
    };

    for (size_t i = 0; i < testProgresses.size(); ++i)
    {
        cout << "===== Test Case " << i + 1 << " =====\n";

        cout << "progresses : ";
        PrintVector(testProgresses[i]);
        cout << "\nspeeds     : ";
        PrintVector(testSpeeds[i]);
        cout << "\n";

        // 네 solution 호출
        vector<int> result = solution(testProgresses[i], testSpeeds[i]);

        cout << "result     : ";
        PrintVector(result);
        cout << "\nexpected   : ";
        PrintVector(expected[i]);
        cout << "\n\n";
    }

    return 0;
}