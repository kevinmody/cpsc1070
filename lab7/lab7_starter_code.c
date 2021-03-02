/*
Remember to include the mandatory header!
*/

#include <stdio.h>

/*
Here are some helpful functions you can use!
Don’t worry if you haven’t seen these before! :-)
You’ll learn more about how to make these yourself later, but for now
Just know that you can call these as you would any other function
And you write how they work down below.
*/
void make_pixel (int r, int g, int b);
void make_ppm_header (int width, int height);
void make_ppm_image (int width, int height);

int main()
{
	int width, country_code;

	// Read image dimensions and pixel color
	/*
	TODO:
	1. prompt user to enter country_code of chosen flag
	-  this should look really similar to the line down below
	*/
	fscanf(stdin, "%d", &country_code);
	fprintf(stderr, "What width (in pixels) do you want it to be?");
	fscanf(stdin, "%d", &width);
	fprintf(stderr, "\nMaking country %d’s flag with width %d pixels... \n", country_code, width);

	// Write the image data
	make_ppm_image(country_code, width);

	fprintf(stderr, "Done!\n\n");
	return(0);
}

// Creates a pixel with the colors you tell it to use when you call it
// To call it, just do something like make_pixel(244, 244, 244);
void make_pixel (int r, int g, int b)
{
	fprintf(stdout, "%c%c%c", r, g, b);
}

// Creates a header with the desired width and height when you call it
void make_ppm_header (int width, int height)
{
	fprintf(stdout, "P6\n");
	fprintf(stdout, "%d %d %d\n", width, height, 255);
}

// Creates a complete ppm image when you call it
void make_ppm_image (int width, int height)
{
	/*
	Here’s an example of calling one of the functions we made earlier
	TODO:
	1. Figure out the correct height per flag and pass it into the function
	*/
	make_ppm_header(width, height);

	/*
	Write your logic to print out the pixel data here for each flag
	TODO:
	1. make an if-else or switch depending on the country
	2. use nested for loops to iterate through
	3. determine which flag you are creating
	4. find where you are in the flag
	5. use make_pixel() to write the pixel
	-  you can use this like you would any other function.
	-  just pass in the values you want for r, g, and b
	*/
}
