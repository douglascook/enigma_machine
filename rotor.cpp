#include "encryptor.h"
#include "rotor.h"

using namespace std;

Rotor::Rotor(vector<int> input, int position)
    : offset(position), transformation_reverse(ALPHABET_SIZE), notches(26, false)
{
    // create transformation mappings
    for (unsigned i = 0; i < ALPHABET_SIZE; i++){
        transformation[i] = input[i];
        transformation_reverse[input[i]] = i;
    }
    // set notches array
    for (unsigned i = ALPHABET_SIZE; i < input.size(); i++){
        notches[input[i]] = true;
    }
}

bool Rotor::rotate()
{
    ++offset %= ALPHABET_SIZE;
    // return value is true if there is a notch at this position
    return notches[offset];
}

int Rotor::encrypt(int letter, bool return_trip)
{
    if (return_trip){
        // use reverse mappings for return trip
        return (transformation_reverse[(letter + offset) % ALPHABET_SIZE] - offset + ALPHABET_SIZE) % ALPHABET_SIZE;
    }
    return (transformation[(letter + offset) % ALPHABET_SIZE] - offset + ALPHABET_SIZE) % ALPHABET_SIZE;
}
