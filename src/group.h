/**
 * @file group.h
 * @brief Заголовочный файл для работы со структурой GROUP
 * @author Ваше имя
 * @version 1.0
 */

#ifndef GROUP_H
#define GROUP_H

#define MAX_NAME 50
#define MAX_STUDENTS 10
#define SUBJECTS_COUNT 3

/**
 * @struct DATE
 * @brief Структура для хранения даты
 */
typedef struct {
    int year;   /**< Год */
    int month;  /**< Месяц (1-12) */
    int day;    /**< День (1-31) */
} DATE;

/**
 * @struct GROUP
 * @brief Структура для хранения информации о студенте
 */
typedef struct {
    char Name[MAX_NAME];     /**< Фамилия и инициалы */
    DATE DAT;                /**< Дата рождения */
    int SES[SUBJECTS_COUNT]; /**< Успеваемость (массив из трёх оценок) */
} GROUP;

/**
 * @brief Ввод одной записи о студенте с клавиатуры
 * @param g Указатель на структуру GROUP для заполнения
 */
void inputGroup(GROUP *g);

/**
 * @brief Вывод одной записи о студенте на экран
 * @param g Указатель на структуру GROUP для вывода
 */
void printGroup(const GROUP *g);

/**
 * @brief Вычисление суммы оценок студента
 * @param g Указатель на структуру GROUP
 * @return Сумма трёх оценок
 */
int getSESSum(const GROUP *g);

/**
 * @brief Функция сравнения для qsort по возрастанию суммы оценок
 * @param a Указатель на первый элемент
 * @param b Указатель на второй элемент
 * @return Отрицательное, если a < b; положительное, если a > b; 0 если равны
 */
int compareBySES(const void *a, const void *b);

/**
 * @brief Проверка, был ли студент младше или равен 20 лет на 01.12.2010
 * @param g Указатель на структуру GROUP
 * @return 1 если возраст <= 20, иначе 0
 */
int isYoungerOrEqual20(const GROUP *g);

/**
 * @brief Вычисление возраста студента на заданную дату
 * @param birth Дата рождения
 * @param targetDate Целевая дата
 * @return Количество полных лет
 */
int calculateAge(const DATE *birth, const DATE *targetDate);

#endif /* GROUP_H */
