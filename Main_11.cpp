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


// Friend classes
/*
The private members of a class are not accessible to outside code, unless a class is marked friendly
*/
class aCustomer {

	private : 

		// Friend classes
		friend class getCustomerData;

		std::string st_name;

	public :

		aCustomer(std::string st_n) {

			/*
			inputs--

			st_n :
				The input string name
			*/

			/*
			outputs--
			*/

			this->st_name = st_n;

		}

};


// Define the friendly class
class getCustomerData {

	public :

		static std::string 
		GetName(aCustomer& aCustomer_) { // Pass customer by reference

			/*
			inputs--

			aCustomer_ :
				The input customer passed by reference
			*/

			/*
			outputs--
			*/

			return aCustomer_.st_name;

		}
};


// Define class
class classShape {

	protected :

		double d_height;

		double d_width;

	public :

		classShape(double d_) {

			/*
			inputs--

			d_ :
				The dimension, to be set as both length and width
			*/

			/*
			outputs--
			*/
			
			this->d_height = d_;
			this->d_width = d_;

		}

		classShape(double d_h, double d_w) {

			/*
			inputs--

			d_h :
				The height dimension, to be set as both length and width
			d_w :
				The width dimension, to be set as both length and width
			*/

			/*
			outputs--
			*/
			
			this->d_height = d_h;
			this->d_width = d_w;

		}

		// Polymorphism : Methods need to be marked as virtual to use the polymorphism
		virtual double
		GetArea() {

			/*
			inputs--
			*/

			/*
			outputs--

			d_area (implicit) :
				The area of the shape
			*/

			return this->d_height*this->d_width;

		}

};


// Circle as inherited class
class classCircle : public classShape {

	public :

		classCircle(double d_dia) : classShape(d_dia)  { // Invoke the constructor of the class shape, wherein the same value is assigned to height and width

			/*
			inputs--

			d_dia :
				The diameter dimension
			*/

			/*
			outputs--
			*/

		}

		double
		GetArea() { // Polymorphic, because the parent class has the same method labeled as virtual

			/*
			inputs--
			*/

			/*
			outputs--

			d_area (implicit) :
				The area of the circle
			*/

			return 3.14159265358979323846*std::pow((this->d_width)/2, 2);

		}

};


// Declare a function to get area of shape or any of its subclass
void
PrintAreaOfAShape(classShape& classShape_);


// Define a function to get area of shape or any of its subclass
void
PrintAreaOfAShape(classShape& classShape_) {

	/*
	inputs--

	classShape_ :
		Instance of the class of shapes or any of its subclass
	*/

	/*
	outputs--
	*/

	std::cout << "[INFO] The area of the passed shape instance is : " << classShape_.GetArea() << std::endl;

}


// Abstract classes : If a parent has no purpose other than to group all its children, we can make it an abstract class
class abstractShape {

	public :
		
		virtual double
		GetArea(); // This needs to be overridden by the child class

}; // This is how an abstract class looks like


// Create an implementation of the abstract class
class abstractChildClassCircle : public abstractShape {

	protected :

		double d_width;

	public : 

		abstractChildClassCircle(double d_dia) {

			/*
			inputs--

			d_dia :
				The diameter of the circle
			*/

			/*
			outputs--
			*/

			this->d_width = d_dia;

		}

		double 
		GetArea() override {

			/*
			inputs--
			*/

			/*
			outputs--

			d_area (implicit) :
				The area of the circle
			*/

			return 3.14159265358979323846*std::pow((this->d_width)/2, 2);

		}		

};


// Create another implementation of the abstract class
class abstractChildClassRectangle : public abstractShape {

	protected :

		double d_width;

		double d_height;

	public : 

		abstractChildClassRectangle(double d_w, double d_h) {

			/*
			inputs--

			d_w :
				The width of the rectangle
			d_h :
				The height of the rectangle
			*/

			/*
			outputs--
			*/

			this->d_width = d_w;
			this->d_height = d_h;

		}

		double 
		GetArea() override { // final { // override does the override of the parent declaration. "final" forces that the subclasses of the class will not have the ability to override

			/*
			If final is present, we get error : error: declaration of 'GetArea' overrides a 'final' function
			*/

			/*
			inputs--
			*/

			/*
			outputs--

			d_area (implicit) :
				The area of the rectangle
			*/

			return this->d_width*this->d_height;

		}		

};


// Create a subclass of rectangle
class aSquare : public abstractChildClassRectangle {

	protected :

		double d_width;

		double d_height;

	public : 

		aSquare(double d_w, double d_h) : abstractChildClassRectangle(d_w, d_h) {

			/*
			inputs--

			d_w :
				The width of the rectangle
			d_h :
				The height of the rectangle
			*/

			/*
			outputs--
			*/

		}

		double 
		GetArea() override {

			/*
			inputs--
			*/

			/*
			outputs--

			d_area (implicit) :
				The area of the rectangle
			*/

			return this->d_width*this->d_height;

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

	// Friendly classes
	aCustomer aCustomer_tom("Tom");
	getCustomerData getCustomerData_;
	std::cout << "The instance of the class aCustomer has name : " << getCustomerData_.GetName(aCustomer_tom) << std::endl; // This can be done because the private attribute can be accessed by friend classes

	// Polymorphism : Allows objects to be used similarly and allows different behaviour with methods marked as virtual
	classShape classShape_sq(10, 10);
	classCircle classCircle_c(10);
	PrintAreaOfAShape(classShape_sq);
	PrintAreaOfAShape(classCircle_c);

	return 0;

}