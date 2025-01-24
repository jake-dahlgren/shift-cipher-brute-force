/**
 * File     : main.c
 * Author   : Jake Dahlgren
 * Course   : CPE2610
 * Dependencies: 
 * 
 * Description: brute force messages encrypted with a shift cipher
 *              Numbers 0-9 and letters A-Z
 * 
 * Created : Jan 23, 2025
 * Author  : dahlgrenj
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int main(int argc, char* argv[]) {
    if (argc > 1) {

        char* encrypted_msg = malloc(sizeof(*argv[1]));
        strcpy(encrypted_msg, argv[1]);
        printf("--- Shift Cipher brute force program ---\n");
        char cipher_string[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int cipher_string_len = strlen(cipher_string);
        int encrypted_msg_len = strlen(encrypted_msg);

        printf("Start decrypt: [ %s ]\n", encrypted_msg);
        printf("message length : %d \n cipher string: %s \n", encrypted_msg_len, cipher_string);
        clock_t startTime = clock();
 


        for (int offset = 0; offset <= cipher_string_len; offset++) {
            char result[encrypted_msg_len + 1];
            for (int pos = 0; pos <= encrypted_msg_len; pos++) {
                // its probably more efficient to use a hash map or something but I dont care
                int lookup_pos = 0;
                bool matched = false;
                while (!matched) {
                    if (encrypted_msg[pos] == cipher_string[lookup_pos]) {
                        result[pos] = cipher_string[(lookup_pos + offset) % (cipher_string_len)];
                        matched = true;
                    }
                    lookup_pos++;
                }
            }
            result[encrypted_msg_len] = '\0';
            printf(" %s  - %d Lshift\t[Key: ", result, offset);
            for (int i = 0; i < cipher_string_len; i++) {
                printf("%c", cipher_string[(i + offset) % cipher_string_len]);
            }
            printf("]\n");
        }
        clock_t endTime = clock();
        double cpuTimeUsed = ((double) (endTime - startTime)) / (CLOCKS_PER_SEC / 1000);
        printf("completed in  %f ms\n", cpuTimeUsed);

    } else {
        printf("please provide the encrypted message as an argument\n");
        printf("exiting...\n");
    }
    return 0;
}