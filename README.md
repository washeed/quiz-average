# quiz-average
This repository contains a student grade management program implemented in C. The program allows users to insert, delete, display, update, and save student records.
The main functionalities of the program are:

Insert: Users can add student records by entering the student's name and their scores for three quizzes.

Delete: Users can remove a student record by providing the student's name.

Display: The program displays all the student records stored in the system, including the name, quiz scores, average, and remarks (pass or fail).

Update: Users can update the quiz scores of a specific student by providing their name.

Save and Exit: Users can save the student records to a file named "record.dbf" and exit the program.

The program uses an array of structures to store the student records, with each structure containing the student's name and scores for three quizzes. The maximum number of records that can be stored is defined as MAX (set to 100).

The program also includes functions for initializing the list, checking if the list is full or empty, locating a specific record by name, and retrieving the records from a file.

To interact with the program, users are presented with a menu that allows them to choose the desired operation.

Please note that the program uses some header files, including <stdio.h>, <stdlib.h>, <conio.h>, and <string.h>, which are included at the beginning of the code.
