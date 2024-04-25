//
// Created by MARWAN on 4/23/2024.
//

#ifndef STUDENT_RECORD_SYSTEM_FILEHANDLING_H
#define STUDENT_RECORD_SYSTEM_FILEHANDLING_H
#include"data.h"
void ReadStudentFile();
void read_student_count();
void write_student_count(int count);
void add_admin_pass(adminpass *ad);
void read_admin_pass(adminpass *ad);
void rm_student(int j);
void edit_user_info(int j);
#endif //STUDENT_RECORD_SYSTEM_FILEHANDLING_H
