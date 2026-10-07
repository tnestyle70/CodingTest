# Coding Test Compass

작성일: 2026-07-22

이 문서는 Winters Codebase Compass의 소유권·검증 사고를 코딩테스트 학습에 옮긴 활성 지도다. 파일 목록을 복사하기보다 어떤 정보가 어디에서 정본인지 정의한다.

## Outcome

최종 목표는 고득점 Kit 47문제 체크 표시가 아니다. 제한 시간 안에 처음 보는 지문을 입력 크기, 상태, 전이, 자료구조, 복잡도로 번역하고 정확한 C++17 코드로 제출하는 능력이다.

## Authority Flow

    공식 문제 조건
    -> 사용자 해석
    -> 허용 복잡도와 반례
    -> 알고리즘 불변식
    -> C++ 구현
    -> 로컬 테스트
    -> 프로그래머스 채점
    -> AC 기록과 복습 예약

- 문제 조건의 정본은 공식 문제 페이지다.
- 알고리즘 선택의 근거는 입력 범위와 불변식이다.
- 코드 정본은 현재 문제의 solution 구현이다.
- 통과 정본은 프로그래머스 AC 결과다.
- 전체 진도 정본은 .md/records/HIGH_SCORE_KIT_TRACKER.md다.

## Learning Boundaries

### Interpretation

- 먼저 무엇을 반환하는지 한 문장으로 고정한다.
- 중복, 순서, 연결, 최솟값/최댓값, 모든 경우, 연속성 같은 단어를 표시한다.
- 예시는 규칙을 설명하지만 전체 규칙을 대신하지 않는다.

### Complexity

- 입력 최댓값으로 O(N), O(N log N), O(N²), O(2^N) 후보를 판결한다.
- STL 호출의 비용을 알고 조합한다.
- 메모리 상한과 정수 범위를 함께 확인한다.

### Implementation

- 제출 함수에는 문제 해결 로직만 둔다.
- 로컬 main은 테스트 하네스이며 제출 대상과 구분한다.
- 공용 템플릿은 이해를 숨기지 않는 범위에서만 사용한다.

### Verification

- Build gate: 문법, 타입, 링크 오류를 잡는다.
- Example gate: 공식 예제를 잡는다.
- Edge gate: 빈도, 중복, 최소/최대, 오버플로, 순서 경계를 잡는다.
- Judge gate: 숨은 테스트와 성능을 판결한다.
- Review gate: 다른 풀이와 비교해 다음 문제에서 재사용할 관찰을 남긴다.

## Document Map

- AGENTS.md: 행동 규칙
- 이 문서: 학습 경계와 정보 소유권
- .md/gotchas.md: 반복 실수 방지
- .md/plan/HIGH_SCORE_KIT_ROADMAP.md: 학습 순서와 완료 기준
- .md/concepts/00_INDEX.md: 개념 지도
- .md/records/HIGH_SCORE_KIT_TRACKER.md: 47문제 진행 상태
- .md/templates/PROBLEM_REVIEW_TEMPLATE.md: 문제별 환전 기록
- problems: AC 당시 제출 코드와 문제 회고

## Done Definition

한 문제는 다음이 모두 충족되어야 Mastered다.

1. 사용자 구현으로 AC를 받았다.
2. 시간·공간 복잡도를 설명할 수 있다.
3. 핵심 불변식과 대표 반례를 말할 수 있다.
4. 24시간 이상 뒤에 핵심 아이디어를 다시 복원했다.
5. 같은 유형 변형 문제를 힌트 없이 해결했다.
