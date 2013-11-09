#include "encryptor.h"
#include "plugboard.h"

using namespace std;

Plugboard::Plugboard(vector<int> input)
{
    int a, b;
    // can we set its size before construction?
    transformation.resize(26);

    // default to no change
    for (int i = 0; i < 26; i++){
        transformation[i] = i;
    }

    for (int i = 0; i < input.size(); i++){
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
