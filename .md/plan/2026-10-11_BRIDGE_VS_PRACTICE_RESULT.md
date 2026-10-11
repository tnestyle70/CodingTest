# 트럭 Visual Studio 따라쓰기 준비 결과

2026-10-11 Asia/Seoul

- `코딩테스트/코딩테스트.slnx`를 VS 18 Insiders에서 열었다. 실행 후 창 제목 `코딩테스트 - Microsoft Visual Studio Insiders`를 확인했다.
- 편집 프로젝트의 `스택과큐\다리를지나는트럭` 필터에 기존 `BRIDGE_TRUCK_QUEUE_SOLUTION.cpp`, `BRIDGE_TRUCK_REFERENCE.cpp`와 새 `코딩테스트/다리를지나는트럭_따라쓰기.cpp`를 등록했다. 기존 파일은 상대경로 연결이며 원본을 복제하거나 수정하지 않았다.
- 따라쓰기 파일은 헤더·solution 시그니처·TODO·임시 return 0만 있는 미완성 작성본이다. 세 소스는 VS 편집 프로젝트의 모든 구성에서 빌드 제외다. 기존 Debugging 프로젝트와 실행 대상은 변경하지 않았다.
- CMake에는 따라쓰기 파일을 주식가격과 같은 OBJECT 타깃으로 등록해 main 없는 소스를 별도 컴파일한다.
- 프로젝트 및 필터 XML 파싱, 세 경로 존재, 필터 일치, 모든 구성 빌드 제외 설정, diff 공백 검사를 확인했다.
- VS에 설치된 CMake 4.3.1-msvc1 경로를 검증 프로세스의 PATH에만 추가하고 `Tools/Build.ps1 -Configuration Debug` 및 `Release`를 실행해 모두 통과했다. 전역 PATH는 변경하지 않았다. 로그는 무시되는 `out/bridge-vs-practice-check/cmake-debug.log`와 `cmake-release.log`에 있다.
- 새 파일은 따라쓰기 준비이며 문제 해결·실행 통과·AC 성과가 아니다. 다른 작업의 미추적 파일은 이번 변경에 포함하지 않는다.
