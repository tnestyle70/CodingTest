# C++ Coding Test Lab

처음 보는 문제를 해석하고, 자료구조·알고리즘을 선택해 C++17 코드로 구현·검증하는 학습 저장소다. 프로그래머스 고득점 Kit 47문제 AC와 독립적인 복원·변형 적용을 목표로 한다.

## 시작하기

1. [코딩테스트 가이드 원문 TXT](코딩테스트_가이드.txt): 사용자가 첨부한 「문제를 읽고 풀이를 만드는 통합 사고 과정」을 그대로 보관했다.
2. [같은 문서를 Markdown으로 읽기](.md/concepts/2026-10-02_UNIFIED_PROBLEM_SOLVING.md): GitHub에서 제목·표·내부 링크를 따라 읽기 편한 기존 문서다. 공통 8단계, 복잡도, 유형별 적용·실패 조건을 담고 있다.
3. [진도 정본](.md/records/HIGH_SCORE_KIT_TRACKER.md): 실제 제출과 복습 증거.
4. [공통 8단계를 실제 답변으로 작성하기](docs/study/WORKFLOW_GUIDE.md): 코드 주석 틀, 스택·큐부터 DP와 고급 문제까지 추가로 증명할 질문. [현재 코드 적용 예시](docs/study/SAME_NUMBER_WALKTHROUGH.md)와 [100문항 연습](docs/study/QUESTIONS.md)으로 이어진다.

TXT는 첨부 원문을 그대로 보관하므로 그 안의 상대 링크는 원래 Markdown 위치를 기준으로 한다. 문서 사이를 이동할 때는 위 Markdown 링크를 사용한다.

## 현재 위치

2026-10-10 확인: 해시 5/5 AC, 스택/큐 1/6 AC, 전체 6/47 AC, Reviewed 0, Mastered 0. 현재는 **같은 숫자는 싫어의 AC 후 설명·지연 복원**이며 다음 신규 문제는 기능개발이다. [이번 문제 회고](problems/stack_queue/12906_같은_숫자는_싫어/REVIEW.md)와 진도 정본을 따른다.

## 파일 구성

- [AGENTS.md](AGENTS.md): 학습·검증 행동 규칙.
- [.md/concepts](.md/concepts/00_INDEX.md): 개념 지도와 상세 참고서. HTML은 과거판이므로 현재 Markdown을 우선한다.
- [.md/plan](.md/plan/HIGH_SCORE_KIT_ROADMAP.md): 학습 순서, 세션 PLAN/RESULT.
- [.md/records](.md/records/LEARNER_CONTEXT.md): 학습자 맥락, 진도, 날짜별 세션 기록.
- [.md/templates](.md/templates/PROBLEM_REVIEW_TEMPLATE.md): 문제 회고 형식.
- [코딩테스트/](코딩테스트/): 현재 Kit 편집용 코드. 기존 해시 파일은 로컬 main을 함께 보존하고, 같은 숫자는 싫어부터 작성 코드와 Debugging 실행 진입점을 분리했다.
- [problems/](problems/README.md): AC 당시 보존 자료와 회고. AC 보고와 보존 코드의 정합성은 별도 검증한다.
- `Tools/`: 빌드·실행 도구.
- 루트의 기존 `.cpp`와 `코딩테스트연습.vcxproj`: GitHub main의 과거 연습 자료를 원래 경로로 보존했다. 파일 존재를 현재 Kit AC 증거로 사용하지 않는다.
- `디버깅/`: 중단점·로컬 검증 프로젝트. 현재 `SameNumberDebug.cpp`가 편집용 같은숫자는싫어.cpp를 포함한다. 이전 Debug.cpp는 보존하며 빌드에서 제외했다.

## 빌드와 실행

CMake는 문제별 실행 파일을 만든다. 기존 해시는 `코딩테스트/*.cpp`의 main을 사용하고, 같은 숫자는 싫어는 `디버깅/Debugging/SameNumberDebug.cpp`를 진입점으로 사용한다. 루트의 과거 코드와 기존 Debug.cpp는 이 빌드에 포함되지 않는다. 현재 프리셋은 Visual Studio 18 2026 x64이며 기존 v145 프로젝트 설정을 유지한다.

```powershell
powershell -ExecutionPolicy Bypass -File Tools/Build.ps1 -Configuration Debug
powershell -ExecutionPolicy Bypass -File Tools/Build.ps1 -Configuration Release
powershell -ExecutionPolicy Bypass -File Tools/Run-CurrentProblem.ps1 -Problem '베스트앨범' -Configuration Debug -SkipBuild
```

`-Problem`에는 확장자를 뺀 소스 파일명을 지정한다. 생략하면 최근 수정된 `.cpp`를 고르므로 의도한 문제를 실행할 때는 명시하는 편이 확실하다. `-SkipBuild`는 해당 구성의 최신 빌드가 성공했을 때만 사용한다.

Visual Studio 중단점 검증은 [코딩테스트.slnx](코딩테스트/코딩테스트.slnx)를 열고 **Debugging을 시작 프로젝트**, **Debug/x64**로 설정한다. 작성은 [같은숫자는싫어.cpp](코딩테스트/같은숫자는싫어.cpp), 실행은 [SameNumberDebug.cpp](디버깅/Debugging/SameNumberDebug.cpp)의 main에서 진행한다. 편집용 파일은 코딩테스트 프로젝트의 독립 실행 빌드에서 제외되어 있다.

2026-10-10 이 데스크탑에서는 CMake 명령을 찾지 못해 Debug/Release 구성 시작 전 빌드가 실패했다. 사용자 보고 Judge AC와 로컬 실행 성공을 구분하며, 검증 상세는 [결과 기록](.md/plan/2026-10-10_STACK_QUEUE_AC_RESULT.md)을 따른다.

## 학습 흐름

목표 → 제약 → 예산 → 직접적인 기준선 → 병목과 방법 선택 → 코딩 전 정확성 설명 → 사용자 구현 → Build/Example/Edge/Judge → AC 후 회고와 지연 복원.

실제 문답은 한 번에 질문 하나씩 진행한다. 코딩 전·판결 후에 8단계 검문소를 확인하며, 빌드·예제·채점·숙달의 증거를 구분한다.

[프로그래머스 공식 Kit](https://school.programmers.co.kr/learn/challenges?tab=algorithm_practice_kit)
