#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "encryptor.h"

class Reflector : public Encryptor
{
public:
    // may want to change this to use proper strings
    // constructor
    Reflector(std::vector<int> input);
};

#endif
