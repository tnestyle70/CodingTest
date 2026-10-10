#include <vector>
#include <iostream>


using namespace std;

vector<int> solution(vector<int> arr)
{
    //answer 기준으로 해당 인덱스 오른쪽이 다르면 answer에 push한다
    vector<int> answer;

    for(int i = 0; i < arr.size(); ++i)
    {
       if(i == arr.size() - 1)
        {
            answer.push_back(arr[i]);
        }
        else
        {
            if(arr[i] == arr[i + 1])
            {
                continue;
            }
            else
            {
                answer.push_back(arr[i]);
            }
        }
    }


    return answer;
}
