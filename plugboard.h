#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "encryptor.h"

class Plugboard: public Encryptor
{
public:
    // constructor
    Plugboard(std::vector<int> input);
};

#endif
