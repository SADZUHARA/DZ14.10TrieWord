#include "Trie.h"
#include <iostream>
using namespace std;

int main()
{
	TrieNode Book;

	insert(&Book, "pease");
	insert(&Book, "pet");
	insert(&Book, "pro");
	insert(&Book, "profesional");
	insert(&Book, "poo");
	insert(&Book, "power");
	insert(&Book, "pork");
	insert(&Book, "pru");
	insert(&Book, "prise");
	insert(&Book, "prison");
	insert(&Book, "prisoner");

	cout << "enter word" << endl;
	string word;
	cin >> word;
	autoWordEntry(&Book, word);

}