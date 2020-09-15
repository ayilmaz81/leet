#include "TrieNode.hpp"

using namespace std;


bool TrieNode::exist(const string& word, int index) const{
    if (word.size() == index) return isWord;
    auto c = word[index] - 'a';
    if (children[c] != nullptr) return children[c]->exist(word,index+1);
    return false;
}
void TrieNode::addWord(const std::string& word, int index){
    if(index == word.size()) {isWord = true; return;}
    auto c = word[index] - 'a';
    if (children[c] == nullptr) children[c] = new TrieNode;
    return children[c]->addWord(word,index+1);
}

void TrieNode::removeWord(const std::string&word, int index){
    if (index == word.size()) {isWord = false; return;}
    auto c = word[index] - 'a';
    if (children[c] != nullptr) children[c]->removeWord(word,index+1);
}

class MostTraded{
    int numberOfShares;
    unordered_map<string,int> shares;
    set<pair<int,string>> topK;
    public:
    
    MostTraded(int n):numberOfShares(n){}
    
    void addTrade(const string& entity, int number){
        auto leastTraded = topK.begin();
        if (leastTraded != topK.end() && leastTraded->first < shares[entity] + number){
            auto it = topK.find({shares[entity], entity});
            if (it != topK.end()){
                topK.erase(it);
            }
            topK.insert({shares[entity], entity});
            if (topK.size() > numberOfShares){
                topK.erase(topK.begin());
            }
        }
        shares[entity] += number;

        
    }
    void printMostTraded(){
        
    }
}
