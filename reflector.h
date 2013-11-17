#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "encryptor.h"

class Reflector : public Encryptor
{
public:
    // constructor
    Reflector(std::vector<int> input);
};

#endif
