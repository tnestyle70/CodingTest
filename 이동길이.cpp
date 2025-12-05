#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(const char* dirs) {

	int Pannel[10][10]; //패널 100으로 초기화, 이동한 길의 값이 100일 경우 이동하지 않았던 길이라는 아이디어
	for (int i = 0; i < 10; ++i) {
		for (int k = 0; k < 10; ++k) {
			Pannel[i][k] = 100; 
		}
	}
	int iR = 4; int iC = 4; int iCount = 0; 

	Pannel[iR][iC] = 1; //4,4 시작점을 1로 초기화 

	for (int i = 0; dirs[i] != '\0'; ++i) {
		char c = dirs[i];

		switch (c) {
		case 'U': {
			if (iR + 1 > 9) {
				continue; 
			}
			else {
				if (Pannel[iR + 1][iC] == 100) { //지나가지 않을 길
					Pannel[iR + 1][iC] = 1; // 지나간 길의 값으로 1 대입, 지나간 길임을 표시 
					iCount++; 
				}
				else if (Pannel[iR + 1][iC] == 1) {//지나간 길
					Pannel[iR + 1][iC] = 1; //iCount++를 하지 않음
				}
				iR += 1; //iR 값 1 증가
			}
			break; 
		}
		case 'D': {
			if (iR - 1 < 0) {
				continue;
			}
			else {
				if (Pannel[iR - 1][iC] == 100) { //지나가지 않을 길
					Pannel[iR - 1][iC] = 1; // 지나간 길의 값으로 1 대입, 지나간 길임을 표시 
					iCount++;
				}
				else if (Pannel[iR - 1][iC] == 1) {//지나간 길
					Pannel[iR - 1][iC] = 1; //iCount++를 하지 않음
				}
				iR -= 1; //iR 값 1 감소
			}
			break;
		}
		case 'L': {
			if (iC - 1 < 0) {
				continue;
			}
			else {
				if (Pannel[iR][iC - 1] == 100) { //지나가지 않을 길
					Pannel[iR][iC - 1] = 1; // 지나간 길의 값으로 1 대입, 지나간 길임을 표시 
					iCount++;
				}
				else if (Pannel[iR][iC - 1] == 1) {//지나간 길
					Pannel[iR][iC - 1] = 1; //iCount++를 하지 않음
				}
				iC -= 1; //iC 값 -1 감소
			}
			break;
		}
		case 'R': {
			if (iC + 1 > 9) {
				continue;
			}
			else {
				if (Pannel[iR][iC + 1] == 100) { //지나가지 않을 길
					Pannel[iR][iC + 1] = 1; // 지나간 길의 값으로 1 대입, 지나간 길임을 표시 
					iCount++;
				}
				else if (Pannel[iR][iC + 1] == 1) {//지나간 길
					Pannel[iR][iC + 1] = 1; //iCount++를 하지 않음
				}
				iC += 1; //iC 값 1 증가
			}
			break;
		}
		}
	}
	int answer = iCount;

	return answer;
}

int main() {
	 
	solution("UUUUU"); 
	return 0; 
}