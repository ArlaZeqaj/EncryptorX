# EncryptorX

EncryptorX is a simple application that allows you to encrypt and decrypt text messages using the RSA cryptographic algorithm. It provides a command-line interface for navigating and different encryption and decryption options.



## Features

- **Key Generation**: Generate secure public encryption key to be used for encypting any plain text, with the given values of p and q
- **Encryption**: Encrypt a single plain text using the RSA algorithm
- **Decryption**: Decrypt an encrypted message to its original plain text format
- **Sentence encryption**: Encrypt a long sentence to a cyphertext
- **Sentence decryption**: Decrypt a long sentence to original plaintext
- **File encryption**: Translate a text file to an encrypted file


## Installation

### Step 1: Install a C Compiler
Ensure that a C compiler is installed on your system. The most common C compiler is GCC (GNU Compiler Collection), which is available on various platforms, including Windows, macOS, and Linux.

To check if GCC is installed, open a terminal or command prompt and run the following command:

```bash
  gcc --version

```
### Step 2: Set Up the Development Environment


- Open a C/C++ IDE to run the app (like CodeBlocks).
- Download the ZIP file from the repository https://github.com/ArlaZeqaj/EncryptorX.git 
- Extract the ZIP file and open the app folder with the IDE of choice

### Step 3: Compile and run the code 
If you are using CodeBlocks (and most other IDEs), you have to build the main.c file and then simply run the code on your PC.  
## Usage

1. Execute the app after installation.
2. Select the desired encryption or decryption option from the main menu.
3. Enter the message or file path for encryption or decryption. 
4. Provide the necessary encryption key or password.
5. Follow the on-screen instructions to complete the process.
6. Copy the encrypted or decrypted message to the clipboard for further use if needed.

## Running Tests

To run tests, add the following condition (remove the comment lines) in the main file:

```bash
  else if (number == 7){
            testRSAEncryption();
    }
```
The testing option will be added to the main menu.

## Authors

- [@ArlaZeqaj](https://github.com/ArlaZeqaj)
- [@estela-mele](https://github.com/estela-mele)
- [@ildalama](https://github.com/ildalama)



## 🚀 Contact

For any questions or inquiries, please contact the project maintainer:

**Name**: Arla Zeqaj

**Email**: azeqaj22@epoka.edu.al

Feel free to reach out if you have any feedback, suggestions, or concerns!
