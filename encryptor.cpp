#include "encryptor.h"

Encryptor::Encryptor() : transformation(ALPHABET_SIZE) {
}

int Encryptor::encrypt(int letter)
{
    return transformation[letter];
}
