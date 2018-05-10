// Dependencies
# include <cstdlib>
# include <iostream>
# include <string>
# include <vector>
# include <sstream>
# include <cmath>
# include <ctime>
# include <numeric>


// Structs : Mainly to create newer data types. Classes incorporate more complex mechanisms
/*
Classes have default private fields and methods
Structs have public versions of these
*/
struct aShape {
	
	double d_length; // By default public
	
	double d_width; // By default public

	// Define the constructor
	aShape(double d_l = 1.0, double d_w = 1.0) { // Public by default and can have default values

		/*
		inputs--

		d_l : 1.0
			Length of shape
		d_w : 1.0
			Width of shape
		*/

		/*
		outputs--
		*/

		d_length = d_l;
		d_width = d_w;

	} 

	// Define a function to get area
	double
	GetArea() {

		/*
		inputs--
		*/

		/*
		outputs--

		d_area (implicit) :
			The area of the shape
		*/

		return d_length*d_width;

	}

	private :

		int n_id;

};


// Struct inheritence
struct aCircle : aShape {

	// Override the constructor
	aCircle(double d_w) {

		/*
		inputs--

		d_w :
			Width of the circle. Its diameter
		*/

		/*
		outputs--
		*/

		this->d_width = d_w;

	}

	// Override the area function
	double
	GetArea() {

		/*
		inputs--
		*/

		/*
		outputs--

		d_area (implicit) :
			The area of the shape
		*/

		return 3.14159265358979323846*std::pow((this->d_width)/2, 2);

	}

};


// Main
int 
main(int argc, char const *argv[])
{

	// Struct instances
	aShape aShape_sq(100.0, 100.0);
	std::cout << "Square of dimensions : " << aShape_sq.d_length << " , " << aShape_sq.d_width << " has area : " << aShape_sq.GetArea() << std::endl;
	aCircle aCircle_(100.0);
	std::cout << "Circle of diameter " << aCircle_.d_width << " has area : " << aCircle_.GetArea() << std::endl;


	return 0;

}