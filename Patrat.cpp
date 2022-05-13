#include "Patrat.h"

Patrat::Patrat(const char* p, double latura_patrat, punct centru_patrat)
{
	this->nume = new char[strlen(p) + 1];

	strcpy_s(this->nume, strlen(p) + 1, p);
	this->latura = latura_patrat;
	this->centru = centru_patrat;
}

Patrat::Patrat(const Patrat& p)
{
	this->nume = new char[strlen(p.nume) + 1];
	strcpy_s(this->nume, strlen(p.nume) + 1, p.nume);
	this->latura = p.latura;
	this->centru = p.centru;
}

char* Patrat::getNumar()
{
	return this->numar;
}

double Patrat::getLatura()
{
	return this->latura;
}

punct Patrat::getCentru()
{
	return this->centru;
}

void Patrat::setNume(const char* n)
{
	if (this->nume) delete[] this->nume;
	this->nume = new char[strlen(n) + 1];
	strcpy_s(this->nume, strlen(n) + 1, n);
}

void Patrat::setLatura(double l)
{
	this->latura = l;
}

void Patrat::setCentru(punct centru_patrat)
{
	this->centru = centru_patrat;
}

Patrat::~Patrat()
{
	if(this->nume != nullptr) delete[] this->nume;
	this->latura = 0;
	this->centru.x = 0;
	this->centru.y = 0;
}
