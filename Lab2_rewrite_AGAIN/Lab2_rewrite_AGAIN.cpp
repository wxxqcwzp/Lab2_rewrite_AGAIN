#include "Figure.h"
#include "Figure_controller.h"
#include "Files.h"
#include "Input.h"
#include "Tasks.h"

#include <iostream>

using namespace std;

enum target {
	ADD_FIGURE = 1,
	SHOW_FIGURES,
	SAVE_FIGURES,
	LOAD_FIGURES,
	RUN_TESTS,
	EXIT
};

int main()
{
	system("chcp 65001");
	system("cls");

	//Show_greeting();

	int menu_item;

	bool repeat = true;

	Figure_controller figures;

	do {

		//Show_menu();

		menu_item = InputInt("Select menu item : ", 0, 9);

		switch (menu_item)
		{

		case(ADD_FIGURE): { add_figure(figures); break; }

		case(SHOW_FIGURES): { figures.show_all_figures(); break; }

		case(SAVE_FIGURES): { save_data(figures); break; }

		case(LOAD_FIGURES): { load_data(figures); break; }

						  //case(RUN_TESTS): { run_tests(); break; }

		case(EXIT): { repeat = false; }

		}

	} while (repeat);

}
