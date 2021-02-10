void print_array(int size,int map[size][size]){
    printf("   ");
    int x=65;
    for(int i=1;i<=size;i++){
        setcolor(6);
        printf("%d  ",i);
    }
    printf("\n");
    int counter=0;
    while(counter<size){
        setcolor(6);
        printf("%c  ", x);
        for(int n=0;n<size;n++){
            if(map[counter][n] > 0){
                if(map[counter][n] >= 10){
                    setcolor(10);
                    printf("%d ",map[counter][n]);
                } else{
                    setcolor(10);
                    printf("%d  ",map[counter][n]);
                }
            }
            else if (map[counter][n] == 0){
                setcolor(3);
                printf("%d  ",map[counter][n]);
            }
            else if (map[counter][n] == -3){
                setcolor(1);
                printf("%d  ",map[counter][n]);
            }
            else if (map[counter][n] == -1){
                setcolor(12);
                printf("%d  ",map[counter][n]);
            }
            else if (map[counter][n] == -2){
                setcolor(5);
                printf("%d  ",map[counter][n]);
            }
        }
        counter++;
        x++;
        printf("\n");
    }
}
void print_array_2(int size,int map[size][size]){
    printf("   ");
    int x=65;
    for(int i=1;i<=size;i++){
        setcolor(6);
        printf("%d  ",i);
    }
    printf("\n");
    for(int i=0;i<size;i++){
        setcolor(6);
        printf("%c  ", x);
        for(int j=0;j<size;j++){
            if(map[i][j] >= 0){
                setcolor(3);
                printf(".  ");
            }
            else if (map[i][j] == -2){
                //full destroyed ship
                setcolor(5);
                printf("%c  ",'C');
            }
            else if(map[i][j] == -1){
                //destroyed part
                setcolor(12);
                printf("%c  ",'E');
            }
            else if (map[i][j] == -3){
                //water
                setcolor(1);
                printf("%c  ",'W');
            }
        }
        printf("\n");
        x++;
    }
}