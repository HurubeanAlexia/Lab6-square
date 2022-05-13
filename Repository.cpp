#include "Repository.h"

void Repo::add_patrat(const Entitate& p)
{
	lista_patrate.push_back(p);
}

vector<Entitate> Repo::get_all()
{
	return lista_patrate;
}

