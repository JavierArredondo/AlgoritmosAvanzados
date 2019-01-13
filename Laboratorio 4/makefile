INC_DIRS = -Iinclude

CFLAGS = -c

main: obj/main.o obj/word.o obj/handler.o
	@ gcc obj/*.o -o bin/main.out
	@ echo "The compilation has been completed successfully!"

obj/main.o: src/main.c
	@ echo "src/main.c"
	@ gcc  $(CFLAGS) $(INC_DIRS) src/main.c -o obj/main.o
obj/word.o: src/word.c
	@ echo "src/word.c"
	@ gcc  $(CFLAGS) $(INC_DIRS) src/word.c -o obj/word.o
obj/handler.o: src/handler.c
	@ echo "src/handler.c"
	@ gcc  $(CFLAGS) $(INC_DIRS) src/handler.c -o obj/handler.o

clean:
	@ clear
	@ echo "Cleaning folders.."
	@ rm -rf obj/*
	@ rm -rf bin/*
	@ rm -rf output/*