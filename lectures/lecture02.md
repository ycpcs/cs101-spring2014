---
layout: default
title: "Lecture 2: More data types, expressions"
---

More Data Types
===============

We covered the **int** data type in [Lecture 1](lecture01.html).

Two other important numeric data types:

> **float** - real numbers in the range (approximately) +/- 10\^-46 to 10\^38
>
> **double** - real numbers in the range (approximately) +/- 10\^-324 to 10\^308

Unlike the int type, float and double are not limited to integer values, and can represent fractions.

float and double are "floating point" types:

-   They are *approximate*. When a program does a computation involving floating-point values, the result will not necessarily be exact. The result will generally be a value *close to* the actual (mathematical) result.
-   For this reason, you should not use floating point data types to store any quantity that needs to be represented exactly: for example, money.

You can specify literal float and double values in a program by expressing them as decimal values:

    double weight;

    weight = 47.5;

The code above assigns the literal **double** value 47.5 to the variable **weight**.

Output and input using float and double
=======================================

The **printf** and **scanf** functions can be used to output and input **float** and **double** values by using the appropriate conversion specifier:

> <table>
> <col width="20%" />
> <col width="36%" />
> <thead>
> <tr class="header">
> <th align="left">Data type</th>
> <th align="left">Conversion specifier</th>
> </tr>
> </thead>
> <tbody>
> <tr class="odd">
> <td align="left">int</td>
> <td align="left">%i</td>
> </tr>
> <tr class="even">
> <td align="left">float</td>
> <td align="left">%f</td>
> </tr>
> <tr class="odd">
> <td align="left">double</td>
> <td align="left">%lf</td>
> </tr>
> </tbody>
> </table>

Example:

    double weight;

    printf("Enter a weight in pounds: ");
    scanf("%lf", &weight);

    printf("You entered: %lf\n", weight);

Note that, for **printf** only, the **%f** conversion specifier can print both **float** and **double** values. So, we could have written the last line of the code snippet above like this:

    printf("You entered: %f\n", weight);

For **scanf**, you *must* use the **%lf** conversion specifier to read a value into **double** variable.

Output precision
----------------

Normally, when you print a **float** or **double** value using **printf**, there will be six decimal places of output past the decimal point. You can specify a *precision* as part of the conversion specified to change the number of decimal places.

Example:

    printf("You entered: %.3f\n", weight);

The **printf** statement above will print 3 decimal places past the decimal point.

Exponential notation
--------------------

The **%e** and **%le** conversion specifiers allow you to print **float** or **double** values (respectively) using exponential notation. Example:

    double a;
    a = 456;
    printf("%le\n", a);

The code above produces the output

    4.560000e+02

You can read this output as "4.56 x 10\^2".

As with **%f** (and (**%lf**), you can control the number of digits of precision after the decimal point. For example, the code

    double a;
    a = 456;
    printf("%.3le\n", a);

prints the output

    4.560e+02

As with **%f**, for output using **printf**, the **%e** conversion specifier works with both **float** *and* **double** values. For input using **scanf**, you must use **%e** for **float** variables and **%le** for **double** variables.

Expressions
===========

So far, we've seen how to specify literal int values in a program, and also how to read an int value from the user, storing it in a variable.

We have also seen how to print a literal int value, or an int value stored in a variable, using the printf function.

This is all good, but the point of writing a program to have the program *do* something with its data. In other words, we want to be able to perform *computations* on data. *Expressions* are constructs which allow a program to perform computations.

An *expression* is a construct in a program which computes a value. We have seen two kinds of expressions already, literals and variable references.

Literals
--------

A literal computes a fixed value. For example,

    42

is an integer literal that computes the integer value 42.

Variable References
-------------------

A variable reference computes the value stored in a variable. For example:

    int age;
    scanf("%i", &age);
    printf("You are %i years old\n", age);

The use of the **age** variable in the **printf** statement is a variable reference. The variable reference will compute whatever **int** value was stored in the variable by the **scanf** statement.

Expressions using operators
===========================

Literals and variable references are the most basic kinds of expressions.

A much more interesting type of expression is expressions involving *operators*. An operator uses the values of one or more *sub-expressions* to compute a new value.

Here is the general syntax of several kinds of expressions using *binary operators*. A binary operator is one which uses the values of two sub-expressions to compute a new value.

> *expression* + *expression*
>
> *expression* - *expression*
>
> *expression* \* *expression*
>
> *expression* / *expression*
>
> *expression* % *expression*

These operators have the following meanings:

> <table>
> <col width="18%" />
> <col width="29%" />
> <thead>
> <tr class="header">
> <th align="left">Operator</th>
> <th align="left">Meaning</th>
> </tr>
> </thead>
> <tbody>
> <tr class="odd">
> <td align="left">+</td>
> <td align="left">Addition</td>
> </tr>
> <tr class="even">
> <td align="left">-</td>
> <td align="left">Subtraction</td>
> </tr>
> <tr class="odd">
> <td align="left">*</td>
> <td align="left">Multiplication</td>
> </tr>
> <tr class="even">
> <td align="left">/</td>
> <td align="left">Division</td>
> </tr>
> <tr class="odd">
> <td align="left">%</td>
> <td align="left">Modulus (remainder)</td>
> </tr>
> </tbody>
> </table>

Example:

    double weight;
    double unit_price;

    printf("How many pounds of potatoes? ");
    scanf("%lf", &weight);

    printf("What is the cost per pound? ");
    scanf("%lf", &unit_price);

    double total;

    total = weight * unit_price;
    printf("The total cost is $%.2f\n", total);

Here is an example run of this code (user input in **bold**):

<pre>
How many pounds of potatoes? <b>10</b>
What is the cost per pound? <b>.79</b>
The total cost is $7.90
</pre>

Integer Division and Modulus
============================

Question: what output does the following code fragment print?

    int a;
    int b;
    int quotient;

    a = 5;
    b = 2;

    quotient = a / b;

    print("%i / %i = %i\n", a, b, quotient);

Mathematically, 5 / 2 = 2.5. However, the output of the code fragment is "2".

The explanation is that when both operands to a division operator are int values, the resulting quotient is also an int. However, 2.5 is not an integer. So, the fractional part of the result is truncated (discarded), resulting in the value 2.

The integer modulus operator, **%**, computes the remainder of an integer division:

    int a;
    int b;
    int remainder;

    a = 5;
    b = 2;
    remainder = a % b;

    printf("remainder is %i\n", remainder);

The code above prints "1".

Note that truncation is different than rounding:

    int a;
    int b;
    int quotient;

    a = 7;
    b = 4;
    quotient = a / b;

    print("%i / %i = %i\n", a, b, quotient);

Even though mathematically 7 / 4 = 1.75, this code fragment prints "1" because the fractional part, .75, is truncated from the result of the division.

Operator Precedence
===================

As in algebra, operators in C obey precedence rules which determine, for expressions containing multiple operators, the order in which the operators are applied.

For example:

    int a;
    int b;
    int c;

    a = 3;
    b = 4;
    c = 5;

    printf("%i\n", a + b * c);

This code prints the output

    23

because multiplication takes precedence over addition. In general, the multiplication (\*), division (/), and modulus (%) operators take precedence over the addition (+) and subtraction (-) operators.

You can (and should) use parentheses to explicitly force the evaluation order you intend. For example, if the last line of the code snippet above was

    printf("%i\n", (a + b) * c);

then the output would be

    35
