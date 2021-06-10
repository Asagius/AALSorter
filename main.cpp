#include <iostream>
#include "Input.h"
#include "BasicSorter.h"
#include "ImprovedSorter.h"
#include "Tester.h"
#include "Generator.h"
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <forward_list>
#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <chrono>

using namespace std;

enum class Color : std::uint8_t {
    C,
    M,
    Y,
    K,
};

namespace std {
    std::ostream &operator<<(std::ostream &os, Color color)
    {
        static const char letters[] = "CMYK";

        os << letters[static_cast<std::size_t>(color)];

        return os;
    }
}

class State {
public:
    State()
    {
        steps = 0;
        colors = {};
    }

    std::size_t countDisplaced() const
    {
        std::size_t count = 0;

        for (std::size_t i = 0; i < colors.size(); ++i) {
            if (static_cast<std::size_t>(colors[i]) != i % 4) {
                ++count;
            }
        }

        return count;
    }

    bool operator==(const State &other) const
    {
        assert(colors.size() == other.colors.size());

        for (std::size_t i = 0; i < colors.size(); ++i) {
            if (colors[i] != other.colors[i]) {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const State &other) const
    {
        return !(*this == other);
    }

    bool operator>(const State &other) const
    {
        assert(colors.size() == other.colors.size());

        if (steps != other.steps) {
            return (steps > other.steps);
        }

        return (countDisplaced() > other.countDisplaced());
    }

    std::size_t steps;
    std::vector<Color> colors;
};

namespace std {
    std::ostream &operator<<(std::ostream &os, const State &state)
    {
        for (std::size_t i = 0; i < state.colors.size(); ++i) {
            os << state.colors[i];
        }

        os << '#' << state.steps;

        return os;
    }

    template <>
    struct hash<State> {
        std::size_t operator()(const State &state) const
        {
            std::size_t h = 111;

            for (auto color : state.colors) {
                h *= 5;
                h += static_cast<std::size_t>(color);
            }

            return h;
        }
    };
}

std::size_t sortedPrefixLength(const State &state)
{
    std::size_t length = 0;

    for (std::size_t i = 0; i + 3 < state.colors.size(); i += 4) {
        if (state.colors[i] != Color::C || state.colors[i + 1] != Color::M || state.colors[i + 2] != Color::Y || state.colors[i + 3] != Color::K) {
            break;
        }

        length += 4;
    }

    return length;
}

State moveToEnd(State state, std::size_t pos)
{
    assert(pos + 3 < state.colors.size());

    ++state.steps;

    auto begin = state.colors.begin() + pos;

    std::rotate(begin, begin + 4, state.colors.end());

    return state;
}

State undoMoveToEnd(State state, std::size_t pos)
{
    assert(pos + 3 < state.colors.size());
    assert(state.steps > 0);

    --state.steps;

    auto end = state.colors.end();

    std::rotate(state.colors.begin() + pos, end - 4, end);

    return state;
}

bool isSorted(const State &state)
{
    std::size_t counters[4] = {0, 0, 0, 0};

    std::size_t prefixLength = sortedPrefixLength(state);

    for (std::size_t i = prefixLength; i < state.colors.size(); ++i) {
        ++counters[static_cast<std::size_t>(state.colors[i])];
    }

    for (std::size_t j = 0; j < 4; ++j) {
        if (counters[j] == 0) {
            return true;
        }
    }

    return false;
}

std::optional<State> solve(State initialState, std::deque<std::pair<State, std::size_t>> &moves, std::size_t limit)
{
    moves.clear();

    if (isSorted(initialState)) {
            return initialState;
    }

    std::priority_queue<State, std::vector<State>, std::greater<State>> queue;
    queue.push(initialState);

    std::unordered_map<State, std::size_t> visited;
    visited.insert({initialState, -1});

    while (!queue.empty() && limit-- > 0) {
        State state = queue.top();
        queue.pop();
        //std::cout << "POP " << state << '/' << state.countDisplaced() << '\n';

        for (std::size_t i = 0; i + 4 < state.colors.size(); ++i) {
            State newState = moveToEnd(state, i);
            //assert(state == undoMoveToEnd(newState, i));

            if (isSorted(newState)) {
                std::size_t lastMove = i;
                State lastState = state;

                while (true) {
                    moves.push_front({lastState, lastMove});

                    if (lastState.steps == 0) {
                        break;
                    }

                    lastMove = visited[lastState];
                    lastState = undoMoveToEnd(lastState, lastMove);
                }

                return newState;
            }

            if (visited.find(newState) != visited.end()) {
                continue;
            }

            //std::cout << "NEW " << newState << '/' << newState.countDisplaced() << '\n';
            visited.insert({newState, i});
            queue.push(newState);
        }
    }

    return std::nullopt;
}


int main(int argc, char *argv[]) {

    int iterations = atoi(argv[1]);
    int size = atoi(argv[2]);

    State initialState;
    Input input;
    input.read();

    vector<char> tab;
    tab=input.getShelf();
    for (int i = 0; i< tab.size(); i++){
        switch (tab[i]){ 
            case 'C':
                initialState.colors.push_back(Color::C);
                break;

            case 'M':
                initialState.colors.push_back(Color::M);
                break;

            case 'Y':
                initialState.colors.push_back(Color::Y);
                break;

            case 'K':  
                initialState.colors.push_back(Color::K);
                break;

            default:
                break;
            } 
        }     
std::deque<std::pair<State, std::size_t>> moves;

    auto t1 = std::chrono::high_resolution_clock::now();
    std::optional<State> result = solve(initialState, moves, 1000000);
    auto t2 = std::chrono::high_resolution_clock::now();


    if (!result) {
        std::cout << "Unable to solve\n";
        return 1;
    }

    Tester tester;
    tester.tests(iterations, size);
    cout << "Algorythms Basic and Improved: " << endl;
    cout << "Number of Iterations: " << iterations << "; Size of sequence: " << size << endl;
    tester.results();
    cout << "Algorythm BFS: " << endl;

    std::cout << "number of steps = " << moves.size() << '\n';
    std::cout << "t = " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms\n";

    for (auto p : moves) {
        std::cout << p.first << '\n';
        std::cout << std::string(p.second, ' ') << "^~~~" << '\n';
    }

    std::cout << *result << '\n';
}