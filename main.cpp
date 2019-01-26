#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <iterator>

using namespace std;

class Date {
	public:
	float day;
	float month;
	float year;
	};
	int count_semicolons(string s) {
		int count = 0;
		for (int i = 0; i < s.size(); i++)
			if (s[i] == ';') count++;
		return count;
	}
	int count_colons(string s) {
		int count = 0;
		int start = s.find("(") + 1;
		int end = s.find(")");
		string z = s.substr(start, end-start);
		for (int i = 0; i < z.size(); i++)
			if (z[i] == ',') count++;
		return count;
	}
	class Courses_exams {
	public:
		string course_code;
		string course_name;
		Date exam_date;
		string exam_location;
	};
	class Students_data {
	public:
		int students_id;
		string student_name;
		string course_codes_stud[10];
	};
	int leap_year(int year){
		if (year % 400 == 0) {
			return 1;
		}
		else if (year % 100 == 0) {
			return 0;
		}
		else if (year % 4 == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int days_in_month(int month, int year) {
		int leap = leap_year(year);
		int days[2][13] = { {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
		{ 0,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
		return days[leap][month];
	}





int main() {
	Courses_exams courses_exams [100];
	for (int l = 0; l < 100; l++) {
		courses_exams[l].course_code = "";
		courses_exams[l].course_name = "";
		courses_exams[l].exam_date.day = 0 ;
		courses_exams[l].exam_date.month = 0;
		courses_exams[l].exam_date.year = 0;
		courses_exams[l].exam_location = "";
	}

	Students_data students_data[100];
	for (int p = 0; p < 100;p++) {
		students_data[p].students_id = 0;
		students_data[p].student_name = "";
		for (int h = 0; h < 10; h++) {
			students_data[p].course_codes_stud[h] = "";
		}
	}

	string x, y, exam, student;
	int exam_start, student_start, exam_end, student_end;
	getline(cin, x); // gets the first string from user
	exam_start=x.find("[") + 1; //finds location on first [
	exam_end = x.find("]"); //finds location of first ]
	exam = x.substr(exam_start , exam_end - exam_start); //the data with out between the two [ & ]

	string exam_temp[100],date;
	int n_courses = count_semicolons(exam) + 1; //get number of courses by number of comma
		istringstream ex(exam); //function on reading (usually used to get input from file, bu I use it here to read the string character by character)
		for (int i = 0; i < n_courses; i++) {
				getline(ex, exam_temp[i], ';'); //now it will read the string and won't stop till it finds the specifind symbol then stores everything beffore symbol in designated spot and removes all of that from original string
				istringstream ex1(exam_temp[i]); //I repeat to divide even further by repeating same way but differet symbols
				getline(ex1, courses_exams[i].course_code, ',');
				getline(ex1, courses_exams[i].course_name, ',');
				getline(ex1, date, ',');
				istringstream ex2(date); //this is done since we had a date and I needed the data of day month and year seperated
					string day, month, year;
					getline(ex2, day, '/');
					getline(ex2, month, '/');
					getline(ex2, year, '/');
					courses_exams[i].exam_date.day = atof(day.c_str()); //change all data I need as float from string they were recived in
					courses_exams[i].exam_date.month = atof(month.c_str());
					courses_exams[i].exam_date.year = atof(year.c_str());
				getline(ex1, courses_exams[i].exam_location, ',');
			}

		getline(cin, y); //repeat for second string
		student_start = y.find("[") + 1;
		student_end = y.find("]");
		student = y.substr(student_start, student_end - student_start);
		int n_students = count_semicolons(student) + 1;
			istringstream st(student);
			string stud_temp[100], stud_id;

	for (int j = 0; j < n_students ; j++) {
		getline(st, stud_temp[j], ';');
		istringstream st1(stud_temp[j]);
		getline(st1, stud_id, ',');
		students_data[j].students_id = atoi(stud_id.c_str());
		getline(st1, students_data[j].student_name, ',');
		int n_courses_stud = count_colons(stud_temp[j]) + 1;
		int start = stud_temp[j].find("(") + 1;
		int end = stud_temp[j].find(")");
		string z = stud_temp[j].substr(start, end - start);
		istringstream st2(z);
		for (int k = 0; k < n_courses_stud; k++) {
			getline(st2, students_data[j].course_codes_stud[k], ',');
			}
		}
	int n_halls = 0;
	string halls[100];
	for (int i = 0; i < 100; i++) {
		halls[i] = "";
	}
	for (int i = 0; i < n_courses; i++) {
			string temp = courses_exams[i].exam_location;
			int hall = find(begin(halls), end(halls), temp) != end(halls);
			if (hall == 0) {
				n_halls++;
				halls[n_halls-1] = courses_exams[i].exam_location;
			}
	}


	int min = students_data[0].students_id;
	for (int i = 0; i < n_students; i++) {
		if (students_data[i].students_id < min) {
			min = students_data[i].students_id;
		}
	}

	int max = students_data[0].students_id;
	for (int i = 0; i < n_students; i++) {
		if (students_data[i].students_id > max) {
			max = students_data[i].students_id;
		}
	}



	int first_year = courses_exams[0].exam_date.year, first_month = courses_exams[0].exam_date.month, first_day = courses_exams[0].exam_date.day;
	for (int i = 0; i < n_courses; i++) {
		if (courses_exams[i].exam_date.year == first_year) {
			if ( courses_exams[i].exam_date.month == first_month) {
				if ( courses_exams[i].exam_date.day <= first_day) {
					first_year = courses_exams[i].exam_date.year;
					first_month = courses_exams[i].exam_date.month;
					first_day = courses_exams[i].exam_date.day;
				}
			}
			else if (courses_exams[i].exam_date.month < first_month) {
				first_year = courses_exams[i].exam_date.year;
				first_month = courses_exams[i].exam_date.month;
				first_day = courses_exams[i].exam_date.day;
			}
		}
		else if (courses_exams[i].exam_date.year < first_year) {
			first_year = courses_exams[i].exam_date.year;
			first_month = courses_exams[i].exam_date.month;
			first_day = courses_exams[i].exam_date.day;
		}
	}

	int last_year = courses_exams[0].exam_date.year, last_month = courses_exams[0].exam_date.month, last_day = courses_exams[0].exam_date.day;
	for (int i = 0; i < n_courses; i++) {
		if (courses_exams[i].exam_date.year == last_year) {
			if (courses_exams[i].exam_date.month == last_month) {
				if (courses_exams[i].exam_date.day >= last_day) {
					last_year = courses_exams[i].exam_date.year;
					last_month = courses_exams[i].exam_date.month;
					last_day = courses_exams[i].exam_date.day;
				}
			}
			else if (courses_exams[i].exam_date.month > last_month) {
				last_year = courses_exams[i].exam_date.year;
				last_month = courses_exams[i].exam_date.month;
				last_day = courses_exams[i].exam_date.day;
			}
		}
		else if (courses_exams[i].exam_date.year > last_year) {
			last_year = courses_exams[i].exam_date.year;
			last_month = courses_exams[i].exam_date.month;
			last_day = courses_exams[i].exam_date.day;
		}
	}

	int leap1 = 0, leap2 = 0, total_leap = 0, false_leap = 0,century1=0;
	int total_days = 0;
	if (first_year == last_year) {
		if (first_month == last_month) {
			total_days = last_day - first_day + 1;
		}
		else {
			total_days = days_in_month(first_month, first_year) + 1 - first_day;
			for (int i = first_month + 1; i < last_month; i++) {
				total_days = total_days + days_in_month(i, first_year);
			}
			total_days = total_days + last_day;
		}
	}
	else {
		total_days = days_in_month(first_month, first_year) + 1 - first_day;
		for (int i = first_month + 1; i <= 12; i++) {
			total_days = total_days + days_in_month(i, first_year);
		}
		for (int i = 1; i < last_month; i++) {
			total_days = total_days + days_in_month(i, last_year);
		}
		total_days = total_days + last_day;
		leap1 = first_year / 4;
		leap2 = last_year / 4;
		if ((last_year % 4) == 0) {
			leap2--;
		}
		total_leap = leap2 - leap1;
		century1 = ((first_year / 100) + 1) * 100;
		for (int i = century1; i < last_year; i += 100)
		{
			if ((i % 400) != 0)
				false_leap = false_leap + 1;
		}
		total_days = total_days + ((365 * (last_year - first_year - 1)) + (total_leap - false_leap));
	}

	int count_stud[100];
	for (int i = 0; i < 100; i++) {
		count_stud[i] = 0;
	}
	for (int i = 0; i < n_courses; i++) {
		for (int j = 0; j < n_students; j++) {
			for (int k = 0; k < 10; k++) {
				if (courses_exams[i].course_code == students_data[j].course_codes_stud[k]) {
					count_stud[i]++;
				}
			}
		}
	}

	int count_course[100];
	for (int i = 0; i < 100; i++) {
		count_course[i] = 0;
	}
	for (int i = 0; i < n_students; i++) {
		for (int j = 0; j < 10; j++) {
			if (students_data[i].course_codes_stud[j] != "") {
				count_course[i]++;
			}
		}
	}



		string command = "";

		while (command != "Quit") {
			getline(cin, command);
			if (command == "Number_Students") {
				cout << n_students << endl;
			}
			if (command == "Number_Courses") {
				cout << n_courses << endl;
			}
			if (command == "Number_Halls") {
				cout << n_halls << endl;
			}
			if (command == "Student_ID_Min") {
				cout << min << endl;
			}
			if (command == "Student_ID_Max") {
				cout << max << endl;
			}
			if (command == "Students_Dropped_IDs") {
				//int dropped_ids[1000];
				int id = 0;
				int ids[100];
				int n_drop_id = 0;
				for (int i = 0; i < 100; i++) {
					ids[i] = 0;
					//dropped_ids[i] = 0;
				}
				for (int i = 0; i < n_students; i++) {
					ids[i] = students_data[i].students_id;
				}
				for (int i = 1; id != max; i++) {
					id = min + i;
					int exist = find(begin(ids), end(ids), id) != end(ids);
					if (exist == 0) {
						n_drop_id++;
						//dropped_ids[n_drop_id - 1] = id;
						cout << id << endl;
					}
				}
				if (n_drop_id == 0) {
					cout << "None" << endl;
				}
				/*else {
					for (int i = 0; i < n_drop_id; i++) {
						cout << dropped_ids[i] << endl;
					}
				}*/
			}
			if (command == "Exams_Start_Date") {
				cout << first_day << "/" << first_month << "/" << first_year << endl;
			}
			if (command == "Exams_End_Date") {
				cout << last_day << "/" << last_month << "/" << last_year << endl;
			}
			if (command == "Exams_Period_InDays") {
				cout << total_days << endl;
			}
			if (command.find(" ") != string::npos) {

				if (command.find("Student_Courses") != string::npos) {
					if (command.find("List") == string::npos) {
						int pos = command.find_first_of(" ") + 1;
						string id_com = command.substr(pos);
						int id_stud = atoi(id_com.c_str());
						int id_stud_course = 0;
						for (int i = 0; i < n_students; i++) {
							if (id_stud == students_data[i].students_id) {
								id_stud_course++;
								for (int j = 0; j < 10; j++) {
									if (students_data[i].course_codes_stud[j] != "") {
										cout << students_data[i].course_codes_stud[j] << endl;
									}
								}
							}
						}
						if (id_stud_course == 0) cout << "none" << endl;
					}
				}
				if (command.find("Course_Students") != string::npos) {
					if (command.find("List") == string::npos) {
						int pos = command.find_first_of(" ") + 1;
						string code_course = command.substr(pos);
						int id_stud_course = 0;
						for (int i = 0; i < n_students; i++) {
							for (int j = 0; j < 10; j++) {
								if (code_course == students_data[i].course_codes_stud[j]) {
									id_stud_course++;
									cout << students_data[i].students_id << endl;
								}
							}
						}
						if (id_stud_course == 0) cout << "none" << endl;
					}
				}
				if (command.find("List_Course_Students") != string::npos) {
					int count_courses = 0;
					if (command.find("More") != string::npos) {
						int pos = command.find_last_of(" ") + 1;
						string temp = command.substr(pos);
						int no_stud = atoi(temp.c_str());
						for (int i = 0; i < n_courses; i++) {
							if (count_stud[i] > no_stud) {
								cout << courses_exams[i].course_code << endl;
								count_courses++;
							}
						}
						if (count_courses == 0) { cout << "none" << endl; }
					}
					if (command.find("Less") != string::npos) {
						int pos = command.find_last_of(" ") + 1;
						string temp = command.substr(pos);
						int no_stud = atoi(temp.c_str());
						for (int i = 0; i < n_courses; i++) {
							if (count_stud[i] < no_stud) {
								cout << courses_exams[i].course_code << endl;
								count_courses++;
							}
						}
						if (count_courses == 0) { cout << "none" << endl; }
					}
					if (command.find("Equal") != string::npos) {
						int pos = command.find_last_of(" ") + 1;
						string temp = command.substr(pos);
						int no_stud = atoi(temp.c_str());
						for (int i = 0; i < n_courses; i++) {
							if (count_stud[i] == no_stud) {
								cout << courses_exams[i].course_code << endl;
								count_courses++;
							}
						}
						if (count_courses == 0) { cout << "none" << endl; }
					}

				}
				if (command.find("List_Student_Courses") != string::npos) {
					int count_students = 0;
					if (command.find("More") != string::npos) {
						int pos = command.find_last_of(" ") + 1;
						string temp = command.substr(pos);
						int no_course = atoi(temp.c_str());
						for (int i = 0; i < n_students; i++) {
							if (count_course[i] > no_course) {
								cout << students_data[i].students_id << endl;
								count_students++;
							}
						}
						if (count_students == 0) { cout << "none" << endl; }
					}
					if (command.find("Less") != string::npos) {
						int pos = command.find_last_of(" ") + 1;
						string temp = command.substr(pos);
						int no_course = atoi(temp.c_str());
						for (int i = 0; i < n_students; i++) {
							if (count_course[i] < no_course) {
								cout << students_data[i].students_id << endl;
								count_students++;
							}
						}
						if (count_students == 0) { cout << "none" << endl; }
					}
					if (command.find("Equal") != string::npos) {
						int pos = command.find_last_of(" ") + 1;
						string temp = command.substr(pos);
						int no_course = atoi(temp.c_str());
						for (int i = 0; i < n_students; i++) {
							if (count_course[i] == no_course) {
								cout << students_data[i].students_id << endl;
								count_students++;
							}
						}
						if (count_students == 0) { cout << "none" << endl; }
					}

				}
				if (command.find("List_Hall_Students") != string::npos) {
					if (command.find("_InAnyDay") == string::npos) {
						int pos1 = command.find(" ") + 1;
						int pos2 = command.find(",") + 1;
						string hall = command.substr(pos1, pos2 - pos1 - 1);
						string date2 = command.substr(pos2);
						int hall_students = 0, day2 = 0, month2 = 0, year2 = 0;
						istringstream ex5(date2);
						string day1, month1, year1;
						getline(ex5, day1, '/');
						getline(ex5, month1, '/');
						getline(ex5, year1, '/');
						day2 = atoi(day1.c_str());
						month2 = atoi(month1.c_str());
						year2 = atoi(year1.c_str());
						int hall_student[100];
						for (int i = 0; i < 100; i++) {
							hall_student[i] = 0;
						}
						for (int i = 0; i < n_courses; i++) {
							if (courses_exams[i].exam_location.find(hall) != string::npos) {
								if ((day2 == courses_exams[i].exam_date.day) && (month2 == courses_exams[i].exam_date.month) && (year2 == courses_exams[i].exam_date.year)) {
									for (int j = 0; j < n_students; j++) {
										for (int k = 0; k < 10; k++) {
											if (courses_exams[i].course_code == students_data[j].course_codes_stud[k]) {
												int exist2 = find(begin(hall_student), end(hall_student), students_data[j].students_id) != end(hall_student);
												if (exist2 == 0) {
													hall_students++;
													hall_student[hall_students - 1] = students_data[j].students_id;
												}
											}
										}
									}
								}
							}
						}
						for (int i = 0; i < hall_students; i++) {
							cout << hall_student[i] << endl;
						}
						if (hall_students == 0) {
							cout << "none\n";
						}
					}
					else if(command.find("_InAnyDay") != string::npos) {
						int pos1 = command.find(" ") + 1;
						string hall = command.substr(pos1);
						int hall_students = 0;
						int hall_student[100];
						for (int i = 0; i < 100; i++) {
							hall_student[i] = 0;
						}
						for (int i = 0; i < n_courses; i++) {
							if (courses_exams[i].exam_location.find(hall) != string::npos) {
								for (int j = 0; j < n_students; j++) {
									for (int k = 0; k < 10; k++) {
										if (courses_exams[i].course_code == students_data[j].course_codes_stud[k]) {
											int exist2 = find(begin(hall_student), end(hall_student), students_data[j].students_id) != end(hall_student);
											if (exist2 == 0) {
												hall_students++;
												hall_student[hall_students - 1] = students_data[j].students_id;
											}
										}
									}
								}
							}
						}
						for (int i = 0; i < hall_students; i++) {
							cout << hall_student[i] << endl;
						}
						if (hall_students == 0) {
							cout << "none\n";
						}
					}
				}
				if (command.find("List_Day_Students_InAnyHall") != string::npos) {
					int pos1 = command.find(" ") + 1;
					string date2 = command.substr(pos1);
					int hall_students = 0, day2 = 0, month2 = 0, year2 = 0;
					istringstream ex5(date2);
					string day1, month1, year1;
					getline(ex5, day1, '/');
					getline(ex5, month1, '/');
					getline(ex5, year1, '/');
					day2 = atoi(day1.c_str());
					month2 = atoi(month1.c_str());
					year2 = atoi(year1.c_str());
					int hall_student[100];
					for (int i = 0; i < 100; i++) {
						hall_student[i] = 0;
					}
					for (int i = 0; i < n_courses; i++) {
						if ((day2 == courses_exams[i].exam_date.day) && (month2 == courses_exams[i].exam_date.month) && (year2 == courses_exams[i].exam_date.year)) {
							for (int j = 0; j < n_students; j++) {
								for (int k = 0; k < 10; k++) {
									if (courses_exams[i].course_code == students_data[j].course_codes_stud[k]) {
										int exist2 = find(begin(hall_student), end(hall_student), students_data[j].students_id) != end(hall_student);
										if (exist2 == 0) {
											hall_students++;
											hall_student[hall_students - 1] = students_data[j].students_id;
										}
									}
								}
							}
						}
					}
					for (int i = 0; i < hall_students; i++) {
						cout << hall_student[i] << endl;
					}
					if (hall_students == 0) {
						cout << "none\n";
					}
				}

				if (command.find("List_Exams") != string::npos) {
					int pos1 = command.find(" ") + 1;
					string date2 = command.substr(pos1);
					int exam_dates = 0, day2 = 0, month2 = 0, year2 = 0;
					istringstream ex5(date2);
					string day1, month1, year1;
					getline(ex5, day1, '/');
					getline(ex5, month1, '/');
					getline(ex5, year1, '/');
					day2 = atoi(day1.c_str());
					month2 = atoi(month1.c_str());
					year2 = atoi(year1.c_str());
					string exam_date[100];
					for (int i = 0; i < 100; i++) {
						exam_date[i] = "";
					}
					for (int i = 0; i < n_courses; i++) {
						if ((day2 == courses_exams[i].exam_date.day) && (month2 == courses_exams[i].exam_date.month) && (year2 == courses_exams[i].exam_date.year)) {
											exam_dates++;
											exam_date[exam_dates - 1] = courses_exams[i].course_code;
										}
									}
					for (int i = 0; i < exam_dates; i++) {
						cout << exam_date[i] << endl;
					}
					if (exam_dates == 0) {
						cout << "none\n";
					}
						}
				if (command.find("List_StudyDays") != string::npos) {
					if (command.find("_ForEveryStudent") == string::npos && command.find("_ForEveryCourse") == string::npos) {

					}
				}
}
				}

		cout << "Thanks!";
		return 0;
	}
