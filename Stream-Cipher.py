def generate_keystream(key, text_length):
    key = bytearray(key, 'utf-8')
    keystream = bytearray()

    while len(keystream) < text_length:
        keystream.extend(key)

    return keystream[:text_length]



def encrypt_decrypt(text, keystream):
    encrypted_text = bytearray()
    for i in range(len(text)):
        encrypted_text.append(text[i] ^ keystream[i])

    return encrypted_text



def main():
    plaintext = input("\nMasukkan plaintext(Ketikkan huruf kapital untuk dapat melihat enkripsi): ")
    key = input("Masukkan kunci: ")

    text_length = len(plaintext.encode('utf-8'))
    keystream = generate_keystream(key, text_length)

    # Konversi plaintext dan keystream ke dalam bentuk byte arrays
    plaintext_bytes = bytearray(plaintext, 'utf-8')
    encrypted_text = encrypt_decrypt(plaintext_bytes, keystream)

    encrypted_hex = encrypted_text.hex() 
    encrypted_hex2 = bytes.fromhex(encrypted_hex)
    encrypted_hex_final = encrypted_hex2.decode('utf-8')
    # Ubah byte array ke bentuk string heksadesimal
    print("\n")
    print("Teks Terenkripsi (dalam heksadesimal):", encrypted_hex)
    print("Teks Terenkripsi (dalam karakter):", encrypted_hex_final)

    # Mengonversi kembali dari string heksadesimal ke byte array
    decrypted_bytes = bytes.fromhex(encrypted_hex)
    decrypted_text = encrypt_decrypt(decrypted_bytes, keystream)

    print("Teks Terdekripsi: ", decrypted_text.decode('utf-8'))
    print("\n")
    
if __name__ == "__main__":
    main()
