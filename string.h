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
     ~String();

    String& operator =(const String&);
    String  operator+ (String &other);
    String& operator+=(String &other);

    friend String operator+(String &str1, const char*str2);
    friend String operator+(const char*str1, String &str2);

    int      find(const char *pattern, unsigned start_pos = 0);
    unsigned replace(const char *word, const char* new_word);
    String&  append(String &other);
    String&  erase(unsigned position, unsigned count);
    String   subStr(unsigned position, unsigned count);
    void     swap(String &);

    unsigned lenght()
    {
        return size_;
    }
    bool empty()
    {
        if(size_ == 0)
            return true;
        return false;
    }

    bool operator==(const String&);
    bool operator!=(const String&);
    bool operator> (const String&);
    bool operator>=(const String&);
    bool operator< (const String&);
    bool operator<=(const String&);

    const char& operator[](int) const;
    char& operator[](int);
    operator const char*();

    friend std::ostream& operator<<(std::ostream&, const String&);
    friend std::istream& operator>>(std::istream&, String&);

private:
    unsigned size_;
    char *str_;

};

}//namespace string

#endif // STRING_H
