# ifndef ANANIMAL_14_H // Guards against including the header in multiple files. Once included, the define is there!
# define ANANIMAL_14_H // We read the following lines only ones!

// Preprocessor directive for include
# include <cstdlib>
# include <iostream>
# include <sstream>
# include <fstream>
# include <string>
# include <vector>
# include <numeric>
# include <ctime>
# include <cmath>


class anAnimal_14 {

	public :

		anAnimal_14();

		virtual ~anAnimal_14(); // Virtual allows for polymorphism!

		std::string st_name;

	private :

};

# endif // ANANIMAL_14_H