#pragma once
#include "Repository.h"

class Service {
private:
	Repo& repo;
public:
	Service(Repo& repo) : repo{ repo } {};
	void adauga_patrat(const char* nume, double latura, punct centru);
	Entitate find_max_patrat();
	vector<Entitate> get_all();
	vector<Entitate> find_max_equal();
	vector<Entitate> find_cadI();

};