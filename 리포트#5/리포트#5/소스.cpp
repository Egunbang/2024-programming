#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100  // 최대 학생 수 정의

// 과목 열거형 정의
typedef enum
{
    KOREAN = 0,
    ENGLISH,
    MATH,
    SUBJECT_COUNT  // 과목 수 정의
} Subject;

// 학생 구조체 정의
typedef struct
{
    char name[50];        // 학생 이름
    char student_id[20];  // 학번
    int scores[SUBJECT_COUNT];  // 과목별 점수
    float average;        // 평균 점수
    int class_rank;       // 분반 석차
    int overall_rank;     // 전체 석차
    int class_number;     // 분반
} Student;

// 학생들의 분반 내 석차를 계산하는 함수
void calculate_ranks(Student* students, int student_count) 
{
    for (int i = 0; i < student_count; i++)
    {
        students[i].class_rank = 1;  // 초기 석차를 1로 설정
        for (int j = 0; j < student_count; j++) 
        {
            if (students[j].average > students[i].average)
            {  // 평균 점수가 더 높은 학생이 있으면
                students[i].class_rank++;  // 석차 증가
            }
        }
    }
}

// 결과를 파일로 출력하고 쓰기 모드로 연다
void write_results(const char* filename, Student* students, int student_count)
{
    FILE* file;
    if (fopen_s(&file, filename, "w") != 0)
    {
        printf("Error: Unable to write to file %s\n", filename);
        exit(1);
    }

    // 헤더 작성
    fprintf(file, "학번,  이름 ,  국어,  영어,  수학,  평균,  분반 석차\n");
    for (int i = 0; i < student_count; i++)
    {
        // 학생 정보 출력
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

// 분반 평균을 계산하는 함수
void calculate_class_average(Student* students, int student_count, float* class_average) 
{
    float total = 0;
    for (int i = 0; i < student_count; i++) {
        total += students[i].average;  // 학생들의 평균 점수를 누적
    }
    *class_average = total / student_count;  // 분반 평균 계산
}

// 학생들을 평균 점수에 따라 내림차순으로 정렬하는 함수
int compare_students(const void* a, const void* b)
{
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    if (studentA->average < studentB->average) return 1;  // 평균 점수에 따라 내림차순 정렬
    if (studentA->average > studentB->average) return -1;
    return 0;  // 점수가 같으면 순서 유지
}

int main(void) 
{
    // 분반 1의 학생 정보 초기화
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

    // 분반 2의 학생 정보 초기화
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

    int class1_count = sizeof(students_class1) / sizeof(Student);  // 분반 1 학생 수 계산
    int class2_count = sizeof(students_class2) / sizeof(Student);  // 분반 2 학생 수 계산

    // 분반 1 학생들의 평균 점수 계산
    for (int i = 0; i < class1_count; i++)
    {
        students_class1[i].average = 0;
        for (int j = 0; j < SUBJECT_COUNT; j++)
        {
            students_class1[i].average += students_class1[i].scores[j];
        }
        students_class1[i].average /= SUBJECT_COUNT;
    }

    // 분반 2 학생들의 평균 점수 계산
    for (int i = 0; i < class2_count; i++)
    {
        students_class2[i].average = 0;
        for (int j = 0; j < SUBJECT_COUNT; j++)
        {
            students_class2[i].average += students_class2[i].scores[j];
        }
        students_class2[i].average /= SUBJECT_COUNT;
    }

    // 분반 1과 2의 석차 계산
    calculate_ranks(students_class1, class1_count);
    calculate_ranks(students_class2, class2_count);

    // 분반 1 학생들을 평균 점수에 따라 내림차순으로 정렬
    qsort(students_class1, class1_count, sizeof(Student), compare_students);
    // 정렬 후 분반 석차 업데이트
    for (int i = 0; i < class1_count; i++)
    {
        students_class1[i].class_rank = i + 1;
    }

    // 분반 2 학생들을 평균 점수에 따라 내림차순으로 정렬
    qsort(students_class2, class2_count, sizeof(Student), compare_students);
    // 정렬 후 분반 석차 업데이트
    for (int i = 0; i < class2_count; i++)
    {
        students_class2[i].class_rank = i + 1;
    }

    // 결과를 파일로 저장
    write_results("students_1_results.txt", students_class1, class1_count);
    write_results("students_2_results.txt", students_class2, class2_count);

    // 분반 평균 계산
    float class1_average, class2_average;
    calculate_class_average(students_class1, class1_count, &class1_average);
    calculate_class_average(students_class2, class2_count, &class2_average);

    // 전체 학생 정보를 결합하여 전체 석차 계산
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

    // 전체 학생들을 평균 점수에 따라 내림차순으로 정렬
    qsort(all_students, total_students, sizeof(Student), compare_students);
    for (int i = 0; i < total_students; i++)
    {
        all_students[i].overall_rank = i + 1;
    }

    // 파일을 포인터로 선언하고 파일을 쓰기 모드로 연다
    FILE* summary_file;
    if (fopen_s(&summary_file, "class_results.txt", "w") != 0) 
    {
        printf("Error: Unable to write to file class_results.txt\n");
        exit(1);
    }

    fprintf(summary_file, "분반,  학번,  이름,  국어,  영어,  수학,  과목 평균,  분반 석차,  전체 석차\n");
    for (int i = 0; i < total_students; i++)
    {
        fprintf(summary_file, "%d반,  %s,  %s,  %d점,  %d점,  %d점,  (%.2f),  %d등,  %d등\n",
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

    printf("성공적으로 파일에 입력했다.\n");
    return 0;
}
