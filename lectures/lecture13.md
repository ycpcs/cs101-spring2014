---
layout: default
title: "Lecture 13: Arrays and functions"
---

Arrays may be passed to functions. However, they behave somewhat differently than other kinds of variables we've seen.

Reading Values from Array Parameters
====================================

Let's consider a function to compute the average of the element values in an array of double:

{% highlight cpp %}
double computeAverage(double array[], int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    return sum / size;
}
{% endhighlight %}

Note a peculiarity - the parameter variable called array is declared without a specific number of elements. This is an intentional feature of C - it allows you to write functions that will work with arrays of any possible length. So, we will be able to call the **computeAverage()** function on **double** arrays of any size.

> The price we pay for this freedom is that when an array is passed to a function, there is no way of knowing the size of the array. So, functions that have an array parameter will typically also take an **int** parameter specifying the number of elements in the array.

Let's consider some tests for this function. One thing that we will need to do in testing this function is to define some arrays to use as input to the function. Array variables can be declared with initializers that specify the initial contents of each element of the array.

For example:

{% highlight cpp %}
double testArray1[4] = {1.0, 3.0, 1.0, 3.0};

printf("%lf = %lf\n",2.0,computeAverage(testArray1, 4));
{% endhighlight %}

The initializer is a comma-separated list of values enclosed in curly braces. Array initializers are useful for assigning some initial values to the elements of an array.

Arrays are Passed By Reference
==============================

What happens if a function that takes an array parameter assigns new values to one or more of the elements of the array parameter?

Example:

{% highlight cpp %}
void negateElements(double array[], int size)
{
    for (int i = 0; i < size; i++) {
        array[i] *= -1;
    }
}
{% endhighlight %}

The question is - how is the value of an array variable passed to a function with an array parameter? For the kinds of variables we have seen so far, the value of the variable is copied into the parameter variable in the called function. This is known as *pass-by-value* (i.e. only the *value* is sent to the function) and is the mechanism used for individual variables.

For arrays, no copying is done. Instead, passing an array works like a reference parameter - the array parameter becomes an *alias* for the array used as the argument. This is known as *pass-by-reference* (i.e. the storage location itself is sent to the function). We can see this with a test:

{% highlight cpp %}
double testArray1[3] = {4.5, -3.6, 0.0};

negateElements(testArray1, 3);

printf("%lf = %lf\n",-4.5, testArray1[0]);
printf("%lf = %lf\n", 0.0, testArray1[2]);
{% endhighlight %}

There are several reasons that array parameters work this way:

> -   Because C arrays do not know their own length, it is impossible to know how many elements an arbitrary array has. Therefore, when passing an array to a function, there would be no way to know (in general) how many elements to copy.
>
> -   Arrays can be very large. For example, it would not be at all unusual to have an array with a million elements. Copying this entire array every time it is passed to a function would be time-consuming and require a lot of memory.
>
> -   Since functions can only return a *value*, an array cannot be returned from a function. One way to work around this limitation is to write functions that take an array parameter and assign values to the elements of the array parameter.
>
Therefore you need to be careful about how you write your programs when passing arrays to functions.

Arrays with a const element type
================================

You can protect yourself against accidentally modifying an array parameter by making the element type **const**.

Example:

{% highlight cpp %}
double computeAverage(const double array[], int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}
{% endhighlight %}

You would read the type of the first parameter as

> "array of const double"

In other words, the element type is **const double**, meaning that assignments to the elements of this array are illegal.

It is always allowed to use an array with a non-const element type as an argument to a function expecting an array with a const element type. For example, the **computeAverage()** function can be called using any array whose element type is (non-const) **double** as an argument.

Passing a multidimensional array to a function
==============================================

Multidimensional arrays can be passed to a function. Although the number of elements in the first dimension of the array may be omitted (and thus may vary), the number of elements in the other dimensions of the array must be specified.

Example:

{% highlight cpp %}
#define NUM_COLUMNS 10

double maximumRowSum(double table[][NUM_COLUMNS], int numRows)
{
    int j, i;
    double sum, max;

    for (j = 0; j < numRows; j++) {
        sum = 0.0;
        for (i = 0; i < NUM_COLUMNS; i++) {
            sum += table[j][i];
        }
        if (j == 0 || sum > max) {
            max = sum;
        }
    }

    return max;
}
{% endhighlight %}

As with one-dimensional arrays, multidimensional arrays are *passed by reference*, so assignments to the array's elements made within the function change the elements of the array passed to the function. Note that any parameters with primitive types (**int**, **double**, etc.) are still *passed-by-value*.
