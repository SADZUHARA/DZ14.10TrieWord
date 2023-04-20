#pragma once
#ifndef TRIE_H
#define TRIE_H

#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

// ��������� ����� ������ 
struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    // isEndOfWord - true, ���� ���� �������� ������ �����
    bool isEndOfWord;

    TrieNode();
};

TrieNode* getNewNode(void);
void insert(TrieNode*, string); //���������� �����
bool search(TrieNode*, string);
bool isEmpty(TrieNode*);
TrieNode* remove(TrieNode*, string, int depth = 0);
void findMinPrefixes(TrieNode*, char[], int, string&);  //����� ����� � ������� �� ���������
TrieNode* arrWord(TrieNode* root, int& ins, string& , string& isword); //����������� �� ������� � ���������� ��������� ��������� ���, �� �������� �����
void autoWordEntry(TrieNode*, string&); //������� ����������� �����
#endif