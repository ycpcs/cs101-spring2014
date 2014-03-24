---
layout: default
title: "Assignment 4: Calendar Computations"
---

**Due**: Wednesday, April 2nd by 11:59 PM

Getting Started
===============

Start by downloading [CS101\_Assign04.zip](CS101_Assign04.zip), saving it in the directory **H:\\CS101**.

Start a **Cygwin Bash Shell** and run the following commands:

    cd h:
    cd CS101
    unzip CS101_Assign04.zip
    cd CS101_Assign04

Using **Notepad++**, open the file

> **H:\\CS101\\CS101\_Assign04\\Calendar.cpp**

You will add your code to this file.

When you are ready to compile the program, in the Cygwin window type the command

    make

To run the program, type the command

    ./Calendar.exe

Your Task
=========

The program should prompt the user to enter the month and year as integers. It should then print out

1.  How many days the specified month has, and
2.  What day of the week the first day of the specified month falls on

Example run (user input in **bold**):

<pre>
Enter month and year: <b>3 2012</b>
That month has 31 days
The first day of that month is Thursday
</pre>

Note that your program must ensure that the user enters a month that is valid (in the range 1..12). If an invalid month is entered, the program should prompt the user to re-enter the month and year:

<pre>
Enter month and year: <b>13 2012</b>
Invalid month: please enter a month value in the range 1-12
Enter month and year: <b>2 2012</b>
That month has 29 days
The first day of that month is Wednesday
</pre>

Required functions
------------------

Your program must contain the following functions:

{% highlight cpp %}
bool is_leap_year(int year);
int num_days_in_month(int month, int year);
int get_julian_day(int day, int month, int year);
{% endhighlight %}

The **is\_leap\_year** function takes an integer year as a parameter and returns true if that year is a leap year, false if it is not a leap year.

The **num\_days\_in\_month** function returns the number of days in the month given as a parameter, where 1 indicates January, 2 indicates February, etc. The **year** parameter specifies the year, because calculating the correct number of days for February requires knowledge of whether or not the year is a leap year.

The **get\_julian\_day** function takes integer day (1 for first day of month), month (1 for January), and year parameters, and returns the [Julian Day Number](http://en.wikipedia.org/wiki/Julian_day) of that day.

Your program **must** use these functions in computing the output values shown to the user.

Approach/Hints
--------------

### Leap Years

A year is a leap year if *either*:

-   It is evenly divisble by 4 and not evenly divisible by 100, or
-   It is evenly divisible by 400

For example, 1996 and 2000 were leap years, but 1900 and 2003 were not leap years.

### Number of days in month

To determine the number of days in the month:

-   January, March, May, July, August, October, and December each have 31 days
-   April, June, September, and November each have 30 days
-   February has 28 days, except in leap years, when it has 29 days

Because the number of days in February depends on whether or not the year is a leap year, your **num\_days\_in\_month** function should call your **is\_leap\_year** function.

### Julian Day Computation

A [Julian Day Number](http://en.wikipedia.org/wiki/Julian_day) is an integer representation of dates since January 1, 4713 BC.

Assuming that **M** is a month (1 for January), **D** is a day of the month (1 for the first day of the month), and **Y** is a year, then the Julian Day Number (JDN) can be computed as follows:

> JDN = (1461 × (Y + 4800 + (M - 14)/12))/4 +(367 × (M - 2 - 12 × ((M - 14)/12)))/12 - (3 × ((Y + 4900 + (M - 14)/12)/100))/4 + D - 32075
>
> [source: Wikipedia]

Note that all divisions in the formula above are integer divisions, meaning that any fraction in the quotient is discarded.

Any Julian Day Number can be taken modulo 7 in order to determine which day of the week the day falls on:

> Test | Day of week
> ---- | -----------
> JDN % 7 == 0 | Monday
> JDN % 7 == 1 | Tuesday
> JDN % 7 == 2 | Wednesday
> JDN % 7 == 3 | Thursday
> JDN % 7 == 4 | Friday
> JDN % 7 == 5 | Saturday
> JDN % 7 == 6 | Sunday

Grading
=======

Your grade will be determined as follows:

* Function prototypes: 5
* Input month/year: 5
* Validate month input, re-prompt if invalid value is entered: 5
* **is\_leap\_year** function: 10
* **num\_days\_in\_month** function: 15
* **get\_julian\_day** function: 15
* Output of number of days in chosen month: 10
* Output of day of week of first day of chosen month: 10

We expect you to use good coding style.  Points may be deducted for poor variable names, inconsistent or missing indentation, and/or lack of comments.

Submitting
==========

To submit your work, make sure your **Calendar.cpp** file is saved, and in the Cygwin window type the command

    make submit

Enter your Marmoset username and password (which you should have received by email.) Note that your password will not be echoed to the screen. Make sure that after you enter your username and password, you see a message indicating that the submission was successful.

**Important**: Make sure that you check the file(s) you submitted to ensure that they are correct. Log into the server using the following URL (also linked from the course homepage):

> [https://cs.ycp.edu/marmoset](https://cs.ycp.edu/marmoset)

You should see a list of labs and assignments. In the row for **assign04**, click the link labeled **view**. You will see a list of your submissions. Download the most recent one (which should be listed first). Verify that it contains the correct files.

**You are responsible for making sure that your submission contains the correct file(s).**
