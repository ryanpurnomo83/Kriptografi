using System;

class BlockCipherExample
{
    static void Main()
    {
        try
        {
            Console.WriteLine("Masukkan plaintext (huruf atau karakter): ");
            string plaintext = Console.ReadLine();

            Console.WriteLine("Masukkan key (huruf atau karakter): ");
            string key = Console.ReadLine();

            Console.WriteLine("Masukkan jumlah pergeseran bit: ");
            int bitShift = Convert.ToInt32(Console.ReadLine());

            string encryptedText = Encrypt(plaintext, key, bitShift);
            string decryptedText = Decrypt(encryptedText, key, bitShift);

            Console.WriteLine($"Plaintext: {plaintext}");
            Console.WriteLine($"Encrypted: {encryptedText}");
            Console.WriteLine($"Decrypted: {decryptedText}");
        }
        catch (Exception e)
        {
            Console.WriteLine($"Error: {e.Message}");
        }
    }

    static string Encrypt(string plaintext, string key, int bitShift)
    {
        string encryptedText = "";

        for (int i = 0; i < plaintext.Length; i++)
        {
            char encryptedChar = (char)(plaintext[i] ^ key[i % key.Length]);
            encryptedChar = (char)(encryptedChar << bitShift);
            encryptedText += encryptedChar;
        }

        return encryptedText;
    }

    static string Decrypt(string encryptedText, string key, int bitShift)
    {
        string decryptedText = "";

        for (int i = 0; i < encryptedText.Length; i++)
        {
            char decryptedChar = (char)(encryptedText[i] >> bitShift);
            decryptedChar = (char)(decryptedChar ^ key[i % key.Length]);
            decryptedText += decryptedChar;
        }

        return decryptedText;
    }
}
