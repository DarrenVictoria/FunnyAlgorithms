#include <stdio.h>
#include <string.h>

char alphabet[] = "abcdefghijklmnopqrstuvwyzàáãâéêóôõíúçABCDEFGHIJKLMNOPQRSTUVWYZÀÁÃÂÉÊÓÕÍÚÇ";
int alphabet_length = sizeof(alphabet) - 1;

char letter_shift(char letter, int shift) {
    for (int i = 0; i < alphabet_length; i++) {
        if (alphabet[i] == letter) {
            int index_shifted = (i + shift) % alphabet_length;
            return alphabet[index_shifted];
        }
    }
    return letter;
}

void caesar_cypher(char *str_user, int shift) {
    for (int i = 0; i < strlen(str_user); i++) {
        if (str_user[i] == ' ') {
            continue;
        }
        str_user[i] = letter_shift(str_user[i], shift);
    }
}

int main() {
    int user_choice;
    printf("Menu - Caesar Cipher Program\nTo Encrypt a message with the default shift - press 0\nTo Encrypt a message with a custom shift - press 1\n");
    scanf("%d", &user_choice);

    char user_input[1000];
    int user_shift;

    if (user_choice == 0) {
        printf("Please provide the message that will be cyphered: ");
        scanf(" %[^\n]s", user_input);
        caesar_cypher(user_input, 3);
        printf("Your message cyphered by the Caesar cipher is: %s\n", user_input);
    } else if (user_choice == 1) {
        printf("Please provide the message that will be cyphered: ");
        scanf(" %[^\n]s", user_input);
        printf("Please provide the shift for cypher: ");
        scanf("%d", &user_shift);
        caesar_cypher(user_input, user_shift);
        printf("Your message cyphered by the Caesar cipher is: %s\n", user_input);
    } else {
        printf("Please select a valid option.\n");
    }

    return 0;
}
