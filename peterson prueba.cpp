#include <iostream>
#include <thread>

using namespace std;
//Algoritmo de peterson
bool s1,s2;
int turno;

void P1(int *c) {
	s1=true;
	turno=2;
	while (s2==true && turno==2);
	//seccion critica
	for (int i=0;i<100000;i++) {
		(*c)++;
	}
	
	s1=false;
}

void P2(int *c) {
	s2=true;
	turno=1;
	while (s1==true && turno==1);
	//seccion critica
	for (int i=0;i<100000;i++) {
		(*c)++;
	}
	
	s2=false;
}

int main() {
	int num;
	s1=false;
	s2=false;
	turno=2;
	
	thread t[2];
	t[0]=thread(P1,&num);
	t[1]=thread(P2,&num);
	for (int i=0;i<2;i++) {
		t[i].join();
	}
	cout<<"texto: "<<num<<endl;
	return 0;
}