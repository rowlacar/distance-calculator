#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double area, distance;
int a_x, a_y, b_x, b_y;


//Function prototypes
void calc_area(double width, double height);
void calc_distance(double width, double height);
void draw_an_ugly_triangle(double width, double height);

int main() {

	int a_x, a_y, b_x, b_y;

	/*declare the variables used for the distance points
	* The points are A(x,y) and B(x,y)
	*/

	printf("Enter the X coordinate for Point A: ");
	scanf_s("%i", &a_x); //The "_s" is like a safer version of scanf
	
	printf("Enter the Y coordinate for Point A: ");
	scanf_s("%i", &a_y);

	printf("Enter the X coordinate for Point B: ");
	scanf_s("%i", &b_x); 

	printf("Enter the Y coordinate for Point B: ");
	scanf_s("%i", &b_y);


	//The distance between two points is just the pythagorean thereom, where X vals are the base and Y vals are the height.
	//The "width" and "height" variables are just simplified versions of the distance formula, since I will be passing these into different functions
	//width will be the simplified version of (x2-x1)
	double width = (a_x - b_x);
	//height will be the simplified version of (y2-y1)
	double height = (a_y - b_y);
	//Make a hypoteneuse
	calc_distance(width, height);
	//how big is it?
	calc_area(width, height);
	
	printf("\nThe distance between these 2 points is %.2f units \n", fabs(distance));
	printf("\nIf you were to create a right triangle using the distance of these 2 points here would be the values of that triangle:\n");

	//print using absolute values since magnitude is absolute.
	//https://www.geeksforgeeks.org/fabs-function-in-c/
	
	printf("The width of the triangle is: %.2f units.\n", fabs(width));
	printf("The height of the triangle is %.2f units.\n", fabs(height));
	printf("The area of the triangle is %.2f units squared\n", fabs(area));
	
	draw_an_ugly_triangle(width,height);



	//consume the carriage return!
	while (getchar() != '\n');

	return 0;

}
/*Calculating distance between 2 points is given by d=sqrt((x2 – x1)^2 + (y2 – y1)^2 
* When we pass in "double width" and "double height"; these are the differences between the 2 points.
* We've already calculated the subx and suby by making a variable "width" and the variable "height" 
* which will be used in another function,so this function can be written as d=sqrt((width)^2 + (height)^2)
* 
* this will return both the distance between these 2 points, and the hypotenuse of a triangle.
*/
void calc_distance(double width, double height) {
	distance = sqrt((width * width) + (height * height));
}

//stop doing bad math by dividing by 2.0 instead of 2...
void calc_area(double width, double height) {
	area = (width * height) / 2.0;
}

void draw_an_ugly_triangle(double width, double height) {
	printf("\nAnd it would kind of look like this, but i'm just a console ok:\n");
	printf("A(%i,%i)\n", a_x, a_y);

/* Create the hypotenuse by incrementing spaces, and a "\" using a carriage return(i), increment 
* the spaces (j) by one until the height is met.
* 
* https://stackoverflow.com/questions/26804841/drawing-a-triangle-using-a-for-loop
* 
* NOTE: The triangle in this reference is different from mine, but I did use this to get help with the for loops.
*/
	for (int i = 0; i < fabs(height); i++) {
		for (int j = 0; j < i; j++) {
			//for every unit that exists within the height of a triangle, add one space before adding the "\"
			printf(" ");
		}
		// Print the hypoteneuse, but you have to escape the "\" so the new line that ends with a "\" is "\\\n"
		//https://stackoverflow.com/questions/43814515/getting-printf-to-print-escaped-backslashes 
		printf("\\\n");
	}

	// Print the base of the triangle, easy peasy
	for (int i = 0; i < fabs(width); i++) {
		printf("-");
	}
	//make a new line to separate the end of the console from my beautiful triangle.
	printf("B(%i,%i)\n", b_x, b_y);
}
