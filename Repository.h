#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Repository {

private:
	vector <string> words;
public:
	vector <string> addWords(vector <string> addedWords);
	bool removeWord(string word);
	int findWord(string word);
	void sortWords();
	vector <string> getWordsList();
};
