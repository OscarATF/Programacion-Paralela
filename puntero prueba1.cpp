#include <iostream>
#include <thread>
using namespace std;
/*
int main() {
	int num;
	int *ptr;
	num=10;
	ptr=&num; //ptr: direccion del dato , *ptr: dato en si
	*ptr+=2;
	
	cout<<"Numero: "<<num;
}
*/

void p1(int *n) {
	for (int i=0;i<100000;i++) {
		(*n)++;
	}
}

void p2(int *n) {
	for (int i=0;i<100000;i++) {
		(*n)++;
	}
}

int main() {
	int numero=0;
	thread t1(p1,&numero);
	thread t2(p2,&numero);
	t1.join();
	t2.join();
	cout<<"Numero: "<<numero<<endl;
}