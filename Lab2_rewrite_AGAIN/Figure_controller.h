#pragma once

#include"Figure.h"

#include <iostream>
#include <memory>

using namespace std;

class Figure_controller {

private:

	vector<unique_ptr<Figure>> figures;

public:

	~Figure_controller() { figures.clear(); }

	void add_figure(unique_ptr<Figure> figure) { figures.push_back(move(figure)); }

	void show_all_figures() {

		cout << endl;

		if (figures.empty()) { cout << "You haven't added any figure yet" << endl; return; }

		cout << "Your figures:" << endl;

		for (auto& figure : figures) { figure->show_figure(); }

		cout << endl;
	}

	void set_figures(vector<unique_ptr<Figure>> new_figures) { figures = move(new_figures); }

	vector<unique_ptr<Figure>>& get_figures() { return figures; }


};