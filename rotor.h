#include <vector>

class Rotor : public Encryptor
{
private:
    // encryption for return leg of circuit
    std::vector<int> transformation_reverse;
    // hold indices for notches on rotor
    std::vector<int> rotate_notch;
    // holds current position relative to A in position 0
    int current_position;
    // encrypt letter on return journey through machine
    int encryptReverse(int letter);
    // deals with one rotation of rotor (revert down to zero if mod 26)
    void rotate();

public:
    // may want to change this to use proper strings
    // constructor
    Rotor(const char *filepath, int& error);
};
