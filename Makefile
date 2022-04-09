all: temp_stat

temp_stat: main.o temp_api.o
	gcc -o temp_stat main.o temp_api.o

main.o: main.c temp_api.h
	gcc -c -o main.o main.c

temp_api.o: temp_api.c temp_api.h temp_struct.h
	gcc -c -o temp_api.o temp_api.c

clean:
	del /f /s /q *.o temp_stat.exe