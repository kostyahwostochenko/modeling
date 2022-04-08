#pragma once

/*#ifndef MY_FLAG
#define MY_FLAG


#endif // MY_FLAG*/


bool compare(std::vector<double>::iterator beg, std::vector<double>::iterator index, double r);

void generate_random(double x_min, double x_max, double v_min,
                     double v_max, std::vector<double>::iterator beg_x,
                     std::vector<double>::iterator beg_v, size_t length, double r);
void download(std::string file_name, std::vector<double>::iterator beg_x,
              std::vector<double>::iterator beg_v, size_t length);

void printer(std::ofstream& file, double t, std::vector<double>::iterator beg_x,
             std::vector<double>::iterator beg_v, size_t length);

void print_energy(std::ofstream& file, double t, std::vector<double>::iterator beg_v,
                  size_t length, size_t n1, size_t k);

bool is_correct(std::vector<double>::iterator beg_x, size_t length, double r);
