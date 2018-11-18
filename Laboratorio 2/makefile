INC_DIRS = -Iinclude

CFLAGS = -c

main: obj/main.o obj/graph.o obj/route.o 
	@ gcc obj/*.o -o bin/main.out
	@ echo "The compilation has been completed successfully!"

obj/main.o: src/main.c
	@ echo "src/main.c"
	@ gcc  $(CFLAGS) $(INC_DIRS) src/main.c -o obj/main.o
obj/graph.o: src/graph.c
	@ echo "src/graph.c"
	@ gcc  $(CFLAGS) $(INC_DIRS) src/graph.c -o obj/graph.o
obj/route.o: src/route.c
	@ echo "src/route.c"
	@ gcc  $(CFLAGS) $(INC_DIRS) src/route.c -o obj/route.o

clean:
	@ clear
	@ echo "Cleaning folders.."
	@ rm -rf obj/*
	@ rm -rf bin/*
	@ rm -rf output/*