INC_DIRS = -Iinclude

CFLAGS = -c

main: obj/main.o obj/list.o obj/knapsack.o obj/box.o obj/handler.o
	@ gcc obj/*.o -o bin/main.out
	@ echo "The compilation has been completed successfully!"

obj/main.o: src/main.c
	@ echo "src/main.cpp"
	@ gcc  $(CFLAGS) $(INC_DIRS) src/main.c -o obj/main.o
obj/list.o: src/list.c
	@ echo "src/list.c"
	@ gcc  $(CFLAGS) $(INC_DIRS) src/list.c -o obj/list.o
obj/knapsack.o: src/knapsack.c
	@ echo "src/knapsack.c"
	@ gcc  $(CFLAGS) $(INC_DIRS) src/knapsack.c -o obj/knapsack.o
obj/box.o: src/box.c
	@ echo "src/box.c"
	@ gcc  $(CFLAGS) $(INC_DIRS) src/box.c -o obj/box.o
obj/handler.o: src/handler.c
	@ echo "src/handler.c"
	@ gcc  $(CFLAGS) $(INC_DIRS) src/handler.c -o obj/handler.o

clean:
	@ clear
	@ echo "Cleaning folders.."
	@ rm -rf obj/*
	@ rm -rf bin/*
	@ rm -rf output/*