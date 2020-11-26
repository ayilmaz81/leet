#include "SpiralMatrix.hpp"
#include <iostream>

using namespace std;

int SpiralMatrix::Input(){
    int n;
    cin>>n;

    return n;
}

vector<vector<int>> SpiralMatrix::Solve(int N){
    vector<vector<int>> answer;
    if (N == 0) return answer;
    enum class States{
        LEFT,
        RIGHT,
        DOWN,
        UP
    };
    answer.resize(N);
    for (auto&row:answer) row.resize(N);

    States currentState = States::RIGHT;
    
    int curVal = 0, row = 0, col = 0;
    int rb = N-1, lb = 0, ub = 0, db = N-1;

    while(1){
        answer[row][col] = ++curVal;
        if (curVal == N*N) break;
        switch (currentState)
        {
            case States::RIGHT:
            if(++col == rb){
                ++ub;
                currentState = States::DOWN;
            }
            break;
            case States::DOWN:
            if (++row == db){
                --rb;
                currentState = States::LEFT;
            }
            break;
            case States::LEFT:
            if(--col == lb){
                --db;
                currentState = States::UP;
            }
            break;
            case States::UP:
            if(--row == ub){
                ++lb;
                currentState = States::RIGHT;
            }
            break;
        }
    }
    return  answer;
}