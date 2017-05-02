#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

// A65, a97
int appearanceCount(int g_size,int s_size,char* g,char* s)
{
	int appearances = 0, counts[52], mcounts[52];
	memset(counts, 0, sizeof(counts));
	memset(mcounts, 0, sizeof(mcounts));

	for (int i = 0; i < g_size; i++) {
		if (g[i] >= 'A' && g[i] <= 'Z') counts[(int)g[i] - 65]++;
		else if (g[i] >= 'a' && g[i] <= 'z') counts[(int)g[i] - 97 + 26]++;

		if (s[i] >= 'A' && s[i] <= 'Z') mcounts[(int)s[i] - 65]++;
		else if (s[i] >= 'a' && s[i] <= 'z') mcounts[(int)s[i] - 97 + 26]++;
	}

	for(int pos = 0; pos + g_size <= s_size; pos++) {
		bool is_good = true;
		for (int i = 0; i < 52; i++) if (counts[i] != mcounts[i]) is_good = false;
		if (is_good) appearances++;

		if (s[pos] >= 'A' && s[pos] <= 'Z') mcounts[(int)s[pos] - 65]--;
		else if (s[pos] >= 'a' && s[pos] <= 'z') mcounts[(int)s[pos] - 97 + 26]--;

		if (pos + g_size < s_size) {
			if (s[pos + g_size] >= 'A' && s[pos + g_size] <= 'Z') mcounts[(int)s[pos + g_size] - 65]++;
			else if (s[pos + g_size] >= 'a' && s[pos + g_size] <= 'z') mcounts[(int)s[pos + g_size] - 97 + 26]++;
		}
	}
	return appearances;
}

int main() {
    int output = 0;
    int ip1;
    scanf("%d", &ip1);
    int ip2;
    scanf("%d", &ip2);
    char* ip3;
    ip3 = (char *)malloc(512000 * sizeof(char));
    scanf("\n%[^\n]",ip3);
    char* ip4;
    ip4 = (char *)malloc(512000 * sizeof(char));
    scanf("\n%[^\n]",ip4);
    output = appearanceCount(ip1,ip2,ip3,ip4);
    printf("%d\n", output);
    return 0;
}