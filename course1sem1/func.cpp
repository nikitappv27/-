#include <iostream>
using namespace std;

#include "func.h"

void funcH (){
	cout << "funcH\n\n";
}

void functionWithParameters(int a) { //ôîðìàëüíûé ïàðàìåòð (êîïèè íàñòîÿùèõ ïàðàìåòðîâ)
	a += 10;
}

void functionWithParameters(int& a, bool f) { //ôóíêöèè ìîæíî äåëàòü ñ îäíèì íàçâàíèåì (ãëàâíîå ðàçíûå àðãóìåíòû)
	a += 10;
}

void functionWithParameters(int* a) {
	*a = 10;
}