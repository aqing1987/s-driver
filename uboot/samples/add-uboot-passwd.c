#include <stdio.h>
#include <string.h>

#define DEFAULT_PASSWD "hello"

// add the passwd logic to
// int readline (const char *const prompt)
// in uboot/common/main.c

void passwd()
{
    char pwd[64];
	char c;
	int index;
	static int bPwd = 1;

    while (bPwd) {
		puts ("### Please input uboot password: ###\n");

        index = 0;
		while ((c = getchar()) != '\n') {
			if (c == 8) {/* Backspace */
				if (index > 0) {
					printf ("\b \b");
					index--;
				}
				continue;
			}
			putchar('*');
			pwd[index] = c;
			index++;
		}
		pwd[index] = '\0';
		putchar('\n');

		if (!strcmp (pwd, DEFAULT_PASSWD)) {
			bPwd = 0;
		}
        else {
            puts("error\n");
        }
	}

    puts("ok\n");
}

int main(int argc, char *argv[])
{
    passwd();

    return 0;
}
