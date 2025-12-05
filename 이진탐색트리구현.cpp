#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node
{
	int iValue;
	Node* pLeft;
	Node* pRight;
	Node(int iValue) : iValue(iValue), pLeft(nullptr), pRight(nullptr) {};
};

void Insert(Node*& nodeRoot, int iValue)
{
	if (nodeRoot == nullptr)
	{	//새 노드를 만들어서 nodeRoot에 대입 새로운 노드를 new로 동적할당해서 트리를 생성한다.
		nodeRoot = new Node(iValue);
		return;
	}
	//새롭게 생성한 nodeRoot를 기준으로 탐색을 진행한다. 쭉 트리가 노드를 기준으로 연결되어 생성된다.
	if (iValue < nodeRoot->iValue) Insert(nodeRoot->pLeft, iValue);
	else if (iValue > nodeRoot->iValue) Insert(nodeRoot->pRight, iValue);
}

bool Search(Node* nodeRoot, int iValue)
{
	//nodeRoot에 대한 null체크
	if (nodeRoot == nullptr)
	{
		return false;
	}
	if (iValue == nodeRoot->iValue)
	{
		return true;
	}
	else if (iValue < nodeRoot->iValue)
	{	//nodeRoot의 iValue보다 더 작으면 pLeft로 탐색
		return(Search(nodeRoot->pLeft, iValue));
	}
	else if (iValue > nodeRoot->iValue)
	{
		return(Search(nodeRoot->pRight, iValue));
	}
}

void Destroy(Node* nodeRoot)
{	//트리를 해제할 때는 왼쪽, 오른쪽, 부모 순서대로 지운다.
	if (nodeRoot == nullptr)
		return;
	Destroy(nodeRoot->pLeft);
	Destroy(nodeRoot->pRight);
	//자기 자신 지우기
	delete nodeRoot;
}

vector<bool> solution(const vector<int> list, const vector<int> search_list)
{	//root 노드를 선언하고 nodeRoot 내부에 값을 채워넣어서 list를 정렬한 상태를 구현한다.
	Node* nodeRoot = nullptr;
	//Insert() 함수를 사용해서 list를 정렬한 값을 nodeRoot에 대입한다.
	for (const int iElement : list)
	{	//삽입을 통해서 nodeRoot에 값들을 정렬해서 삽입한다.
		Insert(nodeRoot, iElement);
	}
	vector<bool> vecbAnswer;
	//search_list가 있는지 없는지를 판단해야 하므로 search_list의 size만큼 reserve
	vecbAnswer.reserve(search_list.size());
	for (const int iValue : search_list)
	{
		vecbAnswer.push_back(Search(nodeRoot, iValue));
	}

	//트리 메모리 해제
	Destroy(nodeRoot);
	nodeRoot = nullptr;

	return vecbAnswer;
}