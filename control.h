
#define godeadBuffer     setbuf(stdin, NULL);

// commonFunction.h
extern int getTime(char *date);

extern void printfMenu();

extern void printfMenu_s();


//输出链表
int printfCommodityLink(commodityLink *repertory) {
    commodityLink *goods;
    goods = repertory->next;
    while (goods != NULL) {
        printf("商品编号:%d    商品名:%s    类型:%d\n库存:%d    单价:%lf\n最近一次入库时间:%s    最近一次出库时间:%s\n最近一次供应商:%d    最近一次操作员:%d\n",
               goods->id, goods->name, goods->classId, goods->number, goods->price,
               goods->inDate, goods->outDate, goods->supplier, goods->staff);
        printf("\n");
        goods = goods->next;
    }
    return 1;
}

//将commodity.txt信息导入到链表中 返回值0文件打开失败 返回值1读取成功
int importCommodityLink(commodityLink *repertory) {
    FILE *fp;
    commodityLink *goods, *temp;
    temp = repertory;
    fp = fopen("commodity.txt", "r+");
    if (fp == NULL) {
        fp = fopen("commodity.txt", "w");
        fclose(fp);
        fp = fopen("commodity.txt", "a+");
        return 0;// open fail
    }
    while (!feof(fp)) {
        goods = (commodityLink *) malloc(sizeof(commodityLink));
        goods->next = NULL;
        fscanf(fp, "%d %s %d %d %lf %lf %s %s %d %d\n",
               &goods->id, goods->name, &goods->classId, &goods->number, &goods->price, &goods->totalPrice,
               goods->inDate, goods->outDate, &goods->supplier, &goods->staff);
        temp->next = goods;
        temp = goods;
    }
    return 1;
}


//根据商品ID/name查询
int repertoryInfo(commodityLink *repertory) {

    int mode;
    int id;
    char name[80];
    commodityLink *goods;

    while (1) {
        printf("╭──────────────────────────────────────────────╮\n");
        printf("│ ◎ ○ ○            查看商品的信息               │\n");
        printf("├──────────────────────────────────────────────┤\n");
        printf("│                                              │\n");
        printf("│                1:根据商品ID查询               │\n");
        printf("│                2:根据商品名字查询             │\n");
        printf("│                3:退回菜单                    │\n");
        printf("│                                              │\n");
        printf("└──────────────────────────────────────────────┘\n");
        printf("请输入请输入需要的功能的对于序号并回车,如1\n");

        scanf("%d", &mode);
        godeadBuffer

        if (mode == 1) {
            goods = repertory->next;
            printf("输入你要查询的商品ID,输入格式:1\n");
            scanf("%d", &id);
            godeadBuffer

            while (goods->id != id) {
                goods = goods->next;
                if (goods == NULL) {
                    printf("你输入的是%d，找不到该商品\n", id);
                    break;
                }
            }
            if (goods != NULL) {
                printf("商品编号:%d    商品名:%s    类型:%d\n库存:%d    单价:%lf    总价:%lf\n最近一次入库时间:%s    最近一次出库时间:%s\n最近一次供应商:%d    最近一次操作员:%d\n",
                       goods->id, goods->name, goods->classId, goods->number, goods->price, goods->totalPrice,
                       goods->inDate, goods->outDate, goods->supplier, goods->staff);
            }

        } else if (mode == 2) {
            goods = repertory->next;
            printf("输入你要查询的商品名字,输入格式:飞机\n");
            scanf("%s", name);
            godeadBuffer
            while (strcmp(goods->name, name)) {
                goods = goods->next;
                if (goods == NULL) {
                    printf("你输入的是%s，找不到该商品\n", name);
                    break;
                }
            }
            if (goods != NULL) {
                printf("商品编号:%d    商品名:%s    类型:%d\n库存:%d    单价:%lf    总价:%lf\n最近一次入库时间:%s    最近一次出库时间:%s\n最近一次供应商:%d    最近一次操作员:%d\n",
                       goods->id, goods->name, goods->classId, goods->number, goods->price, goods->totalPrice,
                       goods->inDate, goods->outDate, goods->supplier, goods->staff);
            }

        } else if (mode == 3) {
            return 1;
            //退回菜单
        } else {
            printf("输入有误:你刚刚输入的是%d,请检查你的输入\n", mode);
        }
    }
}


//录入商品信息
int insertRepertory(commodityLink *repertory) {

    commodityLink *goods, *temp, *tail;
    int id;
    char name[80] = {'\0'};
    int classId;
    int number;
    double price;
    double totalPrice;
    char inDate[40] = {'\0'};
    char outDate[40] = {'n', 'u', 'l', 'l'};
    int supplier;
    int staff;
    int mode;

    tail = repertory;
    while (tail->next != NULL) {
        tail = tail->next;
    }


    while (1) {
        temp = repertory->next;
        goods = (commodityLink *) malloc(sizeof(commodityLink));
        goods->next = NULL;
        while (1) {
            printf("请输入商品id,输入格式如:1\n");
            scanf("%d", &id);
            godeadBuffer
            printf("请输入的商品id是%d，确认请按回车,按其他键表示重新输入id\n", id);
            mode = getchar();
            godeadBuffer
            if (mode == '\n') {

                while (temp != NULL) {
                    if (temp->id == id) {
                        printf("商品编号:%d    商品名:%s    类型:%d\n库存:%d   单价:%lf    总价:%lf\n最近一次入库时间:%s    最近一次出库时间:%s\n最近一次供应商:%d    最近一次操作员:%d\n",
                               temp->id, temp->name, temp->classId, temp->number, temp->price, temp->totalPrice,
                               temp->inDate, temp->outDate, temp->supplier, temp->staff);
                        printf("发现该商品id已经存在,请检查输入\n");
                        break;
                    }
                    temp = temp->next;
                }

                if (temp == NULL || temp->id != id) {
                    break;
                }
            }
        }
        while (1) {
            printf("请输入商品名字.输入格式如:飞机\n");
            scanf("%s", name);
            godeadBuffer
            printf("请输入的商品名字是%s，确认请按回车,按其他键表示重新输入商品名字.\n", name);
            mode = getchar();
            godeadBuffer
            if (mode == '\n') {
                break;
            }
        }
        while (1) {
            printf("请输入商品类别.输入格式如: 1\n");
            scanf("%d", &classId);
            godeadBuffer
            printf("请输入的商品类别是%d，确认请按回车,按其他键表示重新输入商品类别.\n", classId);
            mode = getchar();
            godeadBuffer
            if (mode == '\n') {
                break;
            }
        }
        while (1) {
            printf("请输入商品的数量.输入格式如: 1\n");
            scanf("%d", &number);
            godeadBuffer
            printf("请输入的商品数量是%d，确认请按回车,按其他键表示重新输入商品数量.\n", number);
            mode = getchar();
            godeadBuffer
            if (mode == '\n') {
                break;
            }
        }
        while (1) {
            printf("请输入商品的价格.输入格式如:1\n");
            scanf("%lf", &price);
            godeadBuffer
            printf("请输入的商品价格是%lf，确认请按回车,按其他键表示重新输入商品价格.\n", price);
            mode = getchar();
            godeadBuffer
            if (mode == '\n') {
                break;
            }
        }
        while (1) {
            printf("请输入商品的供应商.输入格式如:1\n");
            scanf("%d", &supplier);
            godeadBuffer
            printf("请输入的商品供应商是%d，确认请按回车,按其他键表示重新输入商品供应商.\n", supplier);
            mode = getchar();
            godeadBuffer
            if (mode == '\n') {
                break;
            }
        }
        while (1) {
            printf("请输入最近一次入库时间.输入格式如:2017-03-18-18:38:33\n");
            scanf("%s", inDate);
            godeadBuffer
            printf("请输入的最近一次入库时间是%s，确认请按回车,按其他键表示重新输入最近一次入库时间.\n", inDate);
            mode = getchar();
            godeadBuffer
            if (mode == '\n') {
                break;
            }
        }
        while (1) {
            printf("请输入操作员ID.输入格式如:1\n");
            scanf("%d", &staff);
            godeadBuffer
            printf("请输入的操作员id是%d，确认请按回车,按其他键表示重新输入操作员.输入格式如:1\n", staff);
            mode = getchar();
            godeadBuffer
            if (mode == '\n') {
                break;
            }
        }
        totalPrice = number * price;
        printf("请核对下面输入信息\n");
        printf("商品编号:%d    商品名:%s    类型:%d\n库存:%d    单价:%lf    总价:%lf\n最近一次入库时间:%s    最近一次出库时间:%s\n最近一次供应商:%d    最近一次操作员:%d\n",
               id, name, classId, number, price, totalPrice,
               inDate, outDate, supplier, staff);
        printf("确认请按回车,其他键表示撤销此次录入\n");
        controlLog(staff, id, 1);
        mode = getchar();
        godeadBuffer
        if (mode == '\n') {
            goods->id = id;
            strcpy(goods->name, name);
            goods->classId = classId;
            goods->number = number;
            goods->price = price;
            goods->totalPrice = totalPrice;
            strcpy(goods->inDate, inDate);
            strcpy(goods->outDate, outDate);
            goods->supplier = supplier;
            goods->staff = staff;
            tail->next = goods;
            tail = goods;

            printf("录入成功\n");
            printf("继续操作请按回车，返回菜单按其他键\n");
            mode = getchar();
            godeadBuffer
            if (mode != '\n') {
                if (exportCommodityLink(repertory) < 0) {
                    printf("导入到文本失败\n");
                }
                printf("导入到文本中成功\n");
                return 1;
            }
        }
    }


}


//写入文本 <0表示出现写入错误
int exportCommodityLink(commodityLink *repertory) {

    FILE *fp;
    commodityLink *temp;
    int mode;
    fp = fopen("commodity.txt", "w");
    temp = repertory->next;
    while (temp != NULL) {
        mode = fprintf(fp, "%d %s %d %d %lf %lf %s %s %d %d\n", temp->id, temp->name, temp->classId, temp->number,
                       temp->price, temp->totalPrice,
                       temp->inDate, temp->outDate, temp->supplier, temp->staff);
        if (mode < 0) {
            return 0;
        }
        temp = temp->next;
    }
    fclose(fp);
    return 1;
}


//修改商品信息
int editRepertory(commodityLink *repertory) {


    commodityLink *goods;
    int id;
    char name[80] = {'\0'};
    int classId;
    int number;
    double price;
    double totalPrice;
    char inDate[40] = {'n', 'u', 'l', 'l'};
    char outDate[40] = {'n', 'u', 'l', 'l'};
    int supplier;
    int staff;
    int mode;

    while (1) {
        printf("╭──────────────────────────────────────────────╮\n");
        printf("│ ◎ ○ ○            编辑商品的信息               │\n");
        printf("├──────────────────────────────────────────────┤\n");
        printf("│                                              │\n");
        printf("│                1:根据商品ID修改商品           │\n");
        printf("│                2:根据商品名字修改商品          │\n");
        printf("│                3:退回菜单                     │\n");
        printf("│                                              │\n");
        printf("└──────────────────────────────────────────────┘\n");
        printf("请输入请输入需要的功能的对于序号并回车,如:1\n");
        mode = getchar();
        godeadBuffer

        if (mode == '1') {
            goods = repertory->next;
            printf("输入我你要查询的商品ID,如:1\n");
            scanf("%d", &id);
            godeadBuffer

            while (goods->id != id) {
                goods = goods->next;
                if (goods == NULL) {
                    printf("你输入的是%d，找不到该商品\n", id);
                    break;
                }
            }
            if (goods != NULL) {
                printf("商品编号:%d    商品名:%s    类型:%d\n库存:%d    单价:%lf    总价:%lf\n最近一次入库时间:%s    最近一次出库时间:%s\n最近一次供应商:%d    最近一次操作员:%d\n",
                       goods->id, goods->name, goods->classId, goods->number, goods->price, goods->totalPrice,
                       goods->inDate, goods->outDate, goods->supplier, goods->staff);

                while (1) {
                    printf("是否修改商品名字,回车表示不用修改，其他键表示需要修改\n");
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        strcpy(name, goods->name);
                        break;
                    }
                    printf("请输入商品名字,如:飞机\n");
                    scanf("%s", name);
                    godeadBuffer
                    printf("请输入的商品名字是%s，确认请按回车,按其他键表示重新输入商品名字\n", name);
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        break;
                    }

                }
                while (1) {
                    printf("是否修改商品类别,回车表示不用修改，其他键表示需要修改\n");
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        classId = goods->classId;
                        break;
                    }
                    printf("请输入商品类别,如:1\n");
                    scanf("%d", &classId);
                    godeadBuffer
                    printf("请输入的商品类别是%d，确认请按回车,按其他键表示重新输入商品类别\n", classId);
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        break;
                    }

                }
                while (1) {
                    printf("是否修改商品数量,回车表示不用修改，其他键表示需要修改\n");
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        number = goods->number;
                        break;
                    }
                    printf("请输入商品的数量,如:1\n");
                    scanf("%d", &number);
                    godeadBuffer
                    printf("请输入的商品数量是%d，确认请按回车,按其他键表示重新输入商品数量\n", number);

                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        break;
                    }

                }
                while (1) {
                    printf("是否修改商品价格,回车表示不用修改，其他键表示需要修改\n");
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        price = goods->price;
                        break;
                    }
                    printf("请输入商品的价格,如:1\n");
                    scanf("%lf", &price);
                    godeadBuffer
                    printf("请输入的商品价格是%lf，确认请按回车,按其他键表示重新输入商品价格\n", price);
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        break;
                    }

                }
                while (1) {
                    printf("是否修改商品供应商,回车表示不用修改，其他键表示需要修改\n");
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        supplier = goods->supplier;
                        break;
                    }
                    printf("请输入商品的供应商,如:1\n");
                    scanf("%d", &supplier);
                    godeadBuffer
                    printf("请输入的商品供应商是%d，确认请按回车,按其他键表示重新输入商品供应商\n", supplier);
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        break;
                    }

                }
                while (1) {
                    printf("是否修改商品入库时间,回车表示不用修改，其他键表示需要修改\n");
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        strcpy(inDate, goods->inDate);
                        break;
                    }
                    printf("请输入最近一次入库时间,如:2017-03-18-18:38:33\n");
                    scanf("%s", inDate);
                    godeadBuffer
                    printf("请输入的最近一次入库时间是%s，确认请按回车,按其他键表示重新输入最近一次入库时间\n", inDate);
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        break;
                    }

                }
                while (1) {
                    printf("是否修改商品出库时间,回车表示不用修改，其他键表示需要修改\n");
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        strcpy(outDate, goods->outDate);
                        break;
                    }
                    printf("请输入最近一次出库时间,如:2017-03-18-18:38:33\n");
                    scanf("%s", outDate);
                    godeadBuffer
                    printf("请输入的最近一次出库时间是%s，确认请按回车,按其他键表示重新输入最近一次出库时间\n", outDate);
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        break;
                    }

                }
                while (1) {
                    printf("是否修改操作员ID,回车表示不用修改，其他键表示需要修改\n");
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        staff = goods->staff;
                        break;
                    }
                    printf("请输入操作员ID,如:1\n");
                    scanf("%d", &staff);
                    godeadBuffer
                    printf("请输入的操作员id是%d，确认请按回车,按其他键表示重新输入操作员\n", staff);
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        break;
                    }


                }

                printf("请核对下面输入信息\n");
                printf("商品编号:%d 商品名:%s 类型:%d\n库存:%d 单价:%lf\n最近一次入库时间:%s 最近一次出库时间:%s 供应商:%d 最近一次操作员:%d\n",
                       id, name, classId, number, price,
                       inDate, outDate, supplier, staff);
                printf("确认请按回车,其他键表示撤销此次录入\n");
                mode = getchar();
                godeadBuffer
                if (mode == '\n') {
                    goods->id = id;
                    strcpy(goods->name, name);
                    goods->classId = classId;
                    goods->number = number;
                    goods->price = price;
                    strcpy(goods->inDate, inDate);
                    strcpy(goods->outDate, outDate);
                    goods->supplier = supplier;
                    goods->staff = staff;
                    printf("录入成功\n");
                    controlLog(staff, id, 3);
                    printf("继续操作请按回车，返回菜单按其他键\n");
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        if (exportCommodityLink(repertory) < 0) {
                            printf("导入到文本失败\n");
                        }
                        printf("导入到文本中成功\n");
                        return 1;
                    }
                }

            }

        } else if (mode == '2') {
            goods = repertory->next;
            printf("输入我你要查询的商品名字,如:飞机\n");
            scanf("%s", name);
            godeadBuffer

            while (strcmp(goods->name, name)) {
                goods = goods->next;
                if (goods == NULL) {
                    printf("你输入的是%s，找不到该商品\n", name);
                    break;
                }
            }
            if (goods != NULL) {
                printf("商品编号:%d    商品名:%s    类型:%d\n库存:%d    单价:%lf    总价:%lf\n 最近一次入库时间:%s    最近一次出库时间:%s    最近一次供应商:%d    最近一次操作员:%d\n",
                       goods->id, goods->name, goods->classId, goods->number, goods->price, goods->totalPrice,
                       goods->inDate, goods->outDate, goods->supplier, goods->staff);


                while (1) {
                    printf("是否修改商品id,回车表示不用修改，其他键表示需要修改\n");
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        id = goods->id;
                        break;
                    }
                    printf("请输入商品id,如:1\n");
                    scanf("%d", &id);
                    godeadBuffer
                    printf("请输入的商品id是%d，确认请按回车,按其他键表示重新输入商品id\n", id);
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        break;
                    }

                }
                while (1) {
                    printf("是否修改商品类别,回车表示不用修改，其他键表示需要修改\n");
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        classId = goods->classId;
                        break;
                    }
                    printf("请输入商品类别,如:1\n");
                    scanf("%d", &classId);
                    godeadBuffer

                    printf("请输入的商品类别是%d，确认请按回车,按其他键表示重新输入商品类别\n", classId);
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        break;
                    }

                }
                while (1) {
                    printf("是否修改商品数量,回车表示不用修改，其他键表示需要修改\n");
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        number = goods->number;
                        break;
                    }
                    printf("请输入商品的数量,如:1\n");
                    scanf("%d", &number);
                    godeadBuffer

                    printf("请输入的商品数量是%d，确认请按回车,按其他键表示重新输入商品数量\n", number);
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        break;
                    }

                }
                while (1) {
                    printf("是否修改商品价格,回车表示不用修改，其他键表示需要修改\n");
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        price = goods->price;
                        break;
                    }
                    printf("请输入商品的价格,如:1\n");
                    scanf("%lf", &price);
                    godeadBuffer

                    printf("请输入的商品价格是%lf，确认请按回车,按其他键表示重新输入商品价格\n", price);
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        break;
                    }

                }
                while (1) {
                    printf("是否修改商品供应商,回车表示不用修改，其他键表示需要修改\n");
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        supplier = goods->supplier;
                        break;
                    }
                    printf("请输入商品的供应商,如:1\n");
                    scanf("%d", &supplier);
                    godeadBuffer

                    printf("请输入的商品供应商是%d，确认请按回车,按其他键表示重新输入商品供应商\n", supplier);
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        break;
                    }

                }
                while (1) {
                    printf("是否修改商品入库时间,回车表示不用修改，其他键表示需要修改\n");
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        strcpy(inDate, goods->inDate);
                        break;
                    }
                    printf("请输入最近一次入库时间,如:2017-03-18-18:38:33\n");
                    scanf("%s", inDate);
                    godeadBuffer

                    printf("请输入的最近一次入库时间是%s，确认请按回车,按其他键表示重新输入最近一次入库时间\n", inDate);
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        break;
                    }

                }
                while (1) {
                    printf("是否修改商品出库时间,回车表示不用修改，其他键表示需要修改\n");
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        strcpy(outDate, goods->outDate);
                        break;
                    }
                    printf("请输入最近一次出库时间,如:2017-03-18-18:38:33\n");
                    scanf("%s", outDate);
                    godeadBuffer

                    printf("请输入的最近一次出库时间是%s，确认请按回车,按其他键表示重新输入最近一次出库时间\n", inDate);
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        break;
                    }

                }
                while (1) {
                    printf("是否修改操作员ID,回车表示不用修改，其他键表示需要修改\n");
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        staff = goods->staff;
                        break;
                    }
                    printf("请输入操作员ID,如1\n");
                    scanf("%d", &staff);
                    godeadBuffer

                    printf("请输入的操作员id是%d，确认请按回车,按其他键表示重新输入操作员\n", staff);
                    mode = getchar();
                    godeadBuffer
                    if (mode == '\n') {
                        break;
                    }

                }
                totalPrice = number * price;
                printf("请核对下面输入信息\n");
                printf("商品编号:%d 商品名:%s 类型:%d\n库存:%d 单价:%lf总价:%lf\n最近一次入库时间:%s 最近一次出库时间:%s 供应商:%d 最近一次操作员:%d\n",
                       id, name, classId, number, price, totalPrice,
                       inDate, outDate, supplier, staff);
                printf("确认请按回车,其他键表示撤销此次录入\n");
                mode = getchar();
                godeadBuffer
                if (mode == '\n') {
                    goods->id = id;
                    strcpy(goods->name, name);
                    goods->classId = classId;
                    goods->number = number;
                    goods->price = price;
                    goods->totalPrice = totalPrice;
                    strcpy(goods->inDate, inDate);
                    strcpy(goods->outDate, outDate);
                    goods->supplier = supplier;
                    goods->staff = staff;
                    printf("录入成功\n");
                    controlLog(staff, id, 3);
                    printf("继续操作请按回车，返回菜单按其他键\n");
                    mode = getchar();
                    godeadBuffer
                    if (mode != '\n') {
                        if (exportCommodityLink(repertory) < 0) {
                            printf("导入到文本失败");
                        }
                        printf("导入到文本中成功");
                        return 1;
                    }
                }

            }
        } else if (mode == '3') {
            if (exportCommodityLink(repertory) < 0) {
                printf("导入到文本失败\n");
            }
            printf("导入到文本中成功\n");
            return 1;
            //退回菜单
        } else {
            printf("输入有误:你刚刚输入的是%d,请检查你的输入格式\n", mode);
        }
    }

}


//删除商品信息
int delReportory(commodityLink *repertory) {

    int staff;
    int mode;
    char name[80];
    int id;
    commodityLink *goods, *pre;

    while (1) {
        printf("╭──────────────────────────────────────────────╮\n");
        printf("│ ◎ ○ ○            删除商品的信息               │\n");
        printf("├──────────────────────────────────────────────┤\n");
        printf("│                                              │\n");
        printf("│                1:根据商品ID删除               │\n");
        printf("│                2:根据商品名字删除             │\n");
        printf("│                3:退回菜单                    │\n");
        printf("│                                              │\n");
        printf("└──────────────────────────────────────────────┘\n");
        printf("请输入请输入需要的功能的对于序号并回车,如1\n");
        scanf("%d", &mode);
        godeadBuffer

        if (mode == 1) {
            pre = repertory;
            goods = repertory->next;
            printf("输入我你要删除的商品ID,如:1\n");
            scanf("%d", &id);
            godeadBuffer

            while (goods->id != id) {
                pre = goods;
                goods = goods->next;
                if (goods == NULL) {
                    printf("你输入的是%d，找不到该商品\n", id);
                    break;
                }
            }
            if (goods != NULL) {
                printf("商品编号:%d    商品名:%s    类型:%d\n库存:%d    单价:%lf\n最近一次入库时间:%s    最近一次出库时间:%s\n最近一次供应商:%d    最近一次操作员:%d\n",
                       goods->id, goods->name, goods->classId, goods->number, goods->price,
                       goods->inDate, goods->outDate, goods->supplier, goods->staff);
                printf("确认删除请按回车，其他键撤销操作\n");
                mode = getchar();
                godeadBuffer
                if (mode == '\n') {
                    printf("请输入操作员ID,如:1\n");
                    scanf("%d", &staff);
                    godeadBuffer
                    controlLog(staff, goods->id, 4);
                    pre->next = goods->next;
                    free(goods);
                    printf("删除成功\n");
                }
            }
        } else if (mode == 2) {
            pre = repertory;
            goods = repertory->next;
            printf("输入我你要删除的商品名字,如:飞机\n");
            scanf("%s", name);
            godeadBuffer
            while (strcmp(goods->name, name)) {
                pre = goods;
                goods = goods->next;
                if (goods == NULL) {
                    printf("你输入的是%s，找不到该商品\n", name);
                    break;
                }
            }
            if (goods != NULL) {
                printf("商品编号:%d    商品名:%s    类型:%d\n库存:%d    单价:%lf    总价:%lf\n 最近一次入库时间:%s    最近一次出库时间:%s    最近一次供应商:%d    最近一次操作员:%d\n",
                       goods->id, goods->name, goods->classId, goods->number, goods->price, goods->totalPrice,
                       goods->inDate, goods->outDate, goods->supplier, goods->staff);
                printf("确认删除请按回车，其他键撤销操作\n");
                mode = getchar();
                godeadBuffer
                if (mode == '\n') {
                    printf("请输入操作员ID,如:1\n");
                    scanf("%d", &staff);
                    godeadBuffer
                    controlLog(staff, goods->id, 4);
                    pre->next = goods->next;
                    free(goods);
                    printf("删除成功\n");
                }
            }

        } else if (mode == 3) {
            if (exportCommodityLink(repertory) < 0) {
                printf("导入到文本失败\n");
            }
            printf("导入到文本中成功\n");
            return 1;
            //退回菜单
        } else {
            printf("你刚刚输入的是%d,请检查你的输入格式\n", mode);
        }
    }

}


//排序方式
int sortReportory(commodityLink *repertory) {

    int mode;
    commodityLink *a, *b;

    while (1) {
        printf("╭──────────────────────────────────────────────╮\n");
        printf("│ ◎ ○ ○            对商品信息排序               │\n");
        printf("├──────────────────────────────────────────────┤\n");
        printf("│                                              │\n");
        printf("│                1:按商品id排序                 │\n");
        printf("│                2:按商品类型排序                │\n");
        printf("│                3:按商品数量排序                │\n");
        printf("│                4:按商品价格排序                │\n");
        printf("│                5:按商品总价排序                │\n");
        printf("│                6:按商品入库时间排序            │\n");
        printf("│                7:按商品出库时间排序            │\n");
        printf("│                8:按商品供货商排序              │\n");
        printf("│                9:按商品操作员排序              │\n");
        printf("│                q:返回菜单                     │\n");
        printf("│                                              │\n");
        printf("└──────────────────────────────────────────────┘\n");
        printf("请输入请输入需要的功能的对于序号并回车,如1\n");
        while ((mode = getchar()) == '\n') {}
        godeadBuffer
        if (mode == '1') {
            a = repertory->next;
            for (; a->next != NULL; a = a->next) {
                for (b = a->next; b != NULL; b = b->next) {
                    if (a->id >= b->id) {
                        swapFoods(a, b);
                    }
                }
            }
            printf("排序完毕\n");
            return 1;
        } else if (mode == '2') {
            a = repertory->next;
            for (; a->next != NULL; a = a->next) {
                for (b = a->next; b != NULL; b = b->next) {
                    if (a->classId >= b->classId) {
                        swapFoods(a, b);
                    }
                }
            }
            printf("排序完毕\n");
            return 1;
        } else if (mode == '3') {
            a = repertory->next;
            for (; a->next != NULL; a = a->next) {
                for (b = a->next; b != NULL; b = b->next) {
                    if (a->number >= b->number) {
                        swapFoods(a, b);
                    }
                }
            }
            printf("排序完毕\n");
            return 1;
        } else if (mode == '4') {
            a = repertory->next;
            for (; a->next != NULL; a = a->next) {
                for (b = a->next; b != NULL; b = b->next) {
                    if (a->price >= b->price) {
                        swapFoods(a, b);
                    }
                }
            }
            printf("排序完毕\n");
            return 1;
        } else if (mode == '5') {
            a = repertory->next;
            for (; a->next != NULL; a = a->next) {
                for (b = a->next; b != NULL; b = b->next) {
                    if (a->totalPrice >= b->totalPrice) {
                        swapFoods(a, b);
                    }
                }
            }
            printf("排序完毕\n");
            return 1;
        } else if (mode == '6') {
            a = repertory->next;
            for (; a->next != NULL; a = a->next) {
                for (b = a->next; b != NULL; b = b->next) {
                    if ((strcmp(a->inDate, b->inDate)) > 0) {
                        swapFoods(a, b);
                    }
                }
            }
            printf("排序完毕\n");
            return 1;
        } else if (mode == '7') {
            a = repertory->next;
            for (; a->next != NULL; a = a->next) {
                for (b = a->next; b != NULL; b = b->next) {
                    if ((strcmp(a->outDate, b->outDate)) > 0) {
                        swapFoods(a, b);
                    }
                }
            }
            printf("排序完毕\n");
            return 1;
        } else if (mode == '8') {
            a = repertory->next;
            for (; a->next != NULL; a = a->next) {
                for (b = a->next; b != NULL; b = b->next) {
                    if (a->supplier >= b->supplier) {
                        swapFoods(a, b);
                    }
                }
            }
            printf("排序完毕\n");
            return 1;
        } else if (mode == '9') {
            a = repertory->next;
            for (; a->next != NULL; a = a->next) {
                for (b = a->next; b != NULL; b = b->next) {
                    if (a->staff >= b->staff) {
                        swapFoods(a, b);
                    }
                }
            }
            printf("排序完毕\n");
            return 1;
        } else if (mode == 'q') {
            return 1;
        } else {
            printf("输入有误,你输入的是%c,请检查输入\n", mode);
        }
    }
}


//统计信息
int sumReportory(commodityLink *repertory) {

    int mode;
    commodityLink *goods;
    recordLink *head, *temp, *q, *p;
    double sum;
    head = (recordLink *) malloc(sizeof(recordLink));
    head->next = NULL;
    q = head;
    sum = 0;
    p = head->next;
    while (1) {
        printf("\n");
        printf("╭──────────────────────────────────────────────╮\n");
        printf("│ ◎ ○ ○            统计商品的信息               │\n");
        printf("├──────────────────────────────────────────────┤\n");
        printf("│                                              │\n");
        printf("│                1:统计所有商品id               │\n");
        printf("│                2:统计所有商品名称              │\n");
        printf("│                3:统计所有商品类型              │\n");
        printf("│                4:统计现有商品总价格            │\n");
        printf("│                5:统计现在的供货商              │\n");
        printf("│                6:统计所有操作员ID              │\n");
        printf("│                7:返回菜单                     │\n");
        printf("│                                              │\n");
        printf("└──────────────────────────────────────────────┘\n");
        printf("请输入请输入需要的功能的对于序号并回车,如1\n");

        while ((mode = getchar()) == '\n') {}
        godeadBuffer

        goods = repertory->next;
        if (mode == '1') {
            while (goods != NULL) {
                for (p = head->next; p != NULL; p = p->next) {
                    if (p->zhengshu == goods->id) { break; }//去掉重复的
                }
                if (p == NULL) {
                    temp = (recordLink *) malloc(sizeof(recordLink));
                    temp->next = NULL;
                    temp->zhengshu = goods->id;
                    q->next = temp;
                    q = temp;
                }
                goods = goods->next;
            }
            printf("目前拥有的商品id为:\n");
            for (temp = head->next; temp != NULL; temp = temp->next) {
                printf("%d    ", temp->zhengshu);
            }
        } else if (mode == '2') {
            while (goods != NULL) {
                for (p = head->next; p != NULL; p = p->next) {
                    if (strcmp(p->zifu, goods->name) == 0) { break; }
                }
                if (p == NULL) {
                    temp = (recordLink *) malloc(sizeof(recordLink));
                    temp->next = NULL;
                    strcpy(temp->zifu, goods->name);
                    q->next = temp;
                    q = temp;
                }
                goods = goods->next;
            }
            printf("目前拥有的商品名称为:\n");

            for (temp = head->next; temp != NULL; temp = temp->next) {
                printf("%s    ", temp->zifu);
            }
        } else if (mode == '3') {
            while (goods != NULL) {
                for (p = head->next; p != NULL; p = p->next) {
                    if (p->zhengshu == goods->classId) { break; }
                }
                if (p == NULL) {
                    temp = (recordLink *) malloc(sizeof(recordLink));
                    temp->next = NULL;
                    temp->zhengshu = goods->classId;
                    q->next = temp;
                    q = temp;
                }
                goods = goods->next;
            }
            printf("目前拥有的商品种类为:\n");

            for (temp = head->next; temp != NULL; temp = temp->next) {
                printf("%d    ", temp->zhengshu);
            }
        } else if (mode == '4') {
            sum = 0;
            while (goods != NULL) {
                sum = sum + goods->totalPrice;
                goods = goods->next;
            }
            printf("目前拥有的商品总价为:\n");
            printf("%lf    ", sum);

        } else if (mode == '5') {
            while (goods != NULL) {
                for (p = head->next; p != NULL; p = p->next) {
                    if (p->zhengshu == goods->supplier) { break; }
                }
                if (p == NULL) {
                    temp = (recordLink *) malloc(sizeof(recordLink));
                    temp->next = NULL;
                    temp->zhengshu = goods->supplier;
                    q->next = temp;
                    q = temp;
                }
                goods = goods->next;
            }
            printf("目前拥有的商品供应商为:\n");

            for (temp = head->next; temp != NULL; temp = temp->next) {
                printf("%d    ", temp->zhengshu);
            }
        } else if (mode == '6') {
            while (goods != NULL) {
                for (p = head->next; p != NULL; p = p->next) {
                    if (p->zhengshu == goods->staff) { break; }
                }
                if (p == NULL) {
                    temp = (recordLink *) malloc(sizeof(recordLink));
                    temp->next = NULL;
                    temp->zhengshu = goods->staff;
                    q->next = temp;
                    q = temp;
                }
                goods = goods->next;
            }
            printf("目前拥有的操作员为:\n");

            for (temp = head->next; temp != NULL; temp = temp->next) {
                printf("%d    ", temp->zhengshu);
            }
        } else if (mode == '7') {
            return 1;
        } else {
            printf("你输入的是%c,请检查输入格式\n", mode);
        }
    }
}


//查看供应商信息
int printfSupplier(supplierLink *boss) {
    int mode;
    int id;
    char name[80];
    char phone[12];
    supplierLink *king;
    while (1) {
        printf("╭──────────────────────────────────────────────╮\n");
        printf("│ ◎ ○ ○            查看供应商的信息             │\n");
        printf("├──────────────────────────────────────────────┤\n");
        printf("│                                              │\n");
        printf("│                1:根据供应商ID查询             │\n");
        printf("│                2:根据供应商名字查询           │\n");
        printf("│                3:退回菜单                     │\n");
        printf("│                                              │\n");
        printf("└──────────────────────────────────────────────┘\n");
        printf("请输入请输入需要的功能的对于序号并回车,如1\n");


        scanf("%d", &mode);
        godeadBuffer

        if (mode == 1) {
            king = boss->next;
            printf("输入你要查询的供应商ID,输入格式:1\n");
            scanf("%d", &id);
            godeadBuffer

            while (king->id != id) {
                king = king->next;
                if (king == NULL) {
                    printf("你输入的是%d，找不到该供应商\n", id);
                    break;
                }
            }
            if (king != NULL) {
                printf("供应商编号:%d    供应商名字:%s    供应商电话:%s\n", king->id, king->name, king->phone);
            }

        } else if (mode == 2) {
            king = boss->next;
            printf("输入你要查询的供应商名字,输入格式:飞机\n");
            scanf("%s", name);
            godeadBuffer
            while (strcmp(king->name, name)) {
                king = king->next;
                if (king == NULL) {
                    printf("你输入的是%s，找不到该供应商\n", name);
                    break;
                }
            }
            if (king != NULL) {
                printf("供应商编号:%d    供应商名字:%s    供应商电话:%s\n", king->id, king->name, king->phone);
            }

        } else if (mode == 3) {
            return 1;
            //退回菜单
        } else {
            printf("输入有误:你刚刚输入的是%d,请检查你的输入\n", mode);
        }
    }
}

//查看员工信息
int printfStaff(staffLink *boy) {
    int mode;
    int id;
    char phone[12];
    staffLink *person;

    while (1) {
        printf("╭──────────────────────────────────────────────╮\n");
        printf("│ ◎ ○ ○            查看员工的信息               │\n");
        printf("├──────────────────────────────────────────────┤\n");
        printf("│                                              │\n");
        printf("│                1:根据员工ID查询               │\n");
        printf("│                2:退回菜单                     │\n");
        printf("│                                              │\n");
        printf("└──────────────────────────────────────────────┘\n");
        printf("请输入请输入需要的功能的对于序号并回车,如1\n");


        scanf("%d", &mode);
        godeadBuffer

        if (mode == 1) {
            person = boy->next;
            printf("输入你要查询的员工ID,输入格式:1\n");
            scanf("%d", &id);
            godeadBuffer

            while (person->id != id) {
                person = person->next;
                if (person == NULL) {
                    printf("你输入的是%d，找不到该员工\n", id);
                    break;
                }
            }
            if (person != NULL) {
                printf("员工编号:%d    员工电话:%s\n", person->id, person->phone);
            }

        } else if (mode == 2) {
            return 1;
            //退回菜单
        } else {
            printf("输入有误:你刚刚输入的是%d,请检查你的输入\n", mode);
        }
    }

}

//导入供应商信息
int importSupplier(supplierLink *boss) {
    FILE *fp;
    supplierLink *king, *temp;
    temp = boss;
    fp = fopen("Supplier.txt", "r+");
    if (fp == NULL) {
        fp = fopen("Supplier.txt", "w");
        fclose(fp);
        fp = fopen("Supplier.txt", "a+");
        return 0;// open fail
    }
    while (!feof(fp)) {
        king = (supplierLink *) malloc(sizeof(supplierLink));
        king->next = NULL;
        fscanf(fp, "%d %s %s\n", &king->id, king->name, king->phone);
        temp->next = king;
        temp = king;
    }
    return 1;
}

//导入员工信息
int importStaff(staffLink *boy) {
    FILE *fp;
    staffLink *person, *temp;
    temp = boy;
    fp = fopen("staff.txt", "r+");
    if (fp == NULL) {
        fp = fopen("staff.txt", "w");
        fclose(fp);
        fp = fopen("staff.txt", "a+");
        return 0;// open fail
    }
    while (!feof(fp)) {
        person = (staffLink *) malloc(sizeof(staffLink));
        person->next = NULL;
        fscanf(fp, "%d %s\n", &person->id, person->phone);
        temp->next = person;
        temp = person;
    }
    return 1;
}
