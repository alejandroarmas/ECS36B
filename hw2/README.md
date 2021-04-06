
## Problem Statement


### Part 1 


The regular maintenance of aircraft engines is critical to ensure the high level of safety of air travel. Maintenance activities are scheduled for each engine of an aircraft after specific periods of use, which depend on the aircraft and engine model. In this assignment, you are asked to write a program that determines the maintenance schedule of aircraft engines. The program must be able to process different types of aircrafts (having different numbers of engines), requiring maintenance at different intervals. In this assignment, we will only consider two types of aircraft: `Airbus A380` (four engines, requiring maintenance every 750 hours) and `Boeing 737` (two engines, requiring maintenance every 600 hours).

The input of the program is read from standard input. Each input line consists of a description of an aircraft, including the model (encoded as one character), the aircraft name (or “tail code”), and the number of hours recorded since the last maintenance check for each of its engines. The number of hours of use may differ among the engines of a given aircraft due to the fact that not all engines are subjected to maintenance at the same time.  


### Part 2 

Welcome to the one-of-a-kind "All-or-Nothing-Restaurant", where if guests are lucky enough to get seated, then they can eat as much as they want. But, there's a catch. The arriving group can only be seated all together at one table. If the current seating arrangement cannot accommodate them, they need to try coming back another night.  Each table in the restaurant can only be used once in the entire evening.Given the restaurant's popularity, there is large queue of groups waiting to be seated everyday. The restaurant however only has 3 types of tables -Large (which can accommodate 10 guests, Medium which can accommodate 7 guests and Small which can accommodate 5 guests). Currently, the restaurant has only 1 Large sized table, 2 Medium sized tables and 3 small sized tables. The owner of the restaurant has hired you to write a program to assign guests to tables.

The input of the program consists of the size of the groups, in the order in which they appear in the queue. The size of the first group to be seated appears first. The table assignment program must first print a list of available tables in the restaurant. It should then read thesizes of each group to be seated and report on attempts to assign the group to a table. Finally, it should print a summary of seat assignments. See the example input and output files for details. If a group size is not valid (i.e. not a positive number) an exception should be thrown and an error message printed before the program proceeds with the next group.