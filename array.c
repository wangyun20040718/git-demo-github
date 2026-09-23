#include <stdio.h>
#include <string.h>
#include "pointer.h"
#include "test.h"
#include "array.h"
#include "struct.h"

int arrayTow[][4] = 
    {{1, 2, 3, 4}, 
     {5, 6, 7, 8}, 
     {9, 10, 11, 12}};

people_st people[] = 
    {{"ZS", 18, "BOY"},
     {"LS", 20, "BOY"},
     {"LW", 20, "girl"},
     {"WZ", 22, "girl"},
     {"LW", 19, "BOY"},
     {"WZ", 20, "girl"}};

people_st LQ = {"LQ", 20, "BOY"};
people_st LS = {"LS", 20, "BOY"};

people_st *people_p[] = {&LQ, &LS};



