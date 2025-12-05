#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {

    stack<int> sStackBox;

    int iResult = 0; 

    for (int i = 0; i < moves.size(); ++i)
    {
        int iIndex = moves[i] - 1; 

        for (auto& vec : board)
        {
            if (vec[iIndex] != 0)
            {
                if (sStackBox.empty())
                {
                    sStackBox.push(vec[iIndex]); 
                    vec[iIndex] = 0;
                    break; 
                }
                else 
                {
                    if (sStackBox.top() == vec[iIndex])
                    {
                        sStackBox.pop(); 
                        vec[iIndex] = 0; 
                        iResult++; 
                        break; 
                    }
                    else
                    {
                        sStackBox.push(vec[iIndex]);
                        vec[iIndex] = 0;
                        break;
                    }
                }
            }
        }
    }
    int answer = iResult * 2;
    return answer;
}

int main()
{
    vector<vector<int>> board = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 3},
        {0, 2, 5, 0, 1},
        {4, 2, 4, 4, 2},
        {3, 5, 1, 3, 1}
    };

    vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };

    int expected = 4; // Á¤´ä °ª

    int answer = solution(board, moves);
    cout << "answer = " << answer << endl;

    return 0;
}