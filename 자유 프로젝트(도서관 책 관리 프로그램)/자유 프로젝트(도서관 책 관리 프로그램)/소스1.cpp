#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100      // �ִ� ���� ��
#define MAX_MEMBERS 100    // �ִ� ȸ�� ��
#define MAX_TITLE_LEN 100  // ���� ���� �ִ� ����
#define MAX_NAME_LEN 100   // �̸� �ִ� ����
#define FILENAME "library.txt"  // ������ ���� �̸�

// ���� ����ü
typedef struct {
    int id;                      // ���� ID (�ڵ� ����)
    char title[MAX_TITLE_LEN];   // ���� ����
    char author[MAX_NAME_LEN];   // ���� ����
    int available;               // ���� ���� ���� (1: ���� ����, 0: ���� ��)
} Book;

// ȸ�� ����ü
typedef struct {
    int id;                      // ȸ�� ID (�ڵ� ����)
    char name[MAX_NAME_LEN];     // ȸ�� �̸�
    int borrowedBookId;          // ������ ���� ID, �������� ������ -1
} Member;

Book books[MAX_BOOKS];           // ���� �迭
Member members[MAX_MEMBERS];     // ȸ�� �迭
int bookCount = 0;               // ��ϵ� ������ ��
int memberCount = 0;             // ��ϵ� ȸ���� ��

// �Լ� ����
void addBook();
void viewBooks();
void borrowBook();
void returnBook();
void addMember();
void viewMembers();
int findBookById(int id);
int findMemberById(int id);
void loadData();                // ���Ͽ��� ������ �ε�
void saveData();                // ���Ͽ� ������ ����

int main(void) {
    loadData(); // ���α׷� ���� �� ���Ͽ��� ������ �ε�

    int choice;
    while (1) {
        // �޴� ���
        printf("\n���� ���� ���α׷�\n");
        printf("1. ���� ���\n");
        printf("2. ���� ��ȸ\n");
        printf("3. ���� ����\n");
        printf("4. ���� �ݳ�\n");
        printf("5. ȸ�� ���\n");
        printf("6. ȸ�� ��ȸ\n");
        printf("0. ����\n");
        printf("�޴� ����: ");

        // �޴� ���� �Է¹ޱ�
        if (scanf_s("%d", &choice) != 1) {
            while (getchar() != '\n'); // �Է� ���� ����
            printf("�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���.\n");
            continue;
        }

        // �޴� ���ÿ� ���� ����
        switch (choice) {
        case 1: addBook(); break;       // ���� ���
        case 2: viewBooks(); break;     // ���� ��ȸ
        case 3: borrowBook(); break;    // ���� ����
        case 4: returnBook(); break;    // ���� �ݳ�
        case 5: addMember(); break;     // ȸ�� ���
        case 6: viewMembers(); break;   // ȸ�� ��ȸ
        case 0:
            saveData();              // ���α׷� ���� �� ������ ����
            printf("���α׷� ����\n");
            return 0;
        default:
            printf("�߸��� �����Դϴ�.\n");  // �߸��� �޴� ���� ��
        }
    }

    return 0;
}

// ���� ��� �Լ�
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        // ������ �ִ� ���� �������� ���
        printf("������ ���� á���ϴ�.\n");
        return;
        return;
    }

    Book newBook;
    newBook.id = bookCount + 1;  // ���� ID�� ���� ��ϵ� ���� �� + 1 (�ڵ� ����)

    // ���� ���� �Է�
    printf("���� ����: ");
    getchar();  // ���� ���� ����
    fgets(newBook.title, MAX_TITLE_LEN, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;  // �Էµ� ���񿡼� ���� ���� ����

    // ���� ���� �Է�
    printf("����: ");
    fgets(newBook.author, MAX_NAME_LEN, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;  // �Էµ� ���ڿ��� ���� ���� ����

    newBook.available = 1;  // ��ϵ� ������ ���� ���� ���·� ����

    // ���� �迭�� ���ο� ���� �߰�
    books[bookCount++] = newBook;
    printf("������ ��ϵǾ����ϴ�.\n");
}

// ���� ��ȸ �Լ�
void viewBooks() {
    if (bookCount == 0) {
        // ��ϵ� ������ ���� ���
        printf("��ϵ� ������ �����ϴ�.\n");
        return;
    }

    printf("\n���� ���:\n");
    for (int i = 0; i < bookCount; i++) {
        // ���� ���� ���
        printf("ID: %d, ����: %s, ����: %s, ���� ����: %s\n",
            books[i].id, books[i].title, books[i].author,
            books[i].available ? "��" : "�ƴϿ�");
    }
}

// ���� ���� �Լ�
void borrowBook() {
    int memberId, bookId;

    // ȸ�� ID �Է�
    printf("ȸ�� ID: ");
    scanf_s("%d", &memberId);
    int memberIndex = findMemberById(memberId);  // �ش� ȸ���� �ε��� ã��
    if (memberIndex == -1) {
        // ȸ���� �������� ������ ���� ���
        printf("ȸ���� �������� �ʽ��ϴ�.\n");
        return;
    }

    // ���� ID �Է�
    printf("���� ID: ");
    scanf_s("%d", &bookId);
    int bookIndex = findBookById(bookId);  // �ش� ������ �ε��� ã��
    if (bookIndex == -1) {
        // ������ �������� ������ ���� ���
        printf("������ �������� �ʽ��ϴ�.\n");
        return;
    }

    if (books[bookIndex].available == 0) {
        // ������ ���� ���� ���
        printf("������ ���� ���Դϴ�.\n");
        return;
    }

    // ���� ���� ó��
    books[bookIndex].available = 0;  // ���� ������ ���� ����
    members[memberIndex].borrowedBookId = bookId;  // ȸ���� ���� ���� ID ����
    printf("���� ������ �Ϸ�Ǿ����ϴ�.\n");
}

// ���� �ݳ� �Լ�
void returnBook() {
    int memberId;

    // ȸ�� ID �Է�
    printf("ȸ�� ID: ");
    scanf_s("%d", &memberId);
    int memberIndex = findMemberById(memberId);  // �ش� ȸ���� �ε��� ã��
    if (memberIndex == -1) {
        // ȸ���� �������� ������ ���� ���
        printf("ȸ���� �������� �ʽ��ϴ�.\n");
        return;
    }

    if (members[memberIndex].borrowedBookId == -1) {
        // �ش� ȸ���� ������ ������ ������ ���� ���
        printf("���� ���� ������ �����ϴ�.\n");
        return;
    }

    int bookIndex = findBookById(members[memberIndex].borrowedBookId);  // ������ ���� ã��
    books[bookIndex].available = 1;  // ���� ���� ���·� ����
    members[memberIndex].borrowedBookId = -1;  // ���� ��� �ʱ�ȭ
    printf("���� �ݳ��� �Ϸ�Ǿ����ϴ�.\n");
}

// ȸ�� ��� �Լ�
void addMember() {
    if (memberCount >= MAX_MEMBERS) {
        // ȸ���� �ִ� ���� �������� ���
        printf("ȸ���� ���� á���ϴ�.\n");
        return;
    }

    Member newMember;
    newMember.id = memberCount + 1;  // ȸ�� ID�� ���� ��ϵ� ȸ�� �� + 1 (�ڵ� ����)

    // ȸ�� �̸� �Է�
    printf("ȸ�� �̸�: ");
    getchar();  // ���� ���� ����
    fgets(newMember.name, MAX_NAME_LEN, stdin);
    newMember.name[strcspn(newMember.name, "\n")] = 0;  // �Էµ� �̸����� ���� ���� ����

    newMember.borrowedBookId = -1;  // ���ο� ȸ���� ������ ������ ����

    // ȸ�� �迭�� ���ο� ȸ�� �߰�
    members[memberCount++] = newMember;
    printf("ȸ���� ��ϵǾ����ϴ�.\n");
}

// ȸ�� ��ȸ �Լ�
void viewMembers() {
    if (memberCount == 0) {
        // ��ϵ� ȸ���� ���� ���
        printf("��ϵ� ȸ���� �����ϴ�.\n");
        return;
    }

    printf("\nȸ�� ���:\n");
    for (int i = 0; i < memberCount; i++) {
        // ȸ�� ���� ���
        printf("ID: %d, �̸�: %s, ���� ���� ID: %d\n",
            members[i].id, members[i].name,
            members[i].borrowedBookId == -1 ? 0 : members[i].borrowedBookId);
    }
}

// ���� ID�� ���� ã��
int findBookById(int id) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            return i;  // ������ �߰ߵǸ� �ش� �ε��� ��ȯ
        }
    }
    return -1;  // ������ ������ -1 ��ȯ
}

// ȸ�� ID�� ȸ�� ã��
int findMemberById(int id) {
    for (int i = 0; i < memberCount; i++) {
        if (members[i].id == id) {
            return i;  // ȸ���� �߰ߵǸ� �ش� �ε��� ��ȯ
        }
    }
    return -1;  // ȸ���� ������ -1 ��ȯ
}

// ������ ���Ͽ��� �ҷ�����
void loadData() {
    FILE* file;
    fopen_s(&file, FILENAME, "r");
    if (file == NULL) {
        printf("������ ������ �� �� �����ϴ�.\n");
        return;
    }

    char line[256];
    int readingBooks = 0, readingMembers = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "[BOOKS]", 7) == 0) {
            readingBooks = 1;  // ���� ����� �б� ����
            readingMembers = 0;
            continue;
        }
        else if (strncmp(line, "[MEMBERS]", 9) == 0) {
            readingBooks = 0;
            readingMembers = 1;  // ȸ�� ����� �б� ����
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

// ������ ���Ͽ� �����ϱ�
void saveData() {
    FILE* file;
    fopen_s(&file, FILENAME, "w");
    if (file == NULL) {
        printf("������ ������ �� �� �����ϴ�.\n");
        return;
    }

    // ���� ��� ����
    fprintf_s(file, "[BOOKS]\n");
    for (int i = 0; i < bookCount; i++) {
        fprintf_s(file, "%d|%s|%s|%d\n", books[i].id, books[i].title, books[i].author, books[i].available);
    }

    // ȸ�� ��� ����
    fprintf_s(file, "[MEMBERS]\n");
    for (int i = 0; i < memberCount; i++) {
        fprintf_s(file, "%d|%s|%d\n", members[i].id, members[i].name, members[i].borrowedBookId);
    }

    fclose(file);
}
