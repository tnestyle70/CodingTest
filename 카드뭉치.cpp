#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {

    queue<string> qCards1; 
    queue<string> qCards2;
    queue<string> qGoal;

    for (int i = 0; i < cards1.size(); ++i)
    {
        qCards1.push(cards1[i]); 
    }
    for (int i = 0; i < cards2.size(); ++i)
    {
        qCards2.push(cards2[i]);
    }
    for (int i = 0; i < goal.size(); ++i)
    {
        qGoal.push(goal[i]);
    }
    string answer = "";
    for (auto word : goal) //마지막 goal의 원소를 대입 시키고 나면 터질까?
    {
        if (!qCards1.empty())
        {
            if (qCards1.front() == word) 
            {
                qCards1.pop();
                qGoal.pop(); 
                continue; 
            }
        }
        if (!qCards2.empty())
        {
            if (qCards2.front() == word) 
            {
                qCards2.pop();
                qGoal.pop();
                continue;
            }
        }
    }
    if (!qCards1.empty() && !qCards2.empty() && !qGoal.empty()) //둘 다 비워지고 goal도 비워졌으면 
    {
        answer = "Yes";
    }
    else
    {
        answer = "No";
    }

    return answer;
}
void PrintVector(const vector<string>& v)
{
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << "\"" << v[i] << "\"";
        if (i != v.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main()
{
    // 테스트 케이스들
    vector<vector<string>> testCards1 = {
        {"i", "drink", "water"},
        {"i", "water", "drink"}
    };

    vector<vector<string>> testCards2 = {
        {"want", "to"},
        {"want", "to"}
    };

    vector<vector<string>> testGoals = {
        {"i", "want", "to", "drink", "water"},
        {"i", "want", "to", "drink", "water"}
    };

    vector<string> expected = {
        "Yes",
        "No"
    };

    for (size_t i = 0; i < testCards1.size(); ++i)
    {
        cout << "===== Test Case " << i + 1 << " =====\n";

        cout << "cards1 : ";
        PrintVector(testCards1[i]);
        cout << "\ncards2 : ";
        PrintVector(testCards2[i]);
        cout << "\ngoal   : ";
        PrintVector(testGoals[i]);
        cout << "\n";

        string result = solution(testCards1[i], testCards2[i], testGoals[i]);

        cout << "result   : " << result << "\n";
        cout << "expected : " << expected[i] << "\n\n";
    }

    return 0;
}