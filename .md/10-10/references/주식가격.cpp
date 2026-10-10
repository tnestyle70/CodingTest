#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {

    int n = prices.size();
    vector<int> answer(n, 0);
    //시점의 인덱스, 값에 대한 접근은 prices를 통해 한다.
    stack<int> st;
    //떨어진 순간을 기준으로 검사 - 관점의 전환
    //스택의 top을 가장 비용이 높은 것으로 유지한 다음에
    // prices[i]의 값이 스택의 top 기준으로 더
    //작아지는 시점을 기준으로 값을 저장하는 것이 핵심
    for(int i = 0; i < n; ++i)
    {
        while(!st.empty() && prices[st.top()] > prices[i])
        {
            int t = st.top();
            st.pop();
            answer[t] = i - t;
        }
        st.push(i);
    }
    //끝까지 안 떨어진 시점 인덱스의 값 계산
    //
    while(!st.empty())
    {
        answer[st.top()] = (n - 1) - st.top();
        st.pop();
    }

    return answer;
}
