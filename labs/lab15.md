---
layout: default
title: "Lab 15: Functions Reading/Modifying Exercise"
---

# Getting started

As always, you may refer to [Lab 1](lab01.html) if you need a reminder about how to start the **Cygwin Terminal** or **Notepad++**.

Begin by downloading [CS101\_Lab15.zip](CS101_Lab15.zip). Save the zip file in the **H:\\CS101** directory.

Start the **Cygwin Terminal** and run the following commands:

    cd h:
    cd CS101
    unzip CS101_Lab15.zip
    cd CS101_Lab15

Start the **Notepad++** text editor. Use it to open the files

> **H:\\CS101\\CS101\_Lab15\\Part1.cpp**

> **H:\\CS101\\CS101\_Lab15\\Part2.cpp**

# Your Task

Your task is broken up into two parts.

Some of the parts ask you to make predictions and write them down.  You should save your predictions in the file **experiment.txt**.  You can use Notepad++ (or any text editor) to open this file.

## Part 1

Consider the program in **Part1.cpp**.  What output will it print when it is executed?  Make a prediction and write it down in **experiment.txt**.

Compile the program by running the command

    make Part1.exe

Then execute the program by running the command

    ./Part1.exe

Did the output match your prediction?  Record your result in **experiment.txt**.  If the output did not match your prediction, explain why.

Finally, modify the program so that the output [looks like this](lab15Part1Output.html) (click link to see).  You should only need to modify the **choose** function.

## Part 2

Consider the program in **Part2.cpp**.  What output will it print when it is executed?  Make a prediction and write it down in **experiment.txt**.

Compile the program (`make Part2.exe`) and execute the program (`./Part2.exe`).

Did the output match your prediction?  Record your result in **experiment.txt**.  If the output did not match your prediction, explain why.

Finally, modify the program so that the output [looks like this](lab15Part2Output.html) (click link to see).  You should **not** need to modify the **choose** function.

# Submitting

When you are done, run the following command from the Cygwin bash shell:

    make submit

You will be prompted for your Marmoset username and password, which you should have received by email. Note that your password will not appear on the screen.

**Important**:

> You **must** submit your work before leaving class. If you do not submit work, you will not receive any credit for the lab.
