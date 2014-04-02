---
layout: default
title: "Lab 16: Grass Fire"
---

Getting Started
===============

Refer to [Lab 1](lab01.html) if you need a reminder about how to start **Cygwin Terminal** or **Notepad++**.

Start by downloading [CS101\_Lab16.zip](CS101_Lab16.zip), saving it in the directory **H:\\CS101**.

Start a **Cygwin Terminal** and run the following commands:

    cd h:
    cd CS101
    unzip CS101_Lab16.zip
    cd CS101_Lab16

Using **Notepad++**, open the file

> **H:\\CS101\\CS101\_Lab16\\GrassFire.cpp**

Run the command

    make

when you are ready to compile the program. To run the program, run the command

    ./GrassFire.exe

Your Task
---------

Your task is to implement a one-dimensional grass fire simulation using functions. The simulation consists of a sequence of cells, each of which represents either grass or fire. At each time step of the simulation, cells are updated according to the following rules:

-   If a cell is currently grass, and either its left or right neighbors is one fire, then it catches on fire
-   If a cell is currently on fire, it stays on fire

The program should prompt the user to enter how many cells there will be, the initial data for each cell (0 is grass, 1 is fire), and how many generations to simulate.

The first line of output should be the initial state. The rest of the lines of output should indicate each subsequent state (as the initial fires spread.)

Example run (user input in **bold**):

<pre>
How many cells? <b>20</b>
<b>0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0</b>
How many generations? 8
,,,,*,,,,,,,,,*,,,,,
,,,***,,,,,,,***,,,,
,,*****,,,,,*****,,,
,*******,,,*******,,
*********,*********,
********************
********************
********************
********************
</pre>

<!-- **** -->

Functions
=========

To simplify the simulation, implement the following functions:

**void read\_cells(int cells[], int num\_cells)**

> This function should read exactly **num\_cells** integer values and store them in the elements of the **cells** array.

**void print\_cells(int cells[], int num\_cells)**

> This function should print a textual representation of the contents of the **cells** array. Each **0** value in the array should result in a comma (,) being printed, and each **1** value should result in an asterisk (\*) being printed. The **num\_cells** parameter specifies the number of elements in the **cells** array.

**void update\_cells(int cells[], int num\_cells)**

> This function should implement one time step of the simulation. Each element in the **cells** array should be updated according to the rules of the simulation. Note that you will probably want to use a temporary array within the function to store the new values, and then copy the updated values back to the original **cells** array. *Hint*: use the **copy\_cells** function (see below) to copy the contents of the temporary array back to the original array. The **num\_cells** parameter specifies the number of elements in the **cells** array.

**void copy\_cells(int source[], int dest[], int num\_cells)**

> Copy all of the element values from the **source** array to the **dest** array. The **num\_cells** parameter specifies how many elements are in the **source** array.

Hints/Specifications
====================

The program should allow at least 100 cells to be simulated. Use a **\#define** constant to specify this maximum, and use it when declaring your array(s).

Start by getting the user input. Implement the **read\_cells** function to read the cell values into the array.

Next, implement the **print\_cells** function so that the program can print out the initial configuration of the simulation.

Finally, implement the simulation loop so that it calls the **update\_cells** and **print\_cells** functions. It will be helpful to call **copy\_cells** from the **update\_cells** function, in order to copy the update cell value back into the main cell data array.

> <div class="callout"> **Important**: make sure that your **update\_cells** function does not make any out of bounds array accesses. Specifically, updating the first and last cell will need to be handled specially because they have no left and right neighbor, respectively. These nonexistent neighbors should be considered to be grass (not on fire). </div>

Submitting
----------

To submit your work, type the command

    make submit

Enter your Marmoset username and password (which you should have received by email.) Note that your password will not be echoed to the screen.

**Important**:

> You **must** submit your work before leaving class. If you do not submit, you will not receive any credit for the lab.
