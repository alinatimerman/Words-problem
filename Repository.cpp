#include "Repository.h"

vector<string> Repository::addWords(vector<string> addedWords)
{
    vector <string> existingWords = {};
    for (int i = 0; i < addedWords.size(); i++) {
        if (findWord(addedWords[i]) == -1) {
            words.push_back(addedWords[i]);
        }
        else {
            existingWords.push_back(addedWords[i]);
        }
    }
    sortWords();
    return existingWords;
}

bool Repository::removeWord(string word)
{
    int index = findWord(word);
    if (index == -1)
        return false;
    words.erase(words.begin() + index);
    return true;
}

int Repository::findWord(string word)
{
    for (int i = 0; i < words.size(); i++) {
        if (word == words[i])
            return i;
    }
    return -1;
}

void Repository::sortWords()
{
    string aux;
    for (int i = 0; i < words.size() - 1; ++i) {
        for (int j = i + 1; j < words.size(); ++j) {
            if (words[i] > words[j]) {
                //swap(words[i], words[j]);
                aux = words[i];
                words[i] = words[j];
                words[j] = aux;
            }
        }
    }
}

vector<string> Repository::getWordsList()
{
    return words;
}
