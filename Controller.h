#pragma once
#include "Repository.h"

class Controller {

private:
	Repository repository;
public:
	vector <string> addWordsController(vector <string> addedWords);
	bool removeWordController(string word);
	vector <string> getWordsListController();
};