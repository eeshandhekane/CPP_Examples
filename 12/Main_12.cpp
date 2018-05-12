// Dependencies
# include <cstdlib>
# include <iostream>
# include <string>
# include <vector>
# include <sstream>
# include <numeric>
# include <cmath>
# include <ctime>
# include <fstream> // For file I/O


// Define a class of box
class aBox {

	public :

		double d_length, d_breadth, d_width;

		std::string st_descr;


		aBox() {

			/*
			inputs--
			*/

			/*
			outputs--
			*/

			this->d_length = 1.0;
			this->d_breadth = 1.0;
			this->d_width = 1.0;

		}

		aBox(double d_l, double d_b, double d_w) {
			
			/*
			inputs--

			d_l :
				Length of box
			d_b :
				Breadth of box
			d_w :
				Width of box
			*/

			/*
			outputs--
			*/

			this->d_length = d_l, this->d_breadth = d_b, this->d_width = d_w; // Single liner assignment ops

		}

		// Operator overloading : Define custom operations like functions on class instances
		/*
		Unary operators : ++, --, *(pointer dereference), ->, !, &(address), +, - and define custom meanings
		*/

		// Overload the ++ operator (pre-increment)
		aBox&
		operator ++ () {

			this->d_length += 10; // Usually the += <n_i> has n_i = 1
			this->d_breadth += 10;
			this->d_width += 10;

			return *this; // Return pointer to updated box

		}

		aBox&
		operator ++ (int ) { // The argumen input needed is "int" ONLY!!

			this->d_length += 5; // Usually the += <n_i> has n_i = 1
			this->d_breadth += 5;
			this->d_width += 5;

			return *this; // Return pointer to updated box

		}

		// Create a c-string representations (char array terminated with null \0)
		operator const char*() {

			std::ostringstream oss_box_descr; // Create a new stream
			oss_box_descr << "[INFO] The instance of class aBox has : " << std::endl;
			oss_box_descr << "[INFO]\t\tlength : " << this->d_length << std::endl;
			oss_box_descr << "[INFO]\t\tbreadth : " << this->d_breadth << std::endl;
			oss_box_descr << "[INFO]\t\twidth : " << this->d_width << std::endl; // Update the stream

			this->st_descr = oss_box_descr.str(); // Convert to string

			return st_descr.c_str(); // Convert to C string

		}

		// Binary operators : aBox (this) + (binary op) aBox_ (another aBox istance). This is how the opeartor is defined
		aBox  // What is returned??
		operator + (const aBox& aBox_) {

			// Create a new box
			aBox aBox_sum;

			// Set entries appropriately
			aBox_sum.d_length = this->d_length + aBox_.d_length;
			aBox_sum.d_breadth = this->d_breadth + aBox_.d_breadth;
			aBox_sum.d_width = this->d_width + aBox_.d_width;

			return aBox_sum; // DEREK BANAS FORGOT THIS

		}

		// Accessing via subscript operators
		double 
		operator [] (int x) {

			if (x == 0) {

				return this->d_length;

			}
			else if (x == 1) {

				return this->d_breadth;
				
			}
			else if (x == 2) {

				return this->d_width;
				
			}
			else {

				return -1;

			}

		}

		// Equality checking
		bool 
		operator == (const aBox& aBox_) {

			return ((this->d_length == aBox_.d_length) && (this->d_breadth == aBox_.d_breadth) && (this->d_width == aBox_.d_width));

		}

		// Less than checking : Custom
		bool 
		operator < (const aBox& aBox_) {

			return ((this->d_length < aBox_.d_length) && (this->d_breadth < aBox_.d_breadth) && (this->d_width < aBox_.d_width));

		}

		// Greater than checking : Custom
		bool 
		operator > (const aBox& aBox_) {

			return ((this->d_length > aBox_.d_length) || (this->d_breadth > aBox_.d_breadth) || (this->d_width > aBox_.d_width));

		}

		// Overwrite assignment
		void 
		operator = (aBox& aBox_) {

			this->d_length = aBox_.d_length, this->d_breadth = aBox_.d_breadth, this->d_width = aBox_.d_width;

		}

};

/*
iostream : Allows to read from standard input and print to standard output
For files, the similar appropriate header is "fstream".
*/


// Main
int 
main(int argc, char const *argv[]) {

	aBox aBox_1(10, 10, 10);
	std::cout << aBox_1 << "\n" ; // This is with operator char*
	++aBox_1;
	std::cout << aBox_1 << "\n" ;
	aBox_1++;
	std::cout << aBox_1 << "\n" ;

	aBox aBox_2(4, 5, 6);
	aBox aBox_3 = aBox_1 + aBox_2;
	std::cout << aBox_3 << "\n" ;	

	std::cout << aBox_3[2] << "\n" ;		
	std::cout << aBox_3[1] << "\n" ;		
	std::cout << aBox_3[0] << "\n" ;	

	aBox aBox_4(29, 30, 31);	
	aBox aBox_5(32, 33, 34);
	std::cout.setf(std::ios::boolalpha);
	std::cout << "aBox_3 == aBox_4 : " << 	(aBox_3 == aBox_4) << std::endl;
	std::cout << "aBox_3 == aBox_5 : " << 	(aBox_3 == aBox_5) << std::endl;
	std::cout << "aBox_3  < aBox_5 : "  << 	(aBox_3  < aBox_5) << std::endl;
	std::cout << "aBox_5  > aBox_3 : "  << 	(aBox_5  > aBox_3) << std::endl;
	std::cout << "aBox_3  > aBox_5 : "  << 	(aBox_5  > aBox_3) << std::endl;

	// Create a stream to write to file
	std::ofstream ofs_write_to;
	std::ifstream ofs_read_from;
	std::string st_write_to;
	std::string st_read_from;
	// Open file by providing name
	/*
	ios::app : Append to the end of the file
	ios::trunc : Delete the content if file exists
	ios::in : Open to read
	ios::out : Open to write
	ios::ate : Open to write and move to the end of the file
	*/
	// Open, if does not exists then create
	ofs_write_to.open("Test_1_12.txt", std::ios_base::out | std::ios_base::trunc);
	if (ofs_write_to.is_open()) { // The opening is successful
		ofs_write_to << "Beginning of the file : \n";
		std::cout << "Enter data to write : \n";
		getline(std::cin, st_write_to); // Read without the ending newline
		ofs_write_to << st_write_to << std::endl;
		ofs_write_to.close();
	}
	// ofs_read_from.open("Test_1_12.txt", std::ios_base::in);
	// if (ofs_read_from.is_open()) {
	// 	while (ofs_read_from.good()) { // There is more information to read if .good() gives true
	// 		getline(ofs_read_from, st_read_from);
	// 		std::cout << st_read_from << std::endl; // Exact read input
	// 	}
	// 	ofs_read_from.close();
	// }

	// Example : File I/O

	std::vector<std::string> vec_st_1;
	std::string st_a_word;
	char ch_ = ' ';
	ofs_read_from.open("Test_1_12.txt", std::ios_base::in);
	if (ofs_read_from.is_open()) {
		while (ofs_read_from.good()) { // There is more information to read if .good() gives true
			getline(ofs_read_from, st_read_from);
			std::cout << st_read_from << std::endl; // Exact read input
			std::stringstream ss_(st_read_from);
			while(getline(ss_, st_a_word, ch_)) { // While there are words, 
				vec_st_1.push_back(st_a_word);
			}
		}
		ofs_read_from.close();
	}

	long long int lln_len = 0, lln_num = 0;
	for (auto x : vec_st_1) {
		lln_len += x.size();
		lln_num += 1;
	}
	double d_avg_len = (double)lln_len/lln_num;
	std::cout << "[INFO] Average word length : " << d_avg_len << std::endl;
	std::cout << "[INFO] Number of words : " << vec_st_1.size() << std::endl; // TRICK : ":" is 1-long word!



	return 0;
}