---
layout: default
title: "Lab 5: Conditions reading/modifying exercise"
---

# Getting started

Refer to [Lab 1](lab01.html) if you need a reminder about how to start **Cygwin Terminal** or **Notepad++**.

Start by downloading [CS101\_Lab05.zip](CS101_Lab05.zip), saving it in the directory **H:\\CS101**.

Start a **Cygwin Terminal** and run the following commands:

    cd h:
    cd CS101
    unzip CS101_Lab05.zip
    cd CS101_Lab05

# Reading and understanding code

One of the reasons that programming can be a challenge is the difficulty of *debugging*: figuring out why your program doesn't behave the way you expect, and modifying it so that it does.

An essential skill for debugging is being able to *read* code: looking at a program and figuring out what it does.

# What you will do in this lab

For each of the code examples below, do the following:

1. Read the code example carefully.
2. Write down a *prediction* about what the code example will do when it is executed; specifically, what output will be produced.
3. Perform an *experiment* to determine the code's actual behavior by running it.
4. If your prediction matched the actual behavior, briefly explain what happened when the code was executed.  If the actual results are different than your preduction, state a *theory* explaining the actual results.

Write down your predictions, experimental results, and theories in the file **report.txt**.  You can use Notepad++ to edit this file.

For step 3, run the command <b>make example<i>N</i>.exe</b>, where <i>N</i> is the example number, then run the command <b>./example<i>N</i>.exe</b>.  E.g., for example 1,

    make example1.exe
    ./example1.exe

Here is a complete example:

    Example 1
    Prediction: The output will be
       A
    Experiment: The output produced was
       A
    Explanation/Theory: Because the variable val contained the
    value 20, the condition val >= 20 was true, and the "if"
    block of the if/else statement was executed, and the "esle"
    block was not executed.

**Important**: Before you leave, show your work to your instructor or a tutor.

# Code examples

## Example 1

{% highlight cpp %}
int val = 20;
if (val >= 20) {
    printf("A\n");
} else {
    printf("B\n");
}
{% endhighlight %}

## Example 2

{% highlight cpp %}
int val = 20;
if (val > 20) {
    printf("A\n");
} else {
    printf("B\n");
}
{% endhighlight %}

## Example 3

{% highlight cpp %}
int val = 20;
if (val == 20) {
    printf("A\n");
} else {
    printf("B\n");
}
{% endhighlight %}

## Example 4

{% highlight cpp %}
int val = 20;
if (val = 20) {
    printf("A\n");
} else {
    printf("B\n");
}
{% endhighlight %}

## Example 5

{% highlight cpp %}
int val = 10;
if (val = 20) {
    printf("A\n");
} else {
    printf("B\n");
}
{% endhighlight %}

## Example 6

{% highlight cpp %}
int val = 0;
if (val = 0) {
    printf("A\n");
} else {
    printf("B\n");
}
{% endhighlight %}

## Example 7

{% highlight cpp %}
int val = 20;
if (val > 20) {
    printf("A\n");
}
if (val < 20) {
    printf("B\n");
}
{% endhighlight %}

## Example 8

{% highlight cpp %}
int val = 20;
if (val >= 20) {
    printf("A\n");
}
if (val <= 20) {
    printf("B\n");
}
{% endhighlight %}

Submit
======

To submit your work, type the command

    make submit

Enter your Marmoset username and password (which you should have received by email.) Note that your password will not be echoed to the screen.

**Important**:

> You **must** submit your work before leaving class. If you do not submit, you will not receive any credit for the lab.

<!-- vim:set wrap: ­-->
<!-- vim:set linebreak: -->
<!-- vim:set nolist: -->
