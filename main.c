#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int s1;

typedef struct ship{
    int ship_id;
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    struct ship* next;
}ship;
void append(ship **head , int i , int j , int k , int h , int z) {
    ship *current = (ship *) malloc(sizeof(ship));
    current->start_x = i;
    current->start_y = j;
    current->end_x = k;
    current->end_y = h;
    current->ship_id = z;
    ship*last_node = *head;
    //*head = current;
    for(last_node;last_node->next != NULL; last_node = last_node->next);
    last_node->next = current;
}
int* size_arr(int num){
    int* arr = (int*)malloc(sizeof(int)*num);

    int count=0;
    while(count<num){
        printf("First enter the required length then enter the number of ships with that specific length\n ");
        int len,quantity;
        scanf("%d",&len);
        scanf("%d",&quantity);
        if(len != 1 && len != 2 && len != 3 && len != 5){
            printf("Your length must be a number between 1 , 2 , 3 or 5\nSo try again\n");
            continue;
        }
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
void print_array(int size,int map[size][size]){
    printf("\t");
    int x=65;
    for(int i=1;i<=size;i++){
        printf("%d\t",i);
    }
    printf("\n");
    int counter=0;
    while(counter<size){
        printf("%c\t",x);
        for(int n=0;n<size;n++){
            printf("%d\t",map[counter][n]);
        }
        counter++;
        x++;
        printf("\n");
    }
}
int* ship_kind;
void create_map(int size1 , int map[size1][size1],int num, ship* head){
    int count  = 1 ;
    int x1,y1,x2,y2;

    int* arr = ship_kind;
    while(count <= num){
        printf("Enter the first coordinates of a ship with the length of %d\n", arr[count-1]);
        scanf("%d",&x1);
        scanf("%d",&y1);
        printf("choose the mode of your ship\n1)horizontal\n2)vertical\n");
        int mode;
        scanf("%d", &mode);
        if(mode == 1){
            y2 = y1 + arr[count-1] - 1;
            x2 = x1;
        } else if (mode == 2){
            x2 = x1 + arr[count-1] - 1;
            y2 = y1;
        }
        bool flag = false , t = true;
        if(check(x1,x2,y1,y2,size1) == true){
            for(int i=x1-1;i<=x2+1;i++){
                for(int j=y1-1;j<=y2+1;j++){
                    if(check(i,i,j,j,size1) == true){
                        if(map[i][j] != 0){
                            printf("try again\n");
                            flag = true;
                            t = false;
                            break;
                        }
                    }
                }
                if(flag == true){
                    break;
                }
            }
        }
        else{
            printf("try again\n");
            continue;
        }
        if(t == true){
            if(x1 == x2){
                for(int i=y1;i<=y2;i++){
                    map[x1][i] = count;
                }
            }
            else if (y1 == y2){
                for(int i=x1;i<=x2;i++){
                    map[i][y1] = count;
                }
            }
            append(&head,x1,y1,x2,y2,count);
            count++;
        }
        print_array(size1,map);
        }

}
void print_array_2(int size,int map[size][size]){
    printf("\t");
    int x=65;
    for(int i=1;i<=size;i++){
        printf("%d\t",i);
    }
    printf("\n");
    for(int i=0;i<size;i++){
        printf("%c\t", x);
        for(int j=0;j<size;j++){
            if(map[i][j] >= 0)
                printf(".\t");
            else if (map[i][j] == -2) //full destroyed ship
                printf("%c\t",'C');
            else if(map[i][j] == -1) //destroyed part
                printf("%c\t",'E');
            else if (map[i][j] == -3) //water
                printf("%c\t",'W');
        }
        printf("\n");
        x++;
    }
}
void delete(ship** head_ref , int key){
    ship *current = *head_ref, *prev;
    for(current;current->ship_id != key;current=current->next){
        prev = current;
    }
    prev->next = current->next;
    free(current);

}
/*bool hit(int size , int map[size][size],ship* head){
    int i,j;
    printf("Enter the point that you wanna hit\n");
    printf("row:\n");
    scanf("%d", &i);
    printf("column:\n");
    scanf("%d", &j);
    if(check(i,i,j,j,size) == true){
        if(map[i][j] >= 0){
            if(map[i][j] == 0){
                map[i][j] = -3;
            } else if (map[i][j] > 0){
                int id;
                id = map[i][j];
                ship* current;
                current = head;
                for(current;current != NULL; current=current->next){
                    bool t = false;
                    if(id == current->ship_id){
                        map[i][j] = -1;
                        if(current->start_x == current->end_x){
                            for(int i=current->start_y;i <= current->end_y;i++){
                                if(map[current->start_x][i] > 0){
                                    t = true;
                                    break;
                                }
                            }
                            if(t == false){
                                for(int i=current->start_y;i <= current->end_y;i++){
                                    map[current->start_x][i] = -2;
                                }
                            }
                        } else if (current->start_y == current->end_y){
                            for(int i=current->start_x;i <= current->end_x;i++){
                                if(map[i][current->start_y] > 0){
                                    t = true;
                                    break;
                                }
                            }
                            if(t == false){
                                for(int i=current->start_x;i <= current->end_x;i++){
                                    map[i][current->start_y] = -2;
                                }
                            }
                        }
                    }
                }
            }
        }
        else
            return false;
    } else
        return false;
    return true;
}*/

bool factor = true;
void hit(int size,int map[size][size],ship* head){
    printf("Please enter the coordinates of the point that you wanna hit\n");
    printf("Row:\n");
    int row;
    scanf("%d" , &row);
    printf("Column:\n");
    int column;
    scanf("%d" , &column);
    if(check(row,row,column,column,size) == true){
        if(map[row][column] < 0){
            printf("This point isn't accessible\nTry again\n");
            factor =  true;
        }
        else if(map[row][column] == 0){
            map[row][column] = -3;
            factor = false;
        } else if (map[row][column] > 0){
            int id;
            id = map[row][column];
            ship* current = head;
            for(current;current != NULL; current=current->next){
                bool t = true;
                if(id == current->ship_id){
                    map[row][column] = -1;
                    if(current->start_x == current->end_x){
                        for(int i=current->start_y;i<=current->end_y;i++){
                            if (map[current->start_x][i] > 0){
                                t = false;
                                break;
                            }
                            else{
                                t = true;
                            }
                        }
                        if(t == true){
                            for(int i=current->start_y;i <= current->end_y;i++){
                                map[current->start_x][i] = -2;
                            }
                            for(int i=(current->start_x)-1;i<=(current->end_x)+1;i++){
                                for(int j=(current->start_y)-1;j<=(current->end_y)+1;j++){
                                    if(check(i,i,j,j,size) == true){
                                        if(map[i][j] != -2){
                                            map[i][j] = -3;
                                        }
                                    }

                                }
                            }
                            id = current->ship_id;
                            delete(&head , id);
                        }
                    }
                    else if (current->start_y == current->end_y){
                        for(int i=current->start_x;i<=current->end_x;i++){
                            if (map[i][current->start_y] > 0){
                                t = false;
                                break;
                            }
                            else{
                                t = true;
                            }
                        }
                        if(t == true){
                            for(int i=current->start_x;i <= current->end_x;i++){
                                map[i][current->start_y] = -2;
                            }
                            for(int i=(current->start_x)-1;i<=(current->end_x)+1;i++){
                                for(int j=(current->start_y)-1;j<=(current->end_y)+1;j++){
                                    if(check(i,i,j,j,size) == true){
                                        if(map[i][j] != -2){
                                            map[i][j] = -3;
                                        }
                                    }
                                }
                            }
                        }
                        id = current->ship_id;
                        delete(&head , id);
                    }

                }
            }
            factor = true;
        }
    } else{
        printf("Your coordinates are not inside the map\nTry again\n");
        factor = true;
    }
}
int main() {
    int ship_num = 3;
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
        printf("Player one:\n");
        ship* head1 = (ship*)malloc(sizeof(ship));
        create_map(10,map1,ship_num,head1);

        printf("Player two:\n");
        ship* head2 = (ship*)malloc(sizeof(ship));
        create_map(10,map2,ship_num,head2);
        bool proof = true;
        bool proof1 = true;
        while(head1 != NULL && head2 != NULL){
            while(factor == true){
                if(head1 == NULL || head2 == NULL){
                    proof1 = false;
                    break;
                }
                printf("Player one:\n");
                print_array(s1,map1);
                printf("\n");
                print_array_2(s1,map2);
                hit(s1,map2,head2);
                printf("\n");
                print_array(s1,map1);
                printf("\n");
                print_array_2(s1,map2);
                if(head2 == NULL){
                    break;
                    proof = false;
                }
            }
            if(proof1 == false){
                break;
            }
            if(proof == false){
                continue;
            }
            factor = true;
            while(factor == true){
                printf("Player two:\n");
                print_array(s1,map2);
                printf("\n");
                print_array_2(s1,map1);
                hit(s1,map1,head1);
                printf("\n");
                print_array(s1,map2);
                printf("\n");
                print_array_2(s1,map1);
            }
        }
    }
    return 0;
}