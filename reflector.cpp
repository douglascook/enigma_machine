#include "encryptor.h"
#include "reflector.h"

using namespace std;

Reflector::Reflector(vector<int> input)
{
    int a, b;

    for (unsigned i = 0; i < input.size(); i++){
        if (i % 2 == 0){
            a = input[i];
        }else{
            b = input[i];
            // swap values around
            transformation[a] = b;
            transformation[b] = a;
        }
    }
}
