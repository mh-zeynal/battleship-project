void swap(int* x, int* y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void setcolor(int code)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (code & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
int* size_arr(int num){
    int* arr = (int*)malloc(sizeof(int)*num);
    int count = 0 ;
    while(count<num){
        system("cls") ;
        setcolor(14);
        printf("First enter the required length then enter the number of ships with that specific length\n");
        int len , quantity ;
        scanf("%d", &len) ;
        scanf("%d", &quantity) ;
        int cur = 0 ;
        cur += quantity ;

        if(cur > num){
            cur = 0 ;
            count = 0 ;
            setcolor(14);
            printf("Outnumbered\nStart from beginning\n") ;
            continue ;
        }

        for(int i = 1 ; i <= quantity ; i++){
            arr[count] = len ;
            count++ ;
        }

    }
    return arr ;
}
bool check(int num1, int num2, int num3, int num4, int size){
    if(num1 >= 0 && num1 < size && num2 >= 0 && num2 < size){
        if(num3 >= 0 && num3 < size && num4 >= 0 && num4 < size){
            return true ;
        }
    }
    return false ;
}
bool game_over(int remain_1, int remain_2){
    if(remain_1 * remain_2 > 0){
        return true ;
    } else{
        return false ;
    }
}