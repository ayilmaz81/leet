#include "TrieNode.hpp"

using namespace std;


bool TrieNode::exist(const string& word, size_t index) const{
    if (word.size() == index) return isWord;
    auto c = word[index] - 'a';
    if (children[c] != nullptr) return children[c]->exist(word,index+1);
    return false;
}
void TrieNode::addWord(const std::string& word, size_t index){
    if(index == word.size()) {isWord = true; return;}
    auto c = word[index] - 'a';
    if (children[c] == nullptr) children[c] = new TrieNode;
    return children[c]->addWord(word,index+1);
}

void TrieNode::removeWord(const std::string&word, size_t index){
    if (index == word.size()) {isWord = false; return;}
    auto c = word[index] - 'a';
    if (children[c] != nullptr) children[c]->removeWord(word,index+1);
}