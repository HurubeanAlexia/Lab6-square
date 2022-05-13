#include <iostream>
#include "UI.h"
#include "Teste.h"
using namespace std;

int main() {
	test_All();
	Repo repo;
	Service srv(repo);
	ui ui(srv);
	ui.run();
	return 0;
}