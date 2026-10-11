# 트럭 전체 참고 풀이 결과

2026-10-11 Asia/Seoul

- 사용자의 전체 풀이 요청에 따라 퇴장 시각으로 이동하는 O(N) 참고 코드와 해설을 `.md/10-11/BRIDGE_TRUCK_REFERENCE.cpp`, `BRIDGE_TRUCK_REFERENCE_WALKTHROUGH.md`에 추가했다.
- 사용자 기존 코드·답변과 점수는 유지했다. 완료 대수 상태와 대기 큐를 줄인 이유, 시간 기준, 두 while의 역할, 정확성 및 비용을 설명했다.
- 별도 `BRIDGE_TRUCK_REFERENCE_TEST.cpp`의 MSVC C++17 /W4 /O2 컴파일 성공. 고정·최대 10개와 독립 칸 시뮬레이션 대비 33,420개 조합이 모두 통과했다.
- 컴파일러는 PATH에는 없지만 설치된 VS 18 Insiders의 vcvars64.bat을 검증용 자식 프로세스에서 사용했다. 전역 PATH·프로젝트 설정은 변경하지 않았다. 검증 실행 파일과 배치 파일은 무시되는 `out/bridge-reference-review`에 둔다.
- 프로그래머스 AC와 학습자 독립 복원은 확인하지 않았다. tracker 상태는 Attempting을 유지한다.
