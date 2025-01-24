# shift-cipher-brute-force

Compile the program, and run it with the text to decrypt as an argument.
> ***Example:*** &nbsp;&nbsp;&nbsp; gcc -o shift_cipher_crack shift_cipher_brute_force.c

***Example command:*** &nbsp;&nbsp;&nbsp; ./shift-cipher-brute_force ABCDEFGXXXX0000 <br>
  where **ABCDEFGXXXX0000** is the encrypted message

***

numbers 0-9 and letters A-Z are supported
The actual shift cipher string compared to is [ 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ ]
Can support more chars by expanding the cipher string, the program will
dynamicly adapt to the length of the message and shift cipher string
