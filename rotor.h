#ifndef ROTOR_H
#define ROTOR_H

#include "encryptor.h"

class Rotor : public Encryptor
{
private:
    // encryption for return leg of circuit
    std::vector<int> transformation_reverse;
    // hold indices for notches on rotor
    std::vector<int> notches;
    // offset from A at top (position 0) 
    int offset; 

public:
    // constructor
    Rotor(std::vector<int> input, int position);
    // encrypt depending on which direction
    int encrypt(int letter, bool return_trip);
    // rotate and return true if reached a notch
    bool rotate();
};

#endif
