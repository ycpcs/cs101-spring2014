---
layout: default
title: "Lab 20: Boing! with pointers"
---

In this lab, we will implement a version of the bouncing character animation using a **Scene** struct type to represent the position and direction of the character. However, the accessor functions to initialize, render, and update the struct will use pointers to take an instance of **struct Scene**.

Getting Started
===============

As always, you may refer to [Lab 1](lab01.html) if you need a reminder about how to start the **Cygwin Bash Shell** or **Notepad++**.

Begin by downloading [CS101\_Lab20.zip](CS101_Lab20.zip). Save the zip file in the **H:\\CS101** directory.

Start the **Cygwin Bash Shell** and run the following commands:

    cd h:
    cd CS101
    unzip CS101_Lab20.zip
    cd CS101_Lab20

Start the **Notepad++** text editor. Use it to open the files

> **H:\\CS101\\CS101\_Lab20\\Boing3.cpp**

When you are ready to compile the program, in the Cygwin window type the command

    make

To run the program, in the Cygwin window type the command

    ./Boing3.exe

Your Task
=========

The task is similar to [Lab 18](lab18.html) and [Lab 19](lab19.html): implement a bouncing character animation.

The main difference is that the **scene\_init**, **scene\_render**, and **scene\_update** functions will now have the following prototypes:

{% highlight cpp %}
void scene_init(struct Scene *s);
void scene_render(const struct Scene *s);
void scene_update(struct Scene *s);
{% endhighlight %}

As you can see, the functions now take a pointer to the **struct Scene**.

You will need to do three things to complete the program:

-   Add fields to the **struct Scene** data type
-   Modify the **main** function to add calls to these functions, as indicated by the *TODO* comments
-   Implement these functions to match the prototypes

Hints
-----

Since these functions take a pointer to a **struct Scene**, you will need to take the address of the **myScene** variable in **main** in order to pass it to these functions.

Use the arrow (**-\>**) operator to access the fields of the **struct Scene** within the functions.

Submitting
==========

When you are done, run the following command from the Cygwin bash shell:

    make submit

You will be prompted for your Marmoset username and password, which you should have received by email. Note that your password will not appear on the screen.

**Important**:

> You **must** submit your work before leaving class. If you do not submit work, you will not receive any credit for the lab.
