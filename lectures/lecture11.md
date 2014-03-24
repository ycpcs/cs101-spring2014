---
layout: default
title: "Lecture 11: Functions, Top-Down Design"
---

Functions
==========

Functions are a way to specify a computation or task that needs to be repeated.

For example: drawing an outlined box of given height and width:

> print a solid row of width number of \* characters
>
> print newline
>
> repeated height - 2 number of times {
>
> > print \*
> >
> > print row of height - 2 spaces
> >
> > print \*
> >
> > print newline
>
> }
>
> draw a solid row of width number of \* characters
>
> print newline

What tasks are repeated in this algorithm?

> print row of \* characters
>
> print row of space characters
>
> others?

Any repeated task that is performed more than one time is an ideal candidate to become a function.

Functions are also called *subprograms*, and that's exactly what they are: little programs that are used to construct a larger program.

Top-down design
===============

Top-down design can be used for

> 1.  Developing an algorithm
>
> 2.  Implementing the algorithm as a program

Start by stating the overall problem:

> Deal a hand of bridge

Break it down into sub-problems:

> Shuffle
>
> Have another player cut
>
> while (there are cards left) {
>
> > for each player in order {
> >
> > > deal a card to that player
> >
> > }
>
> }

Each subproblem can then be further broken down into sub-subproblems until we have a complete description of the algorithm. The sketch of the algorithm using named subproblems is *pseudo-code*. It is an extremely useful technique for planning your algorithm, before you start writing the program.

Generally, each named subproblem will become a procedure when we turn the algorithm into a program. In otherwords, procedures give us an easy way to convert pseudo-code into a complete program.

Functions in C
==============

In C, procedures are called *functions*.

> **They are not (necessarily) like mathematical functions.**

Calling a Function
==================

Using a function involves *calling* or *invoking* the function. A function call is an *expression* of the following general form:

> *identifier* ( *expressionList* )

*expressionList* is a comma-separated list of zero or more expressions. These expressions are used to compute the *argument values*. These values are passed to the function to specify the input values to the function.

Recall that an *expression* computes a *value*.

Here is what happens when you call a function:

> Each expression in the expression list is evaluated to compute its value
>
> The computed value of each expression is "delivered" to the called function (more about this in a moment)
>
> The code inside the function is executed using the computed values
>
> When the code inside the function finishes executing, it can (optionally) return a value.

If you have used the function call as an expression, then the value returned by the function is the value computed by the expression.

Simple example:

> **sqrt(x)** in **&lt;math.h&gt;**: is a function to compute the (approximate) square root of a double value.

**sqrt(x)** is like a mathematical function. For a given input value, there is precisely one possible output value.

{% highlight cpp %}
printf("%lf\n", sqrt(16.0));
{% endhighlight %}

The function call expression **sqrt(16.0)** is evaluated by calling the function with the argument 16.0 and using its return value (4.0) as the value of the function call expression.

A more complex example:

{% highlight cpp %}
#include <stdio.h>
#include <math.h>

int main(void)
{
    double area_in_square_feet, side;

    printf("Area in square feet? ");
    scanf("%lf", &area_in_square_feet);

    side = sqrt(area_in_square_feet);

    printf("%f square feet fit in a square %f feet on a side\n", 
            area_in_square_feet, side);

    return 0;
}
{% endhighlight %}

Some functions do not return a value. Such function calls are written as *statements* rather than expressions. In other words, a call to a function that does not return a value cannot be an expression.

E.g., the **exit()** function, which causes the program to terminate immediately:

{% highlight cpp %}
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int val;

    printf("Enter a non-negative value: ");
    scanf("%i", &val);

    if (val < 0) {
        printf("Invalid value: %i\n", val);
        exit(1);
    }

    ...etc...
}
{% endhighlight %}

Writing your own functions
==========================

Example: draw rectangle using "\*" characters

> What information do we need to define the possible rectangles we will draw?
>
> > *height, width*

These are the *parameters* of the function. They store the data values the function will use to carry out the computation.

Here is the general form of a C function:

> *returnType identifier* ( *parameterList* )
>
> {
>
> > *statements*
>
> }

The *returnType* is a data type defining the type of value that is computed as the result of the function. For example, the return type of the built-in **sqrt()** function is double, since the value that it computes (and returns) has that type.

Some functions do not compute a value. Instead, they are used for some *side-effect* that they have (such as printing output). Such functions use a special data type called **void**. When you see a function with a **void** return type, it means that the function does not compute a value. The **void** type cannot be used to declare a variable, since there are no values of type **void**.

The *identifier* provides a name for the function. Generally, you should try to give the function a name that describes what it does. E.g., **draw\_rectangle**.

The *parameterList* is a comma-separated list of variable declarations, one declaration for each parameter. These *parameter variables* will be initialized to the corresponding argument values each time the function is called.

The *statements* are simply a list of statements which define the computation that the function performs using only the parameters or other locally declared variables.

For example, the **draw\_rectangle()** function might be:

{% highlight cpp %}
void draw_rectangle(int width, int height)
{
    int j, i;

    for (j = 1; j <= height; j++) {
        /* Draw a line of * characters */

        for (i = 1; i <= width; i++) {
            printf("*");
        }

        printf("\n");
    }
}
{% endhighlight %}

Now we can use our **draw\_rectangle()** function whenever we need to draw a rectangle of any width and height.

[Demo program]

What is happening?

> When a function call is reached:
>
> > The argument values are computed. [What are the arguments for the first call to **draw\_rectangle()**?]
> >
> > The argument values are copied into the corresponding parameter variables of the called function. In the case of **draw\_rectangle()**, the parameters are **width** and **height**. [What values are copied into the parameter variables for the first call to **draw\_rectangle()**?]
> >
> > The statements in the body of the function are executed.
> >
> > If the function is one that returns a value, the last statement to be executed in the function will be a return statement. We will see those next lecture.
>
> Once the last statement of the called function is executed, control returns to the point where the function was called from. [Where does control return after the first call to **draw\_rectangle()** finishes?]

Functions must be defined (or declared) before being called. In order to call a function, the function must have been defined or declared earlier in the program. Otherwise, the compiler will complain that the function is unknown.  One way to do this is through the use of *function prototypes*.

Function Prototypes
===================

A *function prototype* (also called a *function declaration*) looks like a function, except that the body of the function is replaced by a semicolon. E.g.:

{% highlight cpp %}
void draw_rectangle(int width, int height);
{% endhighlight %}

is a function prototype for a function called **draw\_rectangle** that takes two **int** arguments, and does not return a value (is a **void** function). A function prototype is a signal to the compiler that the function described by the prototype exists somewhere else in the program.
