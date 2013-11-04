#include <vector>
#include <string>
using namespace std;

class EnigmaMachine
{
private:
    bool direction;
    int no_of_rotors;
    //bool create_config_array(const char *filepath, int config_array[]);
        
public:
    // return encrypted letter
    char encrypt(char letter);

    // constructor for enigma machine (need a default one too?)
    EnigmaMachine(int argc, vector<string>& config_files);
};
