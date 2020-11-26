#include <gtest/gtest.h>
#include "IntervalMap.hpp"

using namespace std;

class KEY
{
private:
    int _key;

public:
    KEY(const KEY &key) : _key(key._key) {}
    explicit KEY(int key) : _key(key) {}
    KEY &operator=(const KEY &key)
    {
        _key = key._key;
        return *this;
    }
    bool operator<(const KEY &key) const
    {
        return _key < key._key;
    }
};

class VALUE
{
private:
    int _value;

public:
    explicit VALUE(int value) : _value(value) {}
    VALUE(const VALUE &value) : _value(value._value) {}
    VALUE &operator=(const VALUE &value)
    {
        _value = value._value;
        return *this;
    }
    bool operator==(const VALUE &value) const
    {
        return _value == value._value;
    }
};


TEST(IntervalMap, INT)
{
    IntervalMap<int, char> mm('X');
    mm.assign(1, 10, 'A');
    ASSERT_EQ(mm[-1], 'X');
    ASSERT_EQ(mm[0], 'X');
    ASSERT_EQ(mm[1], 'A');
    ASSERT_EQ(mm[2], 'A');
    ASSERT_EQ(mm[9], 'A');
    ASSERT_EQ(mm[10], 'X');
    ASSERT_EQ(mm[11], 'X');

    //TAIL
    mm.assign(10, 12, 'C');
    ASSERT_EQ(mm[9], 'A');
    ASSERT_EQ(mm[10], 'C');
    ASSERT_EQ(mm[11], 'C');
    ASSERT_EQ(mm[12], 'X');

    //TAIL 2
    mm.assign(14, 15, 'T');
    ASSERT_EQ(mm[11], 'C');
    ASSERT_EQ(mm[12], 'X');
    ASSERT_EQ(mm[13], 'X');
    ASSERT_EQ(mm[14], 'T');
    ASSERT_EQ(mm[15], 'X');
    ASSERT_EQ(mm[16], 'X');

    //HEAD

    mm.assign(-2, 1, 'D');
    ASSERT_EQ(mm[-3], 'X');
    ASSERT_EQ(mm[-2], 'D');
    ASSERT_EQ(mm[-1], 'D');
    ASSERT_EQ(mm[0], 'D');
    ASSERT_EQ(mm[1], 'A');

    //HEAD 2

    mm.assign(-5, -4, 'E');

    ASSERT_EQ(mm[-5], 'E');
    ASSERT_EQ(mm[-4], 'X');
    ASSERT_EQ(mm[-3], 'X');
    ASSERT_EQ(mm[-2], 'D');
}

TEST(IntervalMap, MID1)
{
    IntervalMap<int, char> mm('X');
    mm.assign(5, 10, 'A');
    mm.assign(6, 9, 'M');
    ASSERT_EQ(mm[6], 'M');
    ASSERT_EQ(mm[7], 'M');
    ASSERT_EQ(mm[8], 'M');
    ASSERT_EQ(mm[9], 'A');
    ASSERT_EQ(mm[10], 'X');

    map<int, char> cop;
    cop[5] = 'A';
    cop[6] = 'M';
    cop[9] = 'A';
    cop[10] = 'X';
    ASSERT_EQ(mm.mp, cop);
}

TEST(IntervalMap, MID2)
{
    IntervalMap<int, char> mm('X');
    mm.assign(1, 3, 'A');
    mm.assign(5, 10, 'B');
    mm.assign(0, 11, 'M');
    ASSERT_EQ(mm[0], 'M');
    ASSERT_EQ(mm[1], 'M');
    ASSERT_EQ(mm[2], 'M');
    ASSERT_EQ(mm[3], 'M');
    ASSERT_EQ(mm[4], 'M');
    ASSERT_EQ(mm[5], 'M');
    ASSERT_EQ(mm[6], 'M');
    ASSERT_EQ(mm[7], 'M');
    ASSERT_EQ(mm[8], 'M');
    ASSERT_EQ(mm[9], 'M');
    ASSERT_EQ(mm[10], 'M');
    ASSERT_EQ(mm[11], 'X');

    map<int, char> cop;
    cop[0] = 'M';
    cop[11] = 'X';
    ASSERT_EQ(mm.mp, cop);
}

TEST(IntervalMap, MID3)
{
    IntervalMap<int, char> mm('X');
    mm.assign(1, 3, 'A');
    mm.assign(5, 10, 'B');
    mm.assign(3, 5, 'M');
    ASSERT_EQ(mm[0], 'X');
    ASSERT_EQ(mm[1], 'A');
    ASSERT_EQ(mm[2], 'A');
    ASSERT_EQ(mm[3], 'M');
    ASSERT_EQ(mm[4], 'M');
    ASSERT_EQ(mm[5], 'B');
    ASSERT_EQ(mm[6], 'B');
    ASSERT_EQ(mm[7], 'B');
    ASSERT_EQ(mm[8], 'B');
    ASSERT_EQ(mm[9], 'B');
    ASSERT_EQ(mm[10], 'X');
    ASSERT_EQ(mm[11], 'X');

    map<int, char> cop;
    cop[1] = 'A';
    cop[3] = 'M';
    cop[5] = 'B';
    cop[10] = 'X';
    ASSERT_EQ(mm.mp, cop);
}

TEST(IntervalMap, MID4)
{
    IntervalMap<int, char> mm('X');
    mm.assign(1, 4, 'A');
    mm.assign(2, 8, 'C');
    mm.assign(8, 10, 'B');

    map<int, char> cop;
    cop[1] = 'A';
    cop[2] = 'C';
    cop[8] = 'B';
    cop[10] = 'X';
    ASSERT_EQ(mm.mp, cop);
}

TEST(IntervalMap, MID5)
{
    IntervalMap<int, char> mm('X');
    mm.assign(1, 4, 'A');
    mm.assign(8, 10, 'B');
    mm.assign(2, 9, 'C');

    map<int, char> cop;
    cop[1] = 'A';
    cop[2] = 'C';
    cop[9] = 'B';
    cop[10] = 'X';
    ASSERT_EQ(mm.mp, cop);
}

TEST(IntervalMap, CROSS1)
{
    IntervalMap<int, char> mm('X');
    mm.assign(4, 8, 'A');
    mm.assign(3, 5, 'C');

    ASSERT_EQ(mm[2], 'X');
    ASSERT_EQ(mm[3], 'C');
    ASSERT_EQ(mm[4], 'C');
    ASSERT_EQ(mm[5], 'A');
    ASSERT_EQ(mm[6], 'A');
    ASSERT_EQ(mm[7], 'A');
    ASSERT_EQ(mm[8], 'X');
}

TEST(IntervalMap, CROSS2)
{
    IntervalMap<int, char> mm('X');
    mm.assign(3, 5, 'A');
    mm.assign(4, 8, 'C');

    ASSERT_EQ(mm[2], 'X');
    ASSERT_EQ(mm[3], 'A');
    ASSERT_EQ(mm[4], 'C');
    ASSERT_EQ(mm[5], 'C');
    ASSERT_EQ(mm[6], 'C');
    ASSERT_EQ(mm[7], 'C');
    ASSERT_EQ(mm[8], 'X');
}

TEST(IntervalMap, GAP1)
{
    IntervalMap<int, char> mm('X');
    mm.assign(3, 4, 'A');
    mm.assign(7, 8, 'B');
    mm.assign(4, 7, 'G');

    ASSERT_EQ(mm[2], 'X');
    ASSERT_EQ(mm[3], 'A');
    ASSERT_EQ(mm[4], 'G');
    ASSERT_EQ(mm[5], 'G');
    ASSERT_EQ(mm[6], 'G');
    ASSERT_EQ(mm[7], 'B');
    ASSERT_EQ(mm[8], 'X');
}

TEST(IntervalMap, OVERRIDE)
{
    IntervalMap<int, char> mm('X');
    mm.assign(3, 4, 'A');
    mm.assign(3, 4, 'O');

    ASSERT_EQ(mm[2], 'X');
    ASSERT_EQ(mm[3], 'O');
    ASSERT_EQ(mm[4], 'X');
    ASSERT_EQ(mm[5], 'X');
}

TEST(IntervalMap, STRING)
{
    IntervalMap<string, int> mm(0);
    mm.assign("A1", "Z9", 1);
    ASSERT_EQ(mm["A1"], 1);
    ASSERT_EQ(mm["B"], 1);
    ASSERT_EQ(mm["Z"], 1);
    ASSERT_EQ(mm["0"], 0);
    ASSERT_EQ(mm["."], 0);
    ASSERT_EQ(mm["l"], 0);
}

TEST(IntervalMap, TYPE)
{
    IntervalMap<KEY, VALUE> mm(VALUE(-1));

    mm.assign(KEY(3), KEY(5), VALUE(10));
    mm.assign(KEY(4), KEY(10), VALUE(8));

    ASSERT_EQ(mm[KEY(2)], VALUE(-1));
    ASSERT_EQ(mm[KEY(3)], VALUE(10));
    ASSERT_EQ(mm[KEY(4)], VALUE(8));
    ASSERT_EQ(mm[KEY(5)], VALUE(8));
    ASSERT_EQ(mm[KEY(6)], VALUE(8));
    ASSERT_EQ(mm[KEY(9)], VALUE(8));
    ASSERT_EQ(mm[KEY(10)], VALUE(-1));
}

TEST(IntervalMap, REM_INIT)
{
    IntervalMap<int, char> mm('X');
    mm.assign(10,20,'X');
    ASSERT_TRUE(mm.mp.empty());
}