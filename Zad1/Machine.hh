//
// Created by mrhowever on 09.03.19.
//

#ifndef SPD1_MACHINE_HH
#define SPD1_MACHINE_HH

//Podstawowa klasa symulujaca maszyne, posiada jedynie jedno pole ktore przechowuje informacje
//o czasie ktory dotychczas uplynal

class Machine {
public:
    int timePassed;

    Machine() : timePassed(0) {}
};


#endif //SPD1_MACHINE_HH
