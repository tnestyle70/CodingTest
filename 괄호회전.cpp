#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stack>
#include <string>
#include <iostream>
using namespace std; 

int solution(const char* s) {

    string sTemp = s; 

    int n = sTemp.size(); //문자열의 길이 

    int iResult = 0; 

    for (int shift = 0; shift < n; ++shift) {
        stack<char> TempStack;

        bool isEmpty = true;

        for (int i = 0; i < n; ++i) {

            char c = s[(shift + i) % n];

            //열린 괄호일 경우 스택에 푸쉬
            if (c == '(' || c == '{' || c == '[') {
                TempStack.push(c);
            }
            //닫힌 괄호일 경우 스택의 top과 검사 -> 일치할 경우 TempStack pop(), 일치하지 않을 경우 return false; 
            else {
                if (TempStack.empty()) {
                    isEmpty = false;
                    break; //스택이 비어있을 경우 올바르지 않은 문자열, 첫번째 경우가 올바르지 않을 경우도 생각
                }
                char cTop = TempStack.top();

                if (c == ')' && cTop == '(' ||
                    c == '}' && cTop == '{' ||
                    c == ']' && cTop == '[') { //stack의 top에서 지움 
                    TempStack.pop();
                }
                else { //일치하는 닫힌 괄호가 존재하지 않을 경우 false
                    isEmpty = false;
                    break; //스택이 비어있을 경우 올바르지 않은 문자열 
                }
            }
        }
        //스택이 비어있는지 확인 (( 같은 예외 처리
        if (!TempStack.empty()) {
            isEmpty = false;
        }

        if (isEmpty) {
            iResult++;
        }
    }
    int answer = iResult; 
    return answer; 
}

int main() {
    const char* tc1 = "[](){}";
    const char* tc2 = "}]()[{";
    const char* tc3 = "[)(]";
    const char* tc4 = "[{}]()"; 

    cout << "tc1 결과: " << solution(tc1) << endl;
    cout << "tc2 결과: " << solution(tc2) << endl;
    cout << "tc3 결과: " << solution(tc3) << endl;
    cout << "tc4 결과: " << solution(tc4) << endl;

    return 0; 
}