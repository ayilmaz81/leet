#include "SudokuSolver.hpp"
#include <array>
#include <bitset>
#include <iostream>

using std::vector;
using std::array;
using std::bitset;

void print(std::vector<std::vector<char>>& board) {
    for (size_t i = 0;i < board.size();++i) {
        for (size_t j = 0;j < board.front().size();++j) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

bool isvalid(std::vector<std::vector<char>>& board) {
    array<array<int, 10>, 9> r = { {0} }, c = { {0} };
    array<array<array<int, 10>, 3>, 3> s = { {{0}} };
    int remain = 0;
    for (size_t i = 0;i < board.size();++i) {
        for (size_t j = 0;j < board.front().size();++j) {
            if (board[i][j] == '.') {
                ++remain;
                continue;
            }

            if (++r[i][board[i][j] - '0'] > 1) return false;
            if (++c[j][board[i][j] - '0'] > 1) return false;
            if (++s[i / 3][j / 3][board[i][j] - '0'] > 1)  return false;;
        }
    }
    return true;
}

bool dfs(array<bitset<10>, 9>& rows, array<bitset<10>, 9>& cols, array<array<bitset<10>, 3>, 3>& squares, vector<vector<char>>& board) {
    int remain = 0;

    int nexti = -1, nextj = -1;
    vector<int> nextv;

    for (size_t i = 0;i < board.size();++i) {
        for (size_t j = 0;j < board.front().size();++j) {
            if (board[i][j] != '.') {
                continue;
            }
            ++remain;

            vector<int> available;
            for (size_t c = 1;c < 10;++c) {
                if (rows[i][c] == false && cols[j][c] == false && squares[i / 3][j / 3][c] == false) {
                    available.push_back(c);
                }
            }
            if (available.empty())  return false;
            if (nexti == -1 || nextv.size() > available.size()) {
                nextv = available;
                nexti = i;
                nextj = j;
            }
        }
    }
    if (remain == 0) {
        return true;
    }

    for (auto& c : nextv) {

        cols[nextj][c] = true;
        rows[nexti][c] = true;
        squares[nexti / 3][nextj / 3][c] = true;
        board[nexti][nextj] = '0' + c;

        if (dfs(rows, cols, squares, board)) {
            return true;
        }

        cols[nextj][c] = false;
        rows[nexti][c] = false;
        squares[nexti / 3][nextj / 3][c] = false;

        board[nexti][nextj] = '.';

    }
    return false;
}

void SudokuSolver::Solve(std::vector<std::vector<char>>& board) {
    array<bitset<10>, 9> rows;
    array<bitset<10>, 9> cols;
    array<array<bitset<10>, 3>, 3> squares;
    for (size_t i = 0;i < board.size();++i) {
        for (size_t j = 0;j < board.front().size();++j) {
            if (board[i][j] != '.') {
                rows[i].set(board[i][j] - '0');
                cols[j].set(board[i][j] - '0');
                squares[i / 3][j / 3].set(board[i][j] - '0');
            }
        }
    }
    dfs(rows, cols, squares, board);
}
