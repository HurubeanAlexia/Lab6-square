#pragma once
#include "Service.h"

class ui {
private:
	Service& srv;
public:
	ui(Service& srv) : srv{ srv } {};
	void print();
	void ui_adauga();
	void ui_find_max_patrat();
	void ui_find_max_eq();
	void ui_find_cadI();
	void ui_print_menu();
	void run();
};