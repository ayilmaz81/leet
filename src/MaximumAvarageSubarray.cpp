#include "MaximumAvarageSubarray.hpp"
#include <algorithm>
#include <map>
#include <iostream>

using std::max;
using std::vector;

double MaximumAvarageSubarray::Solve(const vector<int> &nums, size_t k)
{
    vector<double> running(nums.size(), 0);
    double sum = 0;
    double currentk = k;
    double answer = INT32_MIN;

    for (size_t i = 0; i < nums.size(); ++i)
    {
        running[i] = sum + nums[i];
        sum = running[i];
        if (i >= k)
        {
            answer = max(answer, (running[i] - running[i - k]) / currentk);
        }
    }
    if (nums.size() == k)
        return running.back() / double(k);

    answer = max(answer, (running[k - 1]) / (currentk));

    for (size_t i = k; i < nums.size(); ++i)
    {
        answer = max(answer, (running[i]) / (i + 1));
        for (int j = i - k; j >= (int(i) - 2 * int(k)) && j >= 0; --j)
        {
            answer = max(answer, (running[i] - running[j]) / double(i - j));
        }
    }
    return answer;
}
