---
layout: default
title: "Lecture 7: While loops, Coding style"
---

While loops
===========

Syntax:

<pre>
while ( <i>condition</i> ) {
    statements
}
</pre>

You can think of the whlie loop as being a simplified for loop. The for loop has built-in support for performing initialization and updating the loop variable. In a while loop, these must be done before the loop starts (initialization) and at the end of the loop body (updating the loop variable.)

Examples of for loop and equivalent while loop:

{% highlight cpp %}
// for loop
for (product = 0, count = 0; count < b; count = count + 1) {
    product = product + a;
}

// while loop (note: a for loop is more appropriate in this case)
product = 0;
count = 0;
while (count < b) {
    product = product + a;
    count = count + 1;
}
{% endhighlight %}

While loops are most often used in situations where the number of iterations can't be predicted. For example, you might use a while loop to repeat a computation as long as the user indicates that the loop should continue:

{% highlight cpp %}
int keep_going = 1;

while (keep_going == 1) {
	// computation would go here
	...

	int answer;
	printf("Continue? (1 for yes, 0 for no) ");
	scanf("%i", &answer);
	if (answer == 0) {
		keep_going = 0;
	}
}
{% endhighlight %}

Nesting an if statement in a loop
=================================

Sometimes you may want to write a loop in which particular executions of the loop body are executed in a different way than others. One way to achieve this is to nest an **if**/**else** statement inside the body of the loop.

For example, here is a code fragment that prints a "ruler" of a specified length using text characters, where every 10th character is a vertical bar ("|"), while all of the other characters are hyphens ("-"):

{% highlight cpp %}
int length;
int i;

printf("How long should the ruler be? ");
scanf("%i", &length);
for (i = 1; i <= length; i++) {
    if (i % 10 == 0) {
        printf("|");
    } else {
        printf("-");
    }
}
printf("\n");
{% endhighlight %}

Example run (user input in **bold**):

<pre>
How long should the ruler be? <b>45</b>
---------|---------|---------|---------|-----
</pre>

Coding Style
============

The compiler does not care what your program looks like; it only cares whether or not your progam is syntactically correct.

However, it is important to consider the effect of formatting on the human beings who will read your program. Attention to coding style can make the program much easier to read, and, importantly, can provide clues to the logical structure of the program.

Indentation
-----------

In a C program, space characters (spaces, tabs, newlines, etc.) are not significant. So, inserting spaces, tabs, and newlines does not affect the meaning of the program.

Conventions for indentation:

-   Statements inside the body of a function are indented one level.
-   Statements inside the body of a loop are indented one level.

Example:

{% highlight cpp %}
int main(void)
{
    int n, sum, count;

    printf("Enter an integer: ");
    scanf("%i", &n);

    for (count = 0, sum = 0; count < n; count = count + 1) {
        sum = sum + count;
    }

    printf("sum of 1..%i is %i\n", n, sum);

    return 0;
}
{% endhighlight %}

Note how the statement inside the body of the loop is indented two levels.

Use the tab key to indent.

Opinions vary about how to place the curly braces surrounding the body of a loop. Alternate style:

{% highlight cpp %}
for (count = 0, sum = 0; count < n; count = count + 1)
{
    sum = sum + count;
}
{% endhighlight %}

Either style is fine &mdash; just be consistent.

Identifier naming
-----------------

Identifiers specify the names of variables.

Your goal in choosing an identifier name is to make the name as meaningful as possible.

Good identifiers:

    miles_driven
    product
    high_temp

Bad identifiers:

    md
    p
    ht

Historically, the preferred style for identifiers in C programs is all lower case, using underscore ("\_") characters to separate words. An alternative style which is standard for C++ and Java is "camel case", where each word (except the first) starts with an upper case character.

Examples:

    milesDriven
    product
    highTemp

Again, both styles are fine &mdash; just be consistent.
