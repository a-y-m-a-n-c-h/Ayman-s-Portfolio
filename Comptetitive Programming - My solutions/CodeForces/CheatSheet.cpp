#include <iostream>
#include <string>
using namespace std;

class Fun {
	private: // cannot be accessed outside the class
		int x;
		double y;
	public:
		// Constructor with default values
		Fun (int ax=1, double ay=0): x(ax), y(ay) { }
			

		// Copy constructor; const indicates function does not change f
		Fun (const Fun & f) : x(f.x), y(f.y) { }

		// Destructor (may need to write destructor code for some classes)
		~ Fun () { }

		int getX () const {return x;} // const indicates member function does not change member variables x and y

		void setX (int ax) { x=ax; } // Can also write: this->x = ax; "this" is a pointer to current object

		// Can also have setters and getters for y member variable
		
		// overloading operator ==. 
		bool operator == (const Fun & f) {
			return ( x==f.x && y==f.y); 
		}


};

// Function that prints the x components in an array of Fun elements
// Can equivalently write the definition as void FunArrayPrintX (Fun * a, int n)
void FunArrayPrintX( Fun a [], int n) {
	for (int i=0; i < n; i++)
		cout <<a[i].getX()<<" ";
}

// Reference-based swap
void swap (int &x, int &y) {
	int tmp=x;
	x=y;
	y=tmp;
}

// Templated print array function
template <class T>
void print(T *t, int n) {
	for (int i=0; i<n; i++) {
		cout<<t[i]<<" "; }
	cout<<endl;
}

template <class T>
void insertionSort(T *a, int n) {
	int i;
	T key;
	for (int j=1; j <n; j++) {
		key=a[j];
		i=j-1;
		while (i >= 0 && key < a[i]) {
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=key;
	}
}


int main( ) {
	// Pointers and references
	int x=3;
	int & y = x; // y is an alias of x: can check they have same address cout<<&y <<endl; cout<<&x <<endl;
	int z=5;
	swap(x,z); // x and z are passed by reference and swap values. After this call x=5, z=3. Also y=5 since it is same as x
	int *w = & z; // w is a pointer to an integer; it points to z. cout << w <<endl; and cout << &z <<endl; yield the same value
	*w = 6; // This changes the value of z to 6
	w = & x; // Now the pointer w points to the integer x; cout << w; and cout << &x ; yield the same value

	
	// Instantiating a class
	Fun f0;   // Invoke default constructor
	Fun f1(2,3); 
	
	cout << "Is f0 == f1? ";
	if (f0==f1) {     
		cout<<"Yes."<<endl;}
	else {
		cout<<"No."<<endl;}

	Fun f1copy (f1); // Invoke copy constructor
	Fun f1copy2 = f1; // Invoke copy constructor
	
	Fun farray[2]= {f0,f1}; // Array of fun objects (also invokes copy constructor to  initialize farray[0] and farray[1]
	FunArrayPrintX(farray,2); 
	cout<<endl;



	// Dynamic memory allocation
	Fun * dyn = new Fun[2]; // Invoke default constructor 
	cout<<dyn[0].getX() <<endl; // Prints 1 because this the default value of x
	dyn[0] = Fun(4,7.3); 


	delete [ ] dyn; // Delete dyn because it was dynamically allocated


	int a[5]= {1,5,3,7,8};
	insertionSort(a,5);
	cout << "Sorted array: ";
       	print(a,5); 
		


	return 0;
}

