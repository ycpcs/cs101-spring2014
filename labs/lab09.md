---
layout: default
title: "Lab 9: Fancy Rectangle"
---

Getting Started
===============

Refer to [Lab 1](lab01.html) if you need a reminder about how to start **Cygwin Terminal** or **Notepad++**.

Start by downloading [CS101\_Lab09.zip](CS101_Lab09.zip), saving it in the directory **H:\\CS101**.

Start a **Cygwin Terminal** and run the following commands:

    cd h:
    cd CS101
    unzip CS101_Lab09.zip
    cd CS101_Lab09

Using **Notepad++**, open the file

> **H:\\CS101\\CS101\_Lab09\\FancyRectangle.cpp**

Your task
=========

Your task is to draw a rectangle of a size (number of rows and columns) specified by the user.

The rectangle should have a "special" character (specified by the user) at the corners of the rectangle, inset by one row and column from the edges.

Example run (user input in **bold**):

<pre>Number of rows: <b>12</b>
Number of columns: <b>35</b>
Special character: <b>O</b>

...................................
.O...............................O.
...................................
...................................
...................................
...................................
...................................
...................................
...................................
...................................
.O...............................O.
...................................</pre>

When you are ready to compile the program, in the Cygwin window type the command

    make

To run the program, in the Cygwin window type the command

    ./FancyRectangle.exe

Hints
=====

Suggested approach:

**(1)** First, write the code to prompt the user for the number of rows and columns and the "special" character.

You can read a single non-whitespace character into a variable as follows:

    char special;

    scanf(" %c", &special);

**Note**: there is a *single space* character preceeding the **%c** in the **scanf** format string.

**(2)** Add code to print a "solid" rectangle of the given size. I.e., don't worry about printing the "special" character at the corners.

You should use a pair of nested loops. The outer loop is responsible for generating all of the rows of output making up the rectangle. The inner loop is responsible for printing a single row of the rectangle by repeatedly printing a period (".") character.

The program will need to print a newline (**\\n**) character at the end of each row.

**(3)** Change the code that prints the period character so that it is an **if/else** statement of the following form:

The idea is that a condition (*should be a special character*) determines when the special character should be printed. You will need to think about how to specify this condition.

The code above assumes that the **char** variable called **special** stores the special character entered by the user.

Submit
======

To submit your work, type the command

    make submit

Enter your Marmoset username and password (which you should have received by email.) Note that your password will not be echoed to the screen.

**Important**:

> You **must** submit your work before leaving class. If you do not submit, you will not receive any credit for the lab.
