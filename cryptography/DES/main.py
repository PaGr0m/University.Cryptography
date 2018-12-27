import des


des_msg = ["1111"]
des_key = ["11111111" +
           "11111111" +
           "11111111" +
           "11100111" +
           "11110111" +
           "11111111" +
           "11111111" +
           "11111111"]
print("Data: " + des_msg[0])
print("DES Key: " + des_key[0])
encrypt = des.encrypt(str(des_msg[0]), str(des_key[0]))
print("DES Encrypted: " + encrypt)
decrypt = des.decrypt(encrypt, str(des_key[0]))
print("DES Decrypted: " + decrypt)


