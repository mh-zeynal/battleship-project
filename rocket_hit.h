int temp;
void max_length(int size){
    temp = 0;
    int* arr = ship_kind ;
    int i = 0;
    while(i < size){
        if(arr[i] > temp){
            temp = arr[i] ;
        }
        i++;
    }
    return;
}

int remain1, remain2 , remain3, remain4 ;
bool factor = true;
void hit(int size,int map[size][size],ship* head,int* remain,int* sc){
    setcolor(14);
    printf("Please enter the coordinates of the point that you wanna hit\n");
    setcolor(14);
    printf("Row:\n");
    int row;
    char rowch;
    scanf("%c" , &rowch);
    row = (int)(rowch - 'A');
    setcolor(14);
    printf("Column:\n");
    int column;
    scanf("%d" , &column);
    column = column - 1 ;
    if(check(row,row,column,column,size) == true){
        if(map[row][column] < 0){
            setcolor(14);
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
                            (*sc) += 5 * temp / (int)(fabs(((current->start_y) - (current->end_y)))+1);
                            id = current->ship_id;
                            delete(&head , id);
                            (*remain)--;
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
                        (*sc) += 5 * temp / (int)(fabs(((current->start_x) - (current->end_x)))+1);
                        id = current->ship_id;
                        delete(&head , id);
                        (*remain)--;
                    }

                }
            }
            factor = true;
        }
    } else{
        setcolor(14);
        printf("Your coordinates are not inside the map\nTry again\n");
        factor = true;
    }
}
bool factor1 = true ;
bool monitor = true ;
bool monitor1 = true ;
void hit_bot(int size , int map[size][size] , ship* head , int* remain , int* sc) {
    int row;
    row = rand() % size ;
    int column;
    column = rand() % size ;
    if (check(row, row, column, column, size) == true) {
        if (map[row][column] < 0) {
            factor1 = true ;
            monitor = false ;
            monitor1 = false ;
        } else if (map[row][column] == 0) {
            map[row][column] = -3 ;
            factor1 = false ;
            monitor = true ;
            monitor1 = true ;
        } else if (map[row][column] > 0) {
            int id;
            id = map[row][column];
            ship *current = head;
            for (current; current != NULL; current = current->next) {
                bool t = true;
                if (id == current->ship_id) {
                    map[row][column] = -1;
                    if (current->start_x == current->end_x) {
                        for (int i = current->start_y; i <= current->end_y; i++) {
                            if (map[current->start_x][i] > 0) {
                                t = false;
                                break;
                            } else {
                                t = true;
                            }
                        }
                        if (t == true) {
                            for (int i = current->start_y; i <= current->end_y; i++) {
                                map[current->start_x][i] = -2;
                            }
                            for (int i = (current->start_x) - 1; i <= (current->end_x) + 1; i++) {
                                for (int j = (current->start_y) - 1; j <= (current->end_y) + 1; j++) {
                                    if (check(i, i, j, j, size) == true) {
                                        if (map[i][j] != -2) {
                                            map[i][j] = -3;
                                        }
                                    }

                                }
                            }
                            (*sc) += 5 * temp / (int) fabs(((current->start_y) - (current->end_y) + 1));
                            id = current->ship_id;
                            delete(&head, id);
                            (*remain)--;
                        }
                    } else if (current->start_y == current->end_y) {
                        for (int i = current->start_x; i <= current->end_x; i++) {
                            if (map[i][current->start_y] > 0) {
                                t = false;
                                break;
                            } else {
                                t = true;
                            }
                        }
                        if (t == true) {
                            for (int i = current->start_x; i <= current->end_x; i++) {
                                map[i][current->start_y] = -2;
                            }
                            for (int i = (current->start_x) - 1; i <= (current->end_x) + 1; i++) {
                                for (int j = (current->start_y) - 1; j <= (current->end_y) + 1; j++) {
                                    if (check(i, i, j, j, size) == true) {
                                        if (map[i][j] != -2) {
                                            map[i][j] = -3;
                                        }
                                    }
                                }
                            }
                        }
                        (*sc) += 5 * temp / (int) fabs(((current->start_x) - (current->end_x)) + 1);
                        id = current->ship_id;
                        delete(&head, id);
                        (*remain)--;
                    }

                }
            }
            factor1 = true;
            monitor = true;
            monitor1 = true ;
        }
    } else {
        factor1 = true;
        monitor = false;
        monitor1 = false ;
    }
}