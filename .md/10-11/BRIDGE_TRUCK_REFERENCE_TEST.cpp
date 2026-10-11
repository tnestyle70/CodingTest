#include <deque>
#include <iostream>
#include <vector>

#include "BRIDGE_TRUCK_REFERENCE.cpp"

// 독립적인 검증 기준: L개 칸을 실제로 한 초에 한 칸씩 이동한다.
int simulateSlots(int length, int capacity, const std::vector<int>& trucks)
{
    std::deque<int> slots(length, 0);
    std::size_t next = 0;
    int load = 0;
    int elapsed = 0;
    while (next < trucks.size() || load > 0)
    {
        ++elapsed;
        load -= slots.front();
        slots.pop_front();
        if (next < trucks.size() && load + trucks[next] <= capacity)
        {
            slots.push_back(trucks[next]);
            load += trucks[next];
            ++next;
        }
        else
        {
            slots.push_back(0);
        }
    }
    return elapsed;
}

bool check(int length, int capacity, const std::vector<int>& trucks, int expected)
{
    const int got = solution(length, capacity, trucks);
    if (got == expected)
    {
        return true;
    }
    std::cerr << "FAIL L=" << length << " W=" << capacity << " trucks=";
    for (int w : trucks)
    {
        std::cerr << w << ',';
    }
    std::cerr << " expected=" << expected << " got=" << got << '\n';
    return false;
}

int main()
{
    if (!check(2, 10, {7, 4, 5, 6}, 8)
        || !check(100, 100, {10}, 101)
        || !check(100, 100, std::vector<int>(10, 10), 110)
        || !check(1, 1, {1}, 2)
        || !check(2, 10, {7, 4}, 5)
        || !check(5, 10, {7, 7}, 11)
        || !check(1, 10, {7, 4, 5, 6}, 5)
        || !check(10000, 10000, std::vector<int>(10000, 10000), 100000001)
        || !check(10000, 10000, std::vector<int>(10000, 1), 20000)
        || !check(1, 10000, std::vector<int>(10000, 10000), 10001))
    {
        return 1;
    }
    std::cout << "PASS fixed_and_maximum=10\n";

    int cases = 0;
    for (int capacity = 1; capacity <= 4; ++capacity)
    {
        int combinations = 1;
        for (int n = 1; n <= 6; ++n)
        {
            combinations *= capacity;
            for (int code = 0; code < combinations; ++code)
            {
                int digits = code;
                std::vector<int> trucks(n);
                for (int& w : trucks)
                {
                    w = digits % capacity + 1;
                    digits /= capacity;
                }
                for (int length = 1; length <= 5; ++length)
                {
                    if (!check(length, capacity, trucks,
                               simulateSlots(length, capacity, trucks)))
                    {
                        return 1;
                    }
                    ++cases;
                }
            }
        }
    }
    std::cout << "PASS exhaustive=" << cases << '\n';
    return 0;
}
