#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//트리 구조체
struct Node
{
    int iX;
    int iIndex;
    Node* pLeft;
    Node* pRight;
    Node(int iX, int iIndex) : iX(iX), iIndex(iIndex), pLeft(nullptr), pRight(nullptr) {};
};

struct NodeInfo
{
    int iX;
    int iY;
    int iIndex;
};

//전위 순회 
void preorder(Node* rootNode, vector<int>& vecPreorder)
{
    if (rootNode)
    {
        //부모 순회
        vecPreorder.push_back(rootNode->iIndex);
        //왼쪽 자식 순회 
        preorder(rootNode->pLeft, vecPreorder);
        //오른쪽 자식 순회
        preorder(rootNode->pRight, vecPreorder);
    }
    return;
}
//후위 순회
void postorder(Node* rootNode, vector<int>& vecPostorder)
{
    if (rootNode)
    {   
        //왼쪽 자식 순회
        postorder(rootNode->pLeft, vecPostorder);
        //오른쪽 자식 순회 
        postorder(rootNode->pRight, vecPostorder);
        //부모 순회
        vecPostorder.push_back(rootNode->iIndex);
    }
    return;
}

//목표 1. X, Y 좌표를 바탕으로 트리 구성하기
// 
//BST 만들어서 모든 원소들을 이전에 존재했던 원소들과 비교해야 한다.

void Insert(Node*& nodeRoot, int iX, int iIndex)
{
    //BTS는 위에서부터 아래로 쭉 비교를 하면서 탐색을 한다.
    if (nodeRoot == nullptr)
    {
        //새로운 노드 생성
        nodeRoot = new Node(iX, iIndex);
        return;
    }
    //iY가 겹치기 때문에 iY를 기준으로 계산을 하고 iY가 겹치는 경우에 iX와 비교를 해서 루트를 구성한다. 
    //iX는 겹치는 경우가 존재하지 않고 결국 X,Y 좌표를 다 사용해야 한다.
    if (iX < nodeRoot->iX)
        Insert(nodeRoot->pLeft, iX, iIndex);
    else if (iX > nodeRoot->iX)
        Insert(nodeRoot->pRight, iX, iIndex);

    return;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<NodeInfo> vecNodeInfo;
    vecNodeInfo.reserve(nodeinfo.size());

    for (int i = 0; i < (int)nodeinfo.size(); ++i)
    {
        vecNodeInfo.push_back({ nodeinfo[i][0], nodeinfo[i][1], i + 1 });
    }

    sort(vecNodeInfo.begin(), vecNodeInfo.end(),
        [](const NodeInfo& a, const NodeInfo& b)
        {
            //a의 y와 b의 y가 다르면 내림차순 정렬
            //같으면 x 기준 오름차순 정렬
            if (a.iY != b.iY)
                return a.iY > b.iY;
            else if (a.iY == b.iY)
                return a.iX < b.iX;
        }
    );

    Node* rootNode = nullptr;

    for (int i = 0; i < (int)nodeinfo.size(); ++i)
    {
        Insert(rootNode, vecNodeInfo[i].iX, vecNodeInfo[i].iIndex);
    }
    vector<int> vecPreorder;
    preorder(rootNode, vecPreorder);

    vector<int> vecPostorder;
    postorder(rootNode, vecPostorder);

    vector<vector<int>> answer;

    answer.push_back(vecPreorder);
    answer.push_back(vecPostorder);

    return answer;
}
