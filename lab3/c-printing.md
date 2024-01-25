# Lab 3 - Printing in C

This lab will give you practice printing out variables in different formats. 
In addition, you will get to implement an algorithm for determining the binary representation of a number. 
This lab is intended to prepare you to succesfully complete project 1. 

For this lab, start with an empty `main` function and we will start filling out and modifying it as we go. 

## Printing out variables

Every variable in your code is stored simply as 0s and 1s (each 0/1 is a single bit).  For a given group of bits, (like a byte, which is 8 bits), these 0s and 1s can be interpreted in many different ways.  The `printf` function will print out the content of variables in many different formats, and we will play with that a bit now. 

We will work with an `unsigned char` type for this example, but you are encouraged to play with other types as well.  Start with the following incomplete line of code. 

```
unsigned char u = ?;
```

### Initializing a variable

Our `unsigned char` can be initialized in many different ways.  Each of these will set the bits of `u` to match what we have specified. 

These methods will all work for any whole number type (`char/short/int/long`)

- Initialize to a whole decimal number: `unsigned char u = 51;`  
    - In this case the decimal value will be encoded into bits stored in the variable 
- Initialize to a hexadecimal number: `unsigned char u = 0xa2;`
    - In this case the hexadecimal value will be encoded into bits and stored in the variable
- Initialize to an ASCII character: `unsigned char u = 'c';`
    - In this case the ASCII character will be encoded into bits and stored in the variable.  To see the full ASCII encodings (the decimal and hexadecimal values for each character) check out <https://www.asciitable.com/>

Everything that happens to a variable, or that a variable is used for, depend only on the bits that make up that variable, not how they were initialized.  As an example, testing if two variables are the equal will check the bits that make up those variables.  

Consider the code in `equal.c`.  This will print out that `u` and `c` are the same, even though we initialized them in different ways.  Try it out!

---

#### Task 1: Find more combinations of ways to initialize `u` and `c` such that they are equal, but initialized using different methods.  

---

### Displaying a variable

Similarly to how the bits of a variable can be initialized in many different ways, we can also display the contents of a variable in a number of different ways.  `printf` has several different options for the format of outputting information. 

- `%c` : this will output the ASCII character with the same value as the variable
- `%x` : this will output the value of the variable in hexadecimal (base 16)
- `%d` : this will output the value of the variable in decimal (base 10)

---

#### Task 2: Initialize several different variables, of different types, and print their values out using each of the different formats shown above. 

---

For arrays of `char` variables, we can also use the `%s` format string with `printf`, which will print out the characters corresponding to the ASCII codes of each `char` in the array until it hits a `char` with a value of 0.  We call this the `NULL` character. 

The next 2 tasks will concern the code found in `string.c`.

---

#### Task 3: Figure out the correct 9 decimal numbers to input to the previous code so that it prints out *Go Cougs!*

---

---

#### Task 4: Write a loop to print out the hexadecimal representation of each `char` in the array `s`, after the *Go Cougs!* prints out. 

---

## Printing in Binary

Unfortunately for you, `printf` doesn't have a format string that will print variables in binary.  Instead, you will get to write code that does this (lucky you!).  We will describe to you how this is to be done, and for this lab, you will do it for a single `unsigned char`. 

You can use the code in `binary.c` to get started. 

For the `unsigned char` value set to the ASCII code for 'A' your code should output `01000001`.

There are many different ways you could determine the binary version of an `unsigned char`. 
One option is to implement the algorithm covered in class to convert an `unsigned char` to a string in bits. 
The pseudo-code for this is given below and takes as input an `unsigned char` with name `x`.

```
x = number to convert

repeat 8 times
    if x mod 2 == 1 then
        store a 1 bit
    else
        store a 0 bit
    x = x / 2
end
```

The algorithm generates the least significant bit first and the most significant bit last. Suppose that `x = 13`.

```
Iteration 0: x = 13 --> 1
Iteration 1: x = 6  --> 0
Iteration 2: x = 3  --> 1
Iteration 3: x = 1  --> 1
Iteration 4: x = 0  --> 0
Iteration 5: x = 0  --> 0
Iteration 6: x = 0  --> 0
Iteration 7: x = 0  --> 0
```
The output string should be `00001101`. Iteration `0` generated the least significant bit `1`, and iteration `7` generated the most significant bit `0`.

---

#### Task 5: Write the code to print out a single `char` in binary.  Use the other test cases, shown below, to make sure it is working. 

---

Test cases: 

+ 'p' : `01110000`
+ 'w' : `01110111`
+ 'o' : `01101111`
+ '!' : `00100001`


To pass off this lab show your code successfully printing out the binary of some `unsigned char` variables to a TA. 

---

## Application to Project 1: Myxxd

In project 1 you'll write a program that can print the contents of an entire file in hexadecimal/binary. For hexadecimal, you can use `printf`. For binary, you need to adapt your binary conversion code so that it can easily be used on an array of bytes instead of an individual byte.

