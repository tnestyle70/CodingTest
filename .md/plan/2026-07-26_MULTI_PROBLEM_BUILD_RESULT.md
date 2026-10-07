Session - 문제 파일별 독립 실행 파일 빌드로 전환 (RESULT)
PLAN: 2026-07-26_MULTI_PROBLEM_BUILD_PLAN.md

## Outcome vs Predictions

- 예측 1 (Debug/Release 각각 문제별 exe 생성): 적중 — 완주하지못한선수.exe, 폰켓몬.exe 두 구성 모두 생성.
- 예측 2 (기본 실행 대상 = 최근 수정 파일): 적중 — 선택 로직이 폰켓몬을 반환. 실행 자체는 사용자 게이트 몫으로 미실시.
- 예측 3 (/W4 경고, 빌드는 성공): 적중 — 폰켓몬.cpp(29, 45) C4267 2건. 해석은 사용자 몫.

## Deviations (예측 실패 2건)

1. CMakePresets.json의 buildPresets가 삭제된 CodingTest 타깃을 고정하고 있어 스테일 vcxproj가 빌드됨 (main.cpp C1083). 수정 = targets 핀 제거(전체 빌드 기본값) + out/build/vs2026 캐시 청소.
2. Run-CurrentProblem.ps1에 한글 경로를 추가하면서 BOM 없는 UTF-8로 저장돼 Windows PowerShell 5.1이 파서 오류를 냄. 수정 = UTF-8 BOM으로 재저장. 교훈: 한글이 들어가는 .ps1은 BOM 필수.

## Verification (실측)

- Tools/Build.ps1 -Configuration Debug: 성공 (전 타깃)
- Tools/Build.ps1 -Configuration Release: 성공 (전 타깃)
- Tools/Run-CurrentProblem.ps1 -Problem 완주하지못한선수 -SkipBuild: TC 3/3 PASS, exit 0
- 신규 문제 추가 절차 = 코딩테스트/에 .cpp 추가만 하면 됨 (CONFIGURE_DEPENDS가 자동 재구성)
