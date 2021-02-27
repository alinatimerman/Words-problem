#include "Controller.h"

vector<string> Controller::addWordsController(vector<string> addedWords)
{
    vector <string> goodWords = {};
    bool ok = true;
    for (int i = 0; i < addedWords.size(); ++i)
    {
        //cout << addedWords[i] << "->xd\n";
        ok = true;
        for (int j = 0; j < addedWords[i].size(); ++j)
        {
            //if (!((addedWords[i][j] > 'a' && addedWords[i][j] < 'z') || (addedWords[i][j] > 'A' && addedWords[i][j] < 'Z')))
            if (addedWords[i][j] < 'A' || (addedWords[i][j] > 'Z' && addedWords[i][j] < 'a') || addedWords[i][j] > 'z' )
            {
                ok = false;
                break;
            }
        }
        if (ok == true)
            goodWords.push_back(addedWords[i]);
    }
    return repository.addWords(goodWords);
}

bool Controller::removeWordController(string word)
{
    for (auto character : word)
        if (character < 'A' || (character > 'Z' && character < 'a') || character > 'z')
            return false;
    return repository.removeWord(word);
}

vector<string> Controller::getWordsListController()
{
    return repository.getWordsList();
}
