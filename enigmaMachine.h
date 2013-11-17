#ifndef ENIGMA_H
#define ENIGMA_H

#include <vector>
#include <string>

#include "plugboard.h"
#include "reflector.h"
#include "rotor.h"

class EnigmaMachine
{
private:
    int file_count;
    unsigned rotor_count;
    std::vector<std::vector<int> > input_vectors;

    // pointers to the encryptors
    Plugboard* plugboard;
    Reflector* reflector;
    std::vector<Rotor*> rotors;

    // function to rotate rotors 
    void rotate_rotors();
        
public:
    // create plugboard, reflector and rotors and set pointers to them
    void construct_encryptors();
    // return encrypted letter
    char encrypt(char letter);

    // constructor 
    EnigmaMachine(int argc, std::vector<std::vector<int> > config_vectors);
    // destructor is needed to destroy the plugboard, reflector and rotors
    ~EnigmaMachine();
};

#endif
