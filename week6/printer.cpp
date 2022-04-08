#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void printer(ofstream& file, double t, vector<double>::iterator beg_x,
             vector<double>::iterator beg_v, size_t length){

    file << t << " ";
    size_t i = 0;

    while(i < length){
        file << *(beg_x + i) << " " << *(beg_v + i) << " ";
        i ++;
    }

    file << '\n';

}

void print_energy(ofstream& file, double t, vector<double>::iterator beg_v,
                  size_t length, size_t n1, size_t k){

    file << t << " ";

    double E = 0;
    double v = 0;

    for(size_t i = 0; i < length; i++){
        v = *(beg_v + i);
        if(i < n1){
            E += k*v*v;}
        else{
            E += v*v;}
    }
    file << E << '\n';

}
