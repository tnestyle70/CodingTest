#include <stack>
#include <string>
#include <iostream>
using namespace std; 

//10진수 decimal을 입력 받아서 2진수로 변환해서 출력하는 soluction()

//10진수 2진수 변환 공식 
//->N을 2로 나눈 나머지 연산 값 저장하고 N은 2로 나누기
//몫이 0이 아니라면 반복 -> 즉, 1이하가 될 떄까지 반복을 하는 것이다. 
//1에서 저장한 수들 붙이기 

string solution(int decimal) {
	
	if (decimal == 0) {
		return 0; 
	}

	stack<int> sStack; 

	while (decimal > 0) {
		//2로 나눈 나머지 push
		sStack.push(decimal % 2);
		//deciaml 2로 나누기 
		decimal /= 2; 
	}

	string binary = ""; 

	while (!sStack.empty()) {
		binary = to_string(sStack.top());
		sStack.pop(); 
	}
	return binary; 
}

//

//4의 경우 -> 100
//2로 나눈 나머지 0 몫 2. 