#define _USE_MATH_DEFINES
#include <cmath>
#include "matplotlibcpp.h"

using namespace std;
namespace plt = matplotlibcpp;

int main() 
{	
	// Prepare data for parametric plot.
	int minimum, maximum;

	cout << "Enter minumim angle between cords: ";
	cin >> minimum;
	cout << "Enter maximum angle between cords: ";
	cin >> maximum;

	const int size = maximum - minimum + 1;
	if (size >= 1)
	{
		vector<double> x(size), y(size);

		for (int angle = minimum, i = 0; i < size; angle++, i++)
		{
			x.at(i) = angle;
			y.at(i) = 100 / (2 * cos(angle/2 * (M_PI / 180.0)));
		}

		// plot() takes an arbitrary number of (x,y,format)-triples. 
		// x must be iterable (that is, anything providing begin(x) and end(x)),
		// y must either be callable (providing operator() const) or iterable. 
		plt::plot(x, y, "k-");
	}

	plt::xlabel("Angle formed between bolts (degrees)");
	plt::ylabel("% of load force on each bolt");
	//plt::axis([minimum, maximum, 0, 200]);
	//plt::savefig("resultantForces.png");
	// show plots
	plt::show();
}
