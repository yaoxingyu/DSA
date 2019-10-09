#pragma once

int StringCopy(const char* src, char* dst)
{
	if (src == nullptr || dst == nullptr)
	{
		return -1;
	}

	//while (*dst != '\0' && *src != '\0')
	//{
	//	*dst++ = *src++;
	//}

	while ((*dst++ = *src++) != '\0');

	*dst = '\0';

	if (*src != '\0')
	{
		return -1;
	}

	return 0;
}