#include "DecodedStringIndex.hpp"
#include <vector>
#include <utility>
#include <cctype>
#include <stdexcept>

using std::pair;
using std::runtime_error;
using std::string;
using std::vector;

struct Token
{
    size_t start = 0;
    size_t end = 0;
    size_t repeat = 1;
    size_t counter = 0;
};

char find(vector<Token> &vp, const std::string &S, size_t K)
{
    for (size_t i = 0; i < vp.size(); ++i)
    {
        if (vp[i].counter > K)
        {
            size_t mod = (vp[i].counter / vp[i].repeat);
            K %= mod;
            size_t last = (vp[i].counter - mod * (vp[i].repeat - 1) - (vp[i].end - vp[i].start));
            if (K >= last)
            {
                return S[vp[i].start + K - last];
            }
            return find(vp, S, K);
        }
    }
    throw runtime_error("K is greater than total");
}

char DecodedStringIndex::Solve(const std::string &S, size_t K)
{
    vector<Token> vp;
    vp.push_back({0, 0, 1, 0});
    size_t lastSize = 0;
    size_t i = 1;
    while (i < S.size())
    {
        if (isdigit(S[i]))
        {
            vp.back().end = i;
            while (isdigit(S[i]))
            {
                vp.back().repeat *= (S[i++] - '0');
                if ((lastSize + vp.back().end - vp.back().start) * vp.back().repeat >= K)
                {
                    vp.back().counter = (lastSize + vp.back().end - vp.back().start) * vp.back().repeat;
                    return find(vp, S, K - 1);
                }
            }
            lastSize = (lastSize + vp.back().end - vp.back().start) * vp.back().repeat;
            vp.back().counter = lastSize;
            if (i != S.size())
            {
                vp.push_back({i, 0, 1, 0});
            }
        }
        else
        {
            ++i;
        }
    }
    if (vp.back().end == 0)
    {
        vp.back().end = i;
        vp.back().counter = (lastSize + vp.back().end - vp.back().start) * vp.back().repeat;
    }
    return find(vp, S, K - 1);
}
