
#include "PalindromePartitioning.hpp"
#include <unordered_map>
#include <iostream>
#include <algorithm>

using std::string;
using std::vector;

bool isPalindrome(const string &s, int left, int right)
{
    while (right >= left && s[left++] == s[right--]);
    return s[left - 1] == s[right + 1];
}
void findPalindrome(const string &s, size_t index, vector<string> &cur, vector<vector<string>> &answer)
{
    if (index >= s.size())
    {
        answer.push_back(cur);
        return;
    }
    for (size_t i = index; i < s.size(); ++i)
    {
        if (isPalindrome(s, index, i))
        {
            cur.push_back(s.substr(index, i - index + 1));
            findPalindrome(s, i + 1, cur, answer);
            cur.pop_back();
        }
    }
}

std::vector<std::vector<std::string>> PalindromePartitioning::Solve(const string &s)
{
    vector<string> current;
    vector<vector<string>> answer;
    findPalindrome(s, 0, current, answer);
    return answer;
}