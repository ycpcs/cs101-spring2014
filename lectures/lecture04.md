---
layout: default
title: "Lecture 4: Conditions and decisions"
---

Boolean expressions (Conditions)
================================

A boolean expression is an expression whose result is a boolean value: true or false. Boolean expression are often called *conditions*.

Recall that C uses integers to represent boolean values. 0 means false, any non-zero value means true.

Any time a program makes a yes/no (true/false) decision, a boolean expression specifies what decision to make.

The operators we have seen so far perform arithmetic: the operands (subexpressions) are numeric value, and the result of the overall expression is numeric.

Relational operators are operators where the operands are numeric, but the result is boolean.

<table>
<col width="26%" />
<col width="37%" />
<thead>
<tr class="header">
<th align="left"><strong>Operator</strong></th>
<th align="left"><strong>Meaning</strong></th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td align="left">==</td>
<td align="left">equal</td>
</tr>
<tr class="even">
<td align="left">!=</td>
<td align="left">not equal</td>
</tr>
<tr class="odd">
<td align="left">&gt;</td>
<td align="left">greater than</td>
</tr>
<tr class="even">
<td align="left">&lt;</td>
<td align="left">less than</td>
</tr>
<tr class="odd">
<td align="left">&gt;=</td>
<td align="left">greater than or equal to</td>
</tr>
<tr class="even">
<td align="left">&lt;=</td>
<td align="left">less than or equal to</td>
</tr>
</tbody>
</table>

These are all binary operators, meaning that they conform to the syntax

> *expression operator expression*

Note that the operator for equality is "==", rather than "=". A single equals sign always means "assignment", not "equality". Using the assignment operator instead of the equality operator is a frequent source of errors in C programs. So, you must remember the distinction:

> == means "equals"
>
> = means "assignment"

One programmatic trick to avoid this error is to write the logical expressions in the form

> *value* == *expression*

e.g. 5 == **x** since this syntax is invalid for assignment (5 = **x**).

Examples of expressions containing relational operators (note these are *expressions* and not *statements*:

{% highlight cpp %}
a == 1

count <= 100

currentTemp > previousHighTemp

(a * b) > 4500
{% endhighlight %}

Logical operators
=================

The logical operators are

<table>
<col width="23%" />
<col width="23%" />
<thead>
<tr class="header">
<th align="left"><strong>Operator</strong></th>
<th align="left"><strong>Meaning</strong></th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td align="left">&amp;&amp;</td>
<td align="left">logical AND</td>
</tr>
<tr class="even">
<td align="left">||</td>
<td align="left">logical OR</td>
</tr>
<tr class="odd">
<td align="left">!</td>
<td align="left">logical NOT</td>
</tr>
</tbody>
</table>

Often, the logical operators are used to combine expressions involving relational operators.

Examples:

{% highlight cpp %}
(age < 13) || (age > 19)

(age >= 35) && (born_in_usa)
{% endhighlight %}

C doesn't work like English - can't say "if n is equal to 2 or 3" as (**n** == 2 || 3). Instead it must be "if n is equal to 2 OR n is equal to 3" as (**n** == 2 || **n** == 3).

If statements (decisions)
=========================

An **if** statement makes a yes/no (T/F) decision. Depending on the value of a condition (boolean expression), the **if** statement causes the program to branch one way or another in the program's flow chart. **if** statements allow the program to make a *decision* about what to do next.

General syntax:

<pre>
if ( <i>condition</i> ) {
	<i>statements</i>;
}

if ( <i>condition</i> ) {
	<i>true statements</i>;
}
else {
	<i>false statements</i>;
}
</pre>

In the first form, if the condition computes a true (non-zero) result, then the statements inside the body of the **if** statement are executed. Otherwise, if the condition computes a false (zero) value, the statements in the body of the **if** statement are skipped.

In the second form, the condition, depending on whether it computes a true or false value, causes execution to jump to either the first block of statements (true value) or the second block of statements (false value). The first block of statements is the *if clause*, and the second is the *else clause*.

Example:

{% highlight cpp %}
double temp;

printf("What was today's high temperature? ");
scanf("%lf", &temp);

if (temp >= 90.0) {
    printf("That's hot!\n");
}
else {
    printf("Not too hot today\n");
}
{% endhighlight %}
