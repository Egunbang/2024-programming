#include <stdio.h>

int main(void) {
    int 투입금액, 물건값, 거스름돈;

    printf("투입한 금액: ");
    scanf_s("%d", &투입금액);
    printf("물건값: ");
    scanf_s("%d", &물건값);

    int res = 투입금액 - 물건값;
    거스름돈 = (res >= 0) * res;

    printf("%s거스름돈: %d원\n", (res < 0) ? "돈이 부족합니다, 돈을 반환합니다.\n" : "", 거스름돈);   
    printf("1000원 지폐: %d개\n", 거스름돈 / 1000);
    거스름돈 %= 1000;
    printf("500원 동전: %d개\n", 거스름돈 / 500);
    거스름돈 %= 500;    
    printf("100원 동전: %d개\n", 거스름돈 / 100);
    return 0;
}
