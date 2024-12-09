#include <iostream>
//#include <bits/stdc++.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>

class Nodo_huff{
    public:
        char c;
        int n;
        Nodo_huff *sig;
        Nodo_huff *izq;
        Nodo_huff *der;

        Nodo_huff(char);
};