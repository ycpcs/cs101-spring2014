---
layout: default
title: "Lecture 19: Arrays of structs (with functions)"
---

The last topic we will investigate with regards to structs is creating arrays of structure elements and passing them to functions.

Arrays of struct elements
=========================

Since a struct type is simply a *user-defined datatype*, they can be used in the declaration of an array. For example, given the following basic structure declaration

{% highlight cpp %}
struct Point {
    double x;
    double y;
};
{% endhighlight %}

We can declare an array of **Point**'s similarly to how we have declared other primitive data type arrays (assuming **NUM\_POINTS** is defined)

{% highlight cpp %}
struct Point pts[NUM_POINTS];
{% endhighlight %}

To access an element of an array of struct elements (which is itself a struct) is again done by simply providing an *index* inside [ ]. For example, we would access the first **Point** from the above array using **pts[0]**. Since this element is a **Point** struct, we then access a field within this struct element using the array subscript (square brackets) and member selection (dot) operators together:

{% highlight cpp %}
pts[i].x = 1.0;
{% endhighlight %}

In general, we access the field of an element of a struct array by

{% highlight cpp %}
array[index].field
{% endhighlight %}

where **array** is the name of the array, **index** is the index of the element we want to access, and **field** is a field of that element.

Example: Prompting the user to enter a series of points and storing them in an array:

{% highlight cpp %}
struct Point points[NUM_POINTS];

for (int i = 0; i < NUM_POINTS; i++) {
    printf("Enter point %i: ", i+1);
    scanf("%lf %lf", &(points[i].x), &(points[i].y));
}
{% endhighlight %}

Note we treat **points[i].x** and **points[i].y** as we would any other variable in the **scanf** statement.

Passing arrays of structs to functions
======================================

Arrays of struct elements are treated the same as other arrays when being passed to functions, i.e. they are *passed-by-reference* (unlike a single struct element from the array which would be *passed-by-value*). For example a function to get points from the user and store them in the array

{% highlight cpp %}
void read_Points(struct Point p[ ], int len)
{
    for (int i = 0; i < len; i++) {
        printf("Enter point %i: ", i+1);
        scanf("%lf %lf", &(p[i].x), &(p[i].y));
    }
}
{% endhighlight %}

where the parameter **p** will modify the original array of struct elements (again we need to pass a parameter indicating the array's length).

This function would have a corresponding function call

{% highlight cpp %}
struct Point points[NUM_POINTS];

read_Points(points, NUM_POINTS);
{% endhighlight %}

If instead we wrote a function to initialize a single **Point** (passed-by-reference) as

{% highlight cpp %}
void init_Point(struct Point *p, double x, double y)
{
    p->x = x;
    p->y = y;
}
{% endhighlight %}

Then we could place the function call inside a loop to initialize all the points in the array separately

{% highlight cpp %}
struct Point points[NUM_POINTS];
double tempx, tempy;
for (int i = 0; i < NUM_POINTS; i++) {
    printf("Enter point %i: ", i+1);
    scanf("%lf %lf", &tempx, &tempy);
    init_Point(&points[i], tempx, tempy);
}
{% endhighlight %}

Arrays of structs in another struct
===================================

Using composition, we can embed an array of struct elements inside another structure. For example, we might define a **Triangle** structure using three **Point**'s stored in an array as

{% highlight cpp %}
struct Triangle {
    struct Point pt[3];
};
{% endhighlight %}

We could then set the **x** field of the first point of a **Triangle** by

{% highlight cpp %}
struct Triangle tri;

tri.pt[0].x = 3.2;
// Set other fields
{% endhighlight %}
