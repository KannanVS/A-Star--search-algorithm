HEADERS = list.h map.h status.h

default = map

aStar.o: aStar.c
	cc -c aStar.c

list.o: list.c
	cc -c list.c

main.o: main.c
	cc -c main.c

map.o: map.c
	cc -c map.c

status.o: status.c
	cc -c status.c

map: aStar.o list.o main.o map.o status.o
	cc -o map aStar.o list.o main.o map.o status.o

clean:
	rm *.o
	rm map

output:
	./map StartCity GoalCity

