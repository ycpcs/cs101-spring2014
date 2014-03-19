---
layout: default
title: "Lab 13: Right Triangle"
---

Getting Started
===============

As always, you may refer to [Lab 1](lab01.html) if you need a reminder about how to start the **Cygwin Terminal** or **Notepad++**.

Begin by downloading [CS101\_Lab13.zip](CS101_Lab13.zip). Save the zip file in the **H:\\CS101** directory.

Start the **Cygwin Terminal** and run the following commands:

    cd h:
    cd CS101
    unzip CS101_Lab13.zip
    cd CS101_Lab13

Start the **Notepad++** text editor. Use it to open the files

> **H:\\CS101\\CS101\_Lab13\\RightTriangle.cpp**

Your Task
=========

This lab is broken up into four parts. In each part, your task is to write a program that draws a triangle in the terminal window. You **MUST** draw the triangles using the two functions supplied in **RightTriangle.cpp**. The appearance of the triangle will change slightly in each part, so read each part carefully.

**Part 0**

The file **RightTriangle.cpp** file currently has a **main** function as well as two other functions named **print\_spaces** and **print\_lines**. Before doing Parts 1 -4, read the **print\_spaces** and **print\_lines** functions and determine what those functions do. Write comments above each of the functions that describes their inputs and their behavior.

**Part 1**

Write a program that prompts a user to input the height of a right triangle and then draws the triangle in the terminal window. Inside the **main** function, write the code necessary to draw the right triangle like the one shown in the example below. You **MUST** call the **print\_spaces** and **print\_lines** functions from the **main** function to print the space and asterisk characters to the terminal window. **In part 1, DO NOT modify the print\_spaces or print\_lines function.**

<pre>
Example run (user input in **bold**):

Enter the height for your triangle: <b>6</b>
     *
    **
   ***
  ****
 *****
******
</pre>

When you are ready to compile the program, in the Cygwin window type the command:

    make

To run the program, in the Cygwin window type the command

    ./RightTriangle.exe

**Part 2**

In Part 2, you must modify the **print\_line** function to alter the look of the triangle. Rather than drawing a solid triangle, as in Part 1, you should now draw only the left and right sides of the triangle with an empty center. An example of this triangle can be seen below. You should **NOT** need to modify the code that you wrote for Part 1. That is, do not modify any of the code in your **main** function.

Example run (user input in **bold**):

<pre>
Enter the height for your triangle: <b>6</b>
     *
    **
   * *
  *  *
 *   *
*    *
</pre>

**Part 3**

For Part 3, you will again need to modify the **print\_line** function. This time, your goal is to modify the left and right sides of the triangle so that it is printed using the '/' and '|' characters as shown below. As with Part 2, you need only change the **print\_line** function. Do not change the **main** function.

Example run (user input in **bold**):

<pre>
Enter the height for your triangle: <b>4</b>
     /
    /|
   / |
  /  |
</pre>

**Part 4**

In this last part, you must draw a bottom on your triangle as shown below. To do this, you will need to add a new parameter to the **print\_line** function. This new parameter can be used to tell the **print\_line** function if the line to be drawn is the base of the triangle. Since there are only two different types of lines to draw (base and non-base), consider using a **bool** as the datatype for your new parameter. For this part, you will need to modify the **print\_line** function (as well as its function prototype) and the **main** function.

Example run (user input in **bold**):

<pre>
Enter the height for your triangle: <b>9</b>
        /
       /|
      / |
     /  |
    /   |
   /    |
  /     |
 /      |
/-------|
</pre>

Submitting
==========

When you are done, run the following command from the Cygwin bash shell:

    make submit

You will be prompted for your Marmoset username and password, which you should have received by email. Note that your password will not appear on the screen.

**Important**:

> You **must** submit your work before leaving class. If you do not submit work, you will not receive any credit for the lab.
