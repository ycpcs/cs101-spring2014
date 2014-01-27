---
layout: default
title: "Lab 2: Expensive Calculator"
---

Getting started
===============

Refer to [Lab 1](lab01.html) if you need a reminder about how to start **Cygwin Terminal** or **Notepad++**.

Start by downloading [CS101\_Lab02.zip](CS101_Lab02.zip), saving it in the directory **H:\\CS101**.

Start a **Cygwin Terminal** and run the following commands:

    cd h:
    cd CS101
    unzip CS101_Lab02.zip
    cd CS101_Lab02

Using **Notepad++**, open the file

> **H:\\CS101\\CS101\_Lab02\\Calculator.cpp**

Run the command

    make

when you are ready to compile the program. To run the program, run the command

    ./Calculator.exe

Expensive Calculator
====================

Your task in this lab is to first read two **double** values from the user, and print out their sum, difference, product, and quotient. Then read two **int** values from the user, and print out their quotient and modulus.

Here is an example run of the program (user input in **bold**):

<pre>
Enter first decimal value: <b>8.5</b>
Enter second decimal value: <b>4</b>
8.500 + 4.000 = 12.500
8.500 - 4.000 = 4.500
8.500 x 4.000 = 34.000
8.500 / 4.000 = 2.125

Enter first integer value: <b>7</b>
Enter second integer value: <b>3</b>
7 / 3 = 2
7 % 3 = 1

Thank you for using the expensive calculator.
</pre>

Each double quantity should be printed with three digits of precision after the decimal point.

Hints
=====

Store the first two input values in variables of type **double**.

Store the second two input values in variables of type **int**.

Use the **printf** function to prompt the user for the two values and also to print out the computed results. The **%f** conversion specifier may be used to print values of type **double**, and the **%i** conversion specifier may be used to print values of type **int**.

Note that to print a percent sign (%) character using **printf** you need to put *two* percent characters in the formatting string. For example

    printf("%%");

would print a single % character in the output window.

Use the **scanf** function to read values typed by the user into your **double** and **int** variables. Use the **%lf** conversion specifier (that's "percent", "lower-case L","lower-case F") for the **double** values and **%i** for the integer values. Note: the **%f** conversion specifier will not work correctly for a **double** variable. Do not forget the **&** before the variable in the **scanf** statements.

Submit
======

To submit your work, type the command

    make submit

Enter your Marmoset username and password (which you should have received by email.) Note that your password will not be echoed to the screen.

**Important**:

> You **must** submit your work before leaving class. If you do not submit, you will not receive any credit for the lab.
