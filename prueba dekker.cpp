#include <iostream>
#include <thread>
using namespace std;
//Algoritmo de dekker
bool s1,s2;
int turno,dato;

void P1() {
	s1=true;
	while (s2==true) {
		if (turno==2) {
			s1=false;
			while (turno==2);
			s1=true;
		}
	}
	//Seccion critica
	for (int i=1;i<=10;i++) {
		cout<<"sumando 1"<<endl;
		dato++;
	}
	
	turno=2;
	s1=false;
}

void P2() {
	s2=true;
	while (s1==true) {
		if (turno==1) {
			s2=false;
			while (turno==1);
			s2=true;
		}
	}
	//Seccion critica
	dato+=5;
	cout<<"sumando 5"<<endl;
	
	turno=1;
	s2=false;
}

int main() {
	dato=0;
	s1=false;
	s2=false;
	turno=1;
	thread t[2];
	t[0]=thread(P1);
	t[1]=thread(P2);
	for (int i=0;i<2;i++) {
		t[i].join();
	}	
	cout<<"Dato: "<<dato<<endl;
	return 0;
}