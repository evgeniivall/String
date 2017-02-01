#ifndef STRING_H
#define STRING_H

#include <iostream>
namespace string
{

unsigned StrLen(const char*);
char*    StrCpy(char*, const char*);
char*    StrCat(char*, const char*);
bool     StrCmp(const char*, const char*);

class String
{
public:
    static const unsigned n_pos = -1;
    String(const char *str = "");
    String(const String&);
    String(unsigned size, char symbol);

    String& operator =(const String&);

    operator const char*()
    {
        if(size_ != 0)
        {
            return str_;
        }
        return "";
    }


    String operator+(String &other);
    String&   operator+=(String &other);

    friend String operator+(String &str1, const char*str2);
    friend String operator+(const char*str1, String &str2);

    unsigned strRep(const char *word, const char* newWord);

    int find(const char *pattern, unsigned start_pos = 0);
    unsigned replace(const char *word, const char* new_word);

    unsigned lenght()
    {
        return size_;
    }





    bool operator==(const String&);
    bool operator!=(const String&);
    bool operator> (const String&);
    bool operator>=(const String&);
    bool operator< (const String&);
    bool operator<=(const String&);

    const char& operator[](int) const;
    char& operator[](int);

    friend std::ostream& operator<<(std::ostream&, const String&);
    friend std::istream& operator>>(std::istream&, String&);

    ~String();
private:
    unsigned size_;
    char *str_;

};

}//namespace string

#endif // STRING_H
