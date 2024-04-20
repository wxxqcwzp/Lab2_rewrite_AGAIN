#pragma once

#pragma once

#include "Figure.h"

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

bool file_exists(string filename);

bool confirm_overwrite(string filename);

vector<unique_ptr<Figure>> get_figures_from_file(string fileName);

void export_to_file(vector<unique_ptr<Figure>> &employees_to_export);

bool is_filepath_valid(string filepath);

string get_valid_filepath();

//void run_tests();
