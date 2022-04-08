#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>


#include "my_headers.h"

using namespace std;



using namespace std::chrono;

template<typename T>
class Timer{
public:
    Timer(): beg(steady_clock::now()), time{0}, is_stop{false}{}

    void start(){
       beg = steady_clock::now();
       is_stop = false;
    }

    void stop(){
        if(is_stop == false){
        time += steady_clock::now()-beg;}

        is_stop = true;
    }

    ~Timer(){
        stop();
        cout<<duration_cast<T>(time).count()<<endl;
    }

private:
    steady_clock::time_point beg;
    steady_clock::duration time;
    bool is_stop;
};



int main()
{
    size_t  n = 100;
    size_t n1 = 42;
    size_t k = 4;
    double border = 1;
    double r = 0.001;
    double dt;
    double t = 0;
    double t_max = 20;
    int detecter1  = -3;
    int detecter2 = -3; //-1 - border, -2 - left
    bool is_random = true;
    int cnt = 0;
    double E = 0;
    int cnt_0 = 0;
    int cnt_board = 0;
    int bin_size = 20;
    int natural = 1;

    vector<double> x(n); // первые n1 имеют массу m1 (тяжелые), остальные массу m2
    vector<double> v(n);

    double v_min = -8, v_max = 8;
    double x_min = r, x_max = border - r;

    remove("params.txt");
    ofstream file1;
    file1.open("params.txt", ios::app);
    file1 << n1 << " " << r << " " << border << '\n';
    file1.close();

    remove("energy.txt");
    ofstream energy;
    energy.open("energy.txt", ios::app);

    remove("output_data.txt");
    ofstream file;
    file.open("output_data.txt", ios::app);

    remove("average_small.txt");
    ofstream average_small;
    average_small.open("average_small.txt", ios::app);

    remove("pressure.txt");
    ofstream press;
    press.open("pressure.txt", ios::app);

    if(is_random){
        generate_random(x_min, x_max, v_min, v_max, x.begin(), v.begin(), x.size(), r);
    }

    else{
        download("input_data.txt", x.begin(), v.begin(), x.size());
    }

    if(!is_correct(x.begin(), x.size(), r)){
        return 0;
    }

    /*printer(file, t, x.begin(), v.begin(), x.size());
    print_energy(energy, t, v.begin(), v.size(), n1, k);*/

    /*Timer<seconds> timer;
    timer.start();
    timer.stop();*/
    while(t < t_max){
        dt = border/abs(v[0]);
        for(size_t i=0;i<n;i++){
            if(v[i] > 0 && (border-r-x[i]) < v[i]*dt){
                dt = (border-r-x[i])/v[i];
                detecter1 = i;
                detecter2 = -1;
                }
            if(v[i] < 0 && (x[i]-r) < -v[i]*dt){
                dt = -(x[i]-r)/v[i];
                detecter1 = i;
                detecter2 = -2;
            }
        }

        for(size_t i = 0; i < n - 1; i++){
            for(size_t j = i+1; j < n; j++){
                    if((x[i] < x[j] && v[j]-v[i] < 0) || (x[i] > x[j] && v[j]-v[i] > 0)){
                        if(abs(x[i]-x[j])-2*r < abs(v[i]-v[j])*dt){
                            dt = (abs(x[i]-x[j])-2*r)/abs(v[i]-v[j]);
                            detecter1 = i;
                            detecter2 = j;
                        }
                    }
            }
        }

        for(size_t i = 0; i < n; i++){
            x[i] += v[i]*dt;
        }

        if(detecter2 >= 0){
            size_t i = detecter1, j = detecter2;
            if((i<n1 && j<n1) || (i>=n1 && j>=n1)){
                swap(v[i], v[j]);}
            else{
                if(i < n1 && j >= n1){
                    double tmp = v[i];
                    v[i] = (k*v[i]-v[i]+2*v[j])/(k+1);
                    v[j] = (2*k*tmp+v[j]-k*v[j])/(k+1);
                    }
                else{
                    double tmp = v[i];
                    v[i] = (v[i]-k*v[i]+2*k*v[j])/(k+1);
                    v[j] = (2*tmp+k*v[j]-v[j])/(k+1);
                    }
            }


        }
        if(detecter2 == -1 || detecter2 == -2){
            v[detecter1] = -v[detecter1];
        }
        if(detecter2 == -1){
            cnt_board ++;
        }

        t += dt;
        detecter1 = -3;
        detecter2 = -3;
        cnt ++;

        E += k*v[1]*v[1];
        cnt_0 ++;
        if(t >= natural*t_max/bin_size){
            cout << t << " " << cnt << '\n';
            average_small << E/cnt_0 << '\n';
            press << cnt_board << '\n';
            natural ++;
            E = 0;
            cnt_0 = 0;
            cnt_board = 0;
        }
        if(t >= 19){
            for(size_t i = 0; i < n1; i++){
                file << v[i] << '\n';
            }
        }

        /*printer(file, t, x.begin(), v.begin(), x.size());
        print_energy(energy, t, v.begin(), v.size(), n1, k);*/

    }
    file.close();
    energy.close();
    average_small.close();
    press.close();
    cout <<"Count of collisions " << cnt << '\n';

    return 0;
}


