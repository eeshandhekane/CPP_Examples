/*
This is multi-line comment.
Line 1
Line 2
*/


// Dependencies : Preprocessing directives
# include <iostream> // Input-output functionalities
# include <cstdlib> // From 1 type to another, random number functionalities, memory managements, sorting etc.
# include <string> // String functionalities
# include <vector> // Re-sizable arrays
# include <sstream> // Manipulate strings
# include <limits> // Find min and max of various datatypes


// Namespace : Provides a shortcut to avoid the name of the template. However, conflict if name of my func clashes with its.
// using namespace std;


// Global variables : Hungarian notation => add g to beginning of a global variable and then its data type
// e.g. int g_i_<identifier>;
int GLOBAL_RAND = 0;
const double GLOBAL_PI = 3.14159; // Once assigned, can not be changed


// Main : Execution starts here
int 
main(int argc, char const *argv[]) { // Optional data inputs : Number of arguments, array of input values (typed as strings)-- Also char** argv
	
	// Print out a string and then a new line
	std::cout << "Hello World!!" << std::endl; // cout represents the string. << is string insertion operator and passes the content to the string

	// Check if arguments passed
	if (argc != 1) {
		std::cout << "You entered " << argc << " number of arguments.\n";
	}

	// Print the arguments
	for (int i = 0; i < argc ; i++) {
		std::cout << argv[i] << std::endl;
	}

	// Datatypes : Names of identifiers should be data types. Hungarian notation
	bool is_married = true; // or false
	char ch_grade = 'A';
	unsigned int ui_weight = 43; // Never negative, short = 65k something is the range
	short int si_age = -10; // senseless!
	int n_days = 7;
	long l_big_num = 11001100;
	float f_pi = 3.14;
	double d_num = 3.123242425325;
	long double ld_pi = 3.1232441242352345;
	auto which_data = 3.15; // Automatic assignment of type

	// Ranges
	std::cout << "Min bool : " << std::numeric_limits<bool>::min() << "\n";
	std::cout << "Max bool : " << std::numeric_limits<bool>::max() << "\n";
	std::cout << "Min unsigned : " << std::numeric_limits<unsigned>::min() << "\n";
	std::cout << "Max unsigned : " << std::numeric_limits<unsigned>::max() << "\n";
	std::cout << "Min unsigned int : " << std::numeric_limits<unsigned int>::min() << "\n";
	std::cout << "Max unsigned int : " << std::numeric_limits<unsigned int>::max() << "\n";
	std::cout << "Min unsigned short int : " << std::numeric_limits<unsigned short int>::min() << "\n";
	std::cout << "Max unsigned short int : " << std::numeric_limits<unsigned short int>::max() << "\n";
	std::cout << "Min short int : " << std::numeric_limits<short int>::min() << "\n";
	std::cout << "Max short int : " << std::numeric_limits<short int>::max() << "\n";
	std::cout << "Min short unsigned int : " << std::numeric_limits<short unsigned int>::min() << "\n"; // order of short and unsigned does not matter
	std::cout << "Max short unsigned int : " << std::numeric_limits<short unsigned int>::max() << "\n"; // order of short and unsigned does not matter
	std::cout << "Min int : " << std::numeric_limits<int>::min() << "\n";
	std::cout << "Max int : " << std::numeric_limits<int>::max() << "\n";
	std::cout << "Min long int : " << std::numeric_limits<long int>::min() << "\n";
	std::cout << "Max long int : " << std::numeric_limits<long int>::max() << "\n";
	std::cout << "Min long : " << std::numeric_limits<long>::min() << "\n";
	std::cout << "Max long : " << std::numeric_limits<long>::max() << "\n";
	std::cout << "Min long long int : " << std::numeric_limits<long long int>::min() << "\n";
	std::cout << "Max long long int : " << std::numeric_limits<long long int>::max() << "\n";
	// std::cout << "Min long long long int : " << std::numeric_limits<long long long int>::min() << "\n"; // Should this exist?? NO!! It does not exist
	// std::cout << "Max long long long int : " << std::numeric_limits<long long long int>::max() << "\n"; // Should this exist?? NO!! It does not exist
	std::cout << "Min float : " << std::numeric_limits<float>::min() << "\n";
	std::cout << "Max float : " << std::numeric_limits<float>::max() << "\n";
	// std::cout << "Min long float : " << std::numeric_limits<long float>::min() << "\n"; // Invalid datatype
	// std::cout << "Max long float : " << std::numeric_limits<long float>::max() << "\n"; // Invalid datatype
	std::cout << "Min double : " << std::numeric_limits<double>::min() << "\n";
	std::cout << "Max double : " << std::numeric_limits<double>::max() << "\n";
	std::cout << "Min long double : " << std::numeric_limits<long double>::min() << "\n";
	std::cout << "Max long double : " << std::numeric_limits<long double>::max() << "\n";
	// std::cout << "Min long long double : " << std::numeric_limits<long long double>::min() << "\n"; // Invalid type
	// std::cout << "Max long long double : " << std::numeric_limits<long long double>::max() << "\n"; // Invalid type

	// Sizes in number of bytes used for various datatypes
	std::cout << "Size bool : " << sizeof(bool) << "\n";
	std::cout << "Size unsigned : " << sizeof(unsigned) << "\n";
	std::cout << "Size unsigned int : " << sizeof(unsigned int) << "\n";
	std::cout << "Size unsigned short int : " << sizeof(unsigned short int) << "\n";
	std::cout << "Size short unsigned int : " << sizeof(short unsigned int) << "\n";
	std::cout << "Size short int : " << sizeof(short int) << "\n";
	std::cout << "Size int : " << sizeof(int) << "\n";
	std::cout << "Size long int : " << sizeof(long int) << "\n";
	std::cout << "Size long : " << sizeof(long) << "\n";
	std::cout << "Size long long int : " << sizeof(long long int) << "\n";
	std::cout << "Size float : " << sizeof(float) << "\n";
	std::cout << "Size double : " << sizeof(double) << "\n";
	std::cout << "Size long double : " << sizeof(long double) << "\n";
	// std::cout << "Size auto : " << sizeof(auto) << "\n"; // Not allowed here!! Obviously!!

	// Loss of precision
	float f1 = 1.1111111111;
	float f2 = 1.1111111111;
	float fsum = f1 + f2;
	printf("%.10f + %.10f = %.10f\n", f1, f2, fsum); // 6 points for float, 10 for double
	printf("%s %c %d %5d %.3f\n", "HAHA", 'A', 3241, 1, 24.325325);

	// Math ops and receive inputs from user
	std::string st_question ("Enter number 1 : ");
	std::string st_num1;
	std::string st_num2;
	std::cout << st_question << "\n";
	getline(std::cin, st_num1); //cin is reference to keyboard
	std::cout << "Enter number 2 : " << "\n";
	getline(std::cin, st_num2);
	// Convert to ints
	int num1 = std::stoi(st_num1);
	int num2 = std::stoi(st_num2);
	printf("%d + %d  = %d\n", num1, num2, num1 + num2);
	printf("%d - %d  = %d\n", num1, num2, num1 - num2);
	printf("%d * %d  = %d\n", num1, num2, num1 * num2);
	printf("%d / %d  = %d\n", num1, num2, num1 / num2);
	printf("%d %% %d  = %d\n", num1, num2, num1 % num2);

	// Q1 : Miles to kilometers
	// km = miles * 1.60934
	std::string st_q1 ("Enter the miles : \n"), st_miles;
	std::cout << st_q1; // Print the question and expect an output
	getline(std::cin, st_miles);
	double miles = std::stod(st_miles);
	printf("kilometers corresponding to %.4lf miles is : %.4lf km\n", miles, miles*1.60934);

	// Program executed properly. -1 => Some error occurred
	return 0;

	/*
	./main 12 13 14

	Hello World!!
	You entered 4 number of arguments.
	./main
	12
	13
	14
	*/


}