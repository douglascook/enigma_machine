#include <iostream>
#include <fstream>

#include "enigmaMachine.h"

using namespace std;

// constructor for enigma machine (need a default one too?)
EnigmaMachine::EnigmaMachine(int argc, vector<vector<int> > config_vectors)
    : file_count(argc - 1), rotor_count(argc - 4), input_vectors(config_vectors)
{
    // this is case of only plugboard and reflector
    if (argc < 5){
        rotor_count = 0;
    }
}

void EnigmaMachine::construct_encryptors()
{
    int position;

    plugboard = new Plugboard(input_vectors[0]);
    reflector = new Reflector(input_vectors[1]);

    rotors.resize(rotor_count);
    // loop through to create vector of rotors
    for (int i = 0; i < rotor_count; i++){
        // rotors are specified left to right but we want to start at right
        // so do this bit backwards, define rotors starting with last command line arg 
        position = input_vectors[file_count - 1][input_vectors[file_count - 1].size() - 1 - i];
        rotors[i] = new Rotor(input_vectors[file_count- i - 2], position);
    }
}

void EnigmaMachine::rotate_rotors()
{
    bool rotate_next;
    
    // loop through rotors and rotate as needed
    for (int i = 0; i < rotor_count; i++){
        if (i == 0){
            rotate_next = rotors[i]->rotate();
        }else if (rotate_next){
            // if previous rotor reached a notch then rotate next one
            rotate_next = rotors[i]->rotate();
        }
    }
}

char EnigmaMachine::encrypt(char letter)
{
    // firstly rotate the rotor(s)
    rotate_rotors();

    // convert from capital ascii char
    int char_code = static_cast<int>(letter) - 65;

    // plugboard first
    char_code = plugboard->encrypt(char_code);

    // rotors
    for (int i = 0; i < rotor_count; i++){
        char_code = rotors[i]->encrypt(char_code, false);
    }

    // reflector
    char_code = reflector->encrypt(char_code);

    // rotors on return trip
    if (rotor_count > 0){
        for (int i = rotor_count - 1; i >= 0; i--){
            char_code = rotors[i]->encrypt(char_code, true);
        }
    }

    // finally plugboard again
    char_code = plugboard->encrypt(char_code);
    
    return static_cast<char>(char_code + 65);
}
