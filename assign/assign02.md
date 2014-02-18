---
layout: default
title: "Assignment 2: Let's Make A Deal"
---

**Due dates:**

-   Milestone 1 is due **Wednesday, Feb 12th by 11:59 PM**
-   Milestone 2 is due <strike>Wednesday, Feb 19th</strike> **Monday, Feb 24th by 11:59 PM**

The Monty Hall Problem
======================

In this assignment, you will implement a simulation of the game show Let's Make A Deal. In particular, you will implement a simulation which allows the user to try out strategies for the [Monty Hall Problem](http://www.letsmakeadeal.com/problem.htm).

In the game, the contestant would be shown a stage with three closed doors:

-   Behind one of the doors was a valuable prize (the "car").
-   Behind two of the doors were less desirable prizes (the "goats").
-   The contestant would pick one of the three doors.
-   Monty Hall, the host of the show, would then reveal the prize behind another door (not the door the contestant picked initially), which was always a goat. (Note that even if the contestant happens to guess which door has the car right away, Monty will still reveal a goat behind a different door.)
-   Monty would then ask the contestant whether she wanted to switch her choice. Because Monty always revealed a goat, the contestant would need to decide whether her original door or the remaining unopened door was more likely to contain the car.

Milestone 1
-----------

In **Milestone 1**, the first of two milestones, you will simulate a single "round" in which

-   the program randomly decides which door the car is behind, without revealing this information to the user
-   allows the user to pick a door
-   lets the player know which door Monty opened (which must not be the door the player picked, and which must contain a goat)
-   asks the user whether she wants to change her choice to the other unopened door
-   informs the user which prize she won (car or goat)

Here is an example run of the program (user input in **bold**):

<pre>
Which door would you like to pick? (1-3) <b>3</b>
Monty shows you a goat behind door number 2
Which door would you like to pick now? (1-3) <b>1</b>
You won the car!
</pre>

Another example run (user input in **bold**):

<pre>
Which door would you like to pick? (1-3) <b>2</b>
Monty shows you a goat behind door number 1
Which door would you like to pick now? (1-3) <b>3</b>
You got a goat, sorry. The car was behind door 2
</pre>

Milestone 2
-----------

In this milestone you will allow the user to play repeated games. After each game, your program should prompt the to enter **1** to continue and **0** quit.

When the user quits, the program should print a summary of how many games were played, how many games the player won, and what percentage of games the player won (to two decimal places.)

Example run showing 3 games (user input in **bold**):

<pre>
Which door would you like to pick? (1-3) <b>1</b>
Monty shows you a goat behind door number 2
Which door would you like to pick now? (1-3) <b>3</b>
You won the car!
Another game? (1=yes, 0=no) <b>1</b>
Which door would you like to pick? (1-3) <b>2</b>
Monty shows you a goat behind door number 3
Which door would you like to pick now? (1-3) <b>1</b>
You won the car!
Another game? (1=yes, 0=no) <b>1</b>
Which door would you like to pick? (1-3) <b>3</b>
Monty shows you a goat behind door number 2
Which door would you like to pick now? (1-3) <b>1</b>
You got a goat, sorry. The car was behind door 3
Another game? (1=yes, 0=no) <b>0</b>
You played 3 games
You won 2 games
You won 66.67% of the games
</pre>

### Tasks for milestone 2

Milestone 2 consists of two tasks.

**Task 1**: Modify the program to allow the player to play multiple times as described above.

You will need to use a loop to allow the game to be repeated. Make sure that statements in your loop are properly indented.

**Task 2**: Using your program perform experiments to test two different strategies for playing the game:

1.  After Monty reveals the goat, stick with your original choice of door
2.  After Monty reveals the goat, switch doors to whichever door Monty did not reveal

For each strategy, play the game 10 times. What percentage of games did you win each time?

Using Notepad++, create an empty document and write a brief summary of your findings. Save it as a file called **experiment.txt** in your **CS101\_Assign02** folder. In the report, indicate what percentage of games you won using each strategy. If one strategy seems to be better, state which one.

Hints
-----

You can allow your program to generate random integer values as follows.

-   Add **\#include &lt;stdlib.h&gt;** and **\#include &lt;time.h&gt;** to the top of the file (above or below **\#include &lt;stdio.h&gt;**)
-   The first line of code in your **main** function should be

        srand(time(0));

    This "seeds" the random number generator to ensure that your program produces a different sequence of random numbers each time it is run.
-   You can generate a random integer between 1 and 3 with the code

        int car = (rand() % 3) + 1;

    In this code, "**rand()**" generates a random integer value, "**(rand() % 3)** constrains the random integer to the range 0-2, and adding 1 shifts the range to 1-3. In this code, the generated value is stored in the variable called **car**.

Grading
-------

### Milestone 1

Your grade for milestone 1 will be determined as follows:

-   Choosing a random door that the car is behind: 15%
-   Prompting the user to enter a door, and saving her choice in a variable: 20%
-   Choosing a door for Monty to reveal, printing a message informing the user: 35%
-   Prompting the user to enter a new choice, and saving her choice in a variable: 10%
-   Informing the user whether or not she won the car: 15%
-   Informing the user which door the car was behind: 5%

### Milestone 2

Your grade for milestone 2 will be determined as follows:

-   Allow game to be repeated: 40%
-   Statistics:

    -   Number of games played: 13%
    -   Number of games won: 13%
    -   Percentage of games won: 14%

-   Report describing experiments: 10%
-   Coding style (variable names, indentation, etc.): 10%

Submitting
----------

To submit your work, make sure your **MontyHall.cpp** file is saved, and in the Cygwin window type one of the following commands (depending on whether you are submitting **Milestone 1** or **Milestone 2**).

For **Milestone 1**:

    make submit_ms1

File **Milestone 2**:

    make submit_ms2

Enter your Marmoset username and password (which you should have received by email.) Note that your password will not be echoed to the screen. Make sure that after you enter your username and password, you see a message indicating that the submission was successful.

If the **make** commands above do not work, you can [submit using the web interface](../submitting.html) (see the link for details).

**Important**: Make sure that you check the file(s) you submitted to ensure that they are correct. Log into the server using the following URL (also linked off the course homepage):

> <https://cs.ycp.edu/marmoset/>

You should see a list of labs and assignments. In the row for **assign02\_ms1** (milestone 1) or **assign02\_ms2** (milestone 2), click the link labeled **view**. You will see a list of your submissions. Download the most recent one (which should be listed first). Verify that it contains the correct files.

**You are responsible for making sure that your submission contains the correct file(s).**
