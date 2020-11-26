#include "RotateArray.hpp"
#include <algorithm>

using std::swap;
using std::vector;
void RotateArray::Solve(vector<int> &input, int k)
{
    if (input.empty())
        return;
    int S = input.size();
    if (k >= S - 1)
        k %= (S);

    int K = k;
    if (2 * k > S)
    {
        K = S - k;
    }
    for (int i = 0; i < K; ++i)
    {
        swap(input[i], input[S + i - K]);
    }
    if (2 * k > S)
    {
        reverse(input.begin(), input.begin() + K);
        reverse(input.begin() + K, input.begin() + k);
        reverse(input.begin(), input.begin() + k);
    }
    else
    {
        reverse(input.end() - k, input.end());
        reverse(input.begin() + k, input.end() - k);
        reverse(input.begin() + k, input.end());
    }
}