#pragma once
#ifndef TRIE_H
#define TRIE_H

#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

// Структура узела дерева 
struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    // isEndOfWord - true, если ключ является концом слова
    bool isEndOfWord;

    TrieNode();
};

TrieNode* getNewNode(void);
void insert(TrieNode*, string); //добавление слова
bool search(TrieNode*, string);
bool isEmpty(TrieNode*);
TrieNode* remove(TrieNode*, string, int depth = 0);
void findMinPrefixes(TrieNode*, char[], int, string&);  //поиск слова в словаре по префиксам
TrieNode* arrWord(TrieNode* root, int& ins, string& , string& isword); //проходиться по словарю и возвращает последний найденный нод, по введёному слову
void autoWordEntry(TrieNode*, string&); //функция дописывания слова
#endif