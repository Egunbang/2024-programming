#include <stdio.h>

int main(void) 
{
    double score; //�Ǽ��� ǥ��

    // �Ǽ� �Է¹ޱ�
    printf("������ �Է��Ͻÿ� (0.0 ~ 100.0): ");
    scanf_s("%lf", &score);

    // ������ ������ ��ȯ�Ͽ� ����ġ�� ���
    switch ((int)score / 10) 
    {
     case 10:
     case 9:
        printf("����: A\n"); //90�� �̻��� A����
        break;
    
     case 8:
        printf("����: B\n"); //80�� �̻��� B����
        break;
    
     case 7:
        printf("����: C\n"); //70�� �̻��� C����
        break;
    
     case 6:
        printf("����: D\n"); //60�� �̻��� D����
        break;
    
     default:
        printf("����: F\n");
        break;//60�̸��� F����
    }

    return 0;
}
