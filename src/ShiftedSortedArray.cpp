#include "ShiftedSortedArray.hpp"
#include <iostream>
#include <algorithm>



using namespace std;
pair<vector<int>, int> ShiftedSortedArray::Input(){
    vector<int> vec;
    int k,v,n;
    
    cin>>v;
    cin>>k;
    cin>>n;

    k = k%n;
    vec.resize(n);
    while(n--){
        cin>>vec[n];
    }

    sort(vec.begin(),vec.end());
    rotate(vec.begin(), vec.begin() + k, vec.end());

    return {vec, v};

}


// [5 6 7 8 9 10 1 2 3 4] , 4
bool ShiftedSortedArray::Solve(const vector<int>& input, int target){

    if (input.empty()) return false;
    int left = 1;
    int right = input.size()-1;
    int pivot = 0;

    while(left<=right){
        int mid = (left+right)/2;
        if (input[mid] < input[pivot])
            pivot = mid;
        
        if (input[mid] > input.front()){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }

    auto it = lower_bound(input.begin(), input.begin()+pivot-1, target);
    if (it != input.end() &&  *it == target) return true;
    
    it = lower_bound(input.begin()+pivot, input.end(), target);
    if (it != input.end() && *it == target) return true;

    return false;
}