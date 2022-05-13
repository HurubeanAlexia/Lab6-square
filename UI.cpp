#include "UI.h"
#include <iostream>
using namespace std;

void ui::print()
{
	if (srv.get_all().size() == 0)
		cout << "Lista este goala!\n";
	for (auto p: srv.get_all()) 
		cout << "Patratul " << p.getNume() << " are latura de lungime " << p.getLatura() <<
			" si centrul de coordonatele (" << p.getCentru().x << "," << p.getCentru().y << ")\n";
}

void ui::ui_adauga()
{
	int np;
	char* nume = new char[20];
	double latura, x, y;
	punct p;
	cout << "Dati numarul de patrate pe care doriti sa il adaugati: "; cin >> np;
	for (int i = 0; i < np; ++i)
	{
		cout << "Introduceti un nume pentru patrat: "; cin >> nume;
		cout << "Dati lungimea laturii: "; cin >> latura;
		cout << "Dati coordonatele centrului patratului: \n";
		cout << "x = "; cin >> x;
		cout << "y = "; cin >> y;
		p.x = x;
		p.y = y;
		srv.adauga_patrat(nume, latura, p);
	}
}

void ui::ui_find_max_patrat()
{
	if (srv.get_all().size() == 0)
		cout << "Lista este goala!\n";
	else {
		Entitate x = srv.find_max_patrat();

		cout << "Patratul " << x.getNume() << " are latura de lungime " << x.getLatura() << " este cea mai mare entitate \n";
	}
}

void ui::ui_find_max_eq()
{
	if (srv.get_all().size() == 0)
		cout << "Nu exista patrate in lista!\n";
	else {
		vector<Entitate> v = srv.find_max_equal();
		for (auto c : v)
			cout << "Patratul " << c.getNume() << " are latura de lungime " << c.getLatura() <<
			" si centrul de coordonatele (" << c.getCentru().x << "," << c.getCentru().y << ")\n";
	}
}

void ui::ui_find_cadI()
{
	vector<Entitate> v = srv.find_cadI();
	if (v.size() == 0)
		cout << "Nu exista patrate in cadranul 1!\n";
	else
		for (auto c : v)
			cout << "Patratul " << c.getNume() << " are latura de lungime " << c.getLatura() <<
			" si centrul de coordonatele (" << c.getCentru().x << "," << c.getCentru().y << ")\n";
}

void ui::ui_print_menu()
{
	cout << "(1) Adauga Patrate\n";
	cout << "(2) Afiseaza Patrate\n";
	cout << "(3) Determinarea si afisearea celei mai mari entitati\n";
	cout << "(4) Determinarea si afisearea patratelor situate in cadranul I\n";
	cout << "(5) Afiseara celei mai lungi secvente de entitati egale\n";
	cout << "(-1) Iesire\n";
}

void ui::run()
{
	int cmd;
	while (1)
	{
		ui_print_menu();
		cout << "Dati optiunea dorita: "; cin >> cmd;
		switch (cmd)
		{
		case 1:
			ui_adauga();
			break;
		case 2:
			print();
			break;
		case 3:
			ui_find_max_patrat();
			break;
		case 4:
			ui_find_cadI();
			break;
		case 5:
			ui_find_max_eq();
			break;
		case -1:
			exit(0);
		default:
			cout << "Optiune gresita !\n";
			break;
		}

	}
}

