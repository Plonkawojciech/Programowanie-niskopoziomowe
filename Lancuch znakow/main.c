#include <stdio.h>
#include <string.h>

typedef struct string_view
{
    char const *pointer;
    int length;
} string_view;

string_view sv_from_cstr(char const* s)
{
    string_view wynik;

    wynik.pointer = s;
    wynik.length = strlen(s);

    return wynik;
}

string_view sv_trim_left(string_view s)
{
    while (s.length > 0 && s.pointer[0] == ' ')
    {
        s.pointer++;
        s.length--;
    }

    return s;
}

string_view sv_chop(string_view *s, char delim)
{
    string_view wynik;

    wynik.pointer = s->pointer;
    wynik.length = 0;

    while (wynik.length < s->length && s->pointer[wynik.length] != delim)
    {
        wynik.length++;
    }

    if (wynik.length < s->length)
    {
        s->pointer = s->pointer + wynik.length + 1;
        s->length = s->length - wynik.length - 1;
    }
    else
    {
        s->pointer = s->pointer + s->length;
        s->length = 0;
    }

    return wynik;
}

int main()
{
    string_view sv = sv_from_cstr("  hello world");

    printf("sv: %.*s\n", sv.length, sv.pointer);

    sv = sv_trim_left(sv);
    printf("sv: %.*s\n", sv.length, sv.pointer);

    string_view word = sv_chop(&sv, ' ');

    printf("word: %.*s\n", word.length, word.pointer);
    printf("sv: %.*s\n", sv.length, sv.pointer);

    return 0;
}
