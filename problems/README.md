# Accepted Solution Archive

현재 편집용 코드는 `코딩테스트/<문제명>.cpp`에 둔다. 같은 숫자는 싫어의 실행 진입점은 별도 `디버깅/Debugging/SameNumberDebug.cpp`이며 편집용 코드를 포함한다. 실제 프로그래머스 AC를 받은 뒤에만 아래 구조로 제출 코드를 보존한다.

    problems/<category>/<lesson-id>_<slug>/
    ├── solution.cpp
    └── REVIEW.md

규칙:

- solution.cpp에는 프로그래머스에 제출한 solution 함수와 필요한 include만 둔다.
- REVIEW.md는 .md/templates/PROBLEM_REVIEW_TEMPLATE.md를 사용한다.
- AC 당시 코드는 사후 미화하지 않는다.
- 더 나은 풀이를 다시 작성하면 solution_reviewed.cpp로 분리하고 원본과 복잡도를 비교한다.
- 로컬 예제만 통과한 코드는 이 아카이브에 완료본으로 넣지 않는다.

