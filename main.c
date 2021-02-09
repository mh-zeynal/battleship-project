#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <conio.h>
int s1;

#include "Linked_list_stuff.h"
int* size_arr(int num){
    int* arr = (int*)malloc(sizeof(int)*num);

    int count=0;
    while(count<num){
        printf("First enter the required length then enter the number of ships with that specific length\n ");
        int len,quantity;
        scanf("%d",&len);
        scanf("%d",&quantity);
        int cur=0;
        cur += quantity;

        if(cur > num){
            cur = 0;
            count = 0;
            printf("outnumbered\nstart from beginning\n");
            continue;
        }

        for(int i=1;i<=quantity;i++){
            arr[count] = len;
            count++;
        }

    }
    return arr;
}
bool check(int num1,int num2,int num3,int num4,int size){
    if(num1>=0 && num1<size && num2>=0 && num2<size){
        if(num3>=0 && num3<size && num4>=0 && num4<size){
            return true;
        }
    }
    return false;
}
bool game_over(int remain_1 , int remain_2){
    if(remain_1 * remain_2 > 0){
        return true;
    } else{
        return false;
    }
}
#include "printmap.h"
#include "map_making.h"
#include "rocket_hit.h"

int main() {
    int score1 = 0 , score2= 0 ;
    int score3 = 0 , score4 = 0 ;
    int ship_num = 2 ;
    time_t t = time(NULL) ;
    srand(t) ;
    remain1 = ship_num ;
    remain2 = ship_num ;
    remain3 = ship_num ;
    remain4 = ship_num ;
    printf("Welcome to battleship\n");
    printf("1)Play with a friend\n2)Play with bot\n3)Load game\n4)Load last game\n5)Settings\n6)Scoreboard\n7)Exit\n");
    int choice;
    scanf("%d", &choice);
    s1 = 10;

    if(choice == 5){
        printf("1)Ships\n2)Map size\n");
        int choice1;
        scanf("%d", &choice1);
        if(choice1 == 1){
            printf("Enter the number of ships that you wanna have in the map\n");
            scanf("%d",&ship_num);
        } else if (choice1 == 2){
            printf("Enter the size of the map\n");
            scanf("%d",&s1);
        }
    }
    else if(choice == 1){
        int turn=0;
        int map1[s1][s1],map2[s1][s1];
        for(int i=0;i<s1;i++){
            for(int j=0;j<s1;j++){
                map1[i][j] = 0;
            }
        }
        for(int i=0;i<s1;i++){
            for(int j=0;j<s1;j++){
                map2[i][j] = 0;
            }
        }

        ship_kind = size_arr(ship_num);
        max_length(ship_num);
        printf("Player one:\n");
        ship* head1 = (ship*)malloc(sizeof(ship));
        create_map(10,map1,ship_num,head1);

        printf("Player two:\n");
        ship* head2 = (ship*)malloc(sizeof(ship));
        create_map(10,map2,ship_num,head2);
        bool proof = true;
        bool proof1 = true;
        while(game_over(remain1 , remain2) == true){
            if(turn % 2 == 0){
                printf("Player one:\n");
                printf("your score: %d\trival's score: %d", score1 , score2) ;
                printf("\n");
                print_array(s1,map1);
                printf("\n");
                print_array_2(s1,map2);
                hit(s1,map2,head2,&remain2,&score1);
                printf("your score: %d\trival's score: %d", score1 , score2) ;
                printf("\n");
                print_array(s1,map1);
                printf("\n");
                print_array_2(s1,map2);
                if(factor == true){
                    turn--;
                }
            }
            else{
                printf("Player two:\n");
                printf("your score: %d\trival's score: %d", score2 , score1) ;
                printf("\n");
                print_array(s1,map2);
                printf("\n");
                print_array_2(s1,map1);
                hit(s1,map1,head1,&remain1,&score2);
                printf("\n");
                print_array(s1,map2);
                printf("\n");
                print_array_2(s1,map1);
                if(factor == true){
                    turn--;
                }
            }
            turn++;
        }
    }
    else if(choice == 2){
        int turn1 = 0 ;
        int map_b[s1][s1],map3[s1][s1];
        for(int i=0;i<s1;i++){
            for(int j=0;j<s1;j++){
                map3[i][j] = 0;
            }
        }
        for(int i = 0 ; i < s1 ; i++){
            for(int j = 0 ; j < s1 ; j++){
                map_b[i][j] = 0 ;
            }
        }
        ship_kind = size_arr(ship_num) ;
        max_length(ship_num);
        ship* head_b = (ship*)malloc(sizeof(ship)) ;
        ship* head_p = (ship*)malloc(sizeof(ship)) ;
        create_map(s1 , map3 , ship_num , head_p) ;
        map_bot(s1 , map_b , ship_num , head_b) ;
        bool proof = true;
        bool proof1 = true;
        while(game_over(remain3 , remain4) == true){
            if(turn1 % 2 == 0){
                printf("Player one:\n");
                printf("your score: %d\tbot's score: %d", score3 , score4) ;
                printf("\n");
                print_array(s1,map3);
                printf("\n");
                print_array(s1,map_b);
                hit(s1,map_b,head_b,&remain3,&score3);
                printf("your score: %d\tbot's score: %d", score3 , score4) ;
                printf("\n");
                print_array(s1,map3);
                printf("\n");
                print_array_2(s1,map_b);
                if(factor == true){
                    turn1--;
                }
            }
            else{
                if(monitor1 == true){
                    printf("Bot:\n");
                    printf("bot's score: %d\tyour score: %d", score4 , score3) ;
                }
                printf("\n");
                hit_bot(s1,map3,head_b,&remain4,&score4);
                printf("\n");
                if(monitor == true){
                    print_array(s1,map3);
                }
                if(factor == true){
                    turn1--;
                }
            }
            turn1++;
        }
    }
    return 0;
}