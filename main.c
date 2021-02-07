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
    current->next = *head;
    *head = current;
}
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
        /*if(x1 != x2 && y1 != y2){
            printf("try again\n");
            continue;
        }*/

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
                printf("%c",'C');
            else if(map[i][j] == -1) //destroyed part
                printf("%c",'E');
            else if (map[i][j] == -3) //water
                printf("%c",'W');
        }
        printf("\n");
        x++;
    }
}
bool hit(int size , int map[size][size],ship* head){
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
                            if(!t){
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
                            if(!t){
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
}
int main() {

    printf("Enter the size of the map\n");
    scanf("%d",&s1);
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
    printf("Enter the number of ships that you wanna have in the map\n");
    int ship_num;
    scanf("%d",&ship_num);
    ship_kind = size_arr(ship_num);
    printf("Player one:\n");
    ship* head1 = (ship*)malloc(sizeof(ship));
    create_map(10,map1,ship_num,head1);

    printf("Player two:\n");
    ship* head2 = (ship*)malloc(sizeof(ship));
    create_map(10,map2,ship_num,head2);
    while(true){

    }
    return 0;
}