#include "iostream"

using namespace std;

int strlen(const char *str);
int strcmp(const char *str1, const char *str2);
char* strcpy(char* str1, const char* str2);
char* strcat(char *str1, const char *str2);

int main(int argc, char const *argv[]) {

    char *s1 = new char[100];
    const char *s2 = "Hello, world!";
    strcpy(s1, s2);
    cout << strcat(s1,"Hello Hello");
      return 0;
}

int strlen(const char *str)
{
  const char *eos = str;
  while(*eos++);
  return (int)(eos - str - 1);
  //Lenght without '\n' symbol
}

int strcmp(const char *str1, const char *str2)
{
  while( (*str2 && *str1) && (*str1 == *str2) )
  {
    str1++;
    str2++;
  }
  return *str1 - *str2;
  //return > 0 [str1 > str2]
  //return < 0 [str1 < str2]
  //return = 0 [str1 = str2]
}

char* strcpy(char* str1, const char* str2)
{
  char* d = str1;
  while(*d++ = *str2++);
  return str1;
}

char* strcat(char *str1, const char *str2)
{
  char *cp = str1;
  while(*cp) cp++;
  while(*cp++ = *str2++);
  return str1;
}

void strcp(char** d, const char* source)
{
    unsigned size = strlen(source);
    for(int i = 0; source[i] != '\0'; i++)
    char* str = new char[size+1];
    *d = str;
    for(int i = 0; source[i] != '\0'; i++)
    {
        str[i] = source[i];
    }
}

int strstr(const char* str, const char* pattern, int start = 0)
{
	int str_size = strlen(str);
	const char *p, *j;
	for (int i = start; i < str_size; i++)
	{
		p = &str[i];
		j = pattern;
		while (*p == *j)
		{
			++p;
			++j;
			if (*j == '\0')
				return i;
		}
	}
	return -1;
}

char** strtok(char *str, const char *sep)
{
	int cnt = 0;
	int start = 0;
	char** result = NULL;
	int end = -1;
	while(true)
	{
		end = strstr(str, sep, (end + 1));
		cnt++;
		if (end == -1)
			break;
	}
	result = new char*[cnt];
	for (int i = 0; i < cnt; i++)
	{
		end = strstr(str, sep, (end + 1));
		if (end == -1) end = strlen(str);
		result[i] = new char[end - start + 1];
		int k = 0;
		for (int j = start; j < end; j++, k++)
		{
			result[i][k] = str[j];
		}
		result[i][k] = '\0';
		start = end + strlen(sep);
	}
	return result;
}


void reverse_words(const char* str, char** result)
{
    unsigned str_len = strlen(str);
    char* temp = new char[str_len + 1];
    unsigned temp_i = 0;
    for(unsigned i = 0; i < str_len; i++)
    {
        int start_pos = i;
        while((str[i] != ' ') && (str[i] != '\0'))
        {
            i++;
        }
        for(int j = i - 1; j >= start_pos; j--)
        {
            temp[temp_i] = str[j];
            temp_i++;
        }
        temp[temp_i++] = str[i];
    }
    *result = (temp);
}
