#include <iostream>
#include <cstring>
#include "List.hpp"
#include "MakananIkan.hpp"

using namespace std;

int main() {
	List<MakananIkan> listmakananikan;

	MakananIkan newmakananikan1(rand()%100);
	listmakananikan.add(newmakananikan1);
	MakananIkan newmakananikan2(rand()%100);
	listmakananikan.add(newmakananikan2);
	listmakananikan.removeIdx(1);

	cout << MakananIkan::getBanyakMakananIkan() << "\n";

	for(int i = 0; i < MakananIkan::getBanyakMakananIkan(); i++) {
		cout << listmakananikan.get(i).getX() << "\n";
	}
}