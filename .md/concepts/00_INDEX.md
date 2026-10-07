# Algorithm Concept Index

2026-10-07 GitHub 동기화: [코딩테스트 가이드 원문 TXT](../../코딩테스트_가이드.txt)에 사용자가 첨부한 통합 사고 과정 텍스트를 그대로 보관했다. 제목·표·문서 링크를 따라 읽을 때는 아래 Markdown 문서를 사용한다.

상태는 Not Started, Learning, Converted 중 하나다. Converted는 해당 개념을 사용한 실전 문제 AC가 최소 1개 있다는 뜻이다.

2026-10-02 통합 학습 안내: [문제를 읽고 풀이를 만드는 통합 사고 과정](2026-10-02_UNIFIED_PROBLEM_SOLVING.md) — 공통 8단계의 답 생성법, 복잡도 합산, 10유형의 적용·실패 조건, 스택/큐 진입 원리. [오늘 세션 기록](../records/2026-10-02_UNIFIED_THINKING_SESSION.md)에는 학습자 관찰과 교재 교정을 분리해 기록한다. 이번 개념 설명만으로 상태를 올리지는 않는다.

아래 HTML판은 2026-07 보관본이다. 2026-10-02 교정 내용은 Markdown 정본과 위 통합 문서를 우선한다.

본질 문법(마스터 식 × 유형 10개 × 회고 템플릿 매핑)은 [ESSENCE_BRIDGE.md](ESSENCE_BRIDGE.md) — 매 문제 코딩 전 선서술(한 문장 목표+불변식)의 근거 문서다.

STL 컨테이너 비용 정본은 [STL_COST_SHEET.md](STL_COST_SHEET.md) — 예산 산술 때 옆에 두는 표다 (연산당 vs 구축 비용 구분, 함정 노트 포함).

자료구조·알고리즘·복잡도의 정의 정본은 [ESSENCE_CORE.md](ESSENCE_CORE.md) ([HTML](ESSENCE_CORE.html)) — 두 본질 정의, 시간·공간 예산표, 반복 질문→자료구조 표, 패러다임 표. 매 kit에서 다시 묻지 않기 위한 문서다.

검문소 질문 해설 정본은 [CHECKPOINT_QUESTIONS.md](CHECKPOINT_QUESTIONS.md) ([HTML](CHECKPOINT_QUESTIONS.html)) — 질문 1(목표 고정)부터 6(선서술)까지 각 질문의 요지·본질·합격 기준·실사고 앵커.

| 순서 | 개념 | 핵심 질문 | 상태 |
|---:|---|---|---|
| 0 | 복잡도와 STL 비용 | 입력 최댓값이 허용하는 연산 수는 얼마인가? | Learning |
| 1 | 해시 | 값을 키로 바꾸면 탐색·빈도 계산이 단순해지는가? | Learning |
| 2 | 스택/큐 | 처리 순서가 LIFO/FIFO 또는 대기열인가? | Not Started |
| 3 | 정렬 | 순서를 바꾸면 비교 구조가 단순해지는가? | Not Started |
| 4 | 완전탐색 | 상태 공간이 충분히 작고 모든 경우를 만들 수 있는가? | Not Started |
| 5 | 힙 | 매 순간 최솟값/최댓값을 반복해서 꺼내는가? | Not Started |
| 6 | DFS/BFS | 상태를 노드, 가능한 행동을 간선으로 볼 수 있는가? | Not Started |
| 7 | 그리디 | 현재 선택이 미래 최적해를 해치지 않음을 증명할 수 있는가? | Not Started |
| 8 | 이분탐색 | 답 후보에 단조성이 있는가? | Not Started |
| 9 | 동적 계획법 | 중복 부분 문제와 최적 부분 구조가 있는가? | Not Started |
| 10 | 그래프 | 연결, 최단거리, 순위, 신장 트리 구조인가? | Not Started |

각 개념 문서는 다음을 포함한다.

- 알아볼 신호
- 가장 단순한 기준선
- 핵심 불변식
- C++ STL 도구와 비용
- 자주 틀리는 경계
- 변형 문제
