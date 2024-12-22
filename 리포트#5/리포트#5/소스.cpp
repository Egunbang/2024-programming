#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100  // �ִ� �л� �� ����

// ���� ������ ����
typedef enum
{
    KOREAN = 0,
    ENGLISH,
    MATH,
    SUBJECT_COUNT  // ���� �� ����
} Subject;

// �л� ����ü ����
typedef struct
{
    char name[50];        // �л� �̸�
    char student_id[20];  // �й�
    int scores[SUBJECT_COUNT];  // ���� ����
    float average;        // ��� ����
    int class_rank;       // �й� ����
    int overall_rank;     // ��ü ����
    int class_number;     // �й�
} Student;

// �л����� �й� �� ������ ����ϴ� �Լ�
void calculate_ranks(Student* students, int student_count) 
{
    for (int i = 0; i < student_count; i++)
    {
        students[i].class_rank = 1;  // �ʱ� ������ 1�� ����
        for (int j = 0; j < student_count; j++) 
        {
            if (students[j].average > students[i].average)
            {  // ��� ������ �� ���� �л��� ������
                students[i].class_rank++;  // ���� ����
            }
        }
    }
}

// ����� ���Ϸ� ����ϰ� ���� ���� ����
void write_results(const char* filename, Student* students, int student_count)
{
    FILE* file;
    if (fopen_s(&file, filename, "w") != 0)
    {
        printf("Error: Unable to write to file %s\n", filename);
        exit(1);
    }

    // ��� �ۼ�
    fprintf(file, "�й�,  �̸� ,  ����,  ����,  ����,  ���,  �й� ����\n");
    for (int i = 0; i < student_count; i++)
    {
        // �л� ���� ���
        fprintf(file, "%s,%s,%d,%d,%d,%.2f,%d\n",
            students[i].student_id,
            students[i].name,
            students[i].scores[KOREAN],
            students[i].scores[ENGLISH],
            students[i].scores[MATH],
            students[i].average,
            students[i].class_rank);
    }

    fclose(file);
}

// �й� ����� ����ϴ� �Լ�
void calculate_class_average(Student* students, int student_count, float* class_average) 
{
    float total = 0;
    for (int i = 0; i < student_count; i++) {
        total += students[i].average;  // �л����� ��� ������ ����
    }
    *class_average = total / student_count;  // �й� ��� ���
}

// �л����� ��� ������ ���� ������������ �����ϴ� �Լ�
int compare_students(const void* a, const void* b)
{
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    if (studentA->average < studentB->average) return 1;  // ��� ������ ���� �������� ����
    if (studentA->average > studentB->average) return -1;
    return 0;  // ������ ������ ���� ����
}

int main(void) 
{
    // �й� 1�� �л� ���� �ʱ�ȭ
    Student students_class1[] = 
    {
        {"Alice", "1001", {85, 90, 78}, 0, 0, 0, 1},
        {"Bob", "1002", {88, 76, 94}, 0, 0, 0, 1},
        {"Charlie", "1003", {92, 81, 85}, 0, 0, 0, 1},
        {"Diana", "1004", {79, 88, 91}, 0, 0, 0, 1},
        {"Edward", "1005", {83, 87, 80}, 0, 0, 0, 1},
        {"Frank", "1006", {86, 84, 88}, 0, 0, 0, 1},
        {"Grace", "1007", {91, 80, 79}, 0, 0, 0, 1},
        {"Hannah", "1008", {78, 92, 86}, 0, 0, 0, 1},
        {"Irene", "1009", {85, 89, 91}, 0, 0, 0, 1},
        {"Jack", "1010", {90, 88, 84}, 0, 0, 0, 1}
    };

    // �й� 2�� �л� ���� �ʱ�ȭ
    Student students_class2[] = 
    {
        {"Kevin", "2001", {81, 77, 89}, 0, 0, 0, 2},
        {"Laura", "2002", {85, 88, 90}, 0, 0, 0, 2},
        {"Michael", "2003", {92, 80, 85}, 0, 0, 0, 2},
        {"Nancy", "2004", {84, 90, 88}, 0, 0, 0, 2},
        {"Olivia", "2005", {79, 85, 87}, 0, 0, 0, 2},
        {"Paul", "2006", {91, 92, 81}, 0, 0, 0, 2},
        {"Queen", "2007", {86, 83, 88}, 0, 0, 0, 2},
        {"Robert", "2008", {83, 86, 82}, 0, 0, 0, 2},
        {"Sarah", "2009", {88, 89, 91}, 0, 0, 0, 2},
        {"Thomas", "2010", {90, 84, 85}, 0, 0, 0, 2}
    };

    int class1_count = sizeof(students_class1) / sizeof(Student);  // �й� 1 �л� �� ���
    int class2_count = sizeof(students_class2) / sizeof(Student);  // �й� 2 �л� �� ���

    // �й� 1 �л����� ��� ���� ���
    for (int i = 0; i < class1_count; i++)
    {
        students_class1[i].average = 0;
        for (int j = 0; j < SUBJECT_COUNT; j++)
        {
            students_class1[i].average += students_class1[i].scores[j];
        }
        students_class1[i].average /= SUBJECT_COUNT;
    }

    // �й� 2 �л����� ��� ���� ���
    for (int i = 0; i < class2_count; i++)
    {
        students_class2[i].average = 0;
        for (int j = 0; j < SUBJECT_COUNT; j++)
        {
            students_class2[i].average += students_class2[i].scores[j];
        }
        students_class2[i].average /= SUBJECT_COUNT;
    }

    // �й� 1�� 2�� ���� ���
    calculate_ranks(students_class1, class1_count);
    calculate_ranks(students_class2, class2_count);

    // �й� 1 �л����� ��� ������ ���� ������������ ����
    qsort(students_class1, class1_count, sizeof(Student), compare_students);
    // ���� �� �й� ���� ������Ʈ
    for (int i = 0; i < class1_count; i++)
    {
        students_class1[i].class_rank = i + 1;
    }

    // �й� 2 �л����� ��� ������ ���� ������������ ����
    qsort(students_class2, class2_count, sizeof(Student), compare_students);
    // ���� �� �й� ���� ������Ʈ
    for (int i = 0; i < class2_count; i++)
    {
        students_class2[i].class_rank = i + 1;
    }

    // ����� ���Ϸ� ����
    write_results("students_1_results.txt", students_class1, class1_count);
    write_results("students_2_results.txt", students_class2, class2_count);

    // �й� ��� ���
    float class1_average, class2_average;
    calculate_class_average(students_class1, class1_count, &class1_average);
    calculate_class_average(students_class2, class2_count, &class2_average);

    // ��ü �л� ������ �����Ͽ� ��ü ���� ���
    Student all_students[MAX_STUDENTS];
    int total_students = 0;

    for (int i = 0; i < class1_count; i++) 
    {
        all_students[total_students++] = students_class1[i];
    }
    for (int i = 0; i < class2_count; i++)
    {
        all_students[total_students++] = students_class2[i];
    }

    // ��ü �л����� ��� ������ ���� ������������ ����
    qsort(all_students, total_students, sizeof(Student), compare_students);
    for (int i = 0; i < total_students; i++)
    {
        all_students[i].overall_rank = i + 1;
    }

    // ������ �����ͷ� �����ϰ� ������ ���� ���� ����
    FILE* summary_file;
    if (fopen_s(&summary_file, "class_results.txt", "w") != 0) 
    {
        printf("Error: Unable to write to file class_results.txt\n");
        exit(1);
    }

    fprintf(summary_file, "�й�,  �й�,  �̸�,  ����,  ����,  ����,  ���� ���,  �й� ����,  ��ü ����\n");
    for (int i = 0; i < total_students; i++)
    {
        fprintf(summary_file, "%d��,  %s,  %s,  %d��,  %d��,  %d��,  (%.2f),  %d��,  %d��\n",
            all_students[i].class_number,
            all_students[i].student_id,
            all_students[i].name,
            all_students[i].scores[KOREAN],
            all_students[i].scores[ENGLISH],
            all_students[i].scores[MATH],
            all_students[i].average,
            all_students[i].class_rank,
            all_students[i].overall_rank);
    }

    // Write class averages to the summary file
    fprintf(summary_file, "\n1 Class Average : ");
    fprintf(summary_file, "%.2f\n", class1_average);
    fprintf(summary_file, "2 Class,Average : ");
    fprintf(summary_file, "%.2f\n", class2_average);

    fclose(summary_file);

    printf("���������� ���Ͽ� �Է��ߴ�.\n");
    return 0;
}
