#include "Figure.h"
#include "Figure_controller.h"
#include "Input.h"
#include "Files.h"

#include <iostream>
#include <memory>

using namespace std;

enum figure {CIRCLE = 1, RECTANGLE, TRAPEZOID};

bool is_trapezoid_valid(double top_base, double bottom_base, double height, double right_side, double left_side) {

	if (top_base <= 0 || bottom_base <= 0 || height <= 0 || right_side <= 0 || left_side <= 0) { return false; }

	if ((top_base + right_side + left_side <= bottom_base)||
		(bottom_base + right_side + left_side <= top_base)) { return false; }

	if (top_base > bottom_base) {

		double right_top_part = sqrt(right_side * right_side - height * height);
		double left_top_part = sqrt(left_side * left_side - height * height);

		if (bottom_base != top_base - right_top_part - left_top_part) { return false; }

	}
	else if (bottom_base > top_base) {

		double right_bottom_part = sqrt(right_side * right_side - height * height);
		double left_bottom_part = sqrt(left_side * left_side - height * height);

		if (top_base != bottom_base - right_bottom_part - left_bottom_part) { return false; }

	}
	else {
		if (height != right_side) { return false; }
	}

	return true;

}

void add_figure(Figure_controller& figures) {

	cout << "1 - Add circle;" << endl;
	cout << "2 - Add rectangle;" << endl;
	cout << "3 - Add trapezoid;" << endl;

	int user_choice = InputInt("Enter menu item:", 0, 4);

	switch (user_choice)
	{
		case CIRCLE: {

			double radius = InputDouble("Enter circle's radius:", 0, DBL_MAX);

			figures.add_figure(make_unique<Circle>(radius));

			break;
		}

		case RECTANGLE: {

			double width = InputDouble("Enter rectangle's width:", 0, DBL_MAX);
			double length = InputDouble("Enter rectangle's length:", 0, DBL_MAX);

			figures.add_figure(make_unique<Rectangle>(width, length));

			break;

		}

		case TRAPEZOID: {

			double top_base = InputDouble("Enter trapezoid's top base:", 0, DBL_MAX);
			double bottom_base = InputDouble("Enter trapezoid's bottom base:", 0, DBL_MAX);
			double height = InputDouble("Enter trapezoid's height:", 0, DBL_MAX);
			double right_side = InputDouble("Enter trapezoid's rigth side:", 0, DBL_MAX);
			double left_side = InputDouble("Enter trapezoid's left side:", 0, DBL_MAX);


			if (is_trapezoid_valid(top_base, bottom_base, height, right_side, left_side)) {

				figures.add_figure(make_unique<Trapezoid>(top_base, bottom_base, height, right_side, left_side));

			}
			else { cout << "A trapezoid with such sides cannot exist" << endl; }
			

			break;

		}

	}

}

void load_data(Figure_controller& figures) {

	string filepath = get_valid_filepath();

	vector<unique_ptr<Figure>> figures_from_file = get_figures_from_file(filepath);

	if (figures_from_file.empty()) { cerr << "Data was not loaded" << endl; return; }

	figures.set_figures(move(figures_from_file));

}

void save_data(Figure_controller& figures) {

	if (figures.get_figures().empty()) { cout << "You haven't added any figure yet"; return; }

	export_to_file(figures.get_figures());

}