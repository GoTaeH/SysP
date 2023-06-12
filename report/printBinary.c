#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printBinary(char hex[]) {
        char binary[17] = "";

        for (int i=0; i<4; i++) {
                char hexDigit = hex[i];
                int dec = 0;

                if(hexDigit >= '0'&&hexDigit <= '9') {
                        dec = hexDigit - '0';
                } else if (hexDigit >= 'A' && hexDigit <= 'F') {
                        dec = hexDigit -'A' + 10;
                } else {
                        return;
                }

                for(int j=3; j>= 0; j--) {
                        binary[i * 4 +j] = (dec % 2) + '0';
                        dec /= 2;
                }
        }
        printf("%.4s : %.3s : %.9s\n", binary, binary+4, binary+7);
}

int main() {
        char hex[5];
        printf("16진수 입력: ");
        scanf("%4s", hex);

        printBinary(hex);

        return 0;
}
// 16비트의 데이터를 2진수로 출력하는 프로그램 (입력: 16진수 / 출력: 4비트 : 3비트 : 9비트)
