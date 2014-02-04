---
layout: default
title: "Lab 5: Conditions reading/modifying exercise"
---

# Reading and understanding code

One of the reasons that programming can be a challenge is the difficulty of *debugging*: figuring out why your program doesn't behave the way you expect, and modifying it so that it does.

An essential skill for debugging is being able to *read* code: looking at a program and figuring out what it does.

# What you will do in this lab

For each of the code examples below, do the following:

1. Read the code example carefully
2. Write down a *prediction* about what the code example will do when it is executed; specifically, what output will be produced
3. Perform an *experiment* to determine the code's actual behavior by running it
4. If the actual results are different than your preduction, state a *theory* explaining the actual results

TODO: worked example

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
int val = 20;
if (val > 20) {
    printf("A\n");
}
if (val < 20) {
    printf("B\n");
}
{% endhighlight %}

<!-- vim:set wrap: ­-->
<!-- vim:set linebreak: -->
<!-- vim:set nolist: -->
