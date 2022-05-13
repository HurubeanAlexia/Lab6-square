#pragma once
#include <cstring>
#include <string>

struct punct {
	double x;
	double y;
};

class Patrat {
private:
	char* nume;
	double latura;
	punct centru;

public:
	Patrat() = default;
	Patrat(const char* p, double latura_patrat, punct centru_patrat);
	Patrat(const Patrat& p);

	int* getNume();
	double getLatura();
	punct getCentru();
	
	void setNume(const char* n);
	void setLatura(double l);
	void setCentru(punct centru_patrat);

	~Patrat();

};