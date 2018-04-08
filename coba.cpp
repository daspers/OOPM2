#include <iostream>
#include <cstring>
#include "List.hpp"
#include "MakananIkan.hpp"

using namespace std;

class A {
	public :
		virtual void f() {
			cout << "f\n";
		}
		virtual void g() {};
};

class B : public A {
	public :
		void f() {
			cout << "f2\n";
		}
		void g() {
			cout << "g2\n";
		}
};

int main() {
	A* a = new B();
	a->f();
	a->g();
}