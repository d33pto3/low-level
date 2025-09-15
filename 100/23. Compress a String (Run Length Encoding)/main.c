#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int append_count(char *ans, int idx, int cnt)
{
	if (cnt > 1)
	{
		char buffer[20];

		int len = sprintf(buffer, "%d", cnt);
		for (int j = 0; j < len; j++)
		{
			ans[idx++] = buffer[j];
		}
	}

	return idx;
}

char *rle(const char *str)
{
	char cur = str[0];
	int idx = 0;
	int cnt = 1;
	char *ans = (char *)malloc(sizeof(*str));

	for (int i = 1; i < strlen(str); i++)
	{
		if (cur == str[i])
		{
			cnt++;
		}
		else
		{
			ans[idx++] = cur;
			idx = append_count(ans, idx, cnt);
			cur = str[i];
			cnt = 1;
		}
	}

	ans[idx++] = cur;
	idx = append_count(ans, idx, cnt);

	ans[idx] = '\0';

	return ans;
}

int main()
{
	char *str = "aaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbcccdefg";

	char *ans = rle(str);

	printf("%s\n", ans);

	return 0;
}
