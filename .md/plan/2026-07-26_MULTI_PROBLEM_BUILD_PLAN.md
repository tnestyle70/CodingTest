Session - 문제 파일별 독립 실행 파일 빌드로 전환
좌표: K00 후속 · 축: C8 검증이 병목

## 1. Decision Record

① 문제·제약: 문제마다 .cpp가 늘어나는데 실행 파일이 1개라 main()이 충돌한다. 사용자가 debug.cpp 분리와 프로젝트 분할로 우회 중이고, 문제 전환마다 CMakeLists 수동 편집이 필요해 게이트 실행 마찰이 커진다 (마찰 = 게이트 생략 재발 원인).
② 순진한 해법의 실패: 활성 파일 1개만 빌드(현행)는 전환 비용이 있고, 이전 문제 재실행(24h 백지 복원 검증)이 불가능하다. 파일들을 한 프로젝트에 넣는 방식은 main() 중복 정의로 링크가 깨진다.
③ 메커니즘: 코딩테스트/*.cpp를 glob해 파일마다 add_executable을 만든다. 한글 파일명은 CMake 타깃 식별자 제약을 피하려고 타깃 이름은 problem_N, 실행 파일 이름은 OUTPUT_NAME=파일 스템으로 분리한다. Run-CurrentProblem.ps1에 -Problem 파라미터를 추가하고 기본값은 최근 수정된 .cpp로 한다.
④ 대조: VS 수동 프로젝트(.slnx/.vcxproj)는 보존한다 — 단일 vcxproj에 여러 main은 여전히 충돌하므로 저장소 공용 게이트는 CMake 경로가 정본이다 (gotchas 2026-07-22 빌드 도구 항목과 일치).
⑤ 대가: 문제 수만큼 빌드 타깃 증가 (상한 47개, 증분 빌드라 실효 비용 낮음). CONFIGURE_DEPENDS로 파일 추가 시 자동 재구성 — glob의 일반적 단점(새 파일 미감지)을 상쇄.

## 2. Scope

- 변경: CMakeLists.txt (멀티 타깃 glob), Tools/Run-CurrentProblem.ps1 (-Problem 파라미터 + 최근 수정 기본값 + 실행 대상 표시)
- 보존: Tools/Build.ps1, CMakePresets.json, VS 수동 프로젝트, 문제 소스 전부
- 제외: VS .slnx 자동 관리, 아카이브(problems/) 빌드 편입

## 3. Predictions

- Debug와 Release 모두에서 완주하지못한선수.exe와 폰켓몬.exe가 생성된다.
- Run-CurrentProblem 기본 실행 = 폰켓몬(최근 수정 파일), TC 3개 판정을 출력한다.
- 폰켓몬.cpp는 /W4에서 부호 비교 경고가 나올 수 있으나 빌드는 성공한다 (경고 해석은 사용자 몫 — 게이트 규칙).

## 4. Verification Commands

- powershell -ExecutionPolicy Bypass -File Tools/Build.ps1 -Configuration Debug
- powershell -ExecutionPolicy Bypass -File Tools/Build.ps1 -Configuration Release
- powershell -ExecutionPolicy Bypass -File Tools/Run-CurrentProblem.ps1 -SkipBuild
- powershell -ExecutionPolicy Bypass -File Tools/Run-CurrentProblem.ps1 -Problem 완주하지못한선수 -SkipBuild
