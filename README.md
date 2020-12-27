# Bike Race


<p align="center">
  <img width="460" height="300" src="https://github.com/tknle/Bike-Race/blob/main/bike-race.jpg">
</p>

## Table of Contents

* [About the Mini Project](#about-the-mini-project)
  * [Description](#description)
  * [Menu](#menu)
  * [Display](#display)
  * [Sorting](#sorting)
  * [Display-winners](#display-winners)
* [Getting Started](#getting-started)
  * [Compilation](#compilation)
  * [Author](#author)
  * [Project Link](#project-link)

## About the Mini Project
- The project is written in C language, it reads data from the text file, do some modification, sorting and display to the console the output.

### Description

>You have been tasked with developing a program to read the information about a bike race
from a text file and produce a report on it. The race is a major event and could attract up to
5,000 participants. The potential of having such high volume of data will require you to be
efficient in how the data is read, stored and processed. There are three timestamps recorded
for each rider:
>1. The start time
>2. The time when the rider crested the top of a mountain pass that is on the route
>3. The completion time (or the time at which the rider withdrew)
>In the event that a rider does not complete the course, they are marked as having not
completed and the time at which they withdrew is recorded but not used in any calculations
and riders who do not finish are not eligible for any awards.
>Riders are organized into categories based on age and the race length. Age groupings are
determined by age ranges, where 16-20 are juniors, 21-34 are adults and 35 or older are
seniors. There are three different races lengths, S (short, 50km), M (medium, 75 km), and L
(long, 100 km). The race will have different start times for each category but this has no
impact on the times it will take the riders to complete the course.
>You cannot guarantee that enough riders will enter for each category to win all awards
available and awards that are not awarded will be listed as “Not Awarded”. 

### Menu 
```sh
******************** Seneca Cycling Race Results ********************
What would you like to do?
0 – Exit
1 – Print top 3 riders in a category
2 – Print all riders in a category
3 – Print last 3 riders in a category
4 – Print winners in all categories
:
```

### Display
Enter 2 to display all riders in a catergory (S, M, L)

example:
```sh
What would you like to do?
0 – Exit
1 – Print top 3 riders in a category
2 – Print all riders in a category
3 – Print last 3 riders in a category
4 – Print winners in all categories
: 2
Which category (S, M, L): S
Rider Age Group Time Withdrew
------------------------------------------------
Angus Young Senior 1:50 No
Eddie Van Halen Senior 2:35 No
Billy F. Gibbons Senior 3:08 No
Nikki Sixx Senior 3:38 No
Charlie Watt Senior 4:19 No
Jocelyn Lovell Senior N/A Yes

```

### Sorting 
1. Print top 3 riders by entering number 1

example:
```sh
******************** Seneca Cycling Race Results ********************
What would you like to do?
0 – Exit
1 – Print top 3 riders in a category
2 – Print all riders in a category
3 – Print last 3 riders in a category
4 – Print winners in all categories
: 1
Which category (S, M, L): s
Rider Age Group Time
---------------------------------------
Angus Young Senior 1:50
Eddie Van Halen Senior 2:35
Billy F. Gibbons Senior 3:08

```
2. Print the last 3 riders in the list by entering number 3
example:

```sh
What would you like to do?
0 – Exit
1 – Print top 3 riders in a category
2 – Print all riders in a category
IPC144 | BTP100 Winter 2020: Final Assessment (Part-2) SDDS
P a g e 6 | 8
3 – Print last 3 riders in a category
4 – Print winners in all categories
: 3
Which category (S, M, L): S
Rider Age Group Time
---------------------------------------
Billy F. Gibbons Senior 3:08
Nikki Sixx Senior 3:38
Charlie Watt Senior 4:19 
```

### Display Winners
- Display winner in all categories

```sh
What would you like to do?
0 – Exit
1 – Print top 3 riders in a category
2 – Print all riders in a category
3 – Print last 3 riders in a category
4 – Print winners in all categories
: 4
Rider Age Group Category Time
------------------------------------------------
Angus Young Senior 50 km 1:50
Eddy Mercx Senior 75 km 1:48
Cecilie Ledwig Adult 100 km 1:38

```
## Getting Started

### Compilation

1. [Click here to run on Repl.it](https://repl.it/@tknle/Bike-Race#main.c)

To run this program, press the **'Run'** button in **repl.it**

2. If download or clone the repository, please run the following command.

```sh
 gcc -o file_helper.c main.c data.txt 
```
3. You can also run on Visual Studio by clicking the **finalP2.vcxproj** file

## Author

Mia Le

**To avoid plagiarism please do not copy the code. Or refer to Mia Le any part of the code you copied**

## Project Link: 

[Project Link](https://github.com/tknle/Bike-Race)
