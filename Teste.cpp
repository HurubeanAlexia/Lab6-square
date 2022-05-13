#include "Teste.h"
#include <iostream>
#include "Patrat.h"
#include "Repository.h"
#include <cassert>
#include "Service.h"


// TESTE REPO:
void test_Repo()
{
	punct pt1;
	pt1.x = 3;
	pt1.y = 4;
	punct pt2;
	pt2.x = 1;
	pt2.y = 0;
	punct pt3;
	pt3.x = 1;
	pt3.y = 0;
	Patrat p1("ABCD", 10, pt1);
	Patrat p2("EFGH", 2, pt2);
	Patrat p3("IJKL", 13, pt3);

	Repo repo;
	repo.add_patrat(p1);
	vector<Entitate> lista_patrate = repo.get_all();
	assert(lista_patrate.size() == 1);
	repo.add_patrat(p2);
	repo.add_patrat(p3);
	lista_patrate = repo.get_all();
	assert(lista_patrate.size() == 3);
	assert(lista_patrate[0].getLatura() == 10);

}

// TESTE SERVICE: 
void test_adauga() {
	Repo repo;
	Service srv(repo);
	punct pt1;
	pt1.x = 3;
	pt1.y = 5;
	punct pt2;
	pt2.x = 4;
	pt2.y = 7;
	srv.adauga_patrat("ABCD", 2, pt1);
	srv.adauga_patrat("MNOP", 3, pt2);
	vector<Entitate> v = srv.get_all();
	assert(v.size() == 2);
	assert(v[0].getLatura() == 2);
	assert(v[1].getLatura() == 3);

}
void test_find_max() {
	Repo repo;
	Service srv(repo);
	punct pt1;
	pt1.x = 3;
	pt1.y = 5;
	punct pt2;
	pt2.x = 4;
	pt2.y = 7;
	punct pt3;
	pt3.x = 1;
	pt3.y = 5;
	punct pt4;
	pt4.x = 7;
	pt4.y = 2;
	srv.adauga_patrat("aaa", 3, pt1);
	srv.adauga_patrat("bbb", 5, pt2);
	srv.adauga_patrat("ccc", 2, pt3);
	srv.adauga_patrat("ddd", 3, pt4);
	vector<Entitate> v = srv.get_all();
	assert(srv.find_max_patrat().getLatura() == 5);

}
void test_find_cad1() {
	Repo repo;
	Service srv(repo);
	punct pt1;
	pt1.x = 3;
	pt1.y = 5;
	punct pt2;
	pt2.x = 4;
	pt2.y = 7;
	punct pt3;
	pt3.x = 1;
	pt3.y = 5;
	punct pt4;
	pt4.x = 7;
	pt4.y = 2;
	srv.adauga_patrat("a", 3, pt1);
	srv.adauga_patrat("b", 3, pt2);
	srv.adauga_patrat("c", 2, pt3);
	srv.adauga_patrat("d", 3, pt4);
	vector<Entitate> rez = srv.find_cadI();
	assert(rez.size() == 2);
	assert(rez[0].getCentru().x == 3);
	assert(rez[1].getCentru().y == 7);

}
void test_find_equal() {
	Repo repo;
	Service srv(repo);
	punct pt1;
	pt1.x = 3;
	pt1.y = 5;
	punct pt2;
	pt2.x = 4;
	pt2.y = 7;
	punct pt3;
	pt3.x = 4;
	pt3.y = 7;
	punct pt4;
	pt4.x = 4;
	pt4.y = 7;
	punct pt5;
	pt5.x = 5;
	pt5.y = 2;
	srv.adauga_patrat("a", 3, pt1);
	srv.adauga_patrat("b", 3, pt2);
	srv.adauga_patrat("c", 3, pt3);
	srv.adauga_patrat("d", 3, pt4);
	srv.adauga_patrat("e", 4, pt5);
	vector<Entitate> rez = srv.find_max_equal();
	assert(rez.size() == 3);
}

// APLEAREA TUTUROR TESTELOR:
void test_All()
{
	test_Repo();
	test_adauga();
	test_find_max();
	test_find_cad1();
	test_find_equal();
	std::cout << "Toate testele au fost trectute cu succes !\n";
}