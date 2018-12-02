import math
import random
import os


def main_menu():
    print("1. Дан диаметр окружности d. Найти ее длину L = π·d. В качестве значения π использовать 3.14.")
    print("2. Даны три целых числа. Найти количество положительных чисел в исходном наборе.")
    print("3. Дан номер месяца — целое число в диапазоне 1–12 (1 — январь, 2 — февраль и т. д.). "
          "Определить количество дней в этом месяце для невисокосного года.")
    print("4. Дано вещественное число — цена 1 кг конфет. Вывести стоимость 1, 2, ..., 10 кг конфет.")
    print("5. Дано целое число N (> 0). "
          "Если оно является степенью числа 3, то вывести True, если не является — вывести False.")
    print("6. Описать процедуру TrianglePS(a, P, S), "
          "вычисляющую по стороне a равностороннего треугольника его "
          "периметр P = 3·a и площадь S = a^2*sqrt(3)/4 "
          "(a — входной, P и S — выходные параметры; "
          "все параметры являются вещественными).")
    print("7. Дано целое число N и набор из N чисел. Найти номер минимального элемента из данного набора.")
    print("8. Дано целое число N (> 1), а также первый член A и знаменатель D геометрической прогрессии. "
          "Сформировать и вывести массив размера N, содержащий N первых членов данной прогрессии: "
          "A, A·D, A·D^2 , A·D^3 , ... .")
    print("9. Дан массив размера N и целые числа K и L (1 ≤ K ≤ L ≤ N)."
          " Найти среднее арифметическое элементов массива с номерами от K до L включительно.")
    print("10. Дан массив размера N. Поменять местами его минимальный и максимальный элементы.")
    print("11. Дана строка. Преобразовать в ней все прописные латинские буквы в строчные.")
    print("\n")


def task_1(diameter: float) -> float:
    """
    Begin4:
    Дан диаметр окружности d.
    Найти ее длину L = π·d.
    В качестве значения π использовать 3.14.

    :param diameter: диаметр окружности
    :return: длина окружности
    """

    return math.pi * float(diameter)


def task_2(a: int, b: int, c: int) -> int:
    """
    If4:
    Даны три целых числа.
    Найти количество положительных чисел в исходном наборе.

    :param a: первое число
    :param b: второе число
    :param c: третье число
    :return: количество положительных чисел
    """

    count = 0
    if (a > 0):
        count += 1
    if (b > 0):
        count += 1
    if (c > 0):
        count += 1

    return count


def task_3(month: int) -> int:
    """
    Case4:
    Дан номер месяца — целое число в диапазоне 1–12 (1 — январь, 2 — февраль и т. д.).
    Определить количество дней в этом месяце для невисокосного года.

    :param month: месяц
    :return: количество дней в месяце
    """

    list_day_31 = [1, 3, 5, 7, 8, 10, 12]
    list_day_30 = [4, 6, 9, 11]

    if month in list_day_31:
        return 31
    elif month in list_day_30:
        return 30
    elif month == 2:
        return 28
    else:
        print("Error month")
        return None


def task_4(price: float) -> None:
    """
    For4:
    Дано вещественное число — цена 1 кг конфет.
    Вывести стоимость 1, 2, ..., 10 кг конфет.

    :param price: цена
    :return: стоимость
    """

    price_list = []

    for idx in range(10):
        price_list.append(idx * price)

    print(price_list)


def task_5(number: int) -> bool:
    """
    While4:
    Дано целое число N (> 0).
    Если оно является степенью числа 3, то вывести True, если не является — вывести False.

    :param number: число
    :return: True/False
    """

    counter = 1
    if number == 1:
        return True
    else:
        while counter < number:
            counter *= 3
            if counter == number:
                return True
    return False


def triangle_ps(a: float) -> tuple:
    perimeter = 3 * a
    square = math.pow(a, 2) * math.sqrt(3) / 4

    return perimeter, square


def task_6(side: float):
    """
    Proc4°:
    Описать процедуру TrianglePS(a, P, S), вычисляющую по стороне a
    равностороннего треугольника его периметр P = 3·a и площадь S = a^2*sqrt(3)/4
    (a — входной, P и S — выходные параметры; все параметры являются вещественными).
    С помощью этой процедуры найти периметры и площади трех равносторонних треугольников с данными сторонами.

    :param side: сторона треугольника
    :return: периметр, площадь
    """

    perimeter, square = triangle_ps(side)
    print(perimeter)
    print(square)


def task_7(array: list) -> int:
    """
    Minmax4:
    Дано целое число N и набор из N чисел.
    Найти номер минимального элемента из данного набора.

    :param array: массив элементов
    :return: номер минимального элемента
    """

    minimum, idx_min = min((array[i], i) for i in range(len(array)))

    return idx_min


def task_8(count: int, term: float, denominator: int) -> list:
    """
    Array4:
    Дано целое число N (> 1), а также первый член A и знаменатель D геометрической прогрессии.
    Сформировать и вывести массив размера N, содержащий N первых членов данной прогрессии:
    A, A·D, A·D^2 , A·D^3 , ... .

    :param count: количество элементов
    :param term: первый член прогрессии
    :param denominator: знаменатель прогрессии
    :return: массив элементов
    """

    array = []

    for i in range(0, count):
        array.append(term * math.pow(denominator, i))

    return array


def task_9(array: list, begin: int, end: int) -> int:
    """
    Array21.
    Дан массив размера N и целые числа K и L (1 ≤ K ≤ L ≤ N).
    Найти среднее арифметическое элементов массива с номерами от K до L включительно.

    :param array: массив элементов
    :param begin: левая граница
    :param end: правая граница
    :return: среднее арифметическое
    """

    average = 0

    for element in array[begin:end+1]:
        average += element

    average /= (end - begin + 1)

    return average


def task_10(array: list) -> list:
    """
    Array68:
    Дан массив размера N.
    Поменять местами его минимальный и максимальный элементы.

    :param array: начальный массив
    :return: измененный массив
    """

    minimum, idx_min = min((array[i], i) for i in range(len(array)))
    maximum, idx_max = max((array[i], i) for i in range(len(array)))

    array[idx_min] = maximum
    array[idx_max] = minimum

    return array


def task_11(string: str) -> str:
    """
    String16:
    Дана строка.
    Преобразовать в ней все прописные латинские буквы в строчные.

    :param string: начальная строка
    :return: измененная строка
    """

    return string.lower()


""" MAIN """
if __name__ == "__main__":
    while True:
        os.system("clear")
        main_menu()

        answer = int(input("Enter the task number >> "))

        if answer == 1:
            print(task_1.__doc__)
            print(task_1(float(input("Enter the diameter --> "))))
        elif answer == 2:
            print(task_2.__doc__)
            print(task_2(int(input("Enter the first number --> ")),
                         int(input("Enter the second number --> ")),
                         int(input("Enter the third number --> "))))
        elif answer == 3:
            print(task_3.__doc__)
            print(task_3(int(input("Enter the month --> "))))
        elif answer == 4:
            print(task_4.__doc__)
            print(task_4(float(input("Enter the price --> "))))
        elif answer == 5:
            print(task_5.__doc__)
            print(task_5(int(input("Enter the number --> "))))
        elif answer == 6:
            print(task_6.__doc__)
            print(task_6(float(input("Enter the side of treangle --> "))))
        elif answer == 7:
            print(task_7.__doc__)
            number = int(input("Enter the number --> "))
            array = []
            for el in range(number):
                array.append(random.randint(-20, 20))
            print(array)
            print(task_7(array))
        elif answer == 8:
            print(task_8.__doc__)
            print(task_8(int(input("Enter the count --> ")),
                         float(input("Enter the term --> ")),
                         int(input("Enter the denominator --> "))))
        elif answer == 9:
            print(task_9.__doc__)
            number = int(input("Enter the number --> "))
            array = []
            for el in range(number):
                array.append(random.randint(-20, 20))
            K = int(input("Enter the start of array --> "))
            L = int(input("Enter the end of array --> "))
            print(array)
            print(task_9(array, K, L))
        elif answer == 10:
            print(task_10.__doc__)
            number = int(input("Enter the number --> "))
            array = []
            for el in range(number):
                array.append(random.randint(-20, 20))
            print(array)
            print(task_10(array))
        elif answer == 11:
            print(task_11.__doc__)
            print(task_11(input("Enter the string --> ")))
        else:
            print("Error")

        input("\n <-- Put Enter to continue -->")
