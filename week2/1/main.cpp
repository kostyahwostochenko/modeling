#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
#include <fstream>
#include <array>

using namespace std;


int main()
{
    int k = 5;
    int n = 0;
    int a = 0;
    int s = 0;
    int test_count = 1'000'00;
    int n_finish = 30;
    vector<int> v(k);
    mt19937_64 gen;
    gen.seed(time(nullptr));
    uniform_int_distribution<int> distr(1, k);

    remove("text.txt");
    ofstream file;
    file.open("text.txt", ios::app);

    for(int t = 0; t <= n_finish; t++){
        for(int j = 0; j < test_count; j++){
            fill(v.begin(), v.end(), 0);

            for(int i = 0; i < n; i++){
                a = distr(gen);
                v[a-1]++;
            }
            for(int i = 0; i < k; i++){
                if(v[i] == 0){
                    s ++;
                    break;}
            }
        }
        file << n << " " << 1 - float(s)/test_count << '\n';
        n++;
        s = 0;
    }

    return 0;
}
