#include <vector>
#include <string>
using namespace std;

string preorder(vector<int> nodes, int iIndex)
{
	if (iIndex < nodes.size())
	{
		//부모 순회 <- 바로 값 대입 
		string sRet = to_string(nodes[iIndex]) + " ";
		//왼쪽 자식 순회 
		sRet += preorder(nodes, iIndex * 2 + 1);
		//오른쪽 자식 순회
		sRet += preorder(nodes, iIndex * 2 + 2);
	}
	return ""; //iIndex가 nodes의 사이즈보다 커질 경우 "" 공백 리턴
}

string inorder(vector<int> nodes, int iIndex)
{
	if (iIndex < nodes.size())
	{
		//왼쪽 자식
		string sRet = inorder(nodes, iIndex * 2 + 1);
		//부모
		sRet += to_string(nodes[iIndex]);
		//오른쪽 자식
		sRet += inorder(nodes, iIndex * 2 + 2);
	}
	return "";
}

string postorder(vector<int> nodes, int iIndex)
{
	if (iIndex < nodes.size())
	{
		//왼쪽 자식
		string sRet = postorder(nodes, iIndex * 2 + 1); 
		//오른쪽 자식
		sRet += postorder(nodes, iIndex * 2 + 2); 
		//부모
		sRet += to_string(nodes[iIndex]);
	}
	return "";
}