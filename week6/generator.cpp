#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>



using namespace std;

bool compare(vector<double>::iterator beg, vector<double>::iterator index, double r){
    for(auto j = beg; j < index; j++){
        if(abs(*j - *index) <= 2*r){
            return false;
        }
    }
    return true;
}

void generate_random(double x_min, double x_max, double v_min,
                     double v_max, vector<double>::iterator beg_x,
                     vector<double>::iterator beg_v, size_t length, double r){

    mt19937_64 gen;
    //gen.seed(0);
    gen.seed(time(nullptr));
    uniform_real_distribution<double> distr_speed(v_min, v_max);
    uniform_real_distribution<double> distr_coord(x_min, x_max);

    for(auto i = beg_v; i < (beg_v + length) ;i++){
        *i = distr_speed(gen);}

    for(auto i = beg_x; i < (beg_x + length) ; i++){
        *i = distr_coord(gen);

        while(!compare(beg_x, i, r)){
            *i = distr_coord(gen);
        }
    }

}

void download(string file_name, vector<double>::iterator beg_x,
              vector<double>::iterator beg_v, size_t length){

    string line;
    ifstream in(file_name);
    if (in.is_open())
    {
        while (getline(in, line)){
            stringstream ss(line);
            int cnt = 0;
            size_t i = 0;
            while(ss >> line){
                if(i >= length){
                    cout << "Error in data" << '\n';
                    exit(1);
                }
                if(cnt % 2 == 0){
                    *(beg_x + i) = atof(line.c_str());
                }
                if(cnt % 2 == 1){
                    *(beg_v + i) = atof(line.c_str());
                    i ++;
                }
                cnt++;
                }
        }
    }
    in.close();

}

bool is_correct(vector<double>::iterator beg_x, size_t length, double r){

    for(auto i = beg_x; i < (beg_x + length); i++){
    for(auto j = next(i); j < (beg_x + length); j++){
        if(abs(*i - *j) <= 2*r){
            cout << "wrong data" << '\n';
            return false;
            }
        }
    }
    return true;
}
