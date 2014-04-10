---
layout: default
title: "Assignment 6: Breakout"
---

**Due: Thursday, May 8th**

*Preliminary assignment description: not official*

Getting Started
===============

Start by downloading [CS101\_Assign06.zip](CS101_Assign06.zip), saving it in the directory **H:\\CS101**.

Start a **Cygwin Bash Shell** and run the following commands:

    cd h:
    cd CS101
    unzip CS101_Assign06.zip
    cd CS101_Assign06

Using **Notepad++**, open the file

> **H:\\CS101\\CS101\_Assign06\\Breakout.cpp**

You will add your code to this file.

When you are ready to compile the program, in the Cygwin window type the command

    make

To run the program, type the command

    ./Breakout.exe

Your Task
=========

Your task is to write an implementation of the classic computer game [Breakout](http://en.wikipedia.org/wiki/Breakout_(arcade_game)).

Here is a screenshot which you should use as a basis for your game:

> ![image](figures/assign6-screenshot.png)

The player controls a paddle (the row of blue '=' characters at the bottom of the screen) by pressing the left and right arrow key. The goal of the game is to deflect the ball (the white '\*' character) towards the colored rows of bricks at the top of the screen. Each time the ball strikes a brick, the brick is destroyed, the player earns some number of points, and the ball is deflected vertically. If the player lets the ball move down past the bottom of the screen, the ball is lost and the game ends.

You can run our implementation to get a sense of how yours should work:

> [Breakout.exe](Breakout.exe)

Requirements
============

Game requirements
-----------------

There should be 6 rows of bricks, each a different color. Each brick is three characters wide. There is one row of space between each row of bricks. Each brick is separated by one column of space.

The bricks in the bottom row are worth 10 points each. The bricks in the row immediately above the bottom row are worth 20 points each, and so forth, up to the bricks in the top row, which are worth 60 points.

The ball always moves diagonally. It bounces when it hits the left, top, or right side of the screen. If the ball moves past the bottom row of the screen, the game is over.

The paddle is 10 characters wide.

The animation delay per frame is set at 75 milliseconds, which works out to about 13 and 1/3 frames per second. The player may move the paddle every time the **update\_scene** function is called. The ball may move only *every other* time the **update\_scene** function is called. This means that the paddle can move faster than the ball.

When the ball strikes the paddle, it is deflected back up towards the top of the screen.

When the ball strikes a brick, it is deflected vertically, meaning that its reverses the vertical component of its motion. For example, if the ball hits a brick while it is traveling up (towards the top of the screen), then it changes to moving down (towards the bottom of the screen).

The player's score should be shown in the upper right-hand corner of the screen.

Program requirements
--------------------

Your task is to implement the **create\_scene**, **render\_scene**, and **update\_scene** functions. *Important*: each of these functions must take an instance of **struct Scene** (representing the overall state of the game) via a pointer parameter.

The **create\_scene** function should set up the initial state of the game by assigning values to the fields of the **struct Scene** instance.

The **render\_scene** function should use the console output functions to draw the current game state on the screen.

The **update\_scene** function should check the keyboard to see if the left or right arrow keys have been pressed, and move the paddle accordingly. (The paddle should not be allowed to be moved off the screen.) It should also check to see if the ball has collided with a brick or the paddle, and update the game state appopriately.

You can use the **cons\_get\_keypress** function to check to see if a key has been pressed:

    int key;

    key = cons_get_keypress();

    if (key == LEFT_ARROW) {
        // the left arrow key was pressed
        // ...
    }

    if (key == RIGHT_ARROW) {
        // the right arrow key was pressed
        // ...
    }

Hints
=====

You should implement the features of the program in stages. Get one feature completely working before moving on to the next feature.

Here is a possible strategy for implementing the program:

1.  Add field(s) to **struct Scene** to represent the paddle. Draw the paddle on the screen. Allow the player to move it using the left and right arrow keys. Make sure you don't allow it to move off screen.

2.  Add fields to **struct Scene** to represent the bricks. Base the number of bricks in each row on the width of the screen. Your **create\_scene** function will need to assign a location and color to each brick. Draw the bricks.

3.  Add fields to **struct Scene** to represent the ball. Allow the ball to move. Allow the ball to bounce off the left, top, and right sides of the screen.

4.  Check for collisions between the ball and the paddle. When a collision occurs, deflect the ball back up towards the top of the screen.

5.  Check for collisions between the ball and a brick. When a collision occurs, mark the brick as destroyed, add the point value of the brick to the player's score, and deflect the ball vertically.

6.  Print the player's current score in the upper-right corner of the screen.

Use struct data types to instances of bricks, balls, and the player's paddle. Write functions to perform operations on instances of these struct data types, taking the instances using pointer parameters. For example, I have the following function in my implementation:

    void destroy_brick(struct Scene *scene, struct Brick *brick)
    {
        // ...
    }

This function causes a specific brick to be destroyed, following a collision between the ball and that particular brick.

Grading criteria
================

Implementing the basic features as described above will earn up to 85 points. Of those 85 points, 15 points are allocated to design and coding style. Make sure your program uses consistent indentation, and has meaningful names for variables, functions, and struct data types.

Extra credit
------------

The following features may be implemented for extra credit:

**Multiple balls** (up to 5 points). Multiple balls are on the screen simultaneously.

**Lives** (up to 5 points). Instead of ending the game when the ball escapes past the bottom row of the screen, consider this as costing the player one life. The game ends when the player runs out of lives. The current number of lives should be displayed on the screen.

**Power-up bricks** (up to 10 points). A selected brick or bricks is a power-up brick. When a power-up brick is hit, it *temporarily* gives the player a new ability, such as:

> -   making the player's paddle wider
> -   allowing the player to shoot missiles at the bricks
> -   slowing down the ball(s)

Power-up bricks must be rendered using a distinct color and/or character.

(The classic video game [Arkanoid](http://en.wikipedia.org/wiki/Arkanoid) featured a number of power-ups you might use for ideas.)

**Controlled deflection** (up to 5 points). Based on where the ball strikes the player's paddle, the ball is deflected to the left, right, or straight up. For example, if the ball hits the left side of the paddle, the ball will be deflected to the left, even if it was originally travelling left-to-right.

Submitting
==========

To submit your work, make sure your **Breakout.cpp** file is saved, and in the Cygwin window type the command

    make submit

Enter your Marmoset username and password (which you should have received by email.) Note that your password will not be echoed to the screen. Make sure that after you enter your username and password, you see a message indicating that the submission was successful.

**Important**: Make sure that you check the file(s) you submitted to ensure that they are correct. Log into the server using the following URL (also linked from the course homepage):

> [https://cs.ycp.edu/marmoset](https://cs.ycp.edu/marmoset)

You should see a list of labs and assignments. In the row for **assign05**, click the link labeled **view**. You will see a list of your submissions. Download the most recent one (which should be listed first). Verify that it contains the correct files.

**You are responsible for making sure that your submission contains the correct file(s).**
