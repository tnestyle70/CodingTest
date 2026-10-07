# C++ Coding Test Lab

처음 보는 문제를 해석하고, 자료구조·알고리즘을 선택해 C++17 코드로 구현·검증하는 학습 저장소다. 프로그래머스 고득점 Kit 47문제 AC와 독립적인 복원·변형 적용을 목표로 한다.

## 시작하기

1. [코딩테스트 가이드 원문 TXT](코딩테스트_가이드.txt): 사용자가 첨부한 「문제를 읽고 풀이를 만드는 통합 사고 과정」을 그대로 보관했다.
2. [같은 문서를 Markdown으로 읽기](.md/concepts/2026-10-02_UNIFIED_PROBLEM_SOLVING.md): GitHub에서 제목·표·내부 링크를 따라 읽기 편한 기존 문서다. 공통 8단계, 복잡도, 유형별 적용·실패 조건을 담고 있다.
3. [진도 정본](.md/records/HIGH_SCORE_KIT_TRACKER.md): 실제 제출과 복습 증거.

TXT는 첨부 원문을 그대로 보관하므로 그 안의 상대 링크는 원래 Markdown 위치를 기준으로 한다. 문서 사이를 이동할 때는 위 Markdown 링크를 사용한다.

## 현재 위치

2026-10-07 확인: 해시 5/5 AC, 전체 5/47 AC, Reviewed 0, Mastered 0. 다음 문제는 **같은 숫자는 싫어**이며 목표 문장부터 진행한다. 이후 상태는 진도 정본을 따른다.

## 파일 구성

- [AGENTS.md](AGENTS.md): 학습·검증 행동 규칙.
- [.md/concepts](.md/concepts/00_INDEX.md): 개념 지도와 상세 참고서. HTML은 과거판이므로 현재 Markdown을 우선한다.
- [.md/plan](.md/plan/HIGH_SCORE_KIT_ROADMAP.md): 학습 순서, 세션 PLAN/RESULT.
- [.md/records](.md/records/LEARNER_CONTEXT.md): 학습자 맥락, 진도, 날짜별 세션 기록.
- [.md/templates](.md/templates/PROBLEM_REVIEW_TEMPLATE.md): 문제 회고 형식.
- [코딩테스트/](코딩테스트/): 현재 Kit 실습. 문제별 `.cpp`에 `solution`과 로컬 `main`이 있다.
- [problems/](problems/README.md): AC 당시 보존 자료와 회고. AC 보고와 보존 코드의 정합성은 별도 검증한다.
- `Tools/`: 빌드·실행 도구.
- 루트의 기존 `.cpp`와 `코딩테스트연습.vcxproj`: GitHub main의 과거 연습 자료를 원래 경로로 보존했다. 파일 존재를 현재 Kit AC 증거로 사용하지 않는다.
- `디버깅/`: 별도의 디버깅 연습 프로젝트.

## 빌드와 실행

CMake는 `코딩테스트/*.cpp`를 파일당 별도 실행 파일로 빌드한다. 루트의 과거 코드와 `디버깅/`은 이 빌드에 포함되지 않는다. 현재 프리셋은 Visual Studio 18 2026 x64이며 기존 v145 프로젝트 설정을 유지한다.

```powershell
powershell -ExecutionPolicy Bypass -File Tools/Build.ps1 -Configuration Debug
powershell -ExecutionPolicy Bypass -File Tools/Build.ps1 -Configuration Release
powershell -ExecutionPolicy Bypass -File Tools/Run-CurrentProblem.ps1 -Problem '베스트앨범' -Configuration Debug -SkipBuild
```

`-Problem`에는 확장자를 뺀 소스 파일명을 지정한다. 생략하면 최근 수정된 `.cpp`를 고르므로 의도한 문제를 실행할 때는 명시하는 편이 확실하다. `-SkipBuild`는 해당 구성의 최신 빌드가 성공했을 때만 사용한다.

## 학습 흐름

목표 → 제약 → 예산 → 직접적인 기준선 → 병목과 방법 선택 → 코딩 전 정확성 설명 → 사용자 구현 → Build/Example/Edge/Judge → AC 후 회고와 지연 복원.

실제 문답은 한 번에 질문 하나씩 진행한다. 코딩 전·판결 후에 8단계 검문소를 확인하며, 빌드·예제·채점·숙달의 증거를 구분한다.

[프로그래머스 공식 Kit](https://school.programmers.co.kr/learn/challenges?tab=algorithm_practice_kit)
