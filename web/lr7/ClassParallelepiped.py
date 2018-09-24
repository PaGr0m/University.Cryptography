import math


class Parallelepiped:

    def __init__(self):
        self.length = 0
        self.width = 0
        self.height = 0

        self.square = 0
        self.amount = 0
        self.diagonal = 0

    # def __init__(self, length, width, height):
    #     self.length = length
    #     self.width = width
    #     self.height = height
    #
    #     self.square = 0
    #     self.amount = 0
    #     self.diagonal = 0

    def __str__(self):
        return "A = {}\n" \
               "B = {}\n" \
               "C = {}".format(self.length,
                               self.width,
                               self.height)

    def set_data(self, length, width, height):
        self.length = length
        self.width = width
        self.height = height

    def calculate_diagonal(self):
        if self.length != 0 and self.width != 0 and self.height != 0:
            self.diagonal = math.sqrt(
                                math.pow(self.length, 2) +
                                math.pow(self.width, 2) +
                                math.pow(self.height, 2))
        return self.diagonal

    def calculate_square(self):
        self.square = 2 * (self.length*self.width + self.length*self.height + self.width*self.height)
        return self.square

    def calculate_amount(self):
        self.amount = self.length*self.width*self.height
        return self.amount

    def print_diagonal(self):
        print("Diagonal = {}".format(self.diagonal))

    def print_amount(self):
        print("V = {}".format(self.amount))

    def print_square(self):
        print("S = {}".format(self.square))
