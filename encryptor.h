#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include <vector>
#include <string>

const unsigned ALPHABET_SIZE = 26;

class Encryptor 
{
protected:
    // encryption of the alphabet for this part of the machine
    std::vector<int> transformation;
public:
    // constructor
    Encryptor();
    // return encrypyted letter 
    int encrypt(int letter);
};

#endif
