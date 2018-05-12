// Dependencies
# include <cstdlib>
# include <iostream>
# include <vector>
# include <string>
# include <sstream>
# include <limits>

// Main function
int main(int argc, char **argv)
{
	
	// Input the string
	std::string st_age = "0";
	std::cout << "Please enter your age : " << std::endl;
	// getline(std::cin, st_age);

	int n_age = std::stoi(st_age);

	// If-else
	if ((n_age >= 1) && (n_age <= 18)) {
		std::cout << "Important age!!" << std::endl;
	}
	else if ((n_age == 21) || (n_age == 50)) {
		std::cout << "Important age!!" << std::endl;
	}
	else if (n_age >= 65) {
		std::cout << "Important age!!" << std::endl;	
	}
	else {
		std::cout << "Unimportant age!!" << std::endl;		
	}

	// Arrays
	int arr_nums_1[10] = {1}; // Array of size 10 with default value 1. Only the 0-th value is stored
	int arr_nums_2[] = {1, 2, 3}; // Initialization along with declaration
	std::cout << arr_nums_1[0] << " " << arr_nums_1[1] << std::endl;
	std::cout << arr_nums_2[0] << " " << arr_nums_2[1] << " " << arr_nums_2[2] << std::endl;
	arr_nums_2[2] = 4;
	std::cout << arr_nums_2[0] << " " << arr_nums_2[1] << " " << arr_nums_2[2] << std::endl;
	// Array size
	std::cout << "Array 2 size : " << sizeof(arr_nums_2)/sizeof(arr_nums_2[0]) << std::endl;
	std::cout << "Array 1 size : " << sizeof(arr_nums_1)/sizeof(*arr_nums_1) << std::endl;
	std::cout << "Array 1 size : " << sizeof(arr_nums_1)/sizeof(arr_nums_1[0]) << std::endl;
	// Multi-dim arrays
	int i_1, j_1, k_1;
	char ch_arr_1[2][2][2] = {'a'}; // Partial definition
	std::cout << "Printing multi-dim character array 1 : \n";
	for (i_1 = 0; i_1 < 2; i_1 ++) {
		for (j_1 = 0; j_1 < 2; j_1 ++) {
			for (k_1 = 0; k_1 < 2; k_1 ++) {
				std::cout << ch_arr_1[i_1][j_1][k_1] << " X ";
			}
		}
	}
	char ch_arr_2[2][2][2] = {{{'1', '2'}, {'3', '4'}}, {{'5', '6'}, {'7', '8'}}}; // Complete definition
	std::cout << "\nPrinting multi-dim character array 2 : \n";
	for (i_1 = 0; i_1 < 2; i_1 ++) {
		for (j_1 = 0; j_1 < 2; j_1 ++) {
			for (k_1 = 0; k_1 < 2; k_1 ++) {
				std::cout << ch_arr_2[i_1][j_1][k_1] << " X ";
			}
		}
	}
	char ch_arr_3[2][2][2] = {'1', '2', '3', '4', '5', '6', '7', '8'}; // Incomplete!! definition
	std::cout << "\nPrinting multi-dim character array 2 : \n";
	for (i_1 = 0; i_1 < 2; i_1 ++) {
		for (j_1 = 0; j_1 < 2; j_1 ++) {
			for (k_1 = 0; k_1 < 2; k_1 ++) {
				std::cout << ch_arr_3[i_1][j_1][k_1] << " X ";
			}
		}
	}

	// Vectors
	std::vector<float> f_vec_1(2);
	f_vec_1[0] = 5;
	f_vec_1[0] = 10; // Rewrite 
	f_vec_1[1] = 20; 
	f_vec_1.push_back(30);
	std::cout << "\nVector f vec 1 has size : " << f_vec_1.size() << std::endl;
	std::cout << "Vector f vec 1 has last entry : " << f_vec_1[f_vec_1.size() - 1] << std::endl;
	std::cout << "Vector f vec 1 has first two entries : " << f_vec_1[0] << " " << f_vec_1[1] << std::endl;

	// String to vectors
	std::string st_sent = "Some random stuff";
	std::vector<std::string> vec_st_words; // NO SIZE NEEDED
	std::stringstream ss(st_sent); // String stream, receives strings and manipulates them
	// Read sentence and separate words
	std::string a_word;
	char space = ' ';
	// Typical and important
	while(getline(ss, a_word, space)) {
		vec_st_words.push_back(a_word);
	}
	// Print all the words
	std::cout << "Printing all the words of the sentence : ";
	for(i_1 = 0; i_1 < vec_st_words.size() ; i_1 ++) {
		std::cout << vec_st_words[i_1] << " X ";
	}
	printf("\n");

	// Calculator example
	double d_num_1 = 0;
	double d_num_2 = 0;
	std::string st_calc_ip = "";
	std::vector<std::string> vec_st_components;
	std::cout << "Please enter the input : \n";
	getline(std::cin, st_calc_ip);
	std::stringstream ss1(st_calc_ip);
	std::string a_word_1;
	char space1 = ' ';
	// Standard procedure to break a string into components
	while(getline(ss1, a_word_1, space1)) {
		vec_st_components.push_back(a_word_1);
	}
	d_num_1 = std::stod(vec_st_components[0]);
	d_num_2 = std::stod(vec_st_components[2]);
	// // Debug step
	// for(i_1 = 0; i_1 < vec_st_components.size() ; i_1 ++) {
	// 	std::cout << vec_st_components[i_1] << " X ";
	// }
	if (vec_st_components[1] == "+") { // Simpler string comparison for std::string type
		std::cout << vec_st_components[0] << " + " << vec_st_components[2] << " = " << d_num_1 + d_num_2 << "\n" ;
	} 
	else if (vec_st_components[1] == "-") {
		std::cout << vec_st_components[0] << " - " << vec_st_components[2] << " = " << d_num_1 - d_num_2 << "\n" ;
	} 
	else if (vec_st_components[1] == "*") {
		std::cout << vec_st_components[0] << " * " << vec_st_components[2] << " = " << d_num_1 * d_num_2 << "\n" ;
	} 
	else if (vec_st_components[1] == "/") {
		std::cout << vec_st_components[0] << " / " << vec_st_components[2] << " = " << d_num_1 / d_num_2 << "\n" ;
	}  
	else {
		std::cout << "Invalid Operand Given As Input.\n";
	}	

	return 0;
	
}