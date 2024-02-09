# Objectives

  * Write a program to grayscale and threshold filter bitmap `bmp` images
  * Use typecasts in C to interpret a byte array (`unsigned char *`) in different ways
  * Use pointer arithmetic or array indexing to traverse memory
  * Compute padding to make an array a multiple of 4 bytes
  * Illustrate row-major order for storing two dimensional arrays
  * Use stream redirection to provide input and capture output from a program
  * Define variables for the C pre-processor and use pre-preprocessor directives to conditionally include code at compilation

# Project Summary

The goal of this project is to write a program that reads a bitmap (`bmp`) file from standard in (`stdin`), apply a threshold or grayscale filter to that image, and then write the filtered image to standard out (`stdout`).  

# Compiling

To compile the code, use the command: `gcc -g -Wall bmpFilter.c`. 

To compile with debugging information being sent to `stdout`, instead of the image bytes instead use the command: `gcc -g -Wall -DDEBUG bmpFilter.c`

The `-DDEBUG` option defines the `DEBUG` symbol for the pre-processor. The preprocessor will include or exclude code depending on whether or not `DEBUG` is defined. You can see this in the code where there are code sections that begin with `#ifdef DEBUG` and end with `#endif`.  Anything inside those two statements will only be included in the compiled code if `DEBUG` is defined. More details about these debugging options are given later in this write-up. 

# Running the program

In this project standard input and standard output are used to pass images to the program and save the filtered image.  Two usage examples: 
```
$ ./a.out < images/orig-cheese.bmp > my-threshold-cheese.bmp
$ ./a.out -g < images/orig-cheese.bmp > my-grayscale-cheese.bmp
```

The `<` character redirects the file `./images/orig-cheese.bmp` to standard input for `a.out` to read. The `>` characters redirects the standout output from `a.out` to the file `threshold-cheese.bmp`. The second example shows how to enable the grayscale filter with the `-g` flag.

# Testing and Debugging

Two test the output of your filter, save the resulting image, and then check to see if it differs at all from the provided output files. This is done using the `diff` command. `diff` takes in two arguments, which it then compares.  

```
$ diff images/threshold-cheese.bmp my-threshold-cheese.bmp
```

If there are any differences then the result of the `diff` command will tell you. 

## More efficient testing

You can also use stream redirection with a pipe to compare the output of the program to a given filtered version, without saving the output in between. This is done as follows:

```
$ ./a.out -g < images/orig-horses.bmp | diff - images/grayscale-horses.bmp 
```

The `-` character means that the first argument to `diff` comes from `stdin`. The `-` can be used for the left or right argument. 

Here is an example that uses pipes to generate the `xxd` dump of the filtered image and then compare that to the given `xxd` dump for the correct image. This command is very helpful for debugging.

```
$ ./a.out -g < images/orig-horses.bmp | xxd | diff - images/grayscale-horses.txt 
```

Here in this example the pipes are used to first generate the `xxd` output from the `a.out` and then redirect that into the `diff` utility.


# How to get started?

 1. Read all of this write up carefully to understand the `bmp` file format -- the file is copied into `bmpFileAsBytes` by the starter code.  
 2. Study the starter code in [bmpFilter.c](bmpFilter.c) and correlate it with the writeup
 3. Identify where in the header the following information is located:
    1. The offset to the start of the pixel array (`offsetFirstBytePixelArray`)
    2. The `width` of the image
    3. The `height` of the image
    4. The start of the actual pixel array in the byte array (`pixelArray`)
 4. Write an equation that uses `width` to compute the padding that separates each row in the pixel array so that the numbers of bytes in each row is a multiple of 4.  Make sure this outputs the correct padding for each sample image. 
 5. Write code top-down starting at `parseHeaderAndApplyFilter` or bottom-up starting at `getAverageIntensity` -- it is a matter of personal preference but a top down attack would be (for a bottom up approach, simply reverse the steps):
    1. Iterate over each row in the pixel array (`void applyFilterToPixelArray(unsigned char* pixelArray, int width, int height, int isGrayscale)`)
    2. Iterate over each pixel in a row (`void applyFilterToRow(unsigned char* row, int width, int isGrayscale)`)
    3. Filter each pixel to update it in the pixel array (`void applyFilterToPixel(unsigned char* pixel, int isGrayscale)`)
      1. `void applyThresholdToPixel(unsigned char* pixel)` or `void applyGrayscaleToPixel(unsigned char* pixel)`
      2. `unsigned char getAverageIntensity(unsigned char blue, unsigned char green, unsigned char red)`
 6. Use the `-DDEBUG` compiler flag to test a function **before** starting the next function in the chain
 7. Use `diff`, `xxd`, and `gdb` the test and debug each file as needed

**Important**: all the work is done *in place*. That means there is no copying of data, reading or writing from a file, or moving data into a data structure. The `bmpfileAsBytes` is an array of all the data; it is a complete copy of the file. The code should traverse and update that array. 

# Submission

Upload the final [bmpFilter.c](bmpFilter.c) file to [Canvas](http://canvas.byu.edu) for submission. A correct solution generates output to `stdout` that exactly matches, byte for byte, the corresponding filtered files in the `image` directory (see [images/README.md](images/README.md)) according to the `diff` utility.

# Rubric

  * Setting value for `offsetFirstBytePixelArray`, `width`, `height`, and `pixelArray` in `void parseHeaderAndApplyFilter(unsigned char* bmpFileAsBytes, int isGrayscale)` (40 points)
  * `void applyFilterToPixelArray(unsigned char* pixelArray, int width, int height, int isGrayscale)` (40 points)
  * `void applyFilterToRow(unsigned char* row, int width, int isGrayscale)` (40 points)
  * `void applyFilterToPixel(unsigned char* pixel, int isGrayscale)` (10 points)
  * `void applyThresholdToPixel(unsigned char* pixel)` (20 points)
  * `void applyGrayscaleToPixel(unsigned char* pixel)` (20 points)
  * `unsigned char getAverageIntensity(unsigned char blue, unsigned char green, unsigned char red)` (10 points)
  * Style (20 points, see [here](../style.md))
  * Other
    * +2 for early submission
    * +10 for 50% scale down filter
    * Late day negative points

# Getting the Starter Code

You should have already cloned the projects repo to you cs-lab account as part of Lab 1, but if for any reason you need to reclone it, you can use the directions below.

The projectss are in a `git` repository named [byu-cs-224-projects](https://bitbucket.org/byucs224/byu-cs-224-projects/src/master/). There is a button on the page named **Clone**, click that button, copy the command, and past it into the terminal. It will download the files directly to the remote machine. Here is the command to save time with following the link:

```
$ git clone https://bitbucket.org/byucs224/byu-cs-224-projects/src/master/
```

`git` is not part of this course. It is just a convenient way to distribute files. Once the files exist on the machine, nothing else is done with git until the next project, in which case the command `git pull` in the directory will get the new files or the repository can be cloned again in a different location.

# The Starter Code and your Tasks

The [bmpFilter.c](bmpFilter.c) files contains code to parse the command line options (`parseCommandLine`), read the entire file from `stdin` and store it into a `unsigned char*` array that is an exact byte-for-byte copy of the original file (`getBmpFileAsBytes`), call code to interpret the array and apply the appropriate filter (`parseHeaderAndApplyFilter`), and then write the entire array for the file to `stdout`.

The file includes additional structure to pattern good programing style. The entry point is `parseHeaderAndApplyFilter`. The parsing extracts from the header for the image the size of the image and where it is located in the array. The filter problem is then decomposed into these steps:

  1. `void applyFilterToPixelArray(unsigned char* pixelArray, int width, int height, int isGrayscale)`: iterate over each row in the pixel array calling step 2 on each one
  2. `void applyFilterToRow(unsigned char* row, int width, int isGrayscale)`: iterate over each pixel in the row and call step 3 on each one
  3. `void applyFilterToPixel(unsigned char* pixel, int isGrayscale)`: call the appropriate step 4 filter on each pixel
  4. `void applyThresholdToPixel(unsigned char* pixel)` or `applyGrayscaleToPixel(unsigned char* pixel)`: write the new value of the pixel using step 5
  5. `unsigned char getAverageIntensity(unsigned char blue, unsigned char green, unsigned char red)`: compute the average intensity of a pixel

Notice that each function does one simple computation that is one part of what is needed to filter the image.

**Extra Credit:** Implement an additional filter that scales down the image by 50%.


# Bitmap Header

The `bmp` file starts with a header that gives information about the structure of the file itself. The sections of the header that matter for this project are those that define the

  1. start of the pixel array (`offsetFirstBytePixelArray`)
  2. The `width` of the image
  3. The `height` of the image

Everything else that is in the header is not relevant to the project and should be ignored. *Note*: the extra-credit scale-down filter needs to modify the header.

The [file layout](fileLayout.png) shows the general structure of the BMP file. The [header](header.png) itself defines the offset to the start of the pixel array relative to the start of the file (*Offset For First Byte of the Pixel Array Data*). The [DIB Header](DIBHeader.png) contains the data needed to know the `width` (*Width of the Bitmap in Pixels*) and the `height` (*Height of the Bitmap in Pixels*).

**Important**: use the diagrams in the links to compute the offset into the file for the data. See [bmp File Info](bmp-file-info.pdf) for more details if needed.

# Pixels and the Pixel Array

A pixel is a sequence of three bytes. The order of the bytes is  **blue**, **green**, and finally **red**. A `bmp` image has a `width` and a `height` measured from the bottom left corner of the image. The `width` is the number of pixels in each row of the image. The `height` is the number of rows in the image. 

The pixel array stores the image in **row major order**. Row major order stores rows in order in the array. If the image has `width = 4` and `height = 3`, then below is an illustration of the pixel array where `i,j` is the `i`-th row and the `j`-th pixel in that row.

```
addresses --->
-------------------------------------------------------------------------
| 0,0 | 0,1 | 0,2 | 0,3 | 1,0 | 1,1 | 1,2 | 1,3 | 2,0 | 2,1 | 2,2 | 2,3 |
-------------------------------------------------------------------------
```

The first three pixels belong to row `0`, the next three pixel belong to row `1`, etc. in this example. An array of rows, as in the pixel array, is what is row major order. Traversing the array means that the pixels are traversed left to right, and then row by row, starting in the bottom left corner of the image.

If the same array is mapped to the memory diagrams that are drawn in class (rows of 4-bytes each with addresses increasing right to left and up) with the byte in each pixel actually shown, then the pixel array for the example looks like that below.

```
--------------------- -----
| r3 | g3 | b3 | r2 | 
---------------------
| g2 | b2 | r1 | g1 | row 2
---------------------
| b1 | r0 | g0 | b0 |
--------------------- -----
| r3 | g3 | b3 | r2 |
---------------------
| g2 | b2 | r1 | g1 | row 1
---------------------
| b1 | r0 | g0 | b0 |
--------------------- ----- 
| r3 | g3 | b3 | r2 |
---------------------
| g2 | b2 | r1 | g1 | row 0
---------------------
| b1 | r0 | g0 | b0 |  
--------------------- ----- <- Pixel Array
<- Addresses
```

Here the `bi`, `gi`, and `ri` indicate the blue, green, and red byte for the `i`-th pixel.

**Important**: each pixel is **3 bytes**. That is super critical to traversing each pixel in each row for the filter.

## Padding

Each row must be a multiple of 4 and if it is not, *padding* must be added to make it a multiple of four (*4-byte aligned*). Padding is just extra unused bytes at the end of the pixels for a row to make the total space taken by the row be a multiple of 4---each row starts on a 4-byte aligned address boundary (more on this later in the course). There is nothing in the padding. The bytes are just filler. 

Consider a pixel array for an image with `width = 2` (2 pixel in each row). A pixel is `3-bytes`, so the actual width in bytes is `2 * 3 = 6`. The nearest multiple of `4` to `6` is `8`, so each row gets `2` unused bytes of padding added to the end as below.

```
|            row 0              |            row 1              |
-----------------------------------------------------------------
| b | g | r | b | g | r | p | p | b | g | r | b | g | r | p | p | ...
-----------------------------------------------------------------
```   

The standard memory diagram in class is below where `pp` is a padding byte.

```
...
--------------------- -----
| pp | pp | r1 | g1 | 
--------------------- row 2
| b1 | r0 | g0 | b0 |  
--------------------- -----
| pp | pp | r1 | g1 | 
--------------------- row 1
| b1 | r0 | g0 | b0 |  
--------------------- -----
| pp | pp | r1 | g1 | 
--------------------- row 0
| b1 | r0 | g0 | b0 |  
--------------------- -----  <- Pixel Array
<- Addresses
```

**Important:** computing the padding for row given its `width` in pixels is super critical to traversing each row in the pixel array. The mod-operator (`%`) is super helpful for the computation because it shows how far off something is from being a multiple of `4`.

# Threshold Filter

Each pixel in the image is converted to either white or black based on the average intensity of its three color values. Pixels in the original image with an average intensity of 128 or more will become white (all colors 0xff); those with average intensities below 128 will become black (all colors 0x00). 

# Grayscale Filter

Each pixel in the image is converted to a *gray* pixel by setting all three color values equal to the average of the three original values. For example, if a pixel's RGB values in decimal are `100`, `55`, and `200`; the average integer value of which is `118`, this pixel's new RGB values in decimal would be set to `118`, `118`, and `118`. 

# Extra Credit 50% Scale Down

This filter will scale an image down to half its dimensions in both `width` and `height`. In other words, if the original image is `100` pixels wide and `50` pixels tall, then the resulting image should be `50` pixels wide and `25` pixels tall. In general, this will mean that four pixels in a square pattern from the original image become a single pixel in the filtered image. Determine the RGB values of this *composite* pixel by averaging the values of the four original pixels together on a per-color basis (i.e. compute the average of the red values, the average of the green values, and the average of the blue values and use these as the RGB values for the new pixel). Start in the bottom left corner of an image and work row by row, left to right and bottom to top to perform the scaling. Depending on the dimensions of the original image you may not have four pixels to work with when you reach the right and top edges of the image. In such cases simply compute the averages based on the pixels that are available (i.e. on the right edge you may only have two pixels stacked vertically to work with and on the top edge of the image you may only have two pixels sitting horizontally side-by-side to work with. It is also possible to end up with a single pixel left in the upper-right corner of the image after processing all the other pixels. In such a case this pixel would simply end up copied unchanged to the new image.

**Note: The autograder assumes the `-s` switch is used to run the scale down filter**  ex. `./bmpfilter -s < ./image.bmp`

# Pre-processor for debugging

The [starter file](bmpFilter.c) includes the following code in the `void parseHeaderAndApplyFilter(unsigned char* bmpFileAsBytes, int isGrayscale)`

```
#ifdef DEBUG
  printf("offsetFirstBytePixelArray = %u\n", offsetFirstBytePixelArray);
  printf("width = %u\n", width);
  printf("height = %u\n", height);
#endif
```

The code uses the pre-processor to conditionally include code. There is also this code in the `int main(int argc, char **argv)` function.

```
#ifndef DEBUG
  if (fwrite(bmpFileAsBytes, fileSizeInBytes, 1, stdout) != 1) {
    exit(FWRITE_ERROR);
  }
#endif
```

The code again uses the pre-processor to conditionally exclude code. In both cases, whether code is included or excluded depends on the presence of `DEBUG` being defined. `DEBUG` is defined at compile time with the command: `gcc -g -Wall -DDEBUG bmpFilter.c`. If is **not** defined with the normal compile command: `gcc -g -Wall bmpFilter.c`. 

The pre-processor is being used to enable `printf` debugging. It turns **off** the `stdout` output of the `bmp` image file, and it turns **on** the `printf` statements. It makes it so that the `printf` statements are easy to see and are not cluttered with the binary image output.

Add other `printf` statements as needed for testing and debugging. As before, `gdb` is a powerful tool for debugging that is more efficient because it does not require additional code. See the [primer](../gdb-primer.md) to get started with `gdb`.

