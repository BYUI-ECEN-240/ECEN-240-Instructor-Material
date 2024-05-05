#include <stdio.h>

int main() {
  for (int firstDigit = 6; firstDigit >= 0; firstDigit--) {
    int secondDigit = firstDigit - 1;

    // Array to store the digits
    int digits[7] = {firstDigit, secondDigit};
    int usedDigits = 2; // Keep track of used digits

    // Fill remaining digits with unused digits (0 to 6)
    for (int i = 0; i < 7; i++) {
      if (usedDigits == 7) {
        break;
      }
      int found = 0;
      for (int j = 0; j < usedDigits; j++) {
        if (digits[j] == i) {
          found = 1;
          break;
        }
      }
      if (!found) {
        digits[usedDigits++] = i;
      }
    }

    // Print the generated number
    for (int i = 0; i < 7; i++) {
      printf("%d", digits[i]);
    }
    printf("\n");
  }

  return 0;
}
