#include <string>
#include <vector>
#include <map>
using namespace std;
//목표 1. 이름과 추천인을 바탕으로 트리 구성하기
//목표 2. 판매자와 금액을 트리를 바탕으로 계산
//목표 3. 계산한 금액과 enroll의 iMoney를 바탕으로 answer에 push_back
struct Node
{
    string sEnroll;
    string sReferral;
    int iMoney;
    Node(string sEnroll, string sReferral) : sEnroll(sEnroll),sReferral(sReferral), iMoney(0) {};
};
//등록한 사람과 추천인을 비교해서 추천인을 연결한다.
Node* Insert(Node*& pnodeRoot, string enroll, string referral)
{
    //추천인이 존재하지 않을 경우 center랑 연결해줌
    if (referral == "-")
    {
        pnodeRoot = new Node(enroll, "center");
        return pnodeRoot;
    }
    //추천인이 존재할 경우 referral와 연결
    else
    {
        pnodeRoot = new Node(enroll, referral);
        return pnodeRoot;
    }
}

void Sell(map<string, Node*>& mapEnrollNode, Node*& pnodeRoot, int total)
{   
    //총액을 10으로 나눴을 때 몫이 0인 경우, sEnroll이 center인 경우 pnodeRoot의 iMoney값 더하고 return 
    if (total / 10 == 0 || pnodeRoot->sReferral == "None")
    {
        pnodeRoot->iMoney += total;
        return;
    }
    //iRemain을 계산해서 돈을 추가하고 추천인에게 남은 값 분배
    else
    {
        int iRemain = total - total / 10;
        pnodeRoot->iMoney += iRemain;
        Sell(mapEnrollNode, mapEnrollNode[pnodeRoot->sReferral], total / 10);
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) 
{
    map<string, Node*> mapEnrollNode;

    Node* nodeRoot = new Node("center", "None");

    mapEnrollNode["center"] = nodeRoot;

    for (size_t i = 0; i < enroll.size(); ++i)
    {
        mapEnrollNode[enroll[i]] = Insert(nodeRoot, enroll[i], referral[i]);
    }
    for (size_t i = 0; i < seller.size(); ++i)
    {
        Sell(mapEnrollNode, mapEnrollNode[seller[i]], amount[i] * 100);
    }
    vector<int> answer;
    answer.reserve(enroll.size());
    for (size_t i = 0; i < enroll.size(); ++i)
    {
        answer.push_back(mapEnrollNode[enroll[i]]->iMoney);
    }
    return answer;
}