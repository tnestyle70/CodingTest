Session - Winters 운영 방식을 C++ 코딩테스트 학습 저장소에 이식
좌표: 신규 K00 · 축: C8 검증이 병목

## 1. Decision Record

① 문제·제약: 시작 상태는 C++ 소스 1개, 학습 정본 0개, 공식 Kit 10유형 47문제이며 VS2022 빌드는 v145 부재로 실패했다.
② 순진한 해법의 실패: Winters의 1,000개 이상 문서와 엔진 모듈 구조를 그대로 복제하면 문제 풀이보다 유지 비용이 커진다.
③ 메커니즘: AGENTS, Compass, gotchas, PLAN/RESULT, tracker, build/run gate만 학습 도메인에 맞게 이식한다.
④ 대조: 기존 VS 프로젝트는 보존하고 같은 main.cpp를 빌드하는 CMake VS2026 검증 경로를 추가한다.
⑤ 대가: 프로그래머스 채점 자체는 로컬에서 재현할 수 없다. AC 상태는 사용자 제출 증거가 있을 때만 갱신한다.

## 2. Scope

- 신규: AGENTS.md, README.md, 학습 문서 구조, 47문제 tracker, AC 코드 아카이브 규칙, CMake 구성, PowerShell 빌드/실행 게이트
- 변경: 로컬 테스트 출력 라벨만 ASCII로 정리
- 보존: solution TODO, 기존 .slnx/.vcxproj, 디버깅 프로젝트
- 제외: Winters 엔진 전용 DLL/RHI/GameSim/타입 접두사 규칙

## 3. Predictions

- CMake VS2026 Debug와 Release가 같은 코딩테스트/main.cpp를 빌드한다. 미완성 solution의 두 입력은 아직 사용되지 않아 C4100 경고 2건이 예상된다.
- 기존 v145 vcxproj도 Directory.Build.props를 읽고 vcpkg 자동 연결 없이 빌드한다.
- 현재 solution이 미완성이므로 Run-CurrentProblem은 세 예제를 FAIL로 표시하고 종료 코드 1을 반환한다.
- 풀이 코드는 변경하지 않으므로 정답 상태는 달라지지 않는다.

## 4. Verification Commands

- powershell -ExecutionPolicy Bypass -File Tools/Build.ps1 -Configuration Debug
- powershell -ExecutionPolicy Bypass -File Tools/Build.ps1 -Configuration Release
- powershell -ExecutionPolicy Bypass -File Tools/Run-CurrentProblem.ps1 -SkipBuild
- Visual Studio 18 Insiders MSBuild로 기존 vcxproj Debug x64 빌드
