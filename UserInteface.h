#pragma once
#include "Controller.h"

class UserInterface {

private:
	Controller controller;
public:
	void uiStart();
	void uiAdd();
	void uiRemove();
	void uiList();
};