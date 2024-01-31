#include <stdio.h>
#include <stdlib.h>  //亂數相關函數
#include <string.h>
#include <time.h>  //時間相關函數
int human_win_line = 0;
int computer_win_line = 0;
int bingo(int size, int line, int (*human)[size], int (*computer)[size]) {
    human_win_line = 0;
    computer_win_line = 0;
    //判斷human是否已經bingo(計算連線數量)
    int bingo_human_table[size + size + 2];
    //初始化為0
    for (int j = 0; j < size + size + 2; j++) {
        bingo_human_table[j] = 0;
    }
    for (int j = 0; j < size + size + 2; j++) {
        int number_check = 0;  //確認一條線中有幾個連線
        if (j < size) {        //直
            for (int k = 0; k < size; k++) {
                if (human[k][j] == 0) {
                    number_check++;
                }
            }
            if (number_check == size) {
                bingo_human_table[j] = 1;
            }
        } else if (j >= size && j < size + size) {  //橫
            for (int k = 0; k < size; k++) {
                if (human[j - size][k] == 0) {
                    number_check++;
                }
            }
            if (number_check == size) {
                bingo_human_table[j] = 1;
            }
        } else if (j == size + size) {
            for (int k = 0; k < size; k++) {
                if (human[k][k] == 0) {
                    number_check++;
                }
            }
            if (number_check == size) {
                bingo_human_table[j] = 1;
            }
        } else {
            for (int k = 0; k < size; k++) {
                if (human[k][size - 1 - k] == 0) {
                    number_check++;
                }
            }
            if (number_check == size) {
                bingo_human_table[j] = 1;
            }
        }
    }
    for (int j = 0; j < size + size + 2; j++) {
        if (bingo_human_table[j] == 1) {
            human_win_line += 1;
        }
    }
    //判斷computer是否已經bingo(計算連線數量)
    int bingo_computer_table[size + size + 2];
    //初始化為0
    for (int j = 0; j < size + size + 2; j++) {
        bingo_computer_table[j] = 0;
    }
    for (int j = 0; j < size + size + 2; j++) {
        int number_check = 0;  //確認一條線中有幾個連線
        if (j < size) {        //直
            for (int k = 0; k < size; k++) {
                if (computer[k][j] == 0) {
                    number_check++;
                }
            }
            if (number_check == size) {
                bingo_computer_table[j] = 1;
            }
        } else if (j >= size && j < size + size) {  //橫
            for (int k = 0; k < size; k++) {
                if (computer[j - size][k] == 0) {
                    number_check++;
                }
            }
            if (number_check == size) {
                bingo_computer_table[j] = 1;
            }
        } else if (j == size + size) {
            for (int k = 0; k < size; k++) {
                if (computer[k][k] == 0) {
                    number_check++;
                }
            }
            if (number_check == size) {
                bingo_computer_table[j] = 1;
            }
        } else {
            for (int k = 0; k < size; k++) {
                if (computer[k][size - 1 - k] == 0) {
                    number_check++;
                }
            }
            if (number_check == size) {
                bingo_computer_table[j] = 1;
            }
        }
    }
    for (int j = 0; j < size + size + 2; j++) {
        if (bingo_computer_table[j] == 1) {
            computer_win_line += 1;
        }
    }
    printf("human_current_line:%d computer_current_line:%d\n", human_win_line, computer_win_line);
    if (human_win_line >= line && computer_win_line >= line) {
        return 1;
    } else if (human_win_line >= line) {
        return 2;
    } else if (computer_win_line >= line) {
        return 3;
    }
    return 0;
}

int bingo_friend(int size, int line, int (*human)[size]) {
    human_win_line = 0;
    //判斷自己是否已經bingo(計算連線數量)
    int bingo_human_table[size + size + 2];
    //初始化為0
    for (int j = 0; j < size + size + 2; j++) {
        bingo_human_table[j] = 0;
    }
    for (int j = 0; j < size + size + 2; j++) {
        int number_check = 0;  //確認一條線中有幾個連線
        if (j < size) {        //直
            for (int k = 0; k < size; k++) {
                if (human[k][j] == 0) {
                    number_check++;
                }
            }
            if (number_check == size) {
                bingo_human_table[j] = 1;
            }
        } else if (j >= size && j < size + size) {  //橫
            for (int k = 0; k < size; k++) {
                if (human[j - size][k] == 0) {
                    number_check++;
                }
            }
            if (number_check == size) {
                bingo_human_table[j] = 1;
            }
        } else if (j == size + size) {
            for (int k = 0; k < size; k++) {
                if (human[k][k] == 0) {
                    number_check++;
                }
            }
            if (number_check == size) {
                bingo_human_table[j] = 1;
            }
        } else {
            for (int k = 0; k < size; k++) {
                if (human[k][size - 1 - k] == 0) {
                    number_check++;
                }
            }
            if (number_check == size) {
                bingo_human_table[j] = 1;
            }
        }
    }
    for (int j = 0; j < size + size + 2; j++) {
        if (bingo_human_table[j] == 1) {
            human_win_line += 1;
        }
    }
    printf("your_current_line:%d\n", human_win_line);
    if (human_win_line >= line) {
        return 1;
    }
    return 0;
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int create_rand_bingo(int size, int (*human)[size]) {
    int human_randbox[size * size];
    for (int i = 0; i < size * size; i++) {
        human_randbox[i] = i + 1;
    }
    for (int i = 0; i < 100; i++) {
        /* 指定亂數範圍 */
        int min = 0;
        int max = size * size - 1;
        int swap_a = rand() % (max - min + 1) + min;
        int swap_b = rand() % (max - min + 1) + min;
        if (swap_a == swap_b) {
            if (swap_a == size * size - 1) {
                swap_b = 0;
            } else {
                swap_b += 1;
            }
        }
        swap(&human_randbox[swap_a], &human_randbox[swap_b]);
    }
    int k = 0;  //用來指放入human array的index
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            human[i][j] = human_randbox[k];
            k++;
        }
    }
    return 0;
}
int print(int size, int (*human)[size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d\t", human[i][j]);
        }
        printf("\n");
    }
    return 0;
}
int change_chosen_number(int size, int number, int (*human)[size]) {
    for (int j = 0; j < size; j++) {
        for (int k = 0; k < size; k++) {
            if (human[j][k] == number) {
                human[j][k] = 0;
            }
        }
    }
    return 0;
}
int computer_chose_number(int size, int (*computer)[size]) {
    int c_number;
    int chosen_number[size][size];
    //初始化被圈起來的數字量
    for (int j = 0; j < size; j++) {
        for (int k = 0; k < size; k++) {
            chosen_number[j][k] = 0;
        }
    }
    //每個還沒被圈起來的數字去檢查
    for (int j = 0; j < size; j++) {
        for (int k = 0; k < size; k++) {
            if (computer[j][k] != 0) {
                if (j == k) {  //在對角線上(左上到右下)
                    for (int h = 0; h < size; h++) {
                        if (computer[j][h] == 0) {
                            chosen_number[j][k] += 1;
                        }
                    }
                    for (int s = 0; s < size; s++) {
                        if (computer[s][k] == 0) {
                            chosen_number[j][k] += 1;
                        }
                    }
                    for (int d = 0; d < size; d++) {
                        if (computer[d][d] == 0) {
                            chosen_number[j][k] += 1;
                        }
                    }
                } else if ((j + k) == (size - 1)) {  //對角線(右上到左下)
                    for (int h = 0; h < size; h++) {
                        if (computer[j][h] == 0) {
                            chosen_number[j][k] += 1;
                        }
                    }
                    for (int s = 0; s < size; s++) {
                        if (computer[s][k] == 0) {
                            chosen_number[j][k] += 1;
                        }
                    }
                    for (int d = 0; d < size; d++) {
                        if (computer[d][size - d - 1] == 0) {
                            chosen_number[j][k] += 1;
                        }
                    }
                } else {  //如果不在對角線上單純只看橫線與直線就好
                    for (int h = 0; h < size; h++) {
                        if (computer[j][h] == 0) {
                            chosen_number[j][k] += 1;
                        }
                    }
                    for (int s = 0; s < size; s++) {
                        if (computer[s][k] == 0) {
                            chosen_number[j][k] += 1;
                        }
                    }
                }
            }
        }
    }
    //找chosen_number陣列中最大值
    int max_row = 0, max_colum = 0, max_number = chosen_number[0][0];
    for (int j = 0; j < size; j++) {
        for (int k = 0; k < size; k++) {
            if (chosen_number[j][k] > max_number) {
                max_number = chosen_number[j][k];
                max_row = j;
                max_colum = k;
            }
        }
    }
    c_number = computer[max_row][max_colum];
    return c_number;
}
int main() {
    srand((unsigned)time(NULL));
    while (1) {
        char yes[2] = "y";
        char no[2] = "n";
        //遊戲模式
        int partner = 0;  // 0就是跟自己玩 1就是跟朋友玩
        while (1) {
            char play_with[8];
            char fri[2] = "f";
            char my[2] = "m";
            printf("Do you play with your friend or play by yourself?[f/m]");
            scanf("%s", play_with);
            if (strcmp(play_with, fri) == 0) {
                partner = 1;
                break;
            } else if (strcmp(play_with, my) == 0) {
                partner = 0;
                break;
            } else {
                printf("Your input is not available\n");
                printf("Please enter again\n");
            }
        }
        if (partner == 0)  //自己玩
        {
            // srand((unsigned)time(NULL));
            //輸入bingo的大小
            int size;
            printf("Please input the bingo's size:");
            scanf("%d", &size);  //
            int human[size][size];
            int computer[size][size];
            //輸入bingo
            while (1) {
                char input_way[10];
                char manual[2] = "m";
                char random[2] = "r";
                printf("Do you want to enter manually or randomly?[m/r]:");
                scanf("%s", input_way);
                if (strcmp(input_way, manual) == 0) {
                    printf("Please input your bingo:\n");
                    for (int i = 0; i < size; i++) {
                        for (int j = 0; j < size; j++) {
                            scanf("%d", &human[i][j]);
                        }
                    }
                    break;
                }
                //電腦幫忙隨機產生
                else if (strcmp(input_way, random) == 0) {
                    create_rand_bingo(size, human);
                    break;
                }
                //輸入錯誤
                else {
                    printf("Your input is not available\n");
                    printf("Please enter again\n");
                }
            }
            //電腦隨機產生自己的bingo
            create_rand_bingo(size, computer);
            //開始遊戲
            printf("start the game!\n");
            printf("This is your original bingo:\n");
            print(size, human);
            int copy_computer[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    copy_computer[i][j] = computer[i][j];
                }
            }
            // printf("This is the computer's original bingo:\n");
            // print(size, computer);
            //輸入需要多少條線才贏
            int line;
            while (1) {
                printf("Please enter how many lines are needed to win:");
                scanf("%d", &line);
                if (line <= size + size + 2) {
                    break;
                } else {
                    printf("Your input is not available\n");
                    printf("Please enter again\n");
                }
            }

            //誰先
            int first = -1;  // 0的話human先 1的話computer先
            while (1) {
                char who_first[2];
                printf("Do you want to be the first?[y/n]:");
                scanf("%s", who_first);
                if (strcmp(who_first, yes) == 0) {  // Human first
                    first = 0;
                    break;
                } else if (strcmp(who_first, no) == 0) {  // computer first
                    first = 1;
                    break;
                }
                //輸入錯誤
                else {
                    printf("Your input is not available\n");
                    printf("Please enter again\n");
                }
            }
            int human_win_line = 0;
            int computer_win_line = 0;
            int who_win = 0;
            for (int i = 0; i <= size * size / 2; i++) {  //最多來回選size*size/2的次數就選完了
                int number;
                if (first == 0) {  // human first

                    // human先選數字
                    printf("Please input which number do you want to choose:");
                    scanf("%d", &number);
                    //把選到的數字改0
                    change_chosen_number(size, number, human);
                    change_chosen_number(size, number, computer);
                    //印出human選完後的bingo
                    printf("Your current bingo:\n");
                    print(size, human);
                    printf("----------------------\n");
                    //選完之後判斷有沒有bingo了
                    who_win = bingo(size, line, human, computer);
                    if (who_win == 1) {  //同時贏
                        human_win_line = line;
                        computer_win_line = line;
                        break;
                    } else if (who_win == 2) {  // human win
                        human_win_line = line;
                        break;
                    } else if (who_win == 3) {  // computer win
                        computer_win_line = line;
                        break;
                    }

                    // computer選數字
                    if (i == 0 && computer[size / 2][size / 2] != 0) {  //第一次，電腦都會自動選中間那格
                        number = computer[size / 2][size / 2];
                        printf("The number chosen by the computer is:%d\n", number);
                    } else {  //不是第一次的話電腦會自動觀察選哪個數字最可以連線
                        number = computer_chose_number(size, computer);
                        printf("The number chosen by the computer is:%d\n", number);
                    }
                    //把選到的數字改0
                    change_chosen_number(size, number, human);
                    change_chosen_number(size, number, computer);
                    //印出computer選完後，human的bingo
                    printf("Your current bingo:\n");
                    print(size, human);
                    printf("----------------------\n");
                    //選完之後判斷有沒有bingo了
                    who_win = bingo(size, line, human, computer);
                    if (who_win == 1) {  //同時贏
                        human_win_line = line;
                        computer_win_line = line;
                        break;
                    } else if (who_win == 2) {  // human win
                        human_win_line = line;
                        break;
                    } else if (who_win == 3) {  // computer win
                        computer_win_line = line;
                        break;
                    }
                } else {  // computer first

                    // computer先選數字
                    if (i == 0 && computer[size / 2][size / 2] != 0) {  //第一次，電腦都會自動選中間那格
                        number = computer[size / 2][size / 2];
                        printf("The number chosen by the computer is:%d\n", number);
                    } else {  //不是第一次的話電腦會自動觀察選哪個數字最可以連線

                        number = computer_chose_number(size, computer);
                        printf("The number chosen by the computer is:%d\n", number);
                    }
                    //把選到的數字改0
                    change_chosen_number(size, number, human);
                    change_chosen_number(size, number, computer);
                    //
                    printf("Your current bingo:\n");
                    print(size, human);
                    printf("----------------------\n");
                    //選完之後判斷有沒有bingo了
                    who_win = bingo(size, line, human, computer);
                    if (who_win == 1) {  //同時贏
                        human_win_line = line;
                        computer_win_line = line;
                        break;
                    } else if (who_win == 2) {  // human win
                        human_win_line = line;
                        break;
                    } else if (who_win == 3) {  // computer win
                        computer_win_line = line;
                        break;
                    }

                    // human先選數字
                    printf("Please input whitch number do you want to choose:");
                    scanf("%d", &number);
                    //把選到的數字改0
                    change_chosen_number(size, number, human);
                    change_chosen_number(size, number, computer);
                    //
                    printf("Your current bingo:\n");
                    print(size, human);
                    printf("----------------------\n");
                    //選完之後判斷有沒有bingo了
                    who_win = bingo(size, line, human, computer);
                    if (who_win == 1) {  //同時贏
                        human_win_line = line;
                        computer_win_line = line;
                        break;
                    } else if (who_win == 2) {  // human win
                        human_win_line = line;
                        break;
                    } else if (who_win == 3) {  // computer win
                        computer_win_line = line;
                        break;
                    }
                }
            }
            //最後印出結果
            if (human_win_line >= line && computer_win_line >= line) {
                printf("You and Computer are winners!\n");
            } else if (human_win_line >= line) {
                printf("Your are the winner!\n");
            } else {
                printf("Computer is the winner!\n");
            }
            //最後印出電腦一開始隨機產生的結果
            printf("This is the computer's original bingo:\n");
            print(size, copy_computer);
            printf("This is the computer's last bindo:\n");
            print(size, computer);
        }

        else {  //跟朋友玩
            // srand((unsigned)time(NULL));
            //輸入bingo的大小
            int size;
            printf("Please input the bingo's size:");
            scanf("%d", &size);  //
            int human[size][size];
            int computer[size][size];
            //輸入bingo
            while (1) {
                char input_way[10];
                char manual[2] = "m";
                char random[2] = "r";
                printf("Do you want to enter manually or randomly?[m/r]:");
                scanf("%s", input_way);
                if (strcmp(input_way, manual) == 0) {
                    printf("Please input your bingo:\n");
                    for (int i = 0; i < size; i++) {
                        for (int j = 0; j < size; j++) {
                            scanf("%d", &human[i][j]);
                        }
                    }
                    break;
                }
                //電腦幫忙隨機產生
                else if (strcmp(input_way, random) == 0) {
                    create_rand_bingo(size, human);
                    break;
                }
                //輸入錯誤
                else {
                    printf("Your input is not available\n");
                    printf("Please enter again\n");
                }
            }
            //開始遊戲
            printf("start the game!\n");
            printf("This is your original bingo:\n");
            print(size, human);
            //輸入需要多少條線才贏
            int line;
            while (1) {
                printf("Please enter how many lines are needed to win:");
                scanf("%d", &line);
                if (line <= size + size + 2) {
                    break;
                } else {
                    printf("Your input is not available\n");
                    printf("Please enter again\n");
                }
            }
            //輸入誰先
            int first = 0;
            while (1) {
                char who_first[8];
                char fri[2] = "f";
                char I[2] = "I";
                printf("You first or your friend first?[I/f]");
                scanf("%s", who_first);
                if (strcmp(who_first, fri) == 0) {  //朋友先
                    first = 0;
                    break;
                } else if (strcmp(who_first, I) == 0) {  //我先
                    first = 1;
                    break;
                } else {
                    printf("Your input is not available\n");
                    printf("Please enter again\n");
                }
            }
            for (int i = 0; i <= size * size / 2; i++) {
                int number;
                int is_win;
                //朋友先
                if (first == 0) {
                    printf("Please enter the number chosen by your friend:");
                    scanf("%d", &number);
                    //把選到的數字改0
                    change_chosen_number(size, number, human);
                    //印出human選完後的bingo
                    printf("Your current bingo:\n");
                    print(size, human);
                    printf("----------------------\n");
                    //選完之後判斷有沒有bingo了
                    is_win = bingo_friend(size, line, human);
                    if (is_win == 1) {  //你贏了
                        printf("Your are winner!\n");
                        break;
                    }
                    while (1) {
                        char is_friend_win[2];
                        printf("Do your friend is bingo?[y/n]:");
                        scanf("%s", is_friend_win);
                        if (strcmp(is_friend_win, yes) == 0) {
                            is_win = 2;
                            break;
                        } else if (strcmp(is_friend_win, no) == 0) {
                            printf("Please continue the game\n");
                            break;
                        } else {
                            printf("Your input is not available\n");
                            printf("Please enter again\n");
                        }
                    }
                    if (is_win == 2) {
                        printf("Your firend is the winner!\n");
                        break;
                    }
                    printf("Please enter the number chosen by yourself:");
                    scanf("%d", &number);
                    //把選到的數字改0
                    change_chosen_number(size, number, human);
                    //印出human選完後的bingo
                    printf("Your current bingo:\n");
                    print(size, human);
                    printf("----------------------\n");
                    //選完之後判斷有沒有bingo了
                    is_win = bingo_friend(size, line, human);
                    if (is_win == 1) {  //你贏了
                        printf("Your are the winner!\n");
                        break;
                    }
                    while (1) {
                        char is_friend_win[2];
                        printf("Do your friend is bingo?[y/n]:");
                        scanf("%s", is_friend_win);
                        if (strcmp(is_friend_win, yes) == 0) {
                            is_win = 2;
                            break;
                        } else if (strcmp(is_friend_win, no) == 0) {
                            printf("Please continue the game\n");
                            break;
                        } else {
                            printf("Your input is not available\n");
                            printf("Please enter again\n");
                        }
                    }
                    if (is_win == 2) {
                        printf("Your firend is the winner!\n");
                        break;
                    }
                }
                //我先
                else {
                    printf("Please enter the number chosen by yourself:");
                    scanf("%d", &number);
                    //把選到的數字改0
                    change_chosen_number(size, number, human);
                    //印出human選完後的bingo
                    printf("Your current bingo:\n");
                    print(size, human);
                    printf("----------------------\n");
                    //選完之後判斷有沒有bingo了
                    is_win = bingo_friend(size, line, human);
                    if (is_win == 1) {  //你贏了
                        printf("Your are the winner!\n");
                        break;
                    }
                    while (1) {
                        char is_friend_win[2];
                        printf("Do your friend is bingo?[y/n]:");
                        scanf("%s", is_friend_win);
                        if (strcmp(is_friend_win, yes) == 0) {
                            is_win = 2;
                            break;
                        } else if (strcmp(is_friend_win, no) == 0) {
                            printf("Please continue the game\n");
                            break;
                        } else {
                            printf("Your input is not available\n");
                            printf("Please enter again\n");
                        }
                    }
                    if (is_win == 2) {
                        printf("Your firend is the winner!\n");
                        break;
                    }
                    printf("Please enter the number chosen by your friend:");
                    scanf("%d", &number);
                    //把選到的數字改0
                    change_chosen_number(size, number, human);
                    //印出human選完後的bingo
                    printf("Your current bingo:\n");
                    print(size, human);
                    printf("----------------------\n");
                    //選完之後判斷有沒有bingo了
                    is_win = bingo_friend(size, line, human);
                    if (is_win == 1) {  //你贏了
                        printf("Your are the winner!\n");
                        break;
                    }
                    while (1) {
                        char is_friend_win[2];
                        printf("Do your friend is bingo?[y/n]:");
                        scanf("%s", is_friend_win);
                        if (strcmp(is_friend_win, yes) == 0) {
                            is_win = 2;
                            break;
                        } else if (strcmp(is_friend_win, no) == 0) {
                            printf("Please continue the game\n");
                            break;
                        } else {
                            printf("Your input is not available\n");
                            printf("Please enter again\n");
                        }
                    }
                    if (is_win == 2) {
                        printf("Your firend is the winner!\n");
                        break;
                    }
                }
            }
        }
        char play_again[2];
        printf("Do yout want to play again?[y/n]:");
        scanf("%s", play_again);
        if (strcmp(play_again, yes) != 0) {
            break;
        }
    }
    return 0;
}