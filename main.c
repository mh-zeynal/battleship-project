#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
int s1;
int* ship_kind;
#include "Linked_list_stuff.h"
#include "Not_categorized.h"
#include "printmap.h"
#include "map_making.h"
#include "rocket_hit.h"
int main() {
    int score1 = 0 , score2= 0 ;
    int score3 = 0 , score4 = 0 ;
    int ship_num = 10 ;
    s1 = 10 ;
    int ship_kind2[] = {5, 3, 3, 2, 2, 2, 1, 1, 1, 1} ;
    ship_kind = ship_kind2 ;
    time_t t = time(NULL) ;
    srand(t) ;
    remain1 = ship_num ;
    remain2 = ship_num ;
    remain3 = ship_num ;
    remain4 = ship_num ;
    char name_1[1000], name_2[1000], name_3[1000];
    setcolor(14);
    printf("Welcome to battleship\n") ;
    while(true){
        system("cls") ;
        setcolor(14) ;
        printf("1- Play with a friend\n2- Play with bot\n3- Load game\n4- Load last game\n5- Settings\n6- Scoreboard\n7- Exit\n") ;
        int choice ;
        scanf("%d", &choice) ;
        if(choice == 1){
            system("cls");
            int turn = 0;
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

            max_length(ship_num) ;
            setcolor(6) ;
            printf("Player one:\n") ;
            setcolor(14) ;
            printf("Type down a username for your avatar\n");
            getchar() ;
            gets(name_1) ;
            ship* head1 = (ship*)malloc(sizeof(ship)) ;
            head1->ship_id = -1 ;
            system("cls") ;
            setcolor(14) ;
            printf("How do you want to make your map?\n") ;
            printf("1- manual\n2- random\n") ;
            int create_choice_1 ;
            scanf("%d", &create_choice_1) ;
            if(create_choice_1 == 1){
                system("cls") ;
                create_map(s1, map1, ship_num, head1) ;
            }
            else if(create_choice_1 == 2){
                system("cls");
                map_bot(s1, map1, ship_num, head1) ;
                print_array(s1,map1) ;

            }
            printf("Press enter to continue......\n");
            getch();
            system("cls") ;
            setcolor(6);
            printf("Player two:\n");
            setcolor(14);
            printf("Type down a username for your avatar\n") ;
            getchar();
            gets(name_2);
            ship* head2 = (ship*)malloc(sizeof(ship)) ;
            head2->ship_id = -1;
            system("cls") ;
            setcolor(14) ;
            printf("How do you want to make your map?\n") ;
            printf("1- manual\n2- random\n") ;
            int create_choice_2 ;
            scanf("%d", &create_choice_2) ;
            if(create_choice_2 == 1){
                system("cls") ;
                create_map(s1, map2, ship_num, head2) ;
            }
            else if(create_choice_2 == 2){
                system("cls") ;
                map_bot(s1, map2, ship_num, head2) ;
                print_array(s1,map2) ;
            }
            printf("Press enter to continue......\n");
            getch();
            while(game_over(remain1 , remain2) == true){
                if(turn % 2 == 0){
                    system("cls") ;
                    setcolor(6) ;
                    printf("%s:\n", name_1) ;
                    printf("%s's coins: %d\t%s's coins: %d\n", name_1, score1, name_2, score2) ;
                    print_array(s1,map1) ;
                    printf("\n") ;
                    print_array_2(s1,map2) ;
                    hit(s1,map2,head2,&remain2,&score1) ;
                    system("cls") ;
                    setcolor(6) ;
                    printf("%s's coins: %d\t%s's coins: %d\n", name_1, score1, name_2, score2) ;
                    print_array(s1,map1) ;
                    printf("\n") ;
                    print_array_2(s1,map2) ;
                    if(factor == true){
                        turn-- ;
                    }
                }
                else{
                    system("cls") ;
                    setcolor(6) ;
                    printf("%s:\n", name_2) ;
                    printf("%s's coins: %d\t%s's coins: %d\n", name_1, score1, name_2, score2) ;
                    print_array(s1, map2) ;
                    printf("\n");
                    print_array_2(s1, map1) ;
                    hit(s1, map1, head1, &remain1, &score2) ;
                    system("cls") ;
                    setcolor(6);
                    printf("%s's coins: %d\t%s's coins: %d\n", name_1, score1, name_2, score2) ;
                    print_array(s1, map2) ;
                    printf("\n") ;
                    print_array_2(s1, map1) ;
                    if(factor == true){
                        turn-- ;
                    }
                }
                turn++ ;
            }
            printf("Press enter to continue......\n");
            getch();
            printf("\n");
            system("cls") ;
        }
        else if(choice == 2){
            system("cls") ;
            int turn1 = 0 ;
            int map_b[s1][s1], map3[s1][s1] ;
            for(int i = 0; i < s1; i++){
                for(int j = 0; j < s1; j++){
                    map3[i][j] = 0 ;
                }
            }
            for(int i = 0; i < s1; i++){
                for(int j = 0; j < s1; j++){
                    map_b[i][j] = 0 ;
                }
            }
            max_length(ship_num) ;
            ship* head_b = (ship*)malloc(sizeof(ship)) ;
            head_b->ship_id = -1 ;
            ship* head_p = (ship*)malloc(sizeof(ship)) ;
            head_p->ship_id = -1 ;
            setcolor(14) ;
            printf("Type down a username for your avatar\n") ;
            getchar() ;
            gets(name_3) ;
            system("cls") ;
            setcolor(14) ;
            printf("How do you want to make your map?\n") ;
            printf("1- manual\n2- random\n") ;
            int create_choice_3 ;
            scanf("%d", &create_choice_3) ;
            if(create_choice_3 == 1){
                system("cls") ;
                create_map(s1, map3, ship_num, head_p) ;
            }
            else if(create_choice_3 == 2){
                system("cls") ;
                map_bot(s1, map3, ship_num, head_p) ;
                print_array(s1,map3) ;
            }
            map_bot(s1 , map_b , ship_num , head_b) ;
            printf("Press enter to continue......\n");
            getch();
            while(game_over(remain3 , remain4) == true){
                if(turn1 % 2 == 0){
                    system("cls") ;
                    setcolor(6) ;
                    printf("%s:\n", name_3) ;
                    printf("%s's coins: %d\tbot's coins: %d\n", name_3, score3 , score4) ;
                    print_array(s1,map3) ;
                    printf("\n") ;
                    print_array_2(s1,map_b) ;
                    hit(s1,map_b, head_b, &remain3, &score3) ;
                    system("cls") ;
                    setcolor(6) ;
                    printf("%s's coins: %d\tbot's coins: %d\n", name_3, score3 , score4) ;
                    print_array(s1, map3) ;
                    printf("\n") ;
                    print_array_2(s1, map_b) ;
                    if(factor == true){
                        turn1-- ;
                    }
                }
                else{
                    system("cls") ;
                    if(monitor1 == true){
                        setcolor(6) ;
                        printf("Bot:\n") ;
                        printf("%s's coins: %d\tbot's coins: %d\n", name_3, score3 , score4) ;
                    }
                    hit_bot(s1, map3, head_b, &remain4, &score4) ;
                    printf("\n") ;
                    if(monitor == true){
                        print_array(s1, map3) ;
                    }
                    if(factor == true){
                        turn1-- ;
                    }
                }
                turn1++ ;
            }
            setcolor(14);
            printf("Press enter to continue......\n");
            getch();
            system("cls") ;
        }
        else if(choice == 3){
            printf("\a") ;
            setcolor(4) ;
            printf("This option isn't available in your country :)\n") ;
            setcolor(14);
            printf("Press enter to continue......\n");
            getch();
            system("cls") ;
        }
        else if(choice == 4){
            printf("\a") ;
            setcolor(4) ;
            printf("This option isn't available in your country :)\n") ;
            setcolor(14);
            printf("Press enter to continue......\n");
            getch();
            system("cls") ;
        }
        else if(choice == 5){
            setcolor(14) ;
            printf("1- Ships\n2- Map size\n3- ship length\n") ;
            int choice1 ;
            scanf("%d", &choice1) ;
            if(choice1 == 1){
                system("cls") ;
                setcolor(14) ;
                printf("Enter the number of ships that you wanna have in the map\n") ;
                scanf("%d",&ship_num) ;
            } else if (choice1 == 2){
                setcolor(14) ;
                printf("Enter the size of the map\n") ;
                scanf("%d", &s1) ;
            }
            else if(choice1 == 3){
                ship_kind = size_arr(ship_num) ;
                printf("\n");
            }
            printf("Press enter to continue......\n");
            getch();
            system("cls") ;
        }
        else if (choice == 6){
            system("cls") ;
            setcolor(14) ;
            printf("1)play with a friend\n2)play with bot\n") ;
            int choice2;
            if(choice2 == 1){
                setcolor(6);
                printf("%s's coins: %d\t%s's coins: %d\n", name_1, score1, name_2, score2) ;
            }
            else if (choice2 == 2){
                setcolor(6);
                printf("%s's coins: %d\tbot's coins: %d\n", name_3, score3 , score4) ;
            }
            printf("Press enter to continue......\n");
            getch();
            system("cls") ;
        }
        else if (choice == 7){
            system("cls") ;
            setcolor(14);
            Sleep(2000);
            char th[] = "Thank you";
            for(int i=0;i<strlen(th);i++){
                printf("%c", th[i]);
                Sleep(200);
            }
            Sleep(2000);
            printf("\n");
            setcolor(14);
            char th1[] = "Good bye :)";
            for(int i=0;i<strlen(th1);i++){
                printf("%c", th1[i]);
                Sleep(200);
            }
            Sleep(2000);
            system("cls") ;
            break;
        }

    }
    return 0;
}