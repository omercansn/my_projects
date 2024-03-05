
typedef struct person {
    bool isClient; 
    float money;     
} person;


typedef struct queue {
    int front, rear, size;
    int capacity;
    struct person *people; 
} queue;

queue *create(int capacity);
bool is_full(queue *q) ;
bool is_empty(queue *q) ;
void add(queue *q, person k);
person remove_person(queue *q) ;
void shift_all(queue *q);

void add_customer(queue *q, person k);
void display_all(queue *q) ;


