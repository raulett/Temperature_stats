#include <stdio.h>
#include "show_help.h"

void show_help(){
    printf("usage: temp_stat.exe [option] ... [-h | -f inputfile_path -y year [?:\\-m month] -s [avg|min|max]\n");
    printf("Options:\n");
    printf("-h              :Shows this help messege\n");
    printf("-f <input_file> :Argument to specify input file name. Tool works works with semicolon separated text files.\n");
    printf("-s <stat>       :Argument to specify statistics type. Statistics type: avg, min, max\n");
    printf("-y <year>       :Argument to specify year to get statistics. Year format is YYYY: 2021\n");
    printf("-m <month>      :Argument to specify month to get statistics. month format is mm: 06, 11\n");
    printf("Examples:\n");
    printf("    temp_stat.exe -h (shows this help)\n");
    printf("    temp_stat.exe -f in_file.txt -s avg -y 2021 (shows average temepature for 2021 year, from file in_file.txt)\n");
    printf("    temp_stat.exe -f in_file.txt -s min -y 2021 -m 06(shows min temepature in June 2021 year, from file in_file.txt)\n");
    printf("    temp_stat.exe -f in_file.txt -s max -y 2021 -m 12(shows max temepature in December 2021 year, from file in_file.txt)\n");    
}