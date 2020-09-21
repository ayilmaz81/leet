#include "ValidNumber.hpp"
#include <iostream>

using namespace std;

string ValidNumber::Input(){
    string ret;
    cin>>ret;
    return ret;
}
bool isSpace(const string &s, size_t index){
    while(++index<s.size() && s[index] == ' ');
    if (index == s.size()) return true;
    return false;
}
bool ValidNumber::Solve(const string& s){
    size_t index = 0;
    bool dotExist = false;
    while(s[index] == ' ') ++index;
    if (s[index] == '-' || s[index] == '+')++index;
    if (s[index] == '.') {
        dotExist = true;
        ++index;
    }
    if (!isdigit(s[index])) return false;
    
    while(++index<s.size() && isdigit(s[index]));
    if (index == s.size()) return true;
    
    if (s[index] == ' ') return isSpace(s,index);
    
    if (s[index] == '.') {
        if (dotExist) return false;
        while(++index<s.size()){
            if (!isdigit(s[index])){
                if (s[index] == ' ') return isSpace(s,index);
                if (s[index] != 'e') return false;
                break;
            }
        }
        if (index ==s.size()) return true;
    }
    if (s[index] != 'e' ) return false;
    if (index+1 == s.size()) return false;
    if (s[index+1] == '-' || s[index+1] == '+') ++index;
    if (index+1 == s.size()) return false;
    if (s[index+1] == ' ') return false;
    while(++index<s.size()){
        if (!isdigit(s[index])) {
            if (s[index] == ' ') return isSpace(s,index);
            return false;
        }
        
    }
    return true;
}