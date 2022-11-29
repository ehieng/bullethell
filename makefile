main:
	g++ -Iinclude -Llib src/glad.c src/main.cpp -lglfw3dll -o myprogram
	
linux:
	g++ src/glad.c src/main.cpp -Iinclude -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl -o main