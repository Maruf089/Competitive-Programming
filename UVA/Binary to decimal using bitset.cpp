#include <iostream>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;

typedef bitset<100> mybitset; // Or some other number

mybitset convert(const char *s)
{
    mybitset result;
    for (int loop = 0; s[loop]; ++loop) {
        if (s[loop] == '1') result[loop] = true;
    }
    return result;
}

int main() {
    mybitset num_1 =    convert(   "11100");
    mybitset num_2 =    convert("1010");

    mybitset result = num_1&num_2;

    cout << num_1.to_string() << endl;
    cout << num_2.to_string() << endl;
    cout << result.to_string() << endl;

    // your code goes here
    return 0;
}
