#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <fstream>
#include <cmath>


using namespace std;

int main()
{
    int k = 5;
    //int n = 12;
    double minimum = 1, maximum = 5;
    double a = 2, sigma = 2;
    mt19937_64 gen;
    gen.seed(time(nullptr));
    uniform_int_distribution<int> distr_discrete(1, k);
    uniform_real_distribution<double> distr_cont(minimum, maximum);
    normal_distribution<double> distr_normal{a, sigma};

    remove("text.txt");
    ofstream file;
    file.open("text.txt", ios::app);

    /*vector<int> v1(n);
    for(int i=0;i<n;i++){
       v1[i] = distr_discrete(gen);
       cout << v1[i] << " ";
    }
        cout << endl;

    vector<double> v2(n);
    for(int i=0;i<n;i++){
       v2[i] = distr_cont(gen);
       cout << v2[i] << " ";
    }
        cout << endl;*/

    double dx = 0.1;
    double x = minimum;
    double test_count = 1'000'00;

    /*for(int i=0; i < test_count; i++){
        file << distr_cont(gen) << '\n';
    }*/

    for(int i=0; i < test_count; i++){
        file << distr_normal(gen) << '\n';
    }

    /*int v_size = (maximum - minimum)/dx;
    vector<int> v(v_size);

    for(int i=0; i < v_size; i++){
        v[i] = 0;}

    for(int i=0; i < test_count; i++){
        x = distr_cont(gen);
        v[(x-minimum)/dx] ++;
    }

    x = minimum;
    for(int i=0; i < v_size; i++){
        file << x << " " << v[i] << '\n';
        x += dx;
    }*/

    return 0;
}
