#pragma once
#include "Patrat.h"
#include <vector>
using namespace std;

typedef Patrat Entitate;

class Repo {
private:
	vector<Entitate> lista_patrate;
public:
	Repo() = default;
	void add_patrat(const Entitate& p);
	vector<Entitate> get_all();
};
