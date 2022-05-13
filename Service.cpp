#include "Service.h"

void Service::adauga_patrat(const char* nume, double latura, punct centru)
{
	Patrat p(nume, latura, centru);
	repo.add_patrat(p);

}

Entitate Service::find_max_patrat()
{
	double max = 0;
	int x = 0;
	vector<Entitate> v = get_all();
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i].getLatura() > max) {
			max = v[i].getLatura();
			x = i;
		}
	}
	return v[x];
}

vector<Entitate> Service::get_all()
{
	return repo.get_all();
}

vector<Entitate> Service::find_max_equal()
{
	int lmax = 0, p1 = 0, p2 = 0;
	int c = 1;
	vector<Entitate> v = get_all();
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i].getLatura() == v[i - 1].getLatura() && v[i].getCentru().x == v[i - 1].getCentru().x && v[i].getCentru().y == v[i - 1].getCentru().y)
			c++;
		if (c > lmax)
		{
			lmax = c;
			p2 = i;
			p1 = i - c + 1;
		}
		if (v[i].getLatura() != v[i - 1].getLatura() || v[i].getCentru().x != v[i - 1].getCentru().x || v[i].getCentru().y != v[i - 1].getCentru().y)
			c = 1;
	}
	vector<Entitate> rez;
	for (int i = p1; i <= p2; i++)
	{
		rez.push_back(v[i]);
	}
	return rez;
}

vector<Entitate> Service::find_cadI()
{
	vector<Entitate> rez;
	for (auto c : get_all())
		if (c.getCentru().x - c.getLatura()/2 >= 0 && c.getCentru().y - c.getLatura()/2 >= 0)
			rez.push_back(c);
	return rez;
}
