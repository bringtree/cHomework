typedef struct commodity {
    int id;
    char name[80];
    int classId;
    int number;
    double price;
    double totalPrice;
    char inDate[40];
    char outDate[40];
    int supplier;
    int staff;
    struct commodity *next;
} commodityLink;


typedef struct record {
    int zhengshu;
    double xiaoshu;
    char zifu[80];
    struct record *next;
} recordLink;

typedef struct supplier {
    int id;
    char name[80];
    char phone[12];
    struct supplier *next;

} supplierLink;


typedef struct staff {
    int id;
    char phone[12];
    struct staff *next;

} staffLink;


typedef struct log {
    int staffId;
    int commodityId;
    int play;
    char playTime[40];
    int res;
    struct log *next;

} logLink;
