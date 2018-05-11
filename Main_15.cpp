// Dependencies
# include <cstdlib>
# include <iostream>
# include <sstream>
# include <fstream>
# include <string>
# include <vector>
# include <numeric>
# include <cmath>
# include <ctime>
# include <iterator>
# include <memory>
# include <stdio.h>


/*
Smart pointers : Class with power of pointers, but with its reallocation of memory when it is no longer required. The later is the extra!
Pointers and allocation of memory before and after
Before smart pointers, use of malloc for the purpose
*/


// Class of pizza
class aPizza {

	public :

		virtual void
		MakePizza() = 0;

};


// Class of NYStylePizza
class pizzaNY {

	public :

		std::string
		AddCrust() {

			std::cout << "Thin crust added to NY Style Pizza!" << std::endl;

		}

};


// Class of Deep Dish
class pizzaDeepDish {

	public :

		std::string
		AddCrust() {

			std::cout << "Deep Dish Pizza of Chicago Style!" << std::endl;

		}

};


// Template
template <typename T>
class lotsOfCheese : public T {

	public :

		std::string 
		AddCrust() {

			std::cout << "Lots of Cheese + " + T::AddCrust();

		}

};


template <typename T>
class lotsOfVeggies : public T {

	public :

		std::string 
		AddCrust() {

			std::cout << "Lots of Veggies + " + T::AddCrust();

		}

};


template <typename T> 
class pizzaCheeseNY : public T, public aPizza {

	public :

		void
		MakePizza() {
			std::cout << "Cheesy NY Style + " << T::AddCrust() << std::endl;
		}

};


template <typename T> 
class pizzaVeggiesDeepDish : public T, public aPizza {

	public :

		void
		MakePizza() {
			std::cout << "Vegan Deep Dish + " << T::AddCrust() << std::endl;
		}

};


// Main
int 
main(int argc, char const *argv[]) {

	// Memory allocation prior to smart pointers
	// int n_num_float;
	// float *ptr_n_floats;
	// std::string st_q_1("How many floats to store? : \n");
	// std::cout << st_q_1;
	// std::cin >> n_num_float;
	// ptr_n_floats = (float *)malloc(n_num_float*sizeof(float));
	// if (ptr_n_floats != NULL) {
	// 	int n_i = 0;
	// 	while(n_i < n_num_float) {
	// 		std::cout<< "Enter next float : \n";
	// 		std::cin >> ptr_n_floats[n_i];
	// 		n_i++;
	// 	}
	// }
	// std::cout << "The entered array of floats : \n";
	// for (int n_i = 0; n_i < n_num_float; n_i++) {
	// 	std::cout << ptr_n_floats[n_i] << " ";
	// }
	// std::cout << std::endl;

	// delete ptr_n_floats;

	// Smart pointers
	// std::unique_ptr<float []> uniq_ptr_arr_f_1(new float[n_num_float]);
	// // std::unique_ptr<float []> uniq_ptr_arr_f_2 = uniq_ptr_arr_f_1; // THIS IS NOT ALLOWED!!
	// std::cout << st_q_1;
	// std::cin >> n_num_float;

	// if (uniq_ptr_arr_f_1 != nullptr) { // It must be nullptr and NOT NULL
	// 	int n_i = 0;
	// 	while(n_i < n_num_float) {
	// 		std::cout<< "Enter next float : \n";
	// 		std::cin >> uniq_ptr_arr_f_1[n_i];
	// 		n_i++;
	// 	}
	// }
	// std::cout << "The entered array of floats : \n";
	// for (int n_i = 0; n_i < n_num_float; n_i++) {
	// 	std::cout << uniq_ptr_arr_f_1[n_i] << " ";
	// }
	// std::cout << std::endl;

	// Combine everything!!
	std::vector<std::unique_ptr<aPizza> > vec_uniq_ptr_aPizza_order;
	vec_uniq_ptr_aPizza_order.emplace_back(new pizzaCheeseNY<lotsOfCheese<pizzaNY> >()); // C++11 construct. If absent, we get error like-- "error: no member named 'emplace_back' in"
	vec_uniq_ptr_aPizza_order.emplace_back(new pizzaVeggiesDeepDish<lotsOfCheese<pizzaNY> >());
	for (auto &pizza : vec_uniq_ptr_aPizza_order) {
		pizza->MakePizza();
	}
	
	return 0;
}