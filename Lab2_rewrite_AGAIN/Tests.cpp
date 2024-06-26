#include "Figure.h"
#include "Test_class.h"
#include "Figure_controller.h"


#include <iostream>
#include <vector>
#include <memory>

using namespace std;

bool is_vectors_fields_equal(Figure_controller& figures_to_test, vector<double>& expectet_circle, vector<double>& expectet_rectangle,vector<double>& expectet_trapezoid) {


	if (figures_to_test.get_figures()[0]->get_fields() != expectet_circle) { return false; }
	if (figures_to_test.get_figures()[1]->get_fields() != expectet_rectangle) { return false; }
	if (figures_to_test.get_figures()[2]->get_fields() != expectet_trapezoid) { return false; }

	return true;

}

void run_tests() {

	//vector<unique_ptr<Figure>> first_test;

	Figure_controller first_test;

	first_test.add_figure(make_unique<Circle>(10));
	first_test.add_figure(make_unique<Rectangle>(10, 10));
	first_test.add_figure(make_unique<Trapezoid>(10, 10, 10, 10, 10));


	/*first_test.push_back(move(make_unique<Circle>(10)));
	first_test.push_back(move(make_unique<Rectangle>(10, 10)));
	first_test.push_back(move(make_unique<Trapezoid>(10, 10, 10, 10, 10)));*/

	//vector<unique_ptr<Figure>> second_test;

	Figure_controller second_test;

	second_test.add_figure(make_unique<Circle>(1));
	second_test.add_figure(make_unique<Rectangle>(1, 1));
	second_test.add_figure(make_unique<Trapezoid>(1, 1, 1, 1, 1));

	/*second_test.push_back(move(make_unique<Circle>(1)));
	second_test.push_back(move(make_unique<Rectangle>(1, 1)));
	second_test.push_back(move(make_unique<Trapezoid>(1, 1, 1, 1, 1)));*/

	//vector<unique_ptr<Figure>> third_test;

	Figure_controller third_test;

	third_test.add_figure(make_unique<Circle>(5.5));
	third_test.add_figure(make_unique<Rectangle>(5.5, 5.5));
	third_test.add_figure(make_unique<Trapezoid>(5.5, 5.5, 5.5, 5.5, 5.5));

	/*third_test.push_back(move(make_unique<Circle>(5.5)));
	third_test.push_back(move(make_unique<Rectangle>(5.5, 5.5)));
	third_test.push_back(move(make_unique<Trapezoid>(5.5, 5.5, 5.5, 5.5, 5.5)));*/

	Figure_controller fourth_test;
	
	//vector<unique_ptr<Figure>> fourth_test;

	fourth_test.add_figure(make_unique<Circle>(1.234));
	fourth_test.add_figure(make_unique<Rectangle>(12.46, 44.7));
	fourth_test.add_figure(make_unique<Trapezoid>(674.5, 0.8723, 0.1234, 78, 565));

	/*fourth_test.push_back(move(make_unique<Circle>(1.234)));
	fourth_test.push_back(move(make_unique<Rectangle>(12.46, 44.7)));
	fourth_test.push_back(move(make_unique<Trapezoid>(674.5, 0.8723, 0.1234, 78, 565)));*/

	Figure_controller fifth_test;

	fifth_test.add_figure(make_unique<Circle>(4));
	fifth_test.add_figure(make_unique<Rectangle>(4.5, 14));
	fifth_test.add_figure(make_unique<Trapezoid>(27.3, 8.25, 10.5, 44, 2.8));

	//vector<unique_ptr<Figure>> fifth_test;

	/*fifth_test.push_back(move(make_unique<Circle>(4)));
	fifth_test.push_back(move(make_unique<Rectangle>(4.5, 14)));
	fifth_test.push_back(move(make_unique<Trapezoid>(27.3, 8.25, 10.5, 44, 2.8)));*/


	vector<Test> tests{

		//1
		Test(

			first_test,

			/*vector<unique_ptr<Figure>>{

				make_unique<Circle>(10), make_unique<Rectangle>(10, 10), make_unique<Trapezoid>(10, 10, 10, 10, 10)

			},*/

			vector<double>{ 10, 314.15926535897933, 62.831853071795862 },

			vector<double>{ 10, 10, 100, 40 },

			vector<double>{ 10, 10, 10, 10, 10, 100, 40 }

		),

		//2
		Test(

			second_test,

			/*vector<unique_ptr<Figure>>{

				make_unique<Circle>(1), make_unique<Rectangle>(1, 1), make_unique<Trapezoid>(1, 1, 1, 1, 1)

			},*/

			vector<double>{ 1, 3.1415926535897933, 6.2831853071795862 },

			vector<double>{ 1, 1, 1, 4 },

			vector<double>{ 1, 1, 1, 1, 1, 1, 4 }

		),

		//3
		Test(

			third_test,

			/*vector<unique_ptr<Figure>>{

				make_unique<Circle>(5.5), make_unique<Rectangle>(5.5, 5.5), make_unique<Trapezoid>(5.5, 5.5, 5.5, 5.5, 5.5)

			},*/

			vector<double>{ 5.5, 95.033177771091232, 34.557519189487721 },

			vector<double>{ 5.5, 5.5, 30.25, 22 },

			vector<double>{ 5.5, 5.5, 5.5, 5.5, 5.5, 30.25, 22 }

		),

		//4
		Test(

			fourth_test,

			/*vector<unique_ptr<Figure>>{

				make_unique<Circle>(1.234), make_unique<Rectangle>(12.46, 44.7), make_unique<Trapezoid>(674.5, 0.8723, 0.1234,78 ,565)

			},*/

			vector<double>{ 1.234, 4.7838790628097794, 7.7534506690596094 },

			vector<double>{ 12.46, 44.7, 556.96200000000010, 114.32000000000001 },

			vector<double>{ 674.5, 0.8723, 0.1234,78 ,565, 41.670470909999999, 1318.3723000000000 }

		),

		//5
		Test(

			fifth_test,

			/*vector<unique_ptr<Figure>>{

				make_unique<Circle>(4), make_unique<Rectangle>(4.5, 14), make_unique<Trapezoid>(27.3 ,8.25 ,10.5, 44, 2.8)

			},*/

			vector<double>{ 4, 50.265482457436690, 25.132741228718345 },

			vector<double>{ 4.5, 14, 63, 37 },

			vector<double>{ 27.3 ,8.25 ,10.5, 44, 2.8, 186.63749999999999, 82.349999999999994 }

		),

	};

	bool test_passed = true;

	cout << endl;

	for (auto& current_test : tests) {

		if (!is_vectors_fields_equal(current_test.figures_to_test,
			current_test.expectet_circle,
			current_test.expectet_rectangle,
			current_test.expectet_trapezoid)) {
			test_passed = false;
		}

	}

	if (test_passed == false) { cout << "Tests passed unsuccessfully" << endl; }
	else { cout << "All test passed successfully" << endl; }

	cout << endl;


}