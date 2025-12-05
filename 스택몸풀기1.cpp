#include <iostream>
#include <stack>
using namespace std;

//소괄호는 짝은 맞춘 괄호와 맞추지 않은 괄호로 구성됨. 
//정상으로 소괄호가 맞춰졌는지 판단하는 solution 함수 구현
//열린 괄호 push, 인접한 다른 부분에 닫힌 괄호가 있으면 열린 괄호 pop 
//위 과정 반복해서 스택이 비어있으면 true, 아니면 false return

bool solution(string s) {
	stack<char> sStack; 

	//s의 크기 만큼 for문을 돌며 ( 열린 괄호 push 
	for (char c : s) {
		if (c == '(') {
			sStack.push('('); 
		}
	}
	//s 안에 )가 존재하면 sStack pop -> ( 하나씩 빠지게 됨 
	for (char c : s) {
		//짝이 존재하면 pop
		if (c == ')') {
			sStack.pop(); 
		}
		//스택이 비어있으면 return false
		else if (sStack.empty()) {
			return false; 
		}
	}

	if (!sStack.empty()) {
		return true;
	}
	else return false;
}

//시간 복잡도 O(N), push, pop의 시간 복잡도 O(1) 

int main() {
	
}