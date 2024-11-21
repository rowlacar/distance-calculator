#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {

	int x_1;
	int x_2;
	int y_1;
	int y_2;

	printf("Enter the X coordinate for Point A: ");
	scanf_s("%i", &x_1); //The "_s" is like a safer version of scanf

	/* The values for scanf include 
	* what am I scanning for, and where is it going
	* the %i means they can only enter an int.
	* the &x_1 is the memory location is age.
	*/
	
	double width = (x_2 - x_1);
	double height = (y_2 - y_1);

	

	printf("The distance between these 2 points is % lf units \n", calc_distance(width, height));
	printf("If you were to create a right triangle using the distance of these 2 points here would be the values of that triangle:");
	printf("The width of the triangle is: %lf\n", abs(width));
	printf("The height of the triangle is %lf\n", abs(height));
	printf("The area of the triangle is %lfunits squared\n", area(width, height);



	//consume the carriage return!
	while (getchar() != '\n');

}

double calc_distance(double width, double height) {
	double distance = sqrt((width * width) + (height * height));

	return distance;
}
double area(double width, double height) {

	double area = abs(((width * height) / 2));
	return area;

}