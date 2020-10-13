#include "FibonacciSum.hpp"
#include <vector>
using namespace std;


vector<int> fibnums{1,1};

int rec(int current){
    if (current == 0) return 0;
    auto it = lower_bound(fibnums.begin(), fibnums.end(), current);     
    if (*it>current) return rec(current-*prev(it))+1;
    return rec(current-*it)+1;
}

int FibonacciSum::Solve(int k) {
    auto index = 2;
    while(fibnums.back()<k){
        fibnums.push_back(fibnums[index-1]+fibnums[index-2]);
        ++index;
    }
    return rec(k);
}