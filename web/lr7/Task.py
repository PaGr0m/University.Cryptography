import os
from ClassParallelepiped import Parallelepiped


def main_menu():
    print("1. Set values. \n"
          "2. Calculate the diagonal. \n"
          "3. Calculate the area. \n"
          "4. Calculate the volume. \n"
          "5. Show information. \n"
          "0. Exit. \n")


def main():
    parallelepiped = Parallelepiped()

    while True:
        os.system("clear")
        main_menu()
        answer = int(input("Enter the number --> "))

        if answer == 1:
            a = float(input("Enter the length = "))
            b = float(input("Enter the width = "))
            c = float(input("Enter the height = "))
            parallelepiped.set_data(length=a, width=b, height=c)
            print(parallelepiped)

        elif answer == 2:
            parallelepiped.calculate_diagonal()
            parallelepiped.print_diagonal()

        elif answer == 3:
            parallelepiped.calculate_square()
            parallelepiped.print_square()

        elif answer == 4:
            parallelepiped.calculate_amount()
            parallelepiped.print_amount()

        elif answer == 5:
            print(parallelepiped)

        elif answer == 0:
            break

        input("\n <-- Put Enter to continue -->")


if __name__ == "__main__":
    main()
