all: temp_stat

temp_stat: main.o temp_api.o show_help.o parse_args.o show_help.o
	gcc -o temp_stat main.o temp_api.o parse_args.o show_help.o

main.o: main.c temp_api.h parse_args.h
	gcc -c -o main.o main.c

parse_args.o: parse_args.c parse_args.h show_help.h
	gcc -c -o parse_args.o parse_args.c

temp_api.o: temp_api.c temp_api.h temp_struct.h
	gcc -c -o temp_api.o temp_api.c

show_help.o: show_help.c show_help.h
	gcc -c -o show_help.o show_help.c

clean:
	del /f /s /q *.o temp_stat.exe