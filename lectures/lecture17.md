---
layout: default
title: "Lecture 17: Pointers to Structures"
---

Pointers to Structures
======================

Pointers to struct instances work much the same way as pointers to the built-in data types. One of the most important uses of pointers to structures is to allow structure reference parameters.

Structure Reference Parameters
------------------------------

By default, structure parameters are passed by value, which means that if a variable is used as an argument in a call to the function, the function can't modify the contents of the original variable.

As we can with primitive types, we can allow functions to take a struct by reference by making the struct parameter a pointer. C gives us a special operator for accessing fields in a struct instance accessed through a pointer: **-\>**

For example, let's say we have a **Point** struct type that represents a point in the x/y coordinate plane:

{% highlight cpp %}
struct Point {
    double x;
    double y;
};
{% endhighlight %}

We could write a **movePoint** function to add arbitrary **dx** and **dy** offsets to a **Point**'s **x** and **y** fields as follows:

{% highlight cpp %}
// NOTE: does not return a value, but instead modifies
//        the parameter "point", which is a reference parameter
void movePoint(struct Point *point, double dx, double dy)
{
    point->x += dx;
    point->y += dy;
}
{% endhighlight %}

This function could be used as follows:

{% highlight cpp %}
struct Point p = { 3.0, 4.0 };

movePoint(&p, 2.0, -3.0);
printf("p.x = %.1lf\n", p.x);     // prints the value 3.0+2.0=5.0
printf("p.y = %.1lf\n", p.y);     // prints the value 4.0-3.0=1.0
{% endhighlight %}

Such functions are very useful because they perform *operations* on instances of struct types. This style of programming --- defining a struct type and implementing functions that operate on instances of that type --- is called *encapsulation*, and is one of the most important techniques for designing and implementing larger programs.

**Const element type**

Just like with other reference parameters, you can protect yourself against accidentally modifying a structure reference parameter by making the element type **const**.

Example:

{% highlight cpp %}
void drawPoint(const struct Point *p, int ch)
{
    cons_move_cursor(p->y,p->x);
    cons_printw("%c",ch);
}
{% endhighlight %}

You would read the type of the first parameter as

> "const struct Point"

In other words, the element type is **const struct Point**, meaning that assignments to the fields of the struct are illegal.
