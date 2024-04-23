#pragma once
#include "Figure.h"
#include "Figure_controller.h"


#include <iostream>
#include <vector>
#include <memory>

using namespace std;


class Test
{
public:
	Figure_controller &figures_to_test;

	//vector<unique_ptr<Figure>> figures_to_test;

	vector<double> expectet_circle;
	vector<double> expectet_rectangle;
	vector<double> expectet_trapezoid;


	Test(Figure_controller &figures_to_test,
		//vector<unique_ptr<Figure>> figures_to_test,
		vector<double> expectet_circle,
		vector<double> expectet_rectangle,
		vector<double> expectet_trapezoid) :

		figures_to_test(figures_to_test),
		expectet_circle(expectet_circle),
		expectet_rectangle(expectet_rectangle),
		expectet_trapezoid(expectet_trapezoid)
	{}



};