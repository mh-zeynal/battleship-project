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
void delete(ship** head_ref , int key){
    ship *current = *head_ref, *prev;
    for(current;current->ship_id != key;current=current->next){
        prev = current;
    }
    prev->next = current->next;
    free(current);
}