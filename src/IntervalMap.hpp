#include <map>
template <typename KEY, typename VALUE>
class IntervalMap
{
    VALUE valBegin;

public:
    std::map<KEY, VALUE> mp;

    IntervalMap(VALUE const &val)
        : valBegin(val)
    {
    }

    void assign(KEY const &keyBegin, KEY const &keyEnd, VALUE const &value)
    {
        if (value == valBegin || !(keyBegin < keyEnd))
            return;
        if (mp.empty())
        {
            mp.insert({keyBegin, value});
            mp.insert({keyEnd, valBegin});
            return;
        }
        auto itUpper = mp.upper_bound(keyEnd);
        auto prevVal = (itUpper != mp.begin()) ? prev(itUpper)->second : valBegin;

        auto insertResult = mp.insert({keyBegin, value});
        if (insertResult.second == false)
        {
            insertResult.first->second = value;
        }

        auto it = next(insertResult.first);
        while (it != itUpper)
        {
            auto nxt = next(it);
            mp.erase(it);
            it = nxt;
        }
        mp.insert({keyEnd, prevVal});
    }

    VALUE const &operator[](KEY const &key) const
    {
        auto it = mp.upper_bound(key);
        if (it == mp.begin())
        {
            return valBegin;
        }
        else
        {
            return (--it)->second;
        }
    }
};
