# CLAUDE.md

이 파일은 LLM용이다 — 프로젝트 백과사전·변경 로그·코드 맵이 아니다. 여기 있는 모든 규칙은 에이전트 행동을 바꿔야 한다. 행동 핵심은 `AGENTS.md`(크로스 에이전트 정본)와 동기화한다.

## Read Order

1. 코딩 전 이 파일과 `AGENTS.md`를 읽는다.
2. `.md/gotchas.md`(오답노트)는 아래 임포트로 매 세션 로드된다.
3. 학습 경계·정보 소유권은 `.md/architecture/CODING_TEST_COMPASS.md`.
4. 진도 정본은 `.md/records/HIGH_SCORE_KIT_TRACKER.md`, 커리큘럼은 `.md/plan/HIGH_SCORE_KIT_ROADMAP.md`.

## Teaching Contract 요약

`AGENTS.md`의 Teaching Contract가 이 저장소의 최우선 규칙이다: 사용자가 먼저 해석과 접근을 제시하고, 요청 전에는 완성 정답을 공개하지 않으며, 힌트는 질문 → 핵심 관찰 → 의사코드 → 부분 코드 → 전체 풀이 순서로만, 재요청 시에만 단계 상승한다.

## Gotchas Refresh Hook

사용자가 "이 실수 다시는 하지 않도록 반영해줘" 또는 동급 요청을 하면:

- `.md/gotchas.md`를 즉시 수정할 권한으로 간주한다.
- 사건 전체가 아니라 재사용 가능한 실패 패턴을 추출해 `YYYY-MM-DD - [영역] 실수 -> 예방 규칙 또는 확인 명령` 형식 한 줄만 추가·갱신하고, 추가한 항목을 그대로 보고한다.
- 코드 검색으로 바로 확인 가능한 사실은 넣지 않는다. ~200줄을 넘으면 하위 페이지로 분리한다.

## Gotchas

오답노트는 [.md/gotchas.md](.md/gotchas.md)에 있다. 아래 임포트로 매 세션 현재 항목이 보인다.

@.md/gotchas.md

## Session Wrap-up

문제 판결(AC/오답/시간초과)이 난 세션을 닫을 때: tracker는 증거 있는 상태로만 갱신하고, 오답이면 gotchas 한 줄을 추가하고, 회고는 `.md/templates/PROBLEM_REVIEW_TEMPLATE.md` 형식으로 남긴다. 환경/구조 변경 세션은 `.md/plan/` PLAN/RESULT 쌍으로 기록한다.
