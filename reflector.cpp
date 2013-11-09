#include "encryptor.h"
#include "reflector.h"

using namespace std;

Reflector::Reflector(vector<int> input)
{
    int a, b;

    // can we set its size before construction?
    transformation.resize(26);

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
