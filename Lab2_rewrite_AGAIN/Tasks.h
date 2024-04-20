#pragma once

#include "Figure_controller.h"

void add_figure(Figure_controller& figures);

void save_data(Figure_controller& figures);

void load_data(Figure_controller& figures);

bool is_trapezoid_valid(double top_base, double bottom_base, double height, double right_side, double left_side);

void run_tests();