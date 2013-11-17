#include "encryptor.h"
#include "plugboard.h"

using namespace std;

Plugboard::Plugboard(vector<int> input)
{
    int a, b;
    // default to no change
    for (unsigned i = 0; i < ALPHABET_SIZE; i++){
        transformation[i] = i;
    }

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
