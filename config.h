//
// Created by huangpeisong on 2017/3/18.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "allList.h"
#include "commonFunction.h"
#include "control.h"


#define godeadBuffer     setbuf(stdin, NULL);

/*commonFunction*/
extern int getTime(char *date);

extern int swapFoods(commodityLink *a, commodityLink *b);

extern void printfMenu();

extern void printfMenu_s();


/*control*/
extern int printfCommodityLink(commodityLink *repertory);

extern int importCommodityLink(commodityLink *repertory);

extern int exportCommodityLink(commodityLink *repertory);

extern int repertoryInfo(commodityLink *repertory);

extern int insertRepertory(commodityLink *repertory);

extern int editRepertory(commodityLink *repertory);

extern int delReportory(commodityLink *repertory);

extern int sortReportory(commodityLink *repertory);

extern int sumReportory(commodityLink *repertory);

extern int controlLog(int staffId, int commodityId, int play);


/*boss and boy*/
extern int printfSupplier(supplierLink *boss);

extern int printfStaff(staffLink *boy);

extern int importSupplier(supplierLink *boss);

extern int importStaff(staffLink *boy);





