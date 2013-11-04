#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>

#include "enigmaMachine.h"
#include "encryptor.h"
#include "plugboard.h"
#include "rotor.h"
#include "reflector.h"

using namespace std;

/*    
bool create_config_array(const char *filepath, int config_array[]){
    char ch;
    ifstream config(filepath);
    // check that we have opened file successfully
    assert(config);

    while (!in.eof()){
        in.get(ch);
        // can only handle numeric input
        if (!isdigit(ch)){
            return false;    
        }
    }
    
    // return to start of file
    in.seekg(0, in.beg);
    int j = 0;
    // now create array for the constructor to use
    while (!in.eof()){
        in >> config_array[j];
        j++;
    }
}
*/

char encrypt(char letter)
{
    return 0;
    // function to encrypt given letter
}

// constructor for enigma machine (need a default one too?)
EnigmaMachine::EnigmaMachine(int file_count, vector<string>& config_files){

    // instantiate plugboard (1st arg)
        
    // instantiate reflector (2nd arg)

    // loop through remaining config files to instantiate all rotors
    
}
