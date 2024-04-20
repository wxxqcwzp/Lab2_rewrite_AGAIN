#pragma once

#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>

using namespace std;

class Figure {
public:

	virtual ~Figure() = default;

	virtual double area() = 0;
	virtual double perimeter() = 0;

	virtual void show_figure() = 0;

	virtual char get_name() = 0;

	virtual vector<double> get_fields() = 0;
};

class Circle : public Figure {
private:

	double radius;

	vector<double>fields{ radius,area(),perimeter() };

public:

	Circle(double radius) : radius(radius) {}

	double area() override { return M_PI * radius * radius; }

	double perimeter() override { return 2 * M_PI * radius; }

	void show_figure() override { cout << "Circle with radius: " << radius << endl; }

	char get_name() override { return 'C'; }

	vector<double> get_fields() override { return fields; }

};

class Rectangle : public Figure {
private:

	double width;
	double length;

	vector<double>fields{ width, length, area(), perimeter() };

public:

	Rectangle(double width, double length) : width(width), length(length) {}

	double area() override { return width * length; }

	double perimeter() override { return 2 * (width + length); }

	void show_figure() override {
		cout << "Rectangle with width: " << width << " and length: " << length << endl;
	}

	char get_name() override { return 'R'; }

	vector<double> get_fields() override { return fields; }

};

class Trapezoid : public Figure {
private:

	double top_base;
	double bottom_base;
	double height;
	double right_side;
	double left_side;

	vector<double> fields{ top_base, bottom_base, height, right_side, left_side };

public:

	Trapezoid(double top_base, double bottom_base, double height, double right_side, double left_side)
		: top_base(top_base), bottom_base(bottom_base), height(height), right_side(right_side), left_side(left_side) {}

	double area()override { return 0.5 * (top_base + bottom_base) * height; }

	double perimeter()override { return top_base + bottom_base + right_side + left_side; }

	void show_figure() override {
		cout << "Trapezoid with top base: " << top_base << ", bottom base: " << bottom_base
			<< ", height: " << height << ", right side: " << right_side << ", left side: " << left_side << endl;
	}

	char get_name() override { return 'T'; }

	vector<double> get_fields() override { return fields; }

};