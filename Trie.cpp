#include <iostream>
#include "Trie.h"
using namespace std;

TrieNode::TrieNode()
{
 //TrieNode* node = getNewNode();
    
    for  (int i = 0; i < size(children); i++)
    {
        children[i] = nullptr;
    }
    isEndOfWord = false;
    
}

// Возвращет новый узел с пустыми детьми
TrieNode* getNewNode(void)
{
    // Выделяем память по новый узел
    struct TrieNode* pNode = new TrieNode;

    // устанавливаем флаг конца слова в false
    pNode->isEndOfWord = false;

    // инициализируем детей нулевым уазателем
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}


// Вставляет ключ в дерево, если его нет, 
// иначе если ключ явлется префксом узла дерева 
// помечает вкачестве лиcтового т.е. конец слова
void insert(TrieNode* root, string key)
{
    TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        // вычисляем индекс в алфите через смещение отнситьельно первой буквы
        int index = key[i] - 'a';

        // если указатель пустрой, т.е. детей с таким префиксом нет
        // создаем новый узел
        if (!node->children[index])
            node->children[index] = getNewNode();

        node = node->children[index];
    }

    // помечаем последний узлел как лист, т.е. конец слова
    node->isEndOfWord = true;
   // std::cout << key << std::endl;
}

// Возврашает true если ключ есть в дереве, иначе false 
bool search(struct TrieNode* root, string key)
{
    struct TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            return false;

        node = node->children[index];
    }

    return (node != nullptr && node->isEndOfWord);
}

// Вохвращает true если root имеет лист, иначе false 
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

// Рекурсивная функция удаления ключа из дерева 
TrieNode* remove(TrieNode* root, string key, int depth)
{
    // Если дерево пустое 
    if (!root)
        return nullptr;

    // если дошли до конца ключа 
    if (depth == key.size()) {

        // Этот узел больше не конец слова 
        if (root->isEndOfWord)
            root->isEndOfWord = false;

        // Если ключ не евляется префиксом, удаляем его
        if (isEmpty(root)) {
            delete (root);
            root = nullptr;
        }

        return root;
    }

    // Если не дошли до конца ключа, рекурсивно вызываем для ребенка 
    // соответствующего символа 
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);

    // Если у корня нет дочернего слова 
    // (удален только один его дочерний элемент), 
    // и он не заканчивается другим словом. 
    if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = nullptr;
    }

    // возвращаем новый корень
    return root;
}

 
void findMinPrefixes(TrieNode* root, char buf[], int ind, string& word, string& res)
{
    if (!root)
        return;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i] != nullptr)
        {
            buf[ind] = (char)(i + 'a'); //добавляем символ в временный массив символов
            buf[ind + 1] = '\0';    //следующим элементом временного массива будет его "окончание"
            ind++;  //увеличиваем число
            
            if (root->children[i]->isEndOfWord || isEmpty(root->children[i]))
            {
                res += buf;
                res += " ";
                ind--;
                cout << "found continue: ";
                //cout << word.insert(word.size(), buf) << endl;
                cout << word+buf << endl;
                //findMinPrefixes(root->children[i], buf, ind+1, res);    //Закокоментить строку чтобы искать только минимальное слово, ориентация по "концу слова"
            }
            else
            {
                findMinPrefixes(root->children[i], buf, ind, word, res);
                ind--;
            }
        }
    }
}


TrieNode* arrWord(TrieNode* root, int& ins, string& isword)  
{
    if (!root)
        return root;
    int index = isword[ins] - 'a';
             
        for (int i = 0; i < ALPHABET_SIZE; i++) //идём по массиву детей
        {
            if (root->children[i] != nullptr)
            {
                if (root->children[i] == root->children[index])
                {
                    ins++;
                    root = arrWord(root->children[i], ins, isword);
                }
            }
       
        }
        return root;
}


void autoWordEntry(TrieNode* book, string& word)
{ 
    int ins = 0;
    TrieNode* isNode = arrWord(book, ins, word);
    //cout << "ins = " << ins << endl;

    if (ins != word.size())
    {
        cout << "not found continue word: " << word << endl;
    }
    else 
    {
        char sim[10];
        string slova;
        int current = 0;
        findMinPrefixes(isNode, sim, current, word, slova);
    }
}

void variantWords(string& slova)
{
    int x = slova.find(' ');
    slova.erase(x);
    cout << "sss" << slova << "sss" << endl;

}
