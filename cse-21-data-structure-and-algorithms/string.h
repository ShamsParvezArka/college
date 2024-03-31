#ifndef STRING_H
#define STRING_H

#define GROWTH_FACTOR 1.125
#define DEFAULT_SIZE 64
#define MOD_STRING_AT(s, i) (s)->text[(i)]
#define STRING_AT(s, i) (s).text[(i)]

typedef struct strign {
	char *text;
	size_t length;
	size_t capacity;
} string;

string string_init(const char *str);
string string_slice(string s, size_t begin, size_t end);
void string_push_back(string *s, const char *str);
void string_erase(string *s, size_t begin, size_t end); //[begin, end)

#endif //STRING_H

#ifdef STRING_IMPLEMENTATION

string string_init(char *str)
{
	string s = {
		.text = malloc(DEFAULT_SIZE),
		.length = strlen(str),
		.capacity = DEFAULT_SIZE
	};
	strcpy(s.text, str);

	return s;
}

void string_push_back(string *s, const char *str)
{
	if (s->length >= s->capacity) {
		size_t new_capacity =  s->capacity + s->capacity*GROWTH_FACTOR;
		s->text = realloc(s->text, new_capacity);
		s->capacity = new_capacity;
	}
	strcat(s->text, str);
	s->length += strlen(str);
}

string string_slice(string s, size_t begin, size_t end)
{
	string sliced_s = {
		.text = malloc(DEFAULT_SIZE),
		.length = end - begin,
		.capacity = DEFAULT_SIZE
	};
	strncpy(sliced_s.text, s.text + begin, end - begin);
	STRING_AT(sliced_s, sliced_s.length) = '\0';

	return sliced_s;
}

void string_erase(string *s, size_t begin, size_t end)
{
	size_t free_spaces = end - begin;
	for (size_t i = end; i < s->length; i++) {
		MOD_STRING_AT(s, i - free_spaces) = MOD_STRING_AT(s, i);
	}
	memset(s->text + end, '\0', free_spaces);
	s->length -= free_spaces;
}

#endif //STRING_IMPLEMENTATION