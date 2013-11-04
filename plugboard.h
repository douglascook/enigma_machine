#include <vector>

class Plugboard: public Encryptor
{
public:
    // may want to change this to use proper strings
    // constructor
    Plugboard(const char *filepath, int& error);
};
