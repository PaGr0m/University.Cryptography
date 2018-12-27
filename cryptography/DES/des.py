# @author Pavel Gromov

from collections import deque

ip_mixing_pattern = [58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4,
                     62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8,
                     57, 49, 41, 33, 25, 17, 9,  1, 59, 51, 43, 35, 27, 19, 11, 3,
                     61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7]

ip_mixing_revert_pattern = [40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31,
                            38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29,
                            36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27,
                            34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41,  9, 49, 17, 57, 25]

extend_vector_32_to_48_bit_pattern = [32, 1,  2,  3,  4,  5,
                                      4,  5,  6,  7,  8,  9,
                                      8,  9,  10, 11, 12, 13,
                                      12, 13, 14, 15, 16, 17,
                                      16, 17, 18, 19, 20, 21,
                                      20, 21, 22, 23, 24, 25,
                                      24, 25, 26, 27, 28, 29,
                                      28, 29, 30, 31, 32, 1]

mixing_p_pattern = [16, 7,  20, 21, 29, 12, 28, 17,
                    1,  15, 23, 26, 5,  18, 31, 10,
                    2,  8,  24, 14, 32, 27, 3,  9,
                    19, 13, 30, 6,  22, 11, 4,  25]

generate_subkey_64_to_56_bit_pattern = [57, 49, 41, 33, 25, 17, 9,  1,  58, 50, 42, 34, 26, 18,
                                        10, 2,  59, 51, 43, 35, 27, 19, 11, 3,  60, 52, 44, 36,
                                        63, 55, 47, 39, 31, 23, 15, 7,  62, 54, 46, 38, 30, 22,
                                        14, 6,  61, 53, 45, 37, 29, 21, 13, 5,  28, 20, 12, 4]

generate_subkey_shifts = [1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1]

generate_subkey_56_to_48_bit_pattern = [14, 17, 11, 24, 1,  5,  3,  28, 15, 6,  21, 10, 23, 19, 12, 4,
                                        26, 8,  16, 7,  27, 20, 13, 2,  41, 52, 31, 37, 47, 55, 30, 40,
                                        51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32]

S_pattern = [  # 1
            [14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
             0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
             4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
             15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13],
               # 2
            [15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
             3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
             0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
             13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9],
               # 3
            [10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
             13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
             13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
             1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12],
               # 4
            [7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
             13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
             10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
             3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14],
               # 5
            [2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
             14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
             4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
             11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3],
               # 6
            [12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
             10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
             9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
             4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13],
               # 7
            [4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
             13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
             1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
             6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12],
               # 8
            [13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
             1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
             7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
             2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11]
]


def apply_pattern(data: list, pattern: list) -> list:
    result = list()
    for index in pattern:
        result.append(data[index - 1])
    return result


def recover_to_size_of_64(message: str) -> list:
    while len(message) % 64 != 0:
        message = '0' + message
    return list(message)


def generate_subkeys(key: list) -> list:
    subkeys = list()

    subkey_56 = deque(apply_pattern(key, generate_subkey_64_to_56_bit_pattern))
    for shift in generate_subkey_shifts:
        local_subkey_56 = subkey_56
        pocket = deque()

        # Shifting to left
        while shift > 0:
            pocket.append(local_subkey_56.popleft())
            shift -= 1
        while len(pocket) > 0:
            local_subkey_56.append(pocket.pop())

        subkeys.append(apply_pattern(list(local_subkey_56), generate_subkey_56_to_48_bit_pattern))

    return subkeys


def calc_f(vector_32_bit: list, subkey_48_bit: list) -> list:
    # Extending vector 32 -> 48 bit
    vector_48_bit = apply_pattern(vector_32_bit, extend_vector_32_to_48_bit_pattern)

    result = list()

    result_32_bit = list()

    # Filling result vector
    for vector_bit, subkey_bit in zip(vector_48_bit, subkey_48_bit):
        result.append(vector_bit ^ subkey_bit)

    # Mutating of 8 S-blocks
    blocks_6_bit = list()

    # Creating 8 blocks of 6 bit length from result
    for index in range(0, len(result), 6):
        blocks_6_bit.append(result[index:index + 6])

    for index, block in enumerate(blocks_6_bit):
        first_digit = int(str(block[0]) + str(block[5]), 2)

        second_digit = int(str(''.join(map(str, block[1:5]))), 2)

        # Define 4 bit block binary code
        # 16 * first defines row
        # + second means column
        block_4_bit = bin(int(str(S_pattern[index][16 * first_digit + second_digit]), 10))[2:]

        # Write 4-bit block to result. 32 = 4 * 8
        while len(block_4_bit) < 4:
            block_4_bit = '0' + block_4_bit

        for bit in block_4_bit:
            result_32_bit.append(bit)

    # P-mixing
    result_32_bit = apply_pattern(result_32_bit, mixing_p_pattern)
    return result_32_bit


def encrypt(message: str, key: str) -> str:
    # Recovering message: right filling zeros if needed
    message = list(map(int, recover_to_size_of_64(message)))

    # Format key to list of integers
    key = list(map(int, key))

    # Calculating subkeys. Subkeys list stores 16 subkeys
    subkeys = generate_subkeys(key)

    # Mixing by IP
    message = apply_pattern(message, ip_mixing_pattern)

    # Encrypting loops: 16 times
    for subkey in subkeys:
        left = message[0:32]
        right = message[32:64]

        next_left = right
        next_right = list()

        # Next right = left XOR f(right, subkey)
        f = calc_f(right, subkey)
        for index, bit in enumerate(f):
            next_right.append(int(bit, 2) ^ left[index])

        message = list()
        # Fill the string by appending Left and Right parts
        for bit in next_left:
            message.append(bit)
        for bit in next_right:
            message.append(bit)

    # Final IP reverting
    message = apply_pattern(message, ip_mixing_revert_pattern)

    # return message
    message_str = ""

    for element in message:
        message_str += str(element)

    return message_str


def decrypt(cipher: str, key: str) -> str:
    cipher = list(map(int, cipher))
    key = list(map(int, key))

    # Calculating subkeys. Subkeys list stores 16 subkeys
    subkeys = generate_subkeys(key)

    # Mixing by IP
    cipher = apply_pattern(cipher, ip_mixing_pattern)

    for subkey in reversed(subkeys):
        left = cipher[0:32]
        right = cipher[32:64]

        next_right = left
        next_left = list()

        f = calc_f(left, subkey)
        for index, bit in enumerate(f):
            next_left.append(int(bit, 2) ^ right[index])

        cipher = list()
        for bit in next_left:
            cipher.append(bit)
        for bit in next_right:
            cipher.append(bit)

    cipher = apply_pattern(cipher, ip_mixing_revert_pattern)

    cipher_str = ""

    for element in cipher:
        cipher_str += str(element)

    return cipher_str
