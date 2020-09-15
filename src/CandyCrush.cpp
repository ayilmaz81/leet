#include "CandyCrush.hpp"
#include <iostream>

using namespace std;


string CandyCrush::Input(){
    string inp;

    cin>>inp;

    return inp;
}

//AABBBXXX
string CandyCrush::Solve(string& input){

    int lp = 0;
    int rp = 0;
    int size = input.size();

    while (rp<size){
        if (input[lp] != input[rp]){
            if (rp - lp>2){
                while(rp<size){
                    swap(input[lp++],input[rp++]);
                }
                break;
            }
            ++lp;
        }
        ++rp;
    }

    if (rp - lp>2){
        input.erase(lp);
    }

    return input;
}