name = pond
compile: main.c 
	 gcc main.c -o $(name)

run: $(name)
	 ./$(name)

clean: $(name)
	 rm $(name)
