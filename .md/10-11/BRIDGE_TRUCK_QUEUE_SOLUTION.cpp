// 2026-10-11: 사용자 최신 코드와 답변. 줄 간격만 정리. C++ 실행·채점은 미확인.
#include <string>
#include <vector>
#include <queue>

using namespace std;

// 1. 한 문장 목표
// 질문: 어떤 입력에서, 어떤 규칙에 따라, 무엇을 반환해야 하는가?
//       선택 조건·중복 처리·결과 순서에 대한 요구는 무엇인가?
// 내 답: 대기 트럭을 다리에 올릴 수 있는지를 검사한다. 다리에 올릴 수 있다면, 다리에 올린다. 다리에 올라간 트럭의 경우는 이동한 시간에 대한 카운트와 해당 카운트가 끝났을 경우에 다리 위에 있는 트럭에서 제외를 시킨다.

//다리 위에 있는 트럭을 이동 시키기 -> 트럭이 다리를 건넜을 경우에 해당 트럭을 전체 다리의 트럭 무게에서 제외를 시킨다.

//대기 트럭을 다리에 올리기 위한 조건 계산 이후 weight >= 대기 트럭 + 다리 트럭 무게의 경우 다리에 올리고 bridge_length를 할당 시키고, 대기 트럭에서 pop 시킨다.

//경과 시간을 증가 시킨다.

//맞네, 나는 시간을 계속 전체 순회하면서 줄이는 것에 대해서 생각을 했는데, 그럴 필요 없이 그냥 경과 시간을 알 수 있기 때문에 다리 위에 올라간 시간과 경과 시간을 더해서, 도착 시간을 구한 다음에, 기준이 되는 시간을 활용해 다리 위에 있는 트럭이 도착하는 것을 판단하면 된다.
//그렇다면, 나는 왜 완전 탐색과 매 초 트럭의 이동 시간을 줄이는 것에 대해서 생각을 해서 queue를 버리고 vector를 선택했을까?

// 2. 제약 어휘
// 질문: 입력 크기와 값의 범위는 각각 얼마인가?
//       숫자마다 무엇의 개수·길이·값을 의미하는가?
//       가장 작은 입력, 가장 큰 입력, 문제에서 보장하는 조건은 무엇인가?
// 내 답:

// 3. 예산 산술
// 질문: 최대 입력을 후보 비용식에 대입하면 작업량은 얼마인가?
//       예: N, N log N, N², 상태 수 × 상태당 처리 비용.
//       시간·메모리 제한을 고려해 어떤 복잡도를 목표로 할 것인가?
// 내 답:

// 4. 완전탐색 기준선 — 가장 직접적인 풀이
// 질문: 입력을 받아 정답을 반환하기까지 어떤 순서로 처리할 것인가?
//       어떤 대상을 확인하고, 어떤 조건으로 판단하며, 결과를 어떻게 만드는가?
//       이 직접적인 풀이의 시간·공간 비용은 얼마인가?
// 내 답:

// 5. 병목 → 자료구조·알고리즘 선택
// 질문: 위 절차에서 비용이 큰 작업이나 반복해서 해결하는 질문은 무엇인가?
//       다음 판단에 필요한 정보는 무엇이며, 무엇부터 처리해야 하는가?
//       어떤 자료구조와 알고리즘을 선택하고, 그 이유는 무엇인가?
//       이미 충분히 효율적이라면 그 이유는 무엇인가?
// 내 답:

// 6. 선서술·불변식·비용 검산
// 질문: 선택한 풀이에서 저장하는 정보는 무엇을 의미하는가?
//       초기 상태에서 그 의미가 맞고, 각 처리 단계 뒤에도 유지되는 이유는 무엇인가?
//       처리가 종료되는 이유와, 종료 시 결과가 정답이 되는 이유는 무엇인가?
//       각 작업의 실행 횟수 × 한 번 비용을 합산하면 시간 복잡도는 얼마인가?
//       동시에 보관해야 하는 데이터의 최대 크기로 본 공간 복잡도는 얼마인가?
// 내 답:

// 7. 검증
// 질문: 내 풀이의 어떤 실수를 잡기 위해 어떤 입력을 시험할 것인가?
//       예상 결과와 실제 결과는 무엇인가?
//       컴파일·예제·경계값·프로그래머스 채점은 각각 어디까지 확인했는가?
// 내 답:

// 8. 회고
// 질문: 처음에 무엇을 잘못 생각했고, 어떤 근거로 수정했는가?
//       선택한 풀이가 성립하는 조건과 성립하지 않는 조건은 무엇인가?
//       다음 문제에서도 사용할 수 있는 판단 기준은 무엇인가?
// 내 답:

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> pendingTrucks;
    for(auto& truck : truck_weights)
    {
        pendingTrucks.push(truck);
    }
    int complete = 0;
    int time = 0;
    //queue로 저장을 하고, 전체 순회를 할 필요가 없이, queue에
    //{트럭 무게, 도착 시간}을 저장하게 하면 된다.
    queue<pair<int, int>> bridgeTrucks;
    int totalBridgeWeights = 0;
    while(complete < truck_weights.size())
    {
        //다리 위에 있는 트럭의 도착 시간을 파악하고, 도착했다면 totalBridgeWeights
        //와 queue를 pop 시킨다.
        if(!bridgeTrucks.empty())
        {
            //queue의 front에 있는 truck이 도착했다면, queue에서 빼내고,
            //totalBridgeWeights를 감소 시킨다.
            if(bridgeTrucks.front().second == time)
            {
                totalBridgeWeights -= bridgeTrucks.front().first;
                bridgeTrucks.pop();
                complete++;
            }
        }
        //트럭 자체를 다리 위에 올릴 때, {트럭 무게, 도착 시간}을 기준으로 넣는다.
        //pendingTrucks의 목록도 제거한다.
        if(!pendingTrucks.empty() &&
           pendingTrucks.front() + totalBridgeWeights <= weight)
        {
            totalBridgeWeights += pendingTrucks.front();
            bridgeTrucks.push({pendingTrucks.front(), time + bridge_length});
            pendingTrucks.pop();
        }
        //경과 시간 증가
        time++;
    }
    return time;
}

// 이전 vector 풀이 전체와 1~8 답변 보존
// #include <string>
// #include <vector>
// #include <queue>
//
// using namespace std;
//
// // 1. 한 문장 목표
// // 질문: 어떤 입력에서, 어떤 규칙에 따라, 무엇을 반환해야 하는가?
// //       선택 조건·중복 처리·결과 순서에 대한 요구는 무엇인가?
// // 내 답: 대기 트럭을 다리에 올릴 수 있는지를 검사한다. 다리에 올릴 수 있다면, 다리에 올린다. 다리에 올라간 트럭의 경우는 이동한 시간에 대한 카운트와 해당 카운트가 끝났을 경우에 다리 위에 있는 트럭에서 제외를 시킨다.
//
// //다리 위에 있는 트럭을 이동 시키기 -> 트럭이 다리를 건넜을 경우에 해당 트럭을 전체 다리의 트럭 무게에서 제외를 시킨다.
//
// //대기 트럭을 다리에 올리기 위한 조건 계산 이후 weight >= 대기 트럭 + 다리 트럭 무게의 경우 다리에 올리고 bridge_length를 할당 시키고, 대기 트럭에서 pop 시킨다.
//
// //경과 시간을 증가 시킨다.
//
// // 2. 제약 어휘
// // 질문: 입력 크기와 값의 범위는 각각 얼마인가?
// //       숫자마다 무엇의 개수·길이·값을 의미하는가?
// //       가장 작은 입력, 가장 큰 입력, 문제에서 보장하는 조건은 무엇인가?
// // 내 답:
//
// // 3. 예산 산술
// // 질문: 최대 입력을 후보 비용식에 대입하면 작업량은 얼마인가?
// //       예: N, N log N, N², 상태 수 × 상태당 처리 비용.
// //       시간·메모리 제한을 고려해 어떤 복잡도를 목표로 할 것인가?
// // 내 답:
//
// // 4. 완전탐색 기준선 — 가장 직접적인 풀이
// // 질문: 입력을 받아 정답을 반환하기까지 어떤 순서로 처리할 것인가?
// //       어떤 대상을 확인하고, 어떤 조건으로 판단하며, 결과를 어떻게 만드는가?
// //       이 직접적인 풀이의 시간·공간 비용은 얼마인가?
// // 내 답:
//
// // 5. 병목 → 자료구조·알고리즘 선택
// // 질문: 위 절차에서 비용이 큰 작업이나 반복해서 해결하는 질문은 무엇인가?
// //       다음 판단에 필요한 정보는 무엇이며, 무엇부터 처리해야 하는가?
// //       어떤 자료구조와 알고리즘을 선택하고, 그 이유는 무엇인가?
// //       이미 충분히 효율적이라면 그 이유는 무엇인가?
// // 내 답:
//
// // 6. 선서술·불변식·비용 검산
// // 질문: 선택한 풀이에서 저장하는 정보는 무엇을 의미하는가?
// //       초기 상태에서 그 의미가 맞고, 각 처리 단계 뒤에도 유지되는 이유는 무엇인가?
// //       처리가 종료되는 이유와, 종료 시 결과가 정답이 되는 이유는 무엇인가?
// //       각 작업의 실행 횟수 × 한 번 비용을 합산하면 시간 복잡도는 얼마인가?
// //       동시에 보관해야 하는 데이터의 최대 크기로 본 공간 복잡도는 얼마인가?
// // 내 답:
//
// // 7. 검증
// // 질문: 내 풀이의 어떤 실수를 잡기 위해 어떤 입력을 시험할 것인가?
// //       예상 결과와 실제 결과는 무엇인가?
// //       컴파일·예제·경계값·프로그래머스 채점은 각각 어디까지 확인했는가?
// // 내 답:
//
// // 8. 회고
// // 질문: 처음에 무엇을 잘못 생각했고, 어떤 근거로 수정했는가?
// //       선택한 풀이가 성립하는 조건과 성립하지 않는 조건은 무엇인가?
// //       다음 문제에서도 사용할 수 있는 판단 기준은 무엇인가?
// // 내 답:
//
// int solution(int bridge_length, int weight, vector<int> truck_weights) {
//
//     queue<int> pendingTrucks;
//
//     for(auto& truck : truck_weights)
//     {
//         pendingTrucks.push(truck);
//     }
//
//     int complete = 0;
//
//     int answer = 0;
//     //남은 거리와 트럭 무게
//     vector<pair<int, int>> bridgeTrucks;
//
//     int totalBridgeWeights = 0;
//
//     while(complete < truck_weights.size())
//     {
//         //다리 위에 존재하는 트럭 이동
//         if(!bridgeTrucks.empty())
//         {
//             //이동만 한다.
//             for(auto& bridgeTruck : bridgeTrucks)
//             {
//                 bridgeTruck.first -= 1;
//             }
//             //이동을 다 했을 경우, completeTrucks로 옮기고, bridge weight 낮추기
//             if(bridgeTrucks.front().first <= 0 )
//             {
//                 complete++;
//
//                 totalBridgeWeights -= bridgeTrucks.front().second;
//                 //다리 위 트럭 제거
//                 bridgeTrucks.erase(bridgeTrucks.begin());
//             }
//         }
//
//         //대기 트럭을 다리 위에 트럭을 실을 수 있을지에 대한 조건 처리
//         if(!pendingTrucks.empty() && pendingTrucks.front() + totalBridgeWeights <= weight)
//         {
//             bridgeTrucks.push_back({bridge_length, pendingTrucks.front()});
//
//             totalBridgeWeights += pendingTrucks.front();
//
//             pendingTrucks.pop();
//         }
//
//         //경과 시간 증가
//         answer++;
//     }
//
//     return answer;
// }
//
