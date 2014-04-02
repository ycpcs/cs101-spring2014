---
layout: default
title: "Assignment 5: Heat Transfer on a Rectangular Plate"
---

*Note: preliminary version of assignment, not official*

Getting Started
===============

Start by downloading [CS101\_Assign05.zip](CS101_Assign05.zip), saving it in the directory **H:\\CS101**.

Start a **Cygwin Bash Shell** and run the following commands:

    cd h:
    cd CS101
    unzip CS101_Assign05.zip
    cd CS101_Assign05

Using **Notepad++**, open the file

> **H:\\CS101\\CS101\_Assign05\\HeatTransfer.cpp**

You will add your code to this file.

Run the command

    make

when you are ready to compile the program. To run the program, run the command

    ./HeatTransfer.exe

Your Task
=========

Your task is to write a program that computes the temperature distribution over a flat plate. Given a rectangular plate whose sides are set to four constant temperatures, we can place a grid over the plate (see the figure below) to find the temperature at each point. The temperature can be modeled as the average of the four points around it.

> Picture

Each time the temperature of one point changes, then, that of the four points around it will also change. After many iterations through the plate, we will find that the temperature distribution reaches equilibrium - it doesn't change much from one iteration to the next. In other words, the difference in temperature is less than some tolerance value for every point in the grid. At that time, we have the temperature distribution in the entire plate.

> Picture

Ideally, the program will take in as inputs:

-   The temperatures on the four sides of the plate;
-   The number of rows and columns to use in the grid;
-   The tolerance on temperature that will be used to terminate the program.

As outputs, the program will:

-   Print the grid of temperatures in a nicely formatted way (see above).
-   Print the number of steps taken before equilibrium.

Hints
=====

For the initial (up to 70%) code, you can use a preset grid size and you can use the previous step's values to update the new step. To get 100% credit, you'll need to use entirely old values to arrive at the new. This may require multiple arrays.

Remember that the tolerance tests the magnitude of the change in temperature. You must make sure that a change of (say) -5 degrees does not count as within your tolerance, unless the tolerance is more than 5 degrees. This tolerance should apply to each point in the plate - if one point is outside of the tolerance, the program continues!

You will need to use a flag (a variable whose value changes based on conditions) in order to tell when equilibrium is reached.

Your grid needs to have regions around the border for the constant temperature points.

Start the internal points in the grid at whatever temperature you find convenient. It won't change the results of the simulation.

Grading Criteria
================

**For a grade up to 70%**: Model the temperature on a rectangular plate using a ten-by-ten grid (the outer perimeter is at constant temperature). Allow the user to enter two temperatures for opposing side pairs (one for top and bottom, another for left and right). Use a tolerance hard-coded in the program (not user-input). Output a temperature grid and the number of steps to complete when finished.

**For a grade up to 80%**: The above, plus: Make each side able to have a different constant temperature. Make the grid into a square of user-specified size, up to at least 20-by-20 locations. Use a tolerance input by the person running the code.

**For a grade of up to 90%**: The above, plus use the previous step's temperatures to update the next. Make the user-input grid rectangular, up to at least 20 rows and 20 columns.

**For a grade of up to 100%**: All of the above, plus use nice formatting of the output, with two decimal places and enough space for temperatures up to 999.99 degrees. The output should line up like the example.

**Insane Extra Credit**: All of the above, plus output the result using contours of different colors to represent temperatures. You may wish to use the Console Graphics functions from [Lab 8](../labs/lab8.html) to accomplish this. Your output might look something like the following (click for full size image):

> Insane extra credit picture

**Coding style**: Make sure that you use meaningful variable names, that your code is properly indented, and that you include some comments explaining how the code works. Credit may be deducted if you use poor coding style.

Submitting
==========

To submit your work, make sure your **HeatTransfer.cpp** file is saved, and type the command

    make submit

Enter your Marmoset username and password (which you should have received by email.) Note that your password will not be echoed to the screen. Make sure that after you enter your username and password, you see a message indicating that the submission was successful.

**Important**: Make sure that you check the file(s) you submitted to ensure that they are correct. Log into the server using the following URL (also linked from the course homepage):

> [https://cs.ycp.edu/marmoset](https://cs.ycp.edu/marmoset)

You should see a list of labs and assignments. In the row for **assign04**, click the link labeled **view**. You will see a list of your submissions. Download the most recent one (which should be listed first). Verify that it contains the correct files.

**You are responsible for making sure that your submission contains the correct file(s).**
