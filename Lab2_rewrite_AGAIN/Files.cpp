#include "Figure.h"
#include "Input.h"
#include "Tasks.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>
#include <memory>

using namespace std;

enum circle { RADIUS = 1, CIRCLE_AREA = 2, CIRCLE_PERIMETER = 3 };

enum rectangle { LENGTH = 1, WIDTH = 2, RECTANGLE_AREA = 3, RECTANGLE_PERIMETER = 4 };

enum trapezoid { TOP_BASE = 1, BOTTOM_BASE = 2, HEIGHT = 3, RIGHT_SIDE = 4, LEFT_SIDE = 5, TRAPEZOID_AREA = 6, TRAPEZOID_PERIMETER = 7 };


bool file_exists(string filename) {
	ifstream file(filename);
	return file.is_open();
}

bool confirm_overwrite(string filename) {

	cout << "File '" << filename << "' already exists." << endl;
	cout << "Do you want to overwrite it?" << endl;
	cout << "1 - Yes" << endl;
	cout << "0 - No" << endl;

	int user_choice = 0;

	user_choice = InputInt("Enter menu item:", -1, 2);

	return user_choice;

}

vector<unique_ptr<Figure>> get_figures_from_file(string filename) {

	vector<unique_ptr<Figure>> figures;

	ifstream input_file(filename);
	if (!input_file.is_open()) {
		cerr << "Error opening file: " << filename << endl;
		return figures;
	}

	string line;
	while (getline(input_file, line)) {

		if (line.empty()) {
			cerr << "Warning: Skipped empty line." << endl;
			continue;
		}

		const int NAME = 0;

		stringstream ss(line);

		string token{ "" };


		int field_count = 0;

		double radius = 0;

		double length = 0;
		double width = 0;

		double right_side = 0;
		double left_side = 0;
		double top_base = 0;
		double bottom_base = 0;
		double height = 0;

		if (line[0] == 'C') {
			while (getline(ss, token, ';')) {
				try {

					switch (field_count) {

					case NAME: break;

					case RADIUS: radius = stod(token); break;

					case CIRCLE_AREA:break;

					case CIRCLE_PERIMETER:break;

					default:
						cerr << "Warning: parsing " << field_count << " field: " << "wrong number of fields" << endl;

					}

				}
				catch (invalid_argument& e) {
					cerr << "Warning: converting field " << field_count << ": " << e.what() << endl;
				}
				field_count++;
			}
			if (radius <= 0) {
				figures.clear();
				input_file.close();
				return figures;
			}

			figures.push_back(make_unique<Circle>(radius));
		}
		if (line[0] == 'R') {
			while (getline(ss, token, ';')) {
				try {

					switch (field_count) {

					case NAME: break;

					case LENGTH: length = stod(token); break;

					case WIDTH: width = stod(token); break;

					case RECTANGLE_AREA:break;

					case RECTANGLE_PERIMETER: break;

					default:
						cerr << "Warning: parsing " << field_count << " field: " << "wrong number of fields" << endl;

					}
				}
				catch (invalid_argument& e) {
					cerr << "Warning: converting field " << field_count << ": " << e.what() << endl;
				}
				field_count++;
			}
			if (length <= 0 || width <= 0) {
				figures.clear();
				input_file.close();
				return figures;
			}

			figures.push_back(make_unique<Rectangle>(length, width));

		}
		if (line[0] == 'T') {
			while (getline(ss, token, ';')) {
				try {

					switch (field_count) {

					case NAME: break;

					case TOP_BASE: top_base = stod(token); break;

					case BOTTOM_BASE: bottom_base = stod(token); break;

					case HEIGHT: height = stod(token); break;

					case RIGHT_SIDE: right_side = stod(token); break;

					case LEFT_SIDE: left_side = stod(token); break;

					case TRAPEZOID_AREA:break;

					case TRAPEZOID_PERIMETER: break;

					default:
						cerr << "Warning: parsing " << field_count << " field: " << "wrong number of fields" << endl;

					}
				}
				catch (invalid_argument& e) {
					cerr << "Warning: converting field " << field_count << ": " << e.what() << endl;
				}
				field_count++;
			}

			if (!is_trapezoid_valid(top_base, bottom_base, height, right_side, left_side)) {

				figures.clear();
				input_file.close();
				return figures;

			}

			figures.push_back(make_unique<Trapezoid>(top_base, bottom_base, height, right_side, left_side));

		}

	}

	input_file.close();

	cout << "Data successfully imported" << endl;

	return figures;
}

bool is_filepath_valid(string filepath) {

	regex file_path_regex("^(?:[a-zA-Z]\\:|\\\\)\\\\([^\\\\]+\\\\)*[^\\/:*?\"<>|]+\\.csv$");

	regex filename_reserved_names("^(?:CON|PRN|AUX|NUL|COM[1-9]|LPT[1-9]|con|prn|aux|nul|com[1-9]|lpt[1-9])(?:\\..*)?$");

	if (!regex_match(filepath, file_path_regex) || regex_match(filepath, filename_reserved_names)) {
		cerr << "Error: Invalid file path." << endl;
		return false;
	}

	return true;
}

string get_valid_filepath() {
	bool is_path_valid = false;

	string filepath{ "" };

	while (!is_path_valid) {

		filepath = InputString("Enter full path to file (only csv acceptable): ");

		if (is_filepath_valid(filepath)) { is_path_valid = true; }
	}

	return filepath;
}

string get_overwrite_confirmation(string filepath) {
	while (file_exists(filepath)) {
		if (confirm_overwrite(filepath)) {
			return filepath;
		}
		else {
			cout << "Please choose another file." << endl;
			return get_valid_filepath();
		}
	}
	return filepath;
}

void export_to_file(vector<unique_ptr<Figure>> &figures_to_export) {

	string filepath = get_valid_filepath();
	filepath = get_overwrite_confirmation(filepath);

	ofstream file(filepath);
	if (!file) {
		cerr << "Error: File is read-only or another error occurred." << endl;
		file.close();

		while (true) {
			cout << "Please enter a new path." << endl;
			filepath = get_valid_filepath();
			filepath = get_overwrite_confirmation(filepath);

			file.open(filepath);
			if (file) {
				break;
			}
			else {
				cerr << "Error: File is read-only or another error occurred." << endl;
				file.close();
			}
		}
	}

	for (auto& export_figures : figures_to_export) {

		if (export_figures->get_name() == 'C') {

			file << export_figures->get_name() << ";"
				<< export_figures->get_fields()[0] << ";"
				<< export_figures->get_fields()[1] << ";"
				<< export_figures->get_fields()[2] << "\n";
		}
		if (export_figures->get_name() == 'R') {

			file << export_figures->get_name() << ";"
				<< export_figures->get_fields()[0] << ";"
				<< export_figures->get_fields()[1] << ";"
				<< export_figures->get_fields()[2] << ";"
				<< export_figures->get_fields()[3] << "\n";
		}
		if (export_figures->get_name() == 'T') {

			file << export_figures->get_name() << ";"
				<< export_figures->get_fields()[0] << ";"
				<< export_figures->get_fields()[1] << ";"
				<< export_figures->get_fields()[2] << ";"
				<< export_figures->get_fields()[3] << ";"
				<< export_figures->get_fields()[4] << ";"
				<< export_figures->get_fields()[5] << ";"
				<< export_figures->get_fields()[6] << "\n";

		}
	}

	file.close();
	cout << "Data successfully exported to file: " << filepath << endl;
}
