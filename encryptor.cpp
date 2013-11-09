#include "encryptor.h"

int Encryptor::encrypt(int letter)
{
    // this will return encrypted version of current letter 
    return transformation[letter];
}
