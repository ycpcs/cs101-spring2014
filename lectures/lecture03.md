---
layout: default
title: "Lecture 3: More about variables and expressions"
---

More about variables
====================

Variables are independent:

{% highlight cpp %}
int a;
int b;

a = 121;
b = a;

printf("a = %i, b = %i\n", a, b); /* prints a = 121, b = 121 */

a = 1001;

printf("a = %i, b = %i\n", a, b); /* prints a = 1001, b = 121 */
{% endhighlight %}

Even though the variable **b** initially contains the same value as the variable **a**, it is still a different variable. Variables are *storage locations*. Storing a value in one variable does not change the value of any other variable.

Updating a variable
===================

The value stored in a variable can be updated whenever necessary. For example, adding 1 to a variable and storing the incremented value back into the same variable:

{% highlight cpp %}
int a;

a = 10;

printf("a = %i\n", a);

a = a + 1;

printf("a = %i\n", a);
{% endhighlight %}

Remember, a variable is a storage location for a value. Because a new value can be stored in a variable at any time, overwriting the previous value, the values of variables can change as the program executes.

Increment and Decrement
=======================

Updating a variable to add 1 to or subtract 1 from the value stored in the variable is such a common operation in C that there are special operators, the *increment* and *decrement* operators, to perform these tasks.

Example:

{% highlight cpp %}
int a;
int b;

a = 3;
b = 3;

a++;
b--;

printf("a = %i, b = %i\n", a, b);
{% endhighlight %}

This code produces the output

    a = 4, b = 2

Compound Assignment
===================

Another way to update the value of a variable using one of the *compound assignment* operators.

Example:

{% highlight cpp %}
int a, b, c;

a = 3;
b = 3;
c = 3;

a += 2;
b -= 2;
c *= 2;

printf("a = %i, b = %i, c = %i\n", a, b, c);
{% endhighlight %}

This code produces the output

    a = 5, b = 1, c = 6

A good way to think about how the compound assignment operators work is to consider them as combining the effect of a mathematical operator with an assignment. For example, the code

    a += 2;

is exactly equivalent to the code

    a = a + 2;

In both cases, the sum of **a** and 2 is computed, and then the sum is stored back into **a**, replacing the previous value.

&lt;math.h&gt;
========

So far, the operators we have seen are useful for simple arithmetic. More powerful mathematical functions are available through the inclusion of the **&lt;math.h&gt;** header file. To use these functions, simply add the line

> **\#include &lt;math.h&gt;**

to the top of your program, just below the line

> **\#include &lt;stdio.h&gt;**

Most of the functions in **&lt;math.h&gt;** operate on **double** values. Here are a few of the functions:

> <table>
> <col width="20%" />
> <col width="76%" />
> <thead>
> <tr class="header">
> <th align="left">Function</th>
> <th align="left">Purpose</th>
> </tr>
> </thead>
> <tbody>
> <tr class="odd">
> <td align="left"><strong>sqrt</strong></td>
> <td align="left">Compute a square root.</td>
> </tr>
> <tr class="even">
> <td align="left"><strong>sin</strong></td>
> <td align="left">Compute the sine of an angle (measured in radians.)</td>
> </tr>
> <tr class="odd">
> <td align="left"><strong>cos</strong></td>
> <td align="left">Compute the cosine of an angle (measured in radians.)</td>
> </tr>
> </tbody>
> </table>

A few examples of using functions from **&lt;math.h&gt;**:

{% highlight cpp %}
double x;
double theta;

printf("Enter a number: ");
scanf("%lf", &x);

printf("The square root of %f is %f\n", x, sqrt(x));

printf("Enter an angle in radians: ");
scanf("%lf", &theta);

printf("The sine of %f is %f\n", theta, sin(theta));
printf("The cosine of %f is %f\n", theta, cos(theta));
{% endhighlight %}

In addition to the functions available in **&lt;math.h&gt;**, the special constant value **M\_PI** is available. This constant represents the **double** value closest to the value of π (pi).

Type casts
==========

Sometimes you may want to convert one type of numeric value to another type of numeric value.

For example, you might want to convert **int** values into **double** values---for example, to avoid truncating the result of a division. This can be accomplished with a *type cast*. The general form of a type cast is

> ( *type* ) *expression*

A type cast converts the value computed by an expression to an "equivalent" value belonging to another type. For example, the **int** value 4, when cast to a **double**, is converted to the double value 4.0.

Example: dividing one integer value by another, retaining the fractional part of the answer:

{% highlight cpp %}
int a;
int b;
double quotient;

a = 7;
b = 4;
quotient = (double) a / (double) b;

print("%i / %i = %f\n", a, b, quotient);
{% endhighlight %}

What's going on is that we are casting the **int** variables **a** and **b** to the type **double**, and then using the division operator on the resulting **double** values. This modified code fragment finally produces the output we want, 1.750000.

Mixed-type expressions
======================

Sometimes you will want to perform a computation on two numeric values of different types. An expression that has two operands of different types is called a *mixed-type expression*.

To evaluate any expression with two operands, the operands must have the same type. So, in a mixed-type expression, C will convert one of the operands so that the types match. This is called an *implicit conversion*.

The question, of course, is which operand should be converted. The following general rules apply:

1.  If one operand's type is integer and the other floating-point, the integer value is converted to floating-point
2.  If one operand's type is more precise than the other, the value whose type is less precise is converted to the more precise type

A type is "more precise" than another when it has more bits in its representation. E.g., **double** is a more precise type than **float** because **double** values occupy 64 bits and **float** values occupy 32 bits.

Example:

{% highlight cpp %}
int a;
double b;

scanf("%i", &a);
scanf("%lf", &b);

printf("%f\n", a * b);
{% endhighlight %}

The **int** value a is converted to an equivalent **double** value before the multiplication is performed.

Unary minus
===========

The unary minus operator computes the negation of a numeric value.

Syntax:

> \- *expression*

Examples:

{% highlight cpp %}
int i;
double d;

i = 17;
d = 43.3;

printf("%i\n", -i);
printf("%f\n", -d);
{% endhighlight %}
