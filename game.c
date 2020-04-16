#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int table[3][3];
    int input[9];
    int inputt;
    int number;
    char player_1[20], player_2[20];
    printf("Welcome to game! \n");
    printf("player one please insert your name:  ");
    scanf("%s", &player_1);
    printf("\nplayer tow please insert your name:  ");
    scanf("%s", &player_2);

    for (int h = 0; h < 9; h++)
        input[h] = 0;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            table[i][j] = i * 3 + j + 3;

    for(int k = 0; k < 9; k++) {
        if (k % 2 == 0) {
            while(input[k] == 0) {
                printf("%s select target number \n", player_1);
                scanf("%d", &inputt);
                if(isTrueChoice(inputt, input) == 1) {
                    input[k] = inputt;
                    table[(input[k] - 1) / 3][(input[k] - 1) % 3] = 1;
                } else {
                    printf("your number is not true! \n");
                }
            }
        } else {
            while(input[k] == 0) {
                printf("%s select target number \n", player_2);
                scanf("%d", &inputt);
                if(isTrueChoice(inputt, input) == 1) {
                    input[k] = inputt;
                    table[(input[k] - 1) / 3][(input[k] - 1) % 3] = 2;
                } else {
                    printf("your number is not true! \n");
                }
            }
        }
        tableMaker(table);
        printf("\n");
        if (gameIsOver(table) == 1) {
            printf("\nthe game is over\n");
            if (k % 2 == 0)
                printf("%s win!!", player_1);
            else
                printf("%s win!!", player_2);
            break;
        }
    }

}

int isTrueChoice(int input, int inputArray[9]) {
    if (input < 1 || input > 9)
        return 0;
    for ( int i = 0; i < 9; i ++) {
        if (inputArray[i] == input)
            return 0;
    }
    return 1;
}

int gameIsOver(int table[3][3]) {
    if (
        table[0][0] == table[0][1] &&
        table[0][0] == table[0][2] ||
        table[1][0] == table[1][1] &&
        table[1][0] == table[1][2] ||
        table[2][0] == table[2][1] &&
        table[2][0] == table[2][2] ||
        table[0][0] == table[1][0] &&
        table[0][0] == table[2][0] ||
        table[0][1] == table[1][1] &&
        table[0][1] == table[2][1] ||
        table[0][2] == table[1][2] &&
        table[0][2] == table[2][2] ||
        table[0][0] == table[1][1] &&
        table[0][0] == table[2][2] ||
        table[0][2] == table[1][1] &&
        table[0][2] == table[2][0]

        ) {
            return 1;
        } else {
            return 0;
        }
}

void tableMaker(int table[3][3]) {
    for(int i = 0; i < 3; i++) {
        printf("-------------");
        printf("\n|");
        for(int j =0; j < 3; j++) {
                if(table[i][j] == 1) {
                    printf(" O ");
                } else if(table[i][j] == 2) {
                    printf(" X ");
                } else {
                    printf("   ");
                }
            printf("|");
        }
        printf("\n");
    }
    printf("-------------");

}
