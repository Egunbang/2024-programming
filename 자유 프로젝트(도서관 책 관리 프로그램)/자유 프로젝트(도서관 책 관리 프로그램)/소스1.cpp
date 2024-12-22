#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100      // 최대 도서 수
#define MAX_MEMBERS 100    // 최대 회원 수
#define MAX_TITLE_LEN 100  // 도서 제목 최대 길이
#define MAX_NAME_LEN 100   // 이름 최대 길이
#define FILENAME "library.txt"  // 데이터 파일 이름

// 도서 구조체
typedef struct {
    int id;                      // 도서 ID (자동 증가)
    char title[MAX_TITLE_LEN];   // 도서 제목
    char author[MAX_NAME_LEN];   // 도서 저자
    int available;               // 대출 가능 여부 (1: 대출 가능, 0: 대출 중)
} Book;

// 회원 구조체
typedef struct {
    int id;                      // 회원 ID (자동 증가)
    char name[MAX_NAME_LEN];     // 회원 이름
    int borrowedBookId;          // 대출한 도서 ID, 대출하지 않으면 -1
} Member;

Book books[MAX_BOOKS];           // 도서 배열
Member members[MAX_MEMBERS];     // 회원 배열
int bookCount = 0;               // 등록된 도서의 수
int memberCount = 0;             // 등록된 회원의 수

// 함수 선언
void addBook();
void viewBooks();
void borrowBook();
void returnBook();
void addMember();
void viewMembers();
int findBookById(int id);
int findMemberById(int id);
void loadData();                // 파일에서 데이터 로드
void saveData();                // 파일에 데이터 저장

int main(void) {
    loadData(); // 프로그램 시작 시 파일에서 데이터 로드

    int choice;
    while (1) {
        // 메뉴 출력
        printf("\n도서 관리 프로그램\n");
        printf("1. 도서 등록\n");
        printf("2. 도서 조회\n");
        printf("3. 도서 대출\n");
        printf("4. 도서 반납\n");
        printf("5. 회원 등록\n");
        printf("6. 회원 조회\n");
        printf("0. 종료\n");
        printf("메뉴 선택: ");

        // 메뉴 선택 입력받기
        if (scanf_s("%d", &choice) != 1) {
            while (getchar() != '\n'); // 입력 버퍼 비우기
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
            continue;
        }

        // 메뉴 선택에 따른 동작
        switch (choice) {
        case 1: addBook(); break;       // 도서 등록
        case 2: viewBooks(); break;     // 도서 조회
        case 3: borrowBook(); break;    // 도서 대출
        case 4: returnBook(); break;    // 도서 반납
        case 5: addMember(); break;     // 회원 등록
        case 6: viewMembers(); break;   // 회원 조회
        case 0:
            saveData();              // 프로그램 종료 시 데이터 저장
            printf("프로그램 종료\n");
            return 0;
        default:
            printf("잘못된 선택입니다.\n");  // 잘못된 메뉴 선택 시
        }
    }

    return 0;
}

// 도서 등록 함수
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        // 도서가 최대 수에 도달했을 경우
        printf("도서가 가득 찼습니다.\n");
        return;
        return;
    }

    Book newBook;
    newBook.id = bookCount + 1;  // 도서 ID는 현재 등록된 도서 수 + 1 (자동 증가)

    // 도서 제목 입력
    printf("도서 제목: ");
    getchar();  // 개행 문자 제거
    fgets(newBook.title, MAX_TITLE_LEN, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;  // 입력된 제목에서 개행 문자 제거

    // 도서 저자 입력
    printf("저자: ");
    fgets(newBook.author, MAX_NAME_LEN, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;  // 입력된 저자에서 개행 문자 제거

    newBook.available = 1;  // 등록된 도서는 대출 가능 상태로 설정

    // 도서 배열에 새로운 도서 추가
    books[bookCount++] = newBook;
    printf("도서가 등록되었습니다.\n");
}

// 도서 조회 함수
void viewBooks() {
    if (bookCount == 0) {
        // 등록된 도서가 없을 경우
        printf("등록된 도서가 없습니다.\n");
        return;
    }

    printf("\n도서 목록:\n");
    for (int i = 0; i < bookCount; i++) {
        // 도서 정보 출력
        printf("ID: %d, 제목: %s, 저자: %s, 대출 가능: %s\n",
            books[i].id, books[i].title, books[i].author,
            books[i].available ? "예" : "아니오");
    }
}

// 도서 대출 함수
void borrowBook() {
    int memberId, bookId;

    // 회원 ID 입력
    printf("회원 ID: ");
    scanf_s("%d", &memberId);
    int memberIndex = findMemberById(memberId);  // 해당 회원의 인덱스 찾기
    if (memberIndex == -1) {
        // 회원이 존재하지 않으면 오류 출력
        printf("회원이 존재하지 않습니다.\n");
        return;
    }

    // 도서 ID 입력
    printf("도서 ID: ");
    scanf_s("%d", &bookId);
    int bookIndex = findBookById(bookId);  // 해당 도서의 인덱스 찾기
    if (bookIndex == -1) {
        // 도서가 존재하지 않으면 오류 출력
        printf("도서가 존재하지 않습니다.\n");
        return;
    }

    if (books[bookIndex].available == 0) {
        // 도서가 대출 중일 경우
        printf("도서가 대출 중입니다.\n");
        return;
    }

    // 도서 대출 처리
    books[bookIndex].available = 0;  // 대출 중으로 상태 변경
    members[memberIndex].borrowedBookId = bookId;  // 회원의 대출 도서 ID 저장
    printf("도서 대출이 완료되었습니다.\n");
}

// 도서 반납 함수
void returnBook() {
    int memberId;

    // 회원 ID 입력
    printf("회원 ID: ");
    scanf_s("%d", &memberId);
    int memberIndex = findMemberById(memberId);  // 해당 회원의 인덱스 찾기
    if (memberIndex == -1) {
        // 회원이 존재하지 않으면 오류 출력
        printf("회원이 존재하지 않습니다.\n");
        return;
    }

    if (members[memberIndex].borrowedBookId == -1) {
        // 해당 회원이 대출한 도서가 없으면 오류 출력
        printf("대출 중인 도서가 없습니다.\n");
        return;
    }

    int bookIndex = findBookById(members[memberIndex].borrowedBookId);  // 대출한 도서 찾기
    books[bookIndex].available = 1;  // 대출 가능 상태로 변경
    members[memberIndex].borrowedBookId = -1;  // 대출 기록 초기화
    printf("도서 반납이 완료되었습니다.\n");
}

// 회원 등록 함수
void addMember() {
    if (memberCount >= MAX_MEMBERS) {
        // 회원이 최대 수에 도달했을 경우
        printf("회원이 가득 찼습니다.\n");
        return;
    }

    Member newMember;
    newMember.id = memberCount + 1;  // 회원 ID는 현재 등록된 회원 수 + 1 (자동 증가)

    // 회원 이름 입력
    printf("회원 이름: ");
    getchar();  // 개행 문자 제거
    fgets(newMember.name, MAX_NAME_LEN, stdin);
    newMember.name[strcspn(newMember.name, "\n")] = 0;  // 입력된 이름에서 개행 문자 제거

    newMember.borrowedBookId = -1;  // 새로운 회원은 대출한 도서가 없음

    // 회원 배열에 새로운 회원 추가
    members[memberCount++] = newMember;
    printf("회원이 등록되었습니다.\n");
}

// 회원 조회 함수
void viewMembers() {
    if (memberCount == 0) {
        // 등록된 회원이 없을 경우
        printf("등록된 회원이 없습니다.\n");
        return;
    }

    printf("\n회원 목록:\n");
    for (int i = 0; i < memberCount; i++) {
        // 회원 정보 출력
        printf("ID: %d, 이름: %s, 대출 도서 ID: %d\n",
            members[i].id, members[i].name,
            members[i].borrowedBookId == -1 ? 0 : members[i].borrowedBookId);
    }
}

// 도서 ID로 도서 찾기
int findBookById(int id) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            return i;  // 도서가 발견되면 해당 인덱스 반환
        }
    }
    return -1;  // 도서가 없으면 -1 반환
}

// 회원 ID로 회원 찾기
int findMemberById(int id) {
    for (int i = 0; i < memberCount; i++) {
        if (members[i].id == id) {
            return i;  // 회원이 발견되면 해당 인덱스 반환
        }
    }
    return -1;  // 회원이 없으면 -1 반환
}

// 데이터 파일에서 불러오기
void loadData() {
    FILE* file;
    fopen_s(&file, FILENAME, "r");
    if (file == NULL) {
        printf("데이터 파일을 열 수 없습니다.\n");
        return;
    }

    char line[256];
    int readingBooks = 0, readingMembers = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "[BOOKS]", 7) == 0) {
            readingBooks = 1;  // 도서 목록을 읽기 시작
            readingMembers = 0;
            continue;
        }
        else if (strncmp(line, "[MEMBERS]", 9) == 0) {
            readingBooks = 0;
            readingMembers = 1;  // 회원 목록을 읽기 시작
            continue;
        }

        if (readingBooks) {
            Book newBook;
            sscanf_s(line, "%d|%99[^|]|%99[^|]|%d", &newBook.id, newBook.title, MAX_TITLE_LEN, newBook.author, MAX_NAME_LEN, &newBook.available);
            books[bookCount++] = newBook;
        }
        else if (readingMembers) {
            Member newMember;
            sscanf_s(line, "%d|%99[^|]|%d", &newMember.id, newMember.name, MAX_NAME_LEN, &newMember.borrowedBookId);
            members[memberCount++] = newMember;
        }
    }

    fclose(file);
}

// 데이터 파일에 저장하기
void saveData() {
    FILE* file;
    fopen_s(&file, FILENAME, "w");
    if (file == NULL) {
        printf("데이터 파일을 열 수 없습니다.\n");
        return;
    }

    // 도서 목록 저장
    fprintf_s(file, "[BOOKS]\n");
    for (int i = 0; i < bookCount; i++) {
        fprintf_s(file, "%d|%s|%s|%d\n", books[i].id, books[i].title, books[i].author, books[i].available);
    }

    // 회원 목록 저장
    fprintf_s(file, "[MEMBERS]\n");
    for (int i = 0; i < memberCount; i++) {
        fprintf_s(file, "%d|%s|%d\n", members[i].id, members[i].name, members[i].borrowedBookId);
    }

    fclose(file);
}
