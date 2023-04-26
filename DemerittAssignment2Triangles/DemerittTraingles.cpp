#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {

	//Declare variables
	double sideA;
	double sideB;
	double sideC;
	double area;
	double halfPerimeter;
	bool isTriangle;

	// open input file
	ifstream fin("triangles.txt");

	//test input file
	if (!fin) {
		cout << "File doesn't exist" << endl;
		system("pause");
		return -1;
	}

	//Create output file
	ofstream fout("Area.txt");

	//read input file numbers
	while (fin >> sideA >> sideB >> sideC) {
		
		//check if proper triangle and set isTriangle accordingly
		if (((sideA + sideB) > sideC) && ((sideB + sideC) > sideA) && ((sideA + sideC) > sideB)) {
			isTriangle = true;
		}
		else {
			isTriangle = false;
			fout << "Invalid triangle" << endl;
		}
		//if proper triangle, calculate area and output area to file
		if (isTriangle) {
			halfPerimeter = (sideA + sideB + sideC) / 2;
			area = sqrt(halfPerimeter * (halfPerimeter - sideA) * (halfPerimeter - sideB) * (halfPerimeter - sideC));
			fout << setprecision(2) << fixed << area << endl;
		}
	}

	//close files and exit
	fout.close();
	fin.close();
	return 0;
}
