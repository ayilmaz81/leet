#pragma once
#include <string>

struct TrieNode{
    bool isWord = false;
    TrieNode* children[26] = {nullptr};

    bool exist(const std::string& word, size_t index = 0) const;
    void addWord(const std::string& word, size_t index = 0);
    void removeWord(const std::string&word, size_t index =0);
};