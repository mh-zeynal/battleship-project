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