#ifndef BENDAAKUARIUM_HPP
#define BENDAAKUARIUM_HPP

#include "Movement.hpp"
#include "Posisi.hpp"

class BendaAkuarium : public Movement, public Posisi {
//Kelas Benda Akuarium ialah benda yang dapat berada pada aquarium
	public :
		BendaAkuarium(double x, double y, double arah, double kecepatan): Movement(arah, kecepatan), Posisi(x, y){};
    	virtual void gerak() = 0; //Prosedur ketika sebuah benda aquarium bergerak
};

#endif