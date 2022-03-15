#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;


int main()
{

    mt19937_64 gen;
    gen.seed(time(nullptr));
    uniform_int_distribution<int> distr(1, 3);

    array<int, 3> a = {1, 1, 1};
    int b1 = 0;
    int b2 = 0;
    int v_size = 100;
    int counter = 0;
    int s = 0;
    int test_counter = 1'000'00;
    vector<int> v(v_size);

    for(int i1=1;i1<4;i1++){
        for(int i2=1;i2<4;i2++){
            for(int i3=1;i3<4;i3++){
        a[0] = i1;
        a[1] = i2;
        a[2] = i3;
        for(int q = 0; q < test_counter; q++){
            while(true){
                for(int i = 0; i < v_size; i++){
                    v[i] = distr(gen);}
                if(b1 == a[0] && b2 == a[1] && v[0] == a[2]){
                    counter ++;
                    b1 = 0;
                    b2 = 0;
                    break;
                }
                auto r = search(v.begin(), v.end(), a.begin(), a.end());
                if(*r != 0){
                    counter += distance(v.begin(), r) + 3;
                    b1 = 0;
                    b2 = 0;
                    break;
                }
                b1 = v[v_size - 2];
                b2 = v[v_size - 1];
                counter += v_size;
            }
        s += counter;
        counter = 0;
    }
    cout << i1 << " " << i2 << " " << i3 << " " << double(s)/test_counter << '\n';
    s = 0;
    counter = 0;
            }
        }
    }

    return 0;
}
