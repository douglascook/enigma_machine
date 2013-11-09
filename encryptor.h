#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include <vector>
#include <string>

class Encryptor 
{
protected:
    // encryption of the alphabet for this part of the machine
    std::vector<int> transformation;
public:
    // this will return encrypted version of current letter 
    int encrypt(int letter);
};

#endif
