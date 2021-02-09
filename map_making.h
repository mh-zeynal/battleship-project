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
void map_bot(int size1 , int map[size1][size1],int num, ship* head){
    int count  = 1 ;
    int x1,y1,x2,y2;

    int* arr = ship_kind;
    while(count <= num){


        x1 = rand() % size1;
        y1 = rand() % size1;

        int mode ;
        mode = rand() % 2 + 1 ;
        if(mode == 1){
            y2 = y1 + arr[count-1] - 1;
            x2 = x1;
        } else if (mode == 2){
            x2 = x1 + arr[count-1] - 1;
            y2 = y1;
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