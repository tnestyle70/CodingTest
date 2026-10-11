#include <queue>
#include <utility>
#include <vector>

using namespace std;

// 코치 참고 풀이: 퇴장 시각으로 이동하는 시뮬레이션.
// 사용자가 작성한 코드와 별도로 보관한다.
int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    // {트럭 무게, 퇴장 예정 시각}
    queue<pair<int, int>> bridge;
    int currentTime = 0;
    int currentWeight = 0;

    for (int truckWeight : truck_weights)
    {
        // 다음 트럭은 이전 진입보다 최소 1초 뒤에 진입할 수 있다.
        ++currentTime;

        // 현재 시각까지 다리를 건넌 트럭을 먼저 제거한다.
        while (!bridge.empty() && bridge.front().second <= currentTime)
        {
            currentWeight -= bridge.front().first;
            bridge.pop();
        }

        // 무게가 초과하면 다음 퇴장 시각으로 바로 이동한다.
        while (currentWeight + truckWeight > weight)
        {
            currentTime = bridge.front().second;
            currentWeight -= bridge.front().first;
            bridge.pop();
        }

        bridge.push({truckWeight, currentTime + bridge_length});
        currentWeight += truckWeight;
    }

    // 입력이 비어 있지 않고, 마지막 진입 트럭이 가장 늦게 퇴장한다.
    return bridge.back().second;
}
