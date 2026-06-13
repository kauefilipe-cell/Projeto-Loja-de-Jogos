# Nome do executável
TARGET = programa

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -g

# Arquivos fonte
SRC = menuPrincipal.c biblioteca/arquivoTXT.c

# Objeto (não precisa alterar, é automático)
OBJ = $(SRC:.c=.o)

#------------------- REGRAS -------------------

# Compile tudo
all: $(TARGET)

# Cria o executável
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# Compila cada arquivo .c para .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa arquivos compilados
clean:
	rm -f *.o biblioteca/*.o $(TARGET)

# Executa o programa
run: $(TARGET)
	./$(TARGET)

# Debug com gdb
debug: $(TARGET)
	gdb $(TARGET)

#------------------- AJUDA -------------------
help:
	@echo "Comandos disponíveis:"
	@echo "  make      - Compilar o programa"
	@echo "  make run  - Compilar e executar"
	@echo "  make clean - Limpar arquivos compilados"
	@echo "  make help - Mostrar esta ajuda"