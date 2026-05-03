# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I./src
TARGET = lab3_task3

# Директории
SRCDIR = src
OBJDIR = obj

# Исходные файлы
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))

# Правило по умолчанию
all: $(TARGET)

# Компоновка исполняемого файла
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

# Компиляция .c в .o
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Создание папки для объектных файлов
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Запуск программы
run: $(TARGET)
	./$(TARGET)

# Очистка
clean:
	rm -rf $(OBJDIR) $(TARGET)

# PHONY цели
.PHONY: all run clean
