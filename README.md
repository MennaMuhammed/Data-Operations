# Data-Operations
## Project Description 
It is required to develop a program to do operations on courses, exams and
students data. The program use a defined string format to represent
courses exams and students. All courses exams will be in one line input, and
all students will be in one line input. For example:
CoursesExams=[HUM001,Technical Writing, 28/4/2016, HallA ; CSE121,Computer Programming,3/5/2016, HallB]
Students=[12001,Ahmed Hassan, (CSE121,HUM001) ; 12002,Aly Hamed,(CSE121)]
## Courses Exams Data
The CoursesExams line contains a list of courses exams data separated by ‘;’.
Fields of a course exam are:
1. Course Code (like HUM001)
2. Course Name (like Technical Writing)
3. Exam Date (like 28/4/2016)
4. Exam Location (like HallA or like 244 or like CSELab)
Data of the same course exam are separated by comma as shown in the
above example. User can enter data for up to 100 courses exams in one line
separated by ; as shown in the above example.

## Students Data
The Students line contains a list of students data separated by ‘;’. Fields of a
students are:
1. Student ID (like 12001)
2. Student Name(like Ahmed Hassan)
3. Course codes of student attended courses (like (CSE121,HUM001)).
One student can attend up to 10 courses.
Students data of the same student are separated by comma as shown in the
above example. User can enter data for up to 100 students in one line
separated by ; as shown in the above example.

## Operations
When the program start, the user enters one CoursesExams Line and one
Students Line in the defined above format then followed by one or more
operations from the below table (each operation in a line). The program
ends when it reads Quit operation.



|Level| Operation Action| Required from the Program|
|-----|-----------------|--------------------------|
|1  |**Number_Students**  | Print the number of students|
|     |**Number_Courses**    |       Print the number of Courses.|
|      |**Number_Halls**      |       Print the number of Halls|
| 			|**Student_ID_Min**      |      Print the minimum student ID value|
| |**Student_ID_Max**           | Print the maximum student ID value|
| |**Students_Dropped_IDs**     | Print the IDs between minimum and maximum student ID that are not assigned to any student|
| |**Exams_Start_Date**        |  The date of the earliest exam|
| |**Exams_End_Date**         |   The date of the latest exam|
| |**Exams_Period_InDays**    |   The number of days from the start date to the end date. (including the start and end days)|
| |**Quit**                   |   End program|
|2     |**Student_Courses** StudentID |List all course codes of the student having the given StudentID (StudentID will be a valid student ID (every  output course code should be printed in a separate output line)|
||**Course_Students** CourseCode |List all student IDs of the students attending the given CourseCode (CourseCode will be a valid Course Code) (every output student ID should be printed in a separate output line)|
||**List_Course_Students More** n |	List course codes of courses having more than n students (n will be a valid non negative integer) (every output course code should be printed in a separate output line)|
||**List_Course_Students Less** n |	List course codes of courses having less than n students (n will be a valid non negative integer) (every output course code should be printed in a separate output line)|
||**List_Course_Students Equal** n |	List course codes of courses having exactly n students (n will be a valid non negativeinteger) (every output course code should be printed in a separate output line)|
||**List_Student_Courses More** n |List all student IDs of the students attending more than n courses (n will be a valid non negative integer) (every output student ID should be printed in a separate output line)|
||**List_Student_Courses Less** n |List all student IDs of the students attending less than n courses (n will be a valid non negative integer) (every output student ID should be printed in a separate output line)|
||**List_Student_Courses Equal** n| List all student IDs of the students attending exactly n courses (n will be a valid non negative integer) (every output student ID should be printed in a separate output line)|
||**List_Hall_Students** Hallname,Date| List all student IDs of the students attending exam at hallname at examdate (Hallname will be a valid Hall Name, Date will be a valid date)(every output student ID should be printed in a separate output line) Repeated ID should only be printed one time|
||**List_Hall_Students_InAnyday** HallName| List all student IDs of the students attending exam at hallname at any date (Hallname will be a valid Hall Name) (every output student ID should be printed in a separate output line) Repeated ID should only be printed one time|
||**List_Day_Students_InAnyHall** Date| List all student IDs of the students attending exam given examdate (Date will be a valid date) (every output student ID should be printed in a separate output line) Repeated ID should only be printed one time|
|3| **List_Exams** Date| List all course codes of the courses having exam at the given Date (Date will be a valid date) (every output course code should be printed in a separate output line)|
||**List_StudyDays** StudendID,CouseCode |StudyDays of is the number of days a student have between two consecutive exams he/she attend (not including the exam days) in case of first exam the StudyDays should be 7. This command should print the StudyDays of a student before certain CourseCode.|
||**List_StudyDays_ForEveryStudent** CourseCode| This command should print every student ID in a course followed by the StudyDays of that student for the given coursecode|
||**List_StudyDays_ForEveryCourse** StudentID| This command should print every Course Code attended by the given student followed by the StudyDays of that course for the given student|
||**List_Minimum_Student_StudyDays** StudentID| This command should print the minimum StudyDays of all courses of the given student|
||**List_Minimum_Course_StudyDays** CourseCode| This command should print the minimum StudyDays of all students of the given course|
||**List_Minimum_StudyDays**| This command should print the minimum StudyDays of all students of all courses|
||**List_Exam_InSameDay** StudentID| Print all course codes of courses attended by the given student that have exams on the same day (conflict)|
||**List_Exam_InSameDay_ForEveryStudent**| Print all student IDs of all students followed by course codes of courses attended by the student that have exams on the same day (conflict)|
||**List_Exam_InSameHall** Date| Print all course codes of courses have exams on the same hall at the given date (conflict)|
||**List_Exam_InSameHall_Simultaneously_InAnyDay**| Print all dates from the start exam date to the end exam date and each date is followed by course codes of courses have exams on the same hall at that date (conflict)|
|4|**Reschedule_Course_InSameHall_InDifferentDay** Code,StartDate,EndDate|Choose another date for thecourse with Course Code(Code) and keeping the same hall without having a conflict with other exams. The chosen date should be in the given date range|
||**Reschedule_Course_InSameDay_InDifferentHall** Code| Choose another hall for the course with Course Code (Code) and keeping the same date without having a conflict with other exams|
||**Reschedule_Course_InSameHall_To_Reach_Minimum_StudyDays** Code,MinDays,StartDate,EndDate| Choose another date for the course with Course Code (Code) and keeping the same hall without having a conflict with other exams. And such that the StudyDays of all students of that course should be at least (MinDays). The chosen date should be in the given date range|
## General Constraints:
1. User can input up to 100 courses and up to 100 students.
2. Each student can attend up to 10 courses.
3. Graphics library and Time class can not be used in that project.
4. All your code should be in one file.
5. Do not prompt user to enter anything , just read the input directly and print the output of operations directly.
6. At any operation if the output is empty the operation should print “none”
7. Output should not include any extra white spaces or any extra texts more than the results.
