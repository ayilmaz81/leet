#include "LargeFactorial.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

using std::string;
using std::to_string;

string multiply(string &&s1, string &s2)
{
    string answer(s1.size() + s2.size(), '0');

    int counter = answer.size() - 1;
    int carryAdd = 0;
    for (int i = s1.size() - 1; i >= 0; --i)
    {
        int carryMultiply = 0;
        for (int j = s2.size() - 1; j >= 0; --j)
        {
            int a = s1[i] - '0';
            int b = s2[j] - '0';
            int p = answer[counter - (s2.size() - j - 1)] - '0';
            int current = a * b + carryMultiply;
            carryMultiply = current / 10;
            current %= 10;
            int t = current + carryAdd + p;
            carryAdd = t / 10;
            t %= 10;
            answer[counter - (s2.size() - j - 1)] = t + '0';
        }
        int t = answer[counter - (s2.size())] - '0' + carryAdd + carryMultiply;
        carryAdd = t / 10;
        t %= 10;
        answer[counter - (s2.size())] = t + '0';
        --counter;
    }
    if (carryAdd > 0)
        answer.front() = carryAdd + '0';
    while (answer.size() > 1 && answer.front() == '0')
        answer.erase(answer.begin());

    return answer;
}

string LargeFactorial::Solve(int n)
{

    string answer = to_string(n);

    while (n-- > 2)
    {
        answer = multiply(to_string(n), answer);
    }

    return answer;
}
