/**
 * Demo of struct declaration
 *
 */
#include <stdio.h>

struct car {
    char *model;
    char *vendor;
    int year;
};

struct acar {
    int year;
    char *model;
    char *vendor;
};

int main(int argc, char *argv[])
{
    /* .field可以指定struct中的某一个属性进行初始化 */
    struct car c1 = {
        .vendor = "Audi",
        .model = "A7",
        .year = 2007
    };

    /* 按照struct中属性的声明顺序进行初始化 */
    struct car c2 = {"750Li", "BMW", 2010};

    printf("car c1: {model: %s, vendor: %s, year: %d}\n", c1.model, c1.vendor, c1.year);
    printf("car c2: {model: %s, vendor: %s, year: %d}\n", c2.model, c2.vendor, c2.year);
    printf("\n");

    printf("Struct pointer casting:\n");
    /** A pointer to a struct can be cast to a pointer to its first member and vice versa **/

    struct car *pcar1 = &c1;
    /* pmodel points to the first field of struct car, model, which type is char*, thus pmodel is a pointer to char* */
    char **pmodel = (char**)&c1;
    printf("*pmodel: %s, pcar1->model: %s\n", *pmodel, pcar1->model);


    struct acar c3 = {2088, "K5", "Qiya"};
    struct acar *pcar3 = &c3;
    int *pyear = (int*)pcar3;
    printf("*pyear: %d, pcar3->year:%d \n", *pyear, pcar3->year);

    return 0;
}






