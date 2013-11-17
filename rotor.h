#ifndef ROTOR_H
#define ROTOR_H

#include "encryptor.h"

class Rotor : public Encryptor
{
private:
    // offset from A at top (position 0) 
    int offset; 
    // encryption for return leg of circuit
    std::vector<int> transformation_reverse;
    // for notches on rotor
    std::vector<bool> notches;

public:
    // constructor
    Rotor(std::vector<int> input, int position);
    // encrypt depending on which direction we are going through the circuit 
    int encrypt(int letter, bool return_trip);
    // rotate rotor and return true if it has reached a notch
    bool rotate();
};

#endif
