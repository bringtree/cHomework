#include "config.h"


int main() {
    commodityLink *repertory;
    staffLink *boyLink;
    supplierLink *bossLink;
    int menuType;
    int mode;

    /*init repertory*/

    repertory = (commodityLink *) malloc(sizeof(commodityLink));
    repertory->next = NULL;
    boyLink = (staffLink *) malloc(sizeof(staffLink));
    boyLink->next = NULL;
    bossLink = (supplierLink *) malloc(sizeof(supplierLink));
    bossLink->next = NULL;

    importSupplier(bossLink);
    importStaff(boyLink);

    /*init end*/



    printf("╭───────────────────────────────────────────────╮\n");
    printf("│ ◎ ○ ○          商品进销存系统v0.1              │\n");
    printf("├───────────────────────────────────────────────┤\n");
    printf("│                                               │\n");
    printf("│            正在加载commodity.txt数据中...      │\n");
    printf("│                                               │\n");
    printf("└───────────────────────────────────────────────┘\n");
    menuType = importCommodityLink(repertory);
    if (menuType == 1) {

        printf("╭───────────────────────────────────────────────╮\n");
        printf("│ ◎ ○ ○          商品进销存系统v0.1              │\n");
        printf("├───────────────────────────────────────────────┤\n");
        printf("│                                               │\n");
        printf("│            commodity.txt的数据加载完毕         │\n");
        printf("│                                               │\n");
        printf("└───────────────────────────────────────────────┘\n");

    } else {
        printf("╭───────────────────────────────────────────────╮\n");
        printf("│ ◎ ○ ○          商品进销存系统v0.1              │\n");
        printf("├───────────────────────────────────────────────┤\n");
        printf("│                                               │\n");
        printf("│            commodity.txt的数据加载失败         │\n");
        printf("│            重新创建commodity.txt新文件         │\n");
        printf("│                                               │\n");
        printf("└───────────────────────────────────────────────┘\n");

    }
    while (1) {
        if (menuType == 1) {
            printfMenu();
        } else {
            printfMenu_s();
            menuType = 1;
        }

        printf("请输入需要的功能的对于序号并回车,如1\n");

        while ((mode = getchar()) == '\n') {}
        godeadBuffer

        if (mode == '1') {
            /*录入商品信息*/
            if (!insertRepertory(repertory)) {
                break;
            }


        } else if (mode == '2') {
            /*根据商品ID/name查询*/
            if (!repertoryInfo(repertory)) {
                break;
            }


        } else if (mode == '3') {
            /*查找修改商品信息*/
            if (!editRepertory(repertory)) {
                break;
            }

        } else if (mode == '4') {
            /*删除商品信息*/
            if (!delReportory(repertory)) {
                break;
            }
        } else if (mode == '5') {
            /*统计信息*/
            if (!sumReportory(repertory)) {
                break;
            }

        } else if (mode == '6') {
            /*商品排序*/
            if (!sortReportory(repertory)) {
                break;
            }

        } else if (mode == '7') {
            /*输出链表*/
            if (!printfCommodityLink(repertory)) {
                break;
            }

        } else if (mode == '8') {
            /*供应商信息*/
            if (!printfSupplier(bossLink)) {
                break;
            }

        } else if (mode == '9') {
            /*导入员工信息*/
            if (!printfStaff(boyLink)) {
                break;
            }
        } else if (mode == 'q') {
                break;
        } else {
            printf("输入有误:你输入的是%c,请检查输入\n", mode);
        }

    }
    return 0;
}
