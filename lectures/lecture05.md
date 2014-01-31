---
layout: default
title: "Lecture 5: If/Else If/Else Statements, Random Numbers"
---

If/else if statements
=====================

A series of if/else statements can be used to test a series of possibilities.

General syntax:

<pre>
if ( <i>condition1</i> ) {
    <i>cond1 statements</i>;
}
else if ( <i>condition2</i> ) {
    <i>cond2 statements</i>;
}
else if ( <i>condition3</i> ) {
    <i>cond3 statements</i>;
}
...
else {
    <i>false statements</i>;
}
</pre>

Each condition is tested in order. If a condition computes a true value, then its block of statements is executed. Otherwise, the next condition is tried, and so on. If none of the conditions computes a true value, then the block of statements associated with the else block is executed.

Chained if/else if statements are useful when you need to test a series of mutually exclusive possibilities.

Example:

{% highlight cpp %}
int age;

printf("enter your age: ");
scanf("%i", &age);

if (age < 13) {
    printf("pre-teen\n");
} 
else if (age >= 13 && age <= 19) {
    printf("teen\n");
} 
else {
    printf("post-teen\n");
}
{% endhighlight %}

Note that we did not explicitly check the condition (age > 19) before printing "post-teen". That is because this condition is logically implied if the previous conditions (age < 13) and (age >= 13 && age <= 19) are both false.

Random Number Generator
=======================

The function **rand()** generates random integers from 0 to 2,147,483,647.

To use **rand()**, you’ll need **#include <stdlib.h>**.

To get a random number in a range from 0 to 9, use:

{% highlight cpp %}
x = rand() % 10;
{% endhighlight %}

In general, **rand() % n** gives you a random number between 0 and *n* - 1.

One issue is that **rand()** will give the same set of random numbers each time you run it unless you “seed” it differently each time.

To seed the random number generator (only once in the program), use

{% highlight cpp %}
srand(time(0));
{% endhighlight %}

somewhere before the first call to **rand()**, where **time(0)** returns the number of seconds since midnight, January 1st, 1970. Basing the seed on the current time means that **rand()** will (usually) generate different random numbers each time the program is run.

Note: **time(0)** needs **#include <time.h>**.

Example:

{% highlight cpp %}
// this program simulates rolling two dice
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    // Put this at the top of the program
    // Important: only call the srand function once!
    srand(time(0));

    // simulate rolling the first die
    int roll = rand()%6 + 1;
    printf("Roll of the first die = %i\n", roll);

    // second die
    roll = rand()%6 + 1;
    printf("Roll of the second die = %i\n", roll);

    return 0;
}
{% endhighlight %}

Which produces the following sample output (depending on the chosen random numbers) for the program:

    Roll of the first die = 6
    Roll of the second die = 1
