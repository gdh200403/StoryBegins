//p192 4.3.3.9-用函数指针实现生成三角函数表，并存入文件以便查阅
#include <stdio.h>
#include <math.h>

// Function prototype for the table() function
void table(double (*f)(double), double first, double last, double incr);

int main() {
	// Declare function pointers for the trigonometric functions
	double (*sin_ptr)(double) = sin;
	double (*cos_ptr)(double) = cos;
	double (*tan_ptr)(double) = tan;

	// Generate tables for the sin, cos, and tan functions
	table(sin, 0, 360, 10);
	table(cos, 0, 360, 10);
	table(tan, 0, 360, 10);

	return 0;
}

// Definition of the table() function
void table(double (*f)(double), double first, double last, double incr) {
	// Open a file for writing the table
	FILE *fp = fopen("trig_table.txt", "a");

	// Print a header for the table
	fprintf(fp, "Trigonometric Function Table\n\n");

	// Loop over the values of the argument
	for (double x = first; x <= last; x += incr) {
		// Print the value of the argument and the corresponding value of the function
		if (f(x) >= 0)
			fprintf(fp, "x = %-3.3f\tf(x) =  %-8.3f\n", x, (*f)(x));
		else
			fprintf(fp, "x = %-3.3f\tf(x) = %-8.3f\n", x, (*f)(x));
	}
	fprintf(fp, "\n");
	// Close the file
	fclose(fp);
}
