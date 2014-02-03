---
layout: default
title: "Lab 4: Salary Calculator"
---

Getting Started
===============

Refer to [Lab 1](lab01.html) if you need a reminder about how to start **Cygwin Terminal** or **Notepad++**.

Start by downloading [CS101\_Lab04.zip](CS101_Lab04.zip), saving it in the directory **H:\\CS101**.

Start a **Cygwin Terminal** and run the following commands:

    cd h:
    cd CS101
    unzip CS101_Lab04.zip
    cd CS101_Lab04

Using **Notepad++**, open the file

> **H:\\CS101\\CS101\_Lab04\\Salary.cpp**

Your Task
=========

Write a program to compute an employee's gross salary for a one-week period, given the number of hours worked and the hourly rate.

If the employee works 40 or fewer hours, then there is no overtime.

If the employee works more than 40 hours, then all hours in excess of 40 are overtime hours, and are paid at a rate 1.5 times higher than the employee's usual hourly rate.

The program should print the number of the overtime hours, the regular salary, the overtime salary, and the gross salary for the employee.

Example run (user input in **bold**):

<pre>
Enter your hours: <b>35</b>
Enter your hourly rate: <b>10.50</b>

Number of hours worked : 35.00h
Hourly rate: $10.50
Overtime hours: 0.00h
Overtime rate: $15.75
Regular pay: $367.50
Overtime pay: $0.00
Gross salary: $367.50
</pre>

In the case above, the employee did not work any overtime hours.

Another example (user input in **bold**):

<pre>
Enter your hours: <b>47</b>
Enter your hourly rate: <b>16.25</b>

Number of hours worked : 47.00h
Hourly rate: $16.25
Overtime hours: 7.00h
Overtime rate: $24.38
Regular pay: $650.00
Overtime pay: $170.62
Gross salary: $820.62
</pre>

In this second example, the employee had 7 overtime hours.

Display all figures using two decimal places of precision after the decimal point.

When you are ready to compile the program, in the Cygwin window type the command

    make

To run the program, in the Cygwin window type the command

    ./Salary.exe

Hints
=====

Use an **if/else** statement to calculate the number of regular hours and the number of overtime hours.

If the employee has worked 40 or fewer hours, then

> *regular hours* = *total hours*
>
> *overtime hours* = 0

If the employee has worked more than 40 hours, then

> *regular hours = 40*
>
> *overtime hours = total hours - 40*

Once the regular and overtime hours are known, then

> *regular pay* = *hourly rate* \* *regular hours*
>
> *overtime pay* = 1.5 \* *hourly rate* \* *overtime hours*

Submit
======

To submit your work, type the command

    make submit

Enter your Marmoset username and password (which you should have received by email.) Note that your password will not be echoed to the screen.

**Important**:

> You **must** submit your work before leaving class. If you do not submit, you will not receive any credit for the lab.
