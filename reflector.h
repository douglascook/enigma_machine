#include <vector>

class Reflector : public Encryptor
{
public:
    // may want to change this to use proper strings
    // constructor
    Reflector(const char *filepath, int& error);
};
