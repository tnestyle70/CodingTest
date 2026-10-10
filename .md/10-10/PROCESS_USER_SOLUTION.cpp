#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    //그냥 return
    if(priorities.size() == 1)
    {
        return 1;
    }

    //인덱스와 우선순위 pair를 가지고 있는 queue
    queue<pair<int, int>> q;

    for(int i = 0; i < priorities.size(); ++i)
    {
        q.push({i, priorities[i]});
    }
    int count = 0;
    int answer = 0;
    //큐를 벗어나는 조건을 어떻게 설계해야 할까?
    while(q.size() >= 1)
    {
        bool isPriority = true;

        for(auto& priority : priorities)
        {
            if(q.front().second < priority)
            {
                q.push({q.front()});
                q.pop();
                isPriority = false;
                break;
            }
        }

        if(isPriority)
        {
            priorities[q.front().first] = 0;

            count++;

            if(q.front().first == location)
            {
                answer = count;
                break;
            }

            q.pop();
        }
    }

    return answer;
}
