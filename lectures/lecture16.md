---
layout: default
title: "Lecture 16: Using structs with functions"
---

Using Struct Types with Functions
=================================

Struct types are data types (the same way that **int**, **double**, and the other built-in types are data types). They can be used with functions in the same way as the built-in types, both as parameter types (to send information to a function) and as a return type (to return information from a function.)

The following struct type will be used in the examples below:

{% highlight cpp %}
struct Complex {
    double real;
    double imag;
};
{% endhighlight %}

An instance of the **Complex** type represents a complex number. The field **real** represents the magnitude of the real part of the complex number, and the field **imag** represents the magnitude of the imaginary part.

Struct Return Value
===================

A function can return a struct instance. For example, we could create a function to return a **Complex** value with specified real and imaginary field values:

{% highlight cpp %}
struct Complex makeComplex(double realValue, double imagValue) {
    struct Complex result;
    result.real = realValue;
    result.imag = imagValue;
    return result;
}
{% endhighlight %}

We can call this function as follows:

{% highlight cpp %}
struct Complex origin;
origin = makeComplex(0.0, 0.0);
printf("real=%.1lf, imag=%.1lf\n", origin.real, origin.imag);
{% endhighlight %}

The code above would print the following output:

    real=0.0, imag=0.0

Struct Parameters
=================

Structs, by default are *passed-by-value* (similar to **int**, **double**, etc.) which means that when we pass a struct to a function, a *copy* is made of all its fields into the local parameter variable. This mechanism also means that a struct may be returned from a function and assigned to a similar type variable in the calling routine. Thus in this style of programming,

> -   functions which perform operations on struct instances take them as *by-value* parameters
>
> -   functions which need to create or "transform" a struct instance do so by returning a struct instance *by-value*

Because passing and returning struct instances by value involves *copying* the data (including array fields) of each struct instances passed to or returned from each function, this style is most appropriate when the struct types have a small number of fields and do not contain array fields which might contain a large number of values.

**For example**: complex numbers

A complex number has the form

> *a* + *bi*

where *i* is the *imaginary unit*, such that

> *i*<sup>2</sup> = (-*i*)<sup>2</sup> = -1

and *a* and *b* are real numbers which represent the magnitudes of the real and imaginary parts of the complex number, respectively.

Complex numbers are useful in a number of situations. For example, the roots of a quadratic equation may be complex. For example, the equation

> *x*<sup>2</sup> - 10*x* + 34

has the complex roots

> *x* = 5 + 3*i*

and

> *x* = 5 - 3*i*

[Example taken from [regentsprep.org](http://regentsprep.org/Regents/mathb/e/quadcomlesson.htm).]

**Operations**

What will make this a useful data type to use in programs are functions to perform operations on instances of the **Complex** type.

For example,

> -   constructing complex number from real and imaginary magnitudes
>
> -   adding complex numbers
>
> -   subtracting complex numbers
>
> -   multiplying complex numbers
>
> -   dividing complex numbers

We might specify functions to perform these operations as follows:

{% highlight cpp %}
struct Complex makeComplex(double real, double imag);
struct Complex addComplex(struct Complex left, struct Complex right);
struct Complex subtractComplex(struct Complex left, struct Complex right);
struct Complex mulitplyComplex(struct Complex left, struct Complex right);
struct Complex divideComplex(struct Complex left, struct Complex right);
{% endhighlight %}

Note: these are just the prototypes, we would also need to write a definition of each function which performs the appropriate computation.

For example, we might define the **makeComplex** function as follows:

{% highlight cpp %}
struct Complex makeComplex(double real, double imag)
{
    struct Complex result;

    result.real = real;
    result.complex = complex;

    return result;
}
{% endhighlight %}

This function is useful because it allows us to "construct" an instance of **Complex** value from the magnitudes of the real and imaginary components.

*Using the operations*

Given the operations (functions) defined above, the following code would compute the product of the complex numbers

(3 + 4*i*)(-5 + 2*i*)

{% highlight cpp %}
struct Complex first, second;

first = makeComplex(3, 4);
second = makeComplex(-5, 2);

struct Complex product;

product = multiplyComplex(first, second);
{% endhighlight %}
