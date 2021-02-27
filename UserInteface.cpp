#include "UserInteface.h"

void UserInterface::uiStart()
{
	cout << "Menu: \n";
	cout << "\t 1. Add words.\n";
	cout << "\t 2. Remove word.\n";
	cout << "\t 3. List existing words.\n";
	cout << "\t 0. Exit.\n";
	int command = -1;
	while (true) {
		cout << "Give command: ";
		cin >> command;
		if (command == 1)
			uiAdd();
		else if (command == 2)
			uiRemove();
		else if (command == 3)
			uiList();
		else if (command == 0)
			break;
		else
			cout << "Invalid command!\n";
	}
}

void UserInterface::uiAdd()
{
	string auxiliary;
	getline(cin, auxiliary);

	//cout << "->" << auxiliary << "<-";

	string line;		//char words[100];
	getline(cin, line);	//cin.get(words, 100)
	//cout << "XD:" << line << endl;
	string word = "";

	vector <string> words = {};

	for (int i = 0; i < line.size(); ++i)
	{
		if (line[i] != ' ')
			word = word + line[i];
		else {
			words.push_back(word);
			word = "";
		}
	}
	if (word != "")
		words.push_back(word);

	vector <string> existingWords = {};
	existingWords = controller.addWordsController(words);

	if (existingWords.size() != 0)
	{
		cout << "Already existing words: ";
		for (int i = 0; i < existingWords.size(); ++i)
			cout << existingWords[i] << " ";
		cout << endl;
	}
}

void UserInterface::uiRemove()
{
	string word;
	cin >> word;
	bool ok = controller.removeWordController(word);
	if (ok == true)
		cout << "Word removed!\n";
	else
		cout << "Inexistent word!\n";
}

void UserInterface::uiList()
{
	vector <string> words = controller.getWordsListController();
	for (auto word : words)
		cout << word << " ";
	cout << endl;
}
