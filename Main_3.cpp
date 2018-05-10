// Dependencies
# include <cstdlib>
# include <iostream>
# include <string>
# include <vector>
# include <numeric> // For iota
# include <sstream> // For string stream


// Function declarations
double
AddDoubles(double, double); // Names are not necessary, only datatypes

double
AddDoubles(); // Overloaded function. As the input types differ, the function is different

int
AssignInt(int age);

void
AssignInt(int*); // Overloading as well as passing addresses

void 
MultBy2(int*, int);

void 
GetRange(std::vector<int>*, int start, int end, int jump); // By address passing

std::vector<int>
GetRange(int start, int end, int jump); // DOES THIS WORK?? Once the call is finished, the vector should be erased right?? It does work, as the vector is created and stored in global memory

std::vector<int>
GetRange(std::vector<int>, int start, int end, int jump); // Can a vector be passed to a function?? THIS THING ALSO WORKS!!

// Function definitions
double
AddDoubles(double d_1, double d_2) {
	return d_1 + d_2;
}

double
AddDoubles() {
	double d_1, d_2;
	std::cout << "Enter number 1 : \n";
	std::cin >> d_1; // Another way to quick input!!
	std::cout << "Enter number 2 : \n";
	std::cin >> d_2;
	return d_1 + d_2;
}

int
AssignInt(int age1) { // Argument identifier in definition can differ from the one in the declaration
	return 27;
}

void
AssignInt(int* pt_n_age) {
	*pt_n_age = 30;
}

void 
MultBy2(int* arr, int size) {
	for(int i = 0; i < size ; i ++) {
		*arr *= 2;
		arr++; // Increment the pointer location
	}
}

void 
GetRange(std::vector<int> *vec_n_1, int start, int end, int jump) {
	while (start <= end) {
		// *vec_n_1.push_back(start); // THIS IS INVALID. THIS IS REPRESENTED AS vec_n_1->push_back(start);
		vec_n_1->push_back(start);
		start += jump;
	}
}

std::vector<int>
GetRange(int start, int end, int jump) {
	std::vector<int> vec_n_1;
	
	while (start <= end) {
		vec_n_1.push_back(start);
		start += jump;
	}

	return vec_n_1;
}

std::vector<int>
GetRange(std::vector<int> v, int start, int end, int jump) {
	
	while (start <= end) {
		v.push_back(start);
		start += jump;
	}

	return v;
}


// Main function
int
main(int argc, char const *argv[])
{
	
	// Vectors
	std::vector<int> vec_n_1(10);
	// Populate
	std::iota(std::begin(vec_n_1), std::end(vec_n_1), 0); // From start value = 0, start population
	for(int i = 0; i < vec_n_1.size(); i++) {
		std::cout << vec_n_1[i] << " X ";
	}
	std::cout << "\n";
	// Automatic data type detection and using the python's "in"-equivalent for traversing a vector
	for (auto y : vec_n_1) { // y in vec_n_1
		std::cout << y << " X ";
	}
	std::cout << "\n";
	// auto in loop is a c++11 thing!
	for (int y : vec_n_1) { // y in vec_n_1, with its type specified correctly
		std::cout << y << " X ";
	}
	std::cout << "\n";

	// // Inputs and vector example
	// std::string st_question("Please enter a starting number and a count : \n");
	// std::cout << st_question;
	// std::string st_input;
	// getline(std::cin, st_input);
	// std::stringstream ss(st_input);
	// std::string a_word;
	// char sep = ' ';
	// std::vector<std::string> vec_st_fields;
	std::vector<int> vec_n_2;
	// while(getline(ss, a_word, sep)) {
	// 	vec_st_fields.push_back(a_word);
	// }
	int n_start = 0, n_count = 10;
	// n_start = std::stoi(vec_st_fields[0]);
	// n_count = std::stoi(vec_st_fields[1]);
	for (int i = 0; i < n_count; i ++) {
		vec_n_2.push_back(i + n_start);
	}
	for (int i = 0; i < vec_n_2.size(); i ++) {
		std::cout << vec_n_2[i] << " X ";
	}
	std::cout << std::endl;
	for (auto an_entry : vec_n_2) {
		std::cout << an_entry << " X ";
	}
	std::cout << std::endl;

	// Functions
	std::cout << "4.43 + 5.4564 = " << AddDoubles(4.43, 5.4564) << std::endl;
	// std::cout << "Test Overloaded Function : \nAdding 4.43 and 5.4564. Please feed in these details to the function input requests : \n";
	// double d_ans = AddDoubles();
	// std::cout << "4.43 + 5.4564 = " << d_ans << std::endl;
	int n_change_age = 40;
	std::cout << "Original Age : " << n_change_age << std::endl;
	n_change_age = AssignInt(n_change_age);
	std::cout << "Changed Age : " << n_change_age << std::endl;

	// Pointers : Stores an address in memory. It has a type, which is the type of the pointed entity. For type t, the type of pointer is t*
	int *pt_n_age, age = 10;
	pt_n_age = &age; // Now, pt_n_age POINTS TO age
	std::cout << "The age is : " << age << std::endl;
	std::cout << "The address where age is stored is : " << &age << std::endl;
	std::cout << "The pointer points to : " << pt_n_age << std::endl;
	std::cout << "The value stored at the address of age, which should be the age itself, is : " << *(&age) << std::endl;
	std::cout << "The value stored at the location to which the pointer points, which should be the age itself, is : " << *pt_n_age << std::endl;
	// Cycling through an array using pointer
	float arr_f_1[] = {1.0, 2.0, 3.0, 4.0};
	float *pt_arr_f = arr_f_1; // Assign the array address, which is the identifier of the array, to the pointer of appropriate type
	for (int i = 0; i < 4; i ++) {
		std::cout << "The pointer points to " << i << "-th location in array.\n";
		std::cout << "Pointer points to location : " << pt_arr_f << std::endl;
		std::cout << "The value stored at the location is : " << *pt_arr_f << "\n";
		pt_arr_f += 1; // Increments the pointer position by appropriate amount. Note the amount un the address of the pointer
	}
	// // TRICK : The location is now out of array. So, trying to access the location might give garbage
	// std::cout << "The pointer points to " << "4" << "-th location in array.\n";
	// std::cout << "Pointer points to location : " << pt_arr_f << std::endl;
	// std::cout << "The value stored at the location is : " << *pt_arr_f << " (garbage value)\n";

	// Passing by address : Changing variable values in place
	int n_age = 40;
	std::cout << "Current age is : " << n_age << std::endl;
	AssignInt(&n_age);
	std::cout << "Changed age after passing address is : " << n_age << std::endl;

	// Passing arrays as pointer
	int arr_n_1[] = {1, 2, 3, 4, 5};
	std::cout << "Original Array : " << std::endl;
	for(int i = 0; i < 5; i ++) {
		std::cout << arr_n_1[i] << " X ";
	}
	std::cout << std::endl;
	// Does this work?? YES, IT DOES!!
	for (auto i : arr_n_1) {
		std::cout << i << " X ";	
	}
	std::cout << std::endl;
	// Does this work?? YES, IT DOES!!
	for (int i : arr_n_1) {
		std::cout << i << " X ";	
	}
	std::cout << std::endl;
	MultBy2(arr_n_1, 5); // Note that the name of the address is the pointer to its first entry (with appropriate type!!). The call changes the array values in place, as the address is passed
	for (auto i : arr_n_1) {
		std::cout << i << " X ";	
	}
	std::cout << std::endl;

	// Starting value, along with max value and increment value is input. Send back a vector as return type
	std::vector<int> vec_n_3;
	std::cout << "We create a vector of int, pass by reference, modify and then print : ";
	// int n_start_1 = -35, n_end_1 = 100, n_jump_1 = 7;
	int n_start_1 = 1, n_end_1 = 10, n_jump_1 = 1;
	GetRange(&vec_n_3, n_start_1, n_end_1, n_jump_1);
	for (auto i : vec_n_3) {
		std::cout << i << " X ";
	}
	std::cout << std::endl;
	std::cout << "We call a function, create a vector in it and return it back to the caller and print : ";
	std::vector<int> vec_n_4 = GetRange(n_start_1, n_end_1, n_jump_1);
	for (auto i : vec_n_4) {
		std::cout << i << " X ";
	}
	std::cout << std::endl;
	std::cout << "We create a vector, pass it and then modify it in function and then return : ";
	std::vector<int> vec_n_5;
	vec_n_5 = GetRange(vec_n_5, n_start_1, n_end_1, n_jump_1);
	for (auto i : vec_n_5) {
		std::cout << i << " X ";
	}
	std::cout << std::endl;

	// Traverse the vectors
	// std::string st_question_1("Please input a stringwith multiple words : \n");
	// std::cout << st_question_1;
	// std::string st_input_1;
	// std::cin >> st_input_1; // Get input
	// std::string a_word_1; 
	// std::stringstream ss_1(st_input_1);
	// std::vector<std::string> vec_st_words;
	// char sep_1 = ' ';
	// while(getline(ss_1, a_word_1, sep_1)) {
	// 	vec_st_words.push_back(a_word_1);
	// }
	// for (auto i : vec_st_words){
	// 	std::cout << i << " X ";
	// }
	// std::cout << std::endl;
	// /*
	// INPUT : fasfasdf dfsdfadfsa afgdsdg
	// OUTPUT : fasfasdf X
	// */
	// This is the correct way, as direct cin gets input that is terminated by any whitespace. getline inputs an entire line
	std::string st_question_2("Please input a stringwith multiple words : \n");
	std::cout << st_question_2;
	std::string st_input_2;
	getline(std::cin, st_input_2);
	std::string a_word_2; 
	std::stringstream ss_2(st_input_2);
	std::vector<std::string> vec_st_words_2;
	char sep_2 = ' ';
	while(getline(ss_2, a_word_2, sep_2)) {
		vec_st_words_2.push_back(a_word_2);
	}
	for (auto i : vec_st_words_2){
		std::cout << i << " X ";
	}
	std::cout << std::endl;
	/*
	INPUT : bjhjkh fassaf sdgjl m63546 
	OUTPUT : bjhjkh X fassaf X sdgjl X m63546 X
	*/

	return 0;
}