---
layout: default
title: "Lecture 10: Multidimensional Arrays"
---

Multidimensional Arrays
=======================

So far, we have looked at one-dimensional arrays, where each element is accessed using a single integer index. E.g., if quiz is an array of **double** elements with length 3, then there are 3 **double** variables which belong to the array, **quiz[0]**, **quiz[1]**, and **quiz[2]**. We call this kind of array a one-dimensional array.

A multidimensional array is one in which the elements (variables) in the array are accessed using multiple index values. For example, a two-dimensional array has its elements arranged like a grid. For example:

{% highlight cpp %}
#define NUM_STUDENTS 3
#define NUM_QUIZZES 2

...

double quiz[NUM_STUDENTS][NUM_QUIZZES];
{% endhighlight %}

In this example, the array quiz has two dimensions. Because **NUM\_STUDENTS** is 3 and **NUM\_QUIZZES** is 2, the size of the array is 3x2. By convention, we think of the first dimension of a two-dimensional array as representing rows, and the second dimension as representing columns.

Conceptually, the array is arranged like this:

> <table>
> <tr><td>quiz[0][0]</td><td>quiz[0][1]</td>
> <tr><td>quiz[1][0]</td><td>quiz[1][1]</td>
> <tr><td>quiz[2][0]</td><td>quiz[2][1]</td>
> </table>

Because there are 3 rows and 2 columns, the array contains 6 elements.

We could use this array to store multiple quiz grades for multiple students. I.e., if **student** is an integer index value in the range 0..2 representing a particular student, and **quiz\_num** is an integer index value in the range 0..1 representing a particular quiz, then

{% highlight cpp %}
quiz[student][quiz_num]
{% endhighlight %}

is a **double** variable recording a particular quiz score.

Here is what a program to store quiz grades for multiple students, and then compute each student's quiz average, might look like:

{% highlight cpp %}
#include <stdio.h>

#define NUM_STUDENTS 3
#define NUM_QUIZZES 2

int main(void)
{
    double quiz[NUM_STUDENTS][NUM_QUIZZES];

    int j, i;

    // Allow the user to enter the quiz grade data
    for (j = 0; j < NUM_STUDENTS; j++) {
        printf("Enter grades for student %i:\n", j + 1);

        for (i = 0; i < NUM_QUIZZES; i++) {
            printf("Quiz %i grade: ", i + 1);
            scanf("%lf", &quiz[j][i]);
        }
    }

    // Now compute each student's quiz average
    for (j = 0; j < NUM_STUDENTS; j++) {
        double quiz_average;

        // Code to compute the average would go here...

        printf("Student %i's average is %.2lf\n", j + 1, quiz_average);
    }

    return 0;
}
{% endhighlight %}

Example run (user input in **bold**):

<pre>
Enter grades for student 1:
Quiz 1 grade: <b>100</b>
Quiz 2 grade: <b>80</b>
Enter grades for student 2:
Quiz 1 grade: <b>85</b>
Quiz 2 grade: <b>92</b>
Enter grades for student 3:
Quiz 1 grade: <b>74</b>
Quiz 2 grade: <b>89</b>
Student 1's average is 90.00
Student 2's average is 88.50
Student 3's average is 81.50
</pre>

It is possible to have 3, 4, and even higher numbers of dimensions in an array.
