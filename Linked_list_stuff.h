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
    if((*head)->ship_id == -1){
        (*head)->start_x = i;
        (*head)->start_y = j;
        (*head)->end_x = k;
        (*head)->end_y = h;
        (*head)->ship_id = z;
    }
    else{
        current->start_x = i;
        current->start_y = j;
        current->end_x = k;
        current->end_y = h;
        current->ship_id = z;
        ship*last_node = *head;
        for(last_node;last_node->next != NULL; last_node = last_node->next);
        last_node->next = current;
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