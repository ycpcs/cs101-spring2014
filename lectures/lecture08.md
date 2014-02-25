---
layout: default
title: "Lecture 8: Nested Loops, char data type"
---

Nested Loops
============

Very often it is useful to nest one loop inside another.

Say we want to print the multiplication table: every product of the integers 0 .. 9:

{% highlight cpp %}
int row, col;

for (row = 0; row <= 9; row = row + 1) {
    for (col = 0; col <= 9; col = col + 1) {
        printf("%3i", row * col);
    }
    printf("\n");
}
{% endhighlight %}

This code produces the following output:

    0  0  0  0  0  0  0  0  0  0
    0  1  2  3  4  5  6  7  8  9
    0  2  4  6  8 10 12 14 16 18
    0  3  6  9 12 15 18 21 24 27
    0  4  8 12 16 20 24 28 32 36
    0  5 10 15 20 25 30 35 40 45
    0  6 12 18 24 30 36 42 48 54
    0  7 14 21 28 35 42 49 56 63
    0  8 16 24 32 40 48 56 64 72
    0  9 18 27 36 45 54 63 72 81

Char data type, char literals
=============================

The **char** data type represents a character values.

A literal char value is specified as a character in single quotes, e.g.:

> 'A'
>
> '?'
>
> ' '

Two char literals are special - the char literal for the single quote character and the char literal for the backslash character. They are written

> '\\''
>
> '\\\\'

The idea is that the first backslash "escapes" the following character. The escape is necessary in the first case because otherwise, an occurrence of a single quote within the char literal would end the char literal. In the second case, the escape is necessary because a single backslash is treated as escaping the next character.

Using scanf to read a single character
======================================

{% highlight cpp %}
char ch;

printf("enter a character: ");
scanf(" %c", &ch);

printf("you entered '%c'\n", ch);
{% endhighlight %}

This can be useful for prompting the user to answer a yes or no question:

{% highlight cpp %}
char answer;
int keep_going = 1;

while (keep_going == 1) {
    // some code...

    printf("Try again (y or n)? ");
    scanf(" %c", &answer);
    if (answer != 'y' && answer != 'Y') {
        keep_going = 0;
    }
}
{% endhighlight %}

Triangular loops
================

In the nested loops we have discussed so far, the inner loop in a pair of nested loops executes the same number of iterations no matter which iteration of the outer loop is being executed. We call such a loop pair "rectangular" because the two loop variables explore a space of values that looks like a rectangle if plotted on the x-y coordinate plane.

In a triangular loop, the number of iterations the inner loop executes depends on the value of the outer loop's loop variable. For example:

{% highlight cpp %}
int height, j, i;

printf("height of triangle: ");
scanf("%i", &height);

for (j = 0; j < height; j++) {
    for (i = 0; i <= j; i++) {
        printf("*");
    }
    printf("\n");
}
{% endhighlight %}

Example run (user input in **bold**):

<pre>
height of triangle: <b>6</b>
*
**
***
****
*****
******
</pre>
