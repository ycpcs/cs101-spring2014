---
layout: default
title: "Assignment 3: Falling Dominoes"
---

Milestone 1 due **Monday, March 17th**

Milestone 2 due **Monday, March 24th**

# Getting Started

Start by downloading [CS101\_Assign03.zip](CS101_Assign03.zip), saving it in the directory **H:\\CS101**.

There are two milestones.

## Milestone 1

In the first milestone, you will begin writing a program to simulate falling dominos.  You will add code to the file **FallingDominoes.cpp**.

Your program should allow the user to determine the initial configuration of the "playing field" consisting of 10 positions. Once the configuration has been entered by the user, the program should print a line of text which is a "picture" of the configuration.

Here is an example run (user input in bold):

<pre>
Enter the initial configuration:
Position 1 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>1</b>
Position 2 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>1</b>
Position 3 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>0</b>
Position 4 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>1</b>
Position 5 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>2</b>
Position 6 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>3</b>
Position 7 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>0</b>
Position 8 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>1</b>
Position 9 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>2</b>
Position 10 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>1</b>

Initial configuration:
|| |/_ |/|
</pre>

When printing out the state of the playing field, each upright domino should be represented by a "|" character, each tipping domino by "/", each horizontal domino by "\_", and each empty position by a blank space.

### Hints

Use an array of integer values to represent the playing field. The element at position 0 is position 1, the element at index 1 is position 2, etc. The value of each element determines what is at that position: 0 for an empty space, 1 for an upright domino, 2 for a tipping domino, 3 for a horizontal domino.

Each iteration of the loop that prints the playing field should print a character representing one position. Print "|" if the position has an upright domino, "/" if the position has a tipping domino, etc.

### Grading

Out of 50 points:

-   Declaration of an array to represent the playing field: 10
-   Loop to read a value for each position of the playing field: 10
-   Store each position value in the appropriate array element: 15
-   Loop to print a "picture" (line of text) of the playing field: 15

## Milestone 2

In this milestone, you will allow the user to simulate what happens when the first domino is pushed over: in other words, the simulation begins by changing the domino at position 1 from upright to tipping (if it was initially upright).

After the first domino has been tipped, the simulation should run for exactly **10** time steps.

Here is an example run (user input in bold):

<pre>
Position 1 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>1</b>
Position 2 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>1</b>
Position 3 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>1</b>
Position 4 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>0</b>
Position 5 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>2</b>
Position 6 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>1</b>
Position 7 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>1</b>
Position 8 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>1</b>
Position 9 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>0</b>
Position 10 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>1</b>

Tipping over domino 0:
/|| /||| |

Time step 1:
_/| _/|| |
Time step 2:
__/ __/| |
Time step 3:
___ ___/ |
Time step 4:
___ ____ |
Time step 5:
___ ____ |
Time step 6:
___ ____ |
Time step 7:
___ ____ |
Time step 8:
___ ____ |
Time step 9:
___ ____ |
Time step 10:
___ ____ |
</pre>

The rules of the simulation are as follows:

-   There are 10 positions, with position 1 being the leftmost position
-   The simulation begins by changing the domino at position 1 to "tipping"
-   On each timestep, each tipping domino will cause its neighbor to the right to change from upright to tipping (if the neighbor is upright); then the tipping domino will change to horizontal

### Hints

Each time step should be implemented as two **for** loops:

-   The first loop finds each tipping domino, changes its right neighbor to "ready to tip" (if it is upright), and then changes the original domino to horizontal.
-   The second loop finds each "ready to tip" domino and changes it to "tipping".

You should use a value for "ready to tip" positions that is distinct from the values that represent empty, upright, tipping, and horizontal.

Use a third for loop to print out the configuration of the playing field after the simulation of the timestep has completed.

### Grading

Out of 100 points:

-   Allow user to enter initial configuration (from milestone 1): 20
-   Tip first domino, print dominos: 10
-   One timestep:
    -   Loop to change successors of tipping dominoes to "ready to tip": 20
    -   Loop to change "ready to tip" to tipping: 20
    -   Print dominos at end of timestep: 10
-   Loop to simulate 10 timesteps: 20

# Submitting

To submit your work, make sure your **FallingDominos.cpp** file is saved, and in the Cygwin window type the command

    make submit_ms1

to submit Milestone 1, or

    make submit_ms2

to submit Milestone 2.

Enter your Marmoset username and password (which you should have received by email.) Note that your password will not be echoed to the screen. Make sure that after you enter your username and password, you see a message indicating that the submission was successful.

**Important**: Make sure that you check the file(s) you submitted to ensure that they are correct. Log into the server using the following URL (also linked off the course homepage):

> <https://cs.ycp.edu/marmoset/>

You should see a list of labs and assignments. In the row for **assign03\_ms1** or **assign03\_ms2**, click the link labeled **view**. You will see a list of your submissions. Download the most recent one (which should be listed first). Verify that it contains the correct files.

**You are responsible for making sure that your submission contains the correct file(s).**
