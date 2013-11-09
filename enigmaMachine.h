#include <vector>
#include <string>

#include "plugboard.h"
#include "reflector.h"
#include "rotor.h"

using namespace std;

class EnigmaMachine
{
private:
    int file_count;
    unsigned rotor_count;
    vector<vector<int> > input_vectors;

    // pointers to the encryptors
    Plugboard* plugboard;
    Reflector* reflector;
    vector<Rotor*> rotors;

    // function to rotate rotors 
    void rotate_rotors();
        
public:
    // create rotors and set pointers to them
    void construct_encryptors();
    // return encrypted letter
    char encrypt(char letter);

    // constructor for enigma machine (need a default one too?)
    EnigmaMachine(int argc, vector<vector<int> > config_vectors);
};
