// Edit the solution in 코딩테스트/같은숫자는싫어.cpp.
// Set Debugging as the Visual Studio startup project and use Debug/x64.
// The accepted archive under problems/ remains a separate historical copy.
#include "../../코딩테스트/같은숫자는싫어.cpp"

int main()
{
    struct TestCase
    {
        const char* name;
        vector<int> input;
        vector<int> expected;
    };

    const vector<TestCase> cases = {
        {"official_1", {1, 1, 3, 3, 0, 1, 1}, {1, 3, 0, 1}},
        {"official_2", {4, 4, 4, 3, 3}, {4, 3}},
        {"one_element", {7}, {7}},
        {"two_equal", {1, 1}, {1}},
        {"two_different", {1, 2}, {1, 2}},
        {"all_equal_zero", {0, 0, 0}, {0}},
        {"separated_equal", {1, 2, 1}, {1, 2, 1}},
        {"last_single", {2, 2, 5}, {2, 5}},
        {"last_repeated", {2, 2, 5, 5}, {2, 5}},
        {"alternating_bounds", {0, 9, 0, 9}, {0, 9, 0, 9}},
    };

    const auto printVector = [](const vector<int>& values)
    {
        cout << '[';
        for (size_t i = 0; i < values.size(); ++i)
        {
            if (i != 0) cout << ',';
            cout << values[i];
        }
        cout << ']';
    };

    bool allPassed = true;
    for (const auto& test : cases)
    {
        // Put a breakpoint here; F11 enters the user's solution.
        const vector<int> actual = solution(test.input);
        const bool passed = actual == test.expected;
        allPassed = allPassed && passed;
        cout << test.name << ": " << (passed ? "PASS" : "FAIL") << " got=";
        printVector(actual);
        cout << " expected=";
        printVector(test.expected);
        cout << '\n';
    }

    // Maximum official input size; structured cases with known outputs.
    vector<int> maximum(1000000, 9);
    const bool samePassed = solution(maximum) == vector<int>{9};
    cout << "maximum_equal: " << (samePassed ? "PASS" : "FAIL") << '\n';
    allPassed = allPassed && samePassed;

    for (size_t i = 0; i < maximum.size(); ++i)
        maximum[i] = (i % 2 == 0) ? 0 : 9;
    const bool alternatingPassed = solution(maximum) == maximum;
    cout << "maximum_alternating: " << (alternatingPassed ? "PASS" : "FAIL") << '\n';
    allPassed = allPassed && alternatingPassed;

    return allPassed ? 0 : 1;
}
