void create_map(int size1 , int map[size1][size1],int num, ship* head){
    int count  = 1 ;
    int x1,y1,x2,y2;
    char x_1;
    int* arr = ship_kind;
    while(count <= num){
        system("cls") ;
        setcolor(14);
        printf("Enter the first coordinates of a ship with the length of %d\n", arr[count-1]);
        getchar();
        scanf(" %c",&x_1);
        x1 = (int)(x_1 - 'A');
        scanf("%d",&y1);
        y1 = y1 - 1;
        if(arr[count - 1] == 1){
            x2 = x1 ;
            y2 = y1 ;
        }
        else{
            setcolor(14) ;
            printf("Choose the mode of your ship\n1)horizontal\n2)vertical\n") ;
            int mode ;
            scanf("%d", &mode) ;
            if(mode == 1){
                system("cls") ;
                setcolor(14);
                printf("1- left\n2- right\n") ;
                int direction1 ;
                scanf("%d", &direction1) ;
                if(direction1 == 1){
                    y2 = y1 - arr[count-1] + 1 ;
                    x2 = x1;
                } else if (direction1 == 2){
                    y2 = y1 + arr[count-1] - 1;
                    x2 = x1;
                }
            }
            else if (mode == 2){
                system("cls") ;
                setcolor(14);
                printf("1- Up\n2- Down\n");
                int direction2;
                scanf("%d", &direction2);
                if(direction2 == 1){
                    x2 = x1 - arr[count-1] + 1;
                    y2 = y1;
                } else if (direction2 == 2){
                    x2 = x1 + arr[count-1] - 1;
                    y2 = y1;
                }
            }
        }
        if(x1 > x2){
            swap(&x1,&x2);
        }
        else if(y1 > y2){
            swap(&y1,&y2);
        }
        bool flag = false , t = true;
        if(check(x1,x2,y1,y2,size1) == true){
            for(int i=x1-1;i<=x2+1;i++){
                for(int j=y1-1;j<=y2+1;j++){
                    if(check(i, i, j, j, size1) == true){
                        if(map[i][j] != 0){
                            system("cls") ;
                            setcolor(14);
                            printf("Try again\n");
                            flag = true;
                            t = false ;
                            break ;
                        }
                    }
                }
                if(flag == true){
                    break ;
                }
            }
        }
        else{
            setcolor(14) ;
            print_array(size1,map) ;
            continue;
        }
        if(t == true){
            if(x1 == x2){
                for(int i = y1; i <= y2; i++){
                    map[x1][i] = count ;
                }
            }
            else if (y1 == y2){
                for(int i = x1; i <= x2; i++){
                    map[i][y1] = count ;
                }
            }
            append(&head, x1, y1, x2, y2, count) ;
            count++ ;
        }

        print_array(size1, map) ;
    }
}
void map_bot(int size1 , int map[size1][size1],int num, ship* head){
    int count  = 1 ;
    int x1,y1,x2,y2;
    int* arr = ship_kind;
    while(count <= num){
        x1 = rand() % size1;
        y1 = rand() % size1;
        if(arr[count - 1] == 1){
            x2 = x1 ;
            y2 = y1 ;
        }
        else{
            int mode ;
            mode = rand() % 2 + 1 ;
            if(mode == 1){
                int direction1 ;
                direction1 = rand() % 2 + 1 ;
                if(direction1 == 1){
                    y2 = y1 - arr[count-1] + 1 ;
                    x2 = x1;
                } else if (direction1 == 2){
                    y2 = y1 + arr[count-1] - 1;
                    x2 = x1;
                }
            }
            else if (mode == 2){
                setcolor(14);
                int direction2;
                direction2 = rand() % 2 + 1 ;
                if(direction2 == 1){
                    x2 = x1 - arr[count-1] + 1 ;
                    y2 = y1;
                } else if (direction2 == 2){
                    x2 = x1 + arr[count-1] - 1 ;
                    y2 = y1;
                }
            }
        }
        if(x1 > x2){
            swap(&x1,&x2);
        }
        else if(y1 > y2){
            swap(&y1,&y2);
        }
        bool flag = false , T = true;
        if(check(x1,x2,y1,y2,size1) == true){
            for(int i = x1 - 1 ; i <= x2 + 1 ; i++){
                for(int j=y1-1;j<=y2+1;j++){
                    if(check(i,i,j,j,size1) == true){
                        if(map[i][j] != 0){
                            flag = true;
                            T = false;
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
            continue;
        }
        if(T == true){
            if(x1 == x2){
                for(int i = y1 ; i <= y2 ; i++){
                    map[x1][i] = count ;
                }
            }
            else if (y1 == y2){
                for(int i = x1 ; i <= x2 ; i++){
                    map[i][y1] = count ;
                }
            }
            append(&head , x1 , y1 , x2 , y2 , count) ;
            count++ ;
        }
    }
}