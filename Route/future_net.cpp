#include "route.h"
#include "lib_io.h"
#include "lib_time.h"
#include "stdio.h"

int main(int argc, char *argv[])
{
    print_time("Begin");
    char *topo[5000];

    int demand_num;

    demand_num = read_file(topo, 5000, "demand.csv");

    search_route(topo, demand_num);

    //char *result_file = argv[3];
    write_result("result.csv");
    release_buff(topo, demand_num);
    //release_buff(&demand, 1);

    print_time("End");

	return 0;
}

