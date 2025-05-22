#include <iostream>
#include <thread>
#define N 3
using namespace std;
//Algoritmo de lamport
int nt[N];
bool s[N];

int ntMax() {
	int max;
	max=nt[0];
	for (int i=1;i<N;i++) {
		if (max<nt[i]) {
			max=nt[i];
		}
	}
	return max;
}

bool ntMayorQue(int i,int j) {
	if (nt[i]>nt[j]) {
		return true;
	} else {
		if (nt[i]<nt[j]) {
			return false;
		} else 
			return i>j;
	}
}

void P(int i,int *num) {
	s[i]=true;
	nt[i]=1+ntMax();
	s[i]=false;
	for (int j=0;j<N;j++) {
		while (s[j]==true);
		while (nt[j]!=0 && ntMayorQue(i,j));
	}
	//Seccion critica
	cout<<"Seccion critica "<<i+1<<endl;
	for (int i=0;i<10000;i++) {
		(*num)++;
	}
	
	nt[i]=0;
}


int main() {
	int numero=0;
	for (int i=0;i<N;i++) {
		nt[i]=0;
		s[i]=false;
	}
	thread t[N];
	for (int i=0;i<N;i++) {
		t[i]=thread(P,i,&numero);
	}
	for (int i=0;i<N;i++) {
		t[i].join();
	}

	cout<<"Numero: "<<numero<<endl;
	return 0;
}