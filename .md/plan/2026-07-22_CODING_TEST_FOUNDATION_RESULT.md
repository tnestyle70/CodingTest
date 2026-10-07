Session - Winters 운영 방식을 C++ 코딩테스트 학습 저장소에 이식한 결과
좌표: K00 · 축: C8 검증이 병목
관련: 2026-07-22_CODING_TEST_FOUNDATION_PLAN.md

## 1. Prediction vs Measurement

- 적중: CMake Visual Studio 18 2026 Debug와 Release가 모두 성공했다.
- 적중: 기존 v145 vcxproj도 Debug/Release x64가 모두 성공했다.
- 적중: 두 빌드 경로 모두 C++17, /W4, /utf-8로 컴파일됐고 vcpkg 자동 연결은 사라졌다.
- 적중: 미완성 solution 때문에 participant와 completion에 C4100 경고가 각각 발생했다.
- 적중: Run-CurrentProblem은 세 예제 FAIL을 읽고 종료 코드 1을 반환했다.
- 적중: solution 본문은 변경하지 않았고 테스트 출력 라벨만 ASCII로 바꿨다.
- 확인: 공식 고득점 Kit 정본은 10개 유형 47문제이며 tracker 링크 47개로 고정했다.

## 2. Verdict

계획 유지. AGENTS, Compass, gotchas, PLAN/RESULT, 개념 지도, 47문제 tracker, AC 코드 아카이브, 문제 회고 템플릿, CMake와 PowerShell 게이트가 같은 학습 흐름을 가리킨다.

Winters 원본은 읽기 전용으로 사용했으며 수정하지 않았다. 엔진 전용 DLL/RHI/GameSim 규칙과 방대한 산출물 폴더는 학습 저장소에 복제하지 않았다.

## 3. Updated Tradeoff

- C4100 경고 2건은 빈 solution 상태를 정직하게 보여주는 신호다. 첫 구현이 입력을 사용하면 자연히 사라져야 한다.
- 로컬 게이트는 예제와 직접 만든 반례만 판정한다. 숨은 테스트·성능의 최종 권위는 계속 프로그래머스 제출 결과다.
- 문서 구조가 문제 풀이 시간을 잠식하면 새 문서를 늘리지 않고 tracker와 문제 회고 두 정본만 유지한다.

## 4. Evidence

- Tools/Build.ps1 -Configuration Debug: exit 0
- Tools/Build.ps1 -Configuration Release: exit 0
- Visual Studio 18 MSBuild Debug x64: exit 0, warning 2, error 0
- Visual Studio 18 MSBuild Release x64: exit 0, warning 2, error 0
- Tools/Run-CurrentProblem.ps1 -SkipBuild: exit 1, local FAIL 3/3
