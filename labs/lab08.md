---
layout: default
title: "Lab 8: Gone Loopy"
---

Getting Started
===============

Refer to [Lab 1](lab01.html) if you need a reminder about how to start **Cygwin Terminal** or **Notepad++**.

Start by downloading [CS101\_Lab08.zip](CS101_Lab08.zip), saving it in the directory **H:\\CS101**.

Start a **Cygwin Terminal** and run the following commands:

    cd h:
    cd CS101
    unzip CS101_Lab08.zip
    cd CS101_Lab08

Using **Notepad++**, open the file

> **H:\\CS101\\CS101\_Lab08\\GoneLoopy.cpp**

Your task
=========

This lab is divided into two parts. Complete both parts in the same file.

Part 1
------

Your first task is to compute the average of some user input. Your program should continually prompt a user to input positive integer values that will be included in the average. When the user inputs a value of **-1**, your program should compute the average of all of the values previously input by the user and print it out to the screen. The average value should be printed to the screen with two decimal places of precision.

Example run (user input in **bold**):

<pre>
Enter a value to include in the average: <b>8</b>
Enter a value to include in the average: <b>3</b>
Enter a value to include in the average: <b>5</b>
Enter a value to include in the average: <b>-1</b>
The average of the 3 values input is: 5.33
</pre>

Another example run is below (user input in **bold**):

<pre>
Enter a value to include in the average: <b>2</b>
Enter a value to include in the average: <b>4</b>
Enter a value to include in the average: <b>6</b>
Enter a value to include in the average: <b>-1</b>
The average of the 3 values input is: 4.00
</pre>

Be sure to consider the case when a user does not input any values on which to compute the average (user input in **bold**):

<pre>
Enter a value to include in the average: <b>-1</b>
No values were input
</pre>

Part 2
------

Consider a situation in which you are given a single penny on day 1, two pennies on day 2, 4 pennies on day 3, etc. Each day the number of pennies received is twice as the number of pennies received the day before. That is, at the end of day 1, you will have a single cent. By the end of day 2, you will have 3 cents, one cent from day 1 and the 2 cents that were received on day 2. At the end of day 3, you will have 7 cents, 3 cents from the previous two days and the 4 cents received on day 3.

Write a program that asks a user how much money they would like to make. Then, using a **while** loop, determine how many days must pass before the user has accumulated the desired amount of money. **Use print statements in the body of your loop to keep track of how much money is given on each day and how much money has currently accumulated.**

Example run (user input in **bold**):

<pre>
How much money do you want (in dollars)? <b>0.56</b>
Day 1: Given $0.01, you now have $0.01
Day 2: Given $0.02, you now have $0.03
Day 3: Given $0.04, you now have $0.07
Day 4: Given $0.08, you now have $0.15
Day 5: Given $0.16, you now have $0.31
Day 6: Given $0.32, you now have $0.63
On day 6, you will have met (or exceeded) your request for $0.56 with a total of $0.63.
</pre>

When you are ready to compile the program, in the Cygwin window type the command

    make

To run the program, in the Cygwin window type the command

    ./GoneLoopy.exe

Submit
======

To submit your work, type the command

    make submit

Enter your Marmoset username and password (which you should have received by email.) Note that your password will not be echoed to the screen.

**Important**:

> You **must** submit your work before leaving class. If you do not submit, you will not receive any credit for the lab.
