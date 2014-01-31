---
layout: default
title: "Lecture 1: printf, scanf, int variables"
---

A First C Program
=================

Here is the traditional first C program:

{% highlight cpp %}
#include <stdio.h>

int main(void)
{
    printf("Hello, world\n");
    return 0;
}
{% endhighlight %}

Once this program has been entered in a *source file* and translated into an *executable file* by the C compiler, we can run it. It will produce the following output, printed to the *console window*:

    Hello, world

Let's briefly examine the parts of this program:

-   **\#include <stdio.h>** is an *include directive* which informs the C compiler that the program will use the built-in functions for input and output.
-   **int main(void)** introduces the *main function*, which is where the execution of the program begins. The curly braces enclose the *statements* which are part of the main function.
-   **printf("Hello, world\\n");** is a statement which prints the text **Hello, world** as output when the program is executed.
-   **return 0;** completes the main function by indicating that the program completed successfully. (Returning 0 traditionally means that the program worked correctly, while a non-zero value indicates that an error occurred.)

Variables and Assignment Statements
===================================

A variable is a small chunk of the computer's memory used to store a value of a particular *data type*.

There are two things you can do with a variable:

1.  Store a new value in the variable
2.  Retrieve the value currently stored in the variable

In a C program, variables are created by using a *variable declaration statement*. A variable declaration has the following general form:

> *type* *identifier* ;

"Type" refers to any C *data type*. A data type is a kind of data that a program can store and manipulate. Today, we will use the **int** data type. The **int** data type is used to represent integer quantities.

"Identifier" refers to the name of the variable. An identifier must follow certain rules:

1.  It must begin with a letter or the underscore ("\_") character
2.  The rest of the identifier must be comprised of letters, digits, or the underscore ("\_") character

For example, here are some examples of variable declarations:

{% highlight cpp %}
int a;
int count;
int product;
{% endhighlight %}

An assignment statement stores a new value in a variable. Assignment statements have the following general form:

> *identifier* = *value* ;

*identifier* is the name of the variable.

*value* is the new value of the variable. There are many ways to specify a value in C. For example, integer literals are values. The value of a variable can be obtained by specifying the name of the variable.

Examples:

{% highlight cpp %}
// store the value 17 in the variable a
a = 17;

// store the value 0 in the variable product
product = 0;

// retrieve the current value of variable a and store it in the variable count
count = a;
{% endhighlight %}

Note that the "//" character sequence starts a *comment*. Comments are ignored by the compiler, but are useful for the programmer reading the program.

Printing Integer Values
=======================

Integer values may be printed to the console window using the **printf** function.

Example:

{% highlight cpp %}
int answer;

answer = 42;

printf("The answer to life, the universe, and everything is %i\n", answer);
{% endhighlight %}

This code fragment prints the following text to the console window:

    The answer to life, the universe, and everything is 42

The special character sequence **%i** means "get an integer value and print its decimal representation". In this case, the value printed is the value stored in the variable answer, which is 42. **%i** is an example of a *conversion specifier*. Conversion specifiers are placeholders for values being printed.

Multiple occurrences of **%i** can be used with multiple values:

{% highlight cpp %}
printf("%i, %i, %i...blast off!\n", 3, 2, 1);
{% endhighlight %}

This prints

    3, 2, 1...blast off!

Reading Integer Values
======================

The built-in **scanf** function reads a value or values from the keyboard. This allows the user of the program to enter information which can be processed by the program.

Here is the syntax of **scanf** in its most basic form:

> scanf(*format-string*, & *identifier*);

The *format-string* is a specification of the kind of data the program wants to read from the keyboard. **scanf** format strings are very similar to the format strings used for **printf**. The main difference is that the conversion specifiers indicate data to be input from the user, rather than output to the console window.

The *identifier* is the name of a variable into which the information typed by the user should be stored.

Example:

{% highlight cpp %}
int age;
scanf("%i", &age);
printf("OK, you are %i years old\n", age);
{% endhighlight %}

In this example, the format string **"%i"** is used, meaning that the program wants an integer value from the keyboard. The value the user types will be stored in the **age** variable.

Here is possible output from the program when this code is executed (user input is in **bold**):

<pre>
How old are you? <b>155</b>
OK, you are 155 years old
</pre>

The output above assumes that the user entered the value **155**.
