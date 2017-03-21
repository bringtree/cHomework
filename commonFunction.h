//
// Created by huangpeisong on 2017/3/20.
//


#define godeadBuffer     setbuf(stdin, NULL);


//获取时间
int getTime(char *date) {
    time_t lt;
    char year[5];
    char month[3];
    char day[3];
    char hours[3];
    char min[3];
    char sec[3];
    struct tm *p;
    char *a = "-";
    char *b = ":";

    time(&lt);
    p = localtime(&lt);
    sprintf(year, "%4d", p->tm_year + 1900);
    sprintf(month, "%02d", p->tm_mon + 1);
    sprintf(day, "%02d", p->tm_mday);
    sprintf(hours, "%02d", p->tm_hour);
    sprintf(min, "%02d", p->tm_min);
    sprintf(sec, "%02d", p->tm_sec);
    strcpy(date, year);
    strcat(date, a);
    strcat(date, month);
    strcat(date, a);
    strcat(date, day);
    strcat(date, a);
    strcat(date, hours);
    strcat(date, b);
    strcat(date, min);
    strcat(date, b);
    strcat(date, sec);
    return 1;
}

//交换ab
int swapFoods(commodityLink *a, commodityLink *b) {
    commodityLink *temp;
    temp = (commodityLink *) malloc(sizeof(commodityLink));

    temp->id = a->id;
    strcpy(temp->name, a->name);
    temp->classId = a->classId;
    temp->number = a->number;
    temp->price = a->price;
    strcpy(temp->inDate, a->inDate);
    strcpy(temp->outDate, a->outDate);
    temp->supplier = a->supplier;
    temp->staff = a->staff;
    temp->totalPrice = a->totalPrice;

    a->id = b->id;
    strcpy(a->name, b->name);
    a->classId = b->classId;
    a->number = b->number;
    a->price = b->price;
    strcpy(a->inDate, b->inDate);
    strcpy(a->outDate, b->outDate);
    a->supplier = b->supplier;
    a->staff = b->staff;
    a->totalPrice = b->totalPrice;

    b->id = temp->id;
    strcpy(b->name, temp->name);
    b->classId = temp->classId;
    b->number = temp->number;
    b->price = temp->price;
    strcpy(b->inDate, temp->inDate);
    strcpy(b->outDate, temp->outDate);
    b->supplier = temp->supplier;
    b->staff = temp->staff;
    b->totalPrice = temp->totalPrice;

    return 1;
}

//操作日记
int controlLog(int staffId, int commodityId, int play) {
    logLink *log;
    FILE *fp;
    char date[40];
    getTime(date);
    if ((fp = fopen("log.txt", "a+")) == NULL) {
        fp = fopen("log.txt", "w");
        fclose(fp);
        fp = fopen("log.txt", "a+");
    }

    if (play == 1) fprintf(fp, "ID:%d操作员在%s对商品编号为%d的商品做了录入操作\n", staffId, date, commodityId);
    if (play == 3) fprintf(fp, "ID:%d操作员在%s对商品编号为%d的商品做了编辑操作\n", staffId, date, commodityId);
    if (play == 4) fprintf(fp, "ID:%d操作员在%s对商品编号为%d的商品做了删除操作\n", staffId, date, commodityId);
    return 1;
}

//打印完成菜单
void printfMenu() {
    printf("╭───────────────────────────────────────────────╮\n");
    printf("│ ◎ ○ ○          商品进销存系统v0.1              │\n");
    printf("├───────────────────────────────────────────────┤\n");
    printf("│                                               │\n");
    printf("│                1.录入商品的信息                │\n");
    printf("│                2.查看商品的信息                │\n");
    printf("│                3.编辑商品的信息                │\n");
    printf("│                4.删除商品的信息                │\n");
    printf("│                5.统计商品的信息                │\n");
    printf("│                6.对商品信息排序                │\n");
    printf("│                7.打印商品的信息                │\n");
    printf("│                8.查看供应商信息                │\n");
    printf("│                9.查看员工的信息                │\n");
    printf("│                q.退出进销存系统                │\n");
    printf("│                                               │\n");
    printf("└───────────────────────────────────────────────┘\n");
}

//打印残缺菜单
void printfMenu_s() {
    printf("╭───────────────────────────────────────────────╮\n");
    printf("│ ◎ ○ ○          商品进销存系统v0.1              │\n");
    printf("├───────────────────────────────────────────────┤\n");
    printf("│                                               │\n");
    printf("│                1.录入商品的信息                │\n");
    printf("│                8.查看供应商信息                │\n");
    printf("│                9.查看员工的信息                │\n");
    printf("│                q.退出进销存系统                │\n");
    printf("│                                               │\n");
    printf("└───────────────────────────────────────────────┘\n");
}
