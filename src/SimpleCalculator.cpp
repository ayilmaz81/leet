#include "SimpleCalculator.hpp"
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

string SimpleCalculator::Input(){
    string ret;
    cin>>ret;
    return ret;
}
inline int stoi(const string&s, size_t& index){
    int ret = 0;
    while(index<s.size() && !isdigit(s[index])) ++index;


    while(index<s.size() && isdigit(s[index])){
        ret = (ret*10) + (s[index] - '0');
        ++index;
    }
    return ret;

}
int helper(const string&s, size_t &index){
    int number = stoi(s, index);
    //index += dist-1;

    while(index<s.size()){
        while(index<s.size() && s[index] == ' ') ++index;
        
        if (index == s.size()) break;
        auto op = s[index];
        if (op == '-' || op == '+') break;
        
        int current = stoi(s, index);
        if (op == '*') number*= current;
        if (op == '/') number/= current;
        
    }
    return number;
}
int SimpleCalculator::Solve(const string &s){
    size_t index = 0;
    int answer = helper(s,index);

    while(index<s.size()){
        auto op = s[index];
        if (op == ' ') {
            ++index;
        }else{
            ++index;
            int nextNumber = helper(s, index);
            if (op == '+') answer += nextNumber;
            if (op == '-') answer -= nextNumber;
        }
    }
    return answer;

}
int Solve_(const string &s){
    vector<string> st;
    
    size_t rp = 0;
    int answer = 0;
    while(rp<s.size()){
        size_t endp = 0;
        int cnumber = stoi(&s[rp], &endp);
        st.push_back(to_string(cnumber));
        rp += endp;
        if (rp<s.size()){
            --rp;
            while(++rp<s.size() && !(s[rp] == '+' || s[rp] == '-' || s[rp] == '*' || s[rp] == '/'));
            if (rp == s.size()) break;
            string op;
            op.push_back(s[rp]);
            st.emplace_back(op);
            ++rp;
        }
    }
    
    for (size_t i = 1;i<st.size();++i){
        if (st[i] == "*"){
            int ans = stoi(st[i-1])*stoi(st[i+1]);
            st[i-1].clear();
            st[i].clear();
            st[i+1] = to_string(ans);
        }else if (st[i] == "/"){
            int ans = stoi(st[i-1])/stoi(st[i+1]);
            st[i-1].clear();
            st[i].clear();
            st[i+1] = to_string(ans);
        }
    }
    size_t i = 0;
    while (i<st.size() && st[i].empty()) ++i;
    answer = stoi(st[i]);
    while (++i<st.size()){
        if (st.empty()) continue;
        if (st[i] == "-"){
            while(++i<st.size()&& st[i].empty());
            answer -= stoi(st[i]);
        }else{
            while(++i<st.size()&& st[i].empty());
            
            answer += stoi(st[i]);
        }
    }
    
    return answer;
}