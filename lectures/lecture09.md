---
layout: default
title: "Lecture 9: Arrays"
---

There are many situations in which we would like to be able to store a sequence of values.

Arrays
======

For example, say we want to figure out our average for some number of quiz grades. If we know how many quiz grades there are, we can just store each grade in a separate variable:

{% highlight cpp %}
double quiz1, quiz2, quiz3;
double avg;

printf("enter 3 quiz grades: ");
scanf("%lf %lf %lf", &quiz1, &quiz2, &quiz3);
avg = (quiz1 + quiz2 + quiz3) / 3;
printf("average is %f\n", avg);
{% endhighlight %}

If we ever need to handle more (or less) than 3 quiz grades, we will have to modify the program.

Notice how the variables storing the quiz grades were defined:

{% highlight cpp %}
double quiz1, quiz2, quiz3;
{% endhighlight %}

These variables differ only in which particular quiz number they represent.

What we really need is a way to represent an arbitrary number of variables. Arrays are a language mechanism for giving a common name to a sequence of variables.

Here is a slightly modified program:

{% highlight cpp %}
double quiz[3];
double avg;

printf("enter 3 quiz grades: ");
scanf("%lf %lf %lf", &quiz[0], &quiz[1], &quiz[2]);
avg = (quiz[0] + quiz[1] + quiz[2]) / 3;
printf("average is %f\n", avg);
{% endhighlight %}

The only difference is that we replaced the three individual variables (*quiz1*, *quiz2*, *quiz3*) with a single array variable called *quiz*.

Consider the first variable declaration:

{% highlight cpp %}
double quiz[3];
{% endhighlight %}

You should read this as

> "quiz is an array of double with 3 elements"

This means that quiz is an array of 3 elements and that the type of each element is a **double**. Each element is a separate variable. So, the array declaration creates three element variables:

> *quiz[0]*
>
> *quiz[1]*
>
> *quiz[2]*

Using the square brackets to refer to an element of an array is known as the *subscript operator*. The value inside the brackets is the *index* of the element you are referring to. The index values for an array start at 0 (the first element of the array) and go to *n*-1 (the last element of the array), where *n* is the number of elements in the array.

Here is an even better program:

{% highlight cpp %}
#define MAX 50

int main(void)
{
    double quiz[MAX];
    double sum;
    int num_quizzes, i;
    printf("How many quizzes? ");
    scanf("%i", &num_quizzes);
    if (num_quizzes > MAX)
    {
        printf("sorry, the maximum number of quiz grades I can handle %i\n",MAX);
        return 1;
    }

    /* Read the quiz grades */
    printf("enter the quiz grades:\n");
    for (i = 0; i < num_quizzes; i++) 
    {
        scanf("%lf", &quiz[i]);
    }

    /* Compute the average */
    sum = 0.0;
    for (i = 0; i < num_quizzes; i++) 
    {
        sum += quiz[i];
    }
    printf("Average is %f\n", (sum / num_quizzes));

    return 0;
}
{% endhighlight %}

Note the declaration of the *symbolic constant* called MAX:

{% highlight cpp %}
#define MAX 50
{% endhighlight %}

Anywhere in the program that **MAX** is used, it will be replaced by 50. Symbolic constants are very useful because they allow you to define limits in the program and refer to those limits by name. In this case, we're making an assumption that we will never need to average more than 50 quiz grades. If this assumption ever needs to change, then we can simply redefine **MAX** to reflect the new value (and recompile the program).

When we declare the array variable called *quiz*, we can define its size (number of elements) using the constant **MAX** rather than hard-coding the value 50. This is important in C, because it is often necessary to refer to the size of an array.

As we can see in the code above, any expression that computes an integer value can be used as an array index in a subscript expression. For example, there are two loops that use an **int** variable *i* as the array index. Because the value of *i* in each loop takes on the values 0, 1, 2, ..., *num*-1, the subscript expression *quiz*[*i*] refers to each element of the array up to *num*-1 in sequence.

Out-Of-Bounds Array Access
--------------------------

What happens if you use a negative array index, or if you use an array index that is equal to or greater than the size of the array?

Any access to an array where the index is not in the range 0..*n*-1, where *n* is the size (number of elements) of the array, is an *out-of-bounds* array access. Using a subscript expression with an out-of-bounds index will result in unpredicable behavior, including mysterious values being computed later in the program or outright crashes (right away, or later).

Problems arising from out-of-bounds array accesses can be extremely difficult to debug. You **MUST** be extremely careful when programming with arrays that the program does not use an index that is out of bounds.

Arrays and Uninitialized Elements
---------------------------------

What is wrong with the following code?

{% highlight cpp %}
double temp[3];
int i;

temp[0] = 48.0;
temp[1] = 52.0;

for (i = 0; i < 3; i++)
{
    printf("%lf\n", temp[i]);
}
{% endhighlight %}

Just like all other kinds of variables, elements of an array are *not* initialized automatically. That means if you try to use the value of an uninitialized array element, the program will get a garbage value, and unpredictable behavior may result.

There is more potential for bugs arising because of uninitialized values with arrays simply because an array can define an arbitrary number of elements. You have to be careful to initialize all array elements whose value may be used by the program (one way to be safe is simply to initialize all the elements using a loop).

Note that it is fine and dandy to write a program that uses only **SOME** of the elements of an array. For example, the example program above that computes the average of a series of grades only used a *prefix* (initial sequence) of the elements of an array. This is a common pattern for programs that create a fixed-size array that is "large enough" for the kinds of problems we want to solve.

Initializing an array
---------------------

An array can be initialized, so that the elements have specified initial values. For example:

{% highlight cpp %}
double temp[3] = { 52.5, 63.2, 53.9 };
{% endhighlight %}

When an initializer is used, any elements of the array not explicitly initialized will be set to zero.
