// Dependencies
# include <cstdlib>
# include <iostream>
# include <sstream>
# include <fstream>
# include <string>
# include <vector>
# include <cmath>
# include <ctime>
# include <numeric>
# include <iterator> // To get iterator instances over structures


/*
Anything that starts with # is a preprocessor directive
It is run/performed before the compilation of the program
We can define various constructs elsewhere in other files and then include them
*/


# include "anAnimal_14.h" // Include from current directory!


# define MACRO_PI 3.14159265358979323846 // Define the macro, before compilation, all the MICRO_<macro> are replaced by the defined value. It can be a string as well
# define MACRO_FN_GET_AREA(rad) (MACRO_PI*(std::pow(rad, 2))) // We can also define functions


/*
Template functions are for functions and for classes. These can work for many different types.
Differ from function reloading. Instead of functions doing similar thing with different objects, a template does the same thing with different objects!!
*/
template<typename T> 
void 
Times2(T T_val) { // Template function

	std::cout << T_val << "*2 = " << T_val*2 << std::endl;

}


// We can create templates with multiple input types 
template<typename T1, typename T2>
T2
TypeCast(T1 T1_val, T2 T2_val) { // Template function

	return (T2)T1_val;

}


// We can have multi-valued template
template<typename T>
T
Max(T T_val_1, T T_val_2) { // Template function

	return ((T_val_1 > T_val_2)? T_val_1 : T_val_2);

}


// Template class!!
template<typename T_1, typename T_2>
class aPerson {

	public :

		T_1 T_1_height;

		T_2 T_2_weight;

		static int n_num_instances;

		aPerson(T_1 T_1_, T_2 T_2_) {

			this->T_1_height = T_1_;
			this->T_2_weight = T_2_;
			n_num_instances ++; // Increase the number of instances!!

		}

		void
		GetData() {

			std::cout << "[INFO] The instance of the class aPerson has : " << std::endl;
			std::cout << "[INFO]\t\theight : " << T_1_height << std::endl;
			std::cout << "[INFO]\t\tweight : " << T_2_weight << std::endl;

		}

} ;
// Note that the static instnace should be uniquely defined by the choice of T_1 and T_2. Thus, for each choice of these typenames, we need to have a different static variable!
template<typename T_1, typename T_2>
int aPerson<T_1, T_2>::n_num_instances; // This must be done for ALL static variables of a class


// Main
int 
main(int argc, char const *argv[]) {
	
	// Create an animal object
	anAnimal_14 anAnimal_14_tommy;
	anAnimal_14_tommy.st_name = "Tommy";
	std::cout << "The instance of anAnimal_14 has name : " << anAnimal_14_tommy.st_name << std::endl;

	// Circle area
	double d_rad = 10.0;
	std::cout << "The value of PI is : " << ((double)MACRO_PI) << std::endl;
	std::cout << "The value of PI is : " << MACRO_PI << std::endl;
	std::cout << "The area of the circle with radius : " << d_rad << " is : " << MACRO_FN_GET_AREA(d_rad) << std::endl;


	// Using a template
	Times2(5);
	Times2(50.0);
	Times2('a'); // 97*2

	// Using the multi-typed template
	std::cout << "(int) 5.9887 = " << TypeCast(5.9887, -3) << std::endl;
	std::cout << "(char) 97 = " << TypeCast(97, 'a') << std::endl; // 'a'

	std::cout << "Max of A and a : " << Max('A', 'a') << std::endl; 
	// std::cout << "Max of 4.5 and 5 : " << Max(4.5, 5) << std::endl;  // NOT ALLOWED!! Be careful! The types are inferred from the input and hence, they MUST be equal!
	std::cout << "Max of 4.5 and 5 : " << Max(4.5, TypeCast(5, 4.5)) << std::endl;  // TRICK!!
	std::cout << "Max of 134.6 and a : " << Max('a', TypeCast(134.6, 'a')) << std::endl;  // TRICK!! Output is empty
	std::cout << "Max of 134 and a : " << Max('a', TypeCast(134, 'a')) << std::endl; // TRICK!!
	std::cout << "Max of 134 and a : " << Max(134, TypeCast('a', 134)) << std::endl; // TRICK!!

	// Create persons!
	aPerson<double, double> aPerson_d_d_mikey(5.43, 50.9);
	aPerson<double, double> aPerson_d_d_mikael(5.43, 50.9);
	aPerson_d_d_mikey.GetData();
	aPerson<double, int> aPerson_d_d_misha(5.43, 50);
	aPerson_d_d_misha.GetData();
	std::cout << "Number of instance like mikey : " << aPerson_d_d_mikael.n_num_instances << std::endl;
	std::cout << "Number of instance like misha : " << aPerson_d_d_misha.n_num_instances << std::endl; // Access the static via an instance only!!

	// Iterators : It is a pointer that is used to point at container memory locations! Vector is an example of a container!!
	srand(time(NULL));
	std::vector<int> vec_n_1;
	for (int n_i = 0; n_i < 10; n_i++) {
		vec_n_1.push_back(std::rand()%101);
	}
	std::vector<int>::iterator vec_n_itr_1; // Define an iterator over a vector!
	std::cout << "Printing the vector using an iterator : \n";
	for (vec_n_itr_1 = vec_n_1.begin(); vec_n_itr_1 < vec_n_1.end(); vec_n_itr_1 ++) {
		std::cout << "Next entry : " << *vec_n_itr_1 << std::endl; // Since iterator is a pointer, dereference it to get the value
	}	

	// Increment iterator by fixed number of spaces!!
	std::vector<int>::iterator vec_n_itr_2 = vec_n_1.begin();
	advance(vec_n_itr_2, 3);
	std::cout << "The fourth entry by position (third by index) : " << *vec_n_itr_2 << std::endl; // 4th entry by number, 3rd by index is printed
	vec_n_itr_2 = vec_n_1.begin();
	advance(vec_n_itr_2, vec_n_1.size());
	std::cout << "The entry following the last valid entry (garbage value!!) : " << *vec_n_itr_2 << std::endl; // The entry following the last valid entry (garbage value!!)
	vec_n_itr_2 = vec_n_1.begin();
	advance(vec_n_itr_2, vec_n_1.size() - 1);
	std::cout << "The last entry : " << *vec_n_itr_2 << std::endl; // The last entry
	std::vector<int>::iterator vec_n_itr_3 = vec_n_1.begin();
	std::vector<int>::iterator vec_n_itr_4 = next(vec_n_itr_3, 5); // Next is similar to advance, but differs in that it returns a pointer to the advanced location
	std::cout << "The first entry : " << *vec_n_itr_3 << std::endl;
	std::cout << "The sixth position entry : " << *vec_n_itr_4 << std::endl;
	std::cout << "The iterator at the first position does not move with next. THe first entry : " << *vec_n_itr_3 << std::endl;
	auto vec_n_itr_5 = prev(vec_n_itr_4, 2); // This type of assignment figures out the type of the iterator (or any variable for that matter) on its own!!
	std::cout << "The fourth position entry : " << *vec_n_itr_5 << std::endl;

	// Iterator insertion at set locations!
	std::vector<int> vec_n_2;
	for (int n_i = 0; n_i < 10; n_i++) {
		if ((n_i != 2) && (n_i != 3) && (n_i != 5) && (n_i != 7)) {
			vec_n_2.push_back(n_i);	
		}
	} // The vector of non-primes!
	std::cout << "The original vector : \n" ;
	for (int x : vec_n_2) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	std::vector<int> vec_n_3;
	vec_n_3.push_back(2);
	vec_n_3.push_back(3);
	vec_n_3.push_back(5);
	vec_n_3.push_back(7);
	std::cout << "The merging vector : \n" ;
	for (int x : vec_n_3) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	// Merger
	std::vector<int>::iterator vec_n_itr_vec_n_2 = vec_n_2.begin();
	std::vector<int>::iterator vec_n_itr_vec_n_3 = vec_n_3.begin();

	copy(vec_n_itr_vec_n_3, next(vec_n_itr_vec_n_3, vec_n_3.size()), inserter(vec_n_2, next(vec_n_itr_vec_n_2, 4))); // Start after the 4th position in vector and append everything!!
	
	
	std::cout << "The merged vector : \n" ;
	for (int x : vec_n_2) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	return 0;
}