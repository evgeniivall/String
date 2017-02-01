#include "string.h"

namespace string
{

unsigned StrLen(const char* str)
{
    unsigned counter = 0;
    while(str[counter] != '\0')
    {
        counter++;
    }
    return counter;
}

char* StrCpy(char *destination, const char *source)
{
    unsigned i = 0;
    for( ;source[i] != '\0'; i++)
    {
        destination[i] = source[i];
    }
    destination[i] = '\0';
    return destination;
}

char* StrCat(char *destination, const char *append)
{
    int i = StrLen(destination);
    unsigned append_i = 0;
    for( ; append[append_i] != '\0'; i++)
    {
        destination[i] = append[append_i];
        append_i++;
    }
    destination[i] = '\0';
    return destination;
}

bool StrCmp(const char* str1, const char* str2)
{
    if(StrLen(str1) != StrLen(str2))
        return false;
    for(unsigned i = 0; i < StrLen(str1); i++)
    {
        if(str1[i] != str2[i])
            return false;
    }
    return true;

}



String::String(unsigned size, char symbol)
{
    size_ = size;
    str_ = new char[size_+1];
    for(unsigned i = 0; i < size; i++)
    {
        str_[i] = symbol;
    }
    str_[size_] = '\0';
}

String::String(const char *str)
{   
    size_ = StrLen(str);
    str_ = new char[size_ + 1];
    StrCpy(str_, str);
}

String::String(const String &source)
{
    size_ = source.size_;
    str_ = new char[size_ + 1];
    StrCpy(str_, source.str_);
}

String& String::operator =(const String&source)
{
    if (this != &source)
    {
        delete[] str_;
        size_ = source.size_;
        str_ = new char[size_ + 1];
        StrCpy(str_, source.str_);
    }
    return *this;
}


String String::operator +(String &other)
{
    String temp(*this);
    temp += other;
    return temp;
}

String operator+(String &str1, const char*str2)
{
    String temp(str2);
    return str1 + temp;
}

String operator+(const char*str1, String &str2)
{
    String temp(str1);
    temp += str2;
    return temp;
}


String& String::operator +=(String &other)
{
    unsigned temp_size = size_ + other.size_;
    char* temp_str = new char[temp_size + 1];
    StrCat(temp_str, str_);
    StrCat(temp_str, other.str_);
    delete[] str_;

    str_ = temp_str;
    size_ = temp_size;
    return *this;
}


std::ostream& operator<<(std::ostream& os, const String& str)
{
    os << str.str_;
    return os;
}

std::istream& operator>>(std::istream& is, String& str)
{
    char BUFF[2048];
    is >> BUFF;
    str = BUFF;
    return is;
}
String::~String()
{
    delete[] str_;
}


const char& String::operator[](int i) const
{
    return (i >= 0 && i < size_) ? str_[i] : 0;
}

char& String::operator[](int i)
{
    static char symbol;
    symbol = '\0';
    return (i >= 0 && i < size_) ? str_[i] : symbol;
}

int String::find(const char *pattern, unsigned start_pos)
{
    int str_itr = start_pos;
    int p_itr = 0;
    int position = n_pos;
    while(str_itr < size_)
        {
            if(str_[str_itr] == pattern[p_itr])
            {
                if(position == n_pos)
                    position = str_itr;
                str_itr++;
                p_itr++;
                if(pattern[p_itr] == '\0')
                    return position;
            }
            else
            {
                if(position == n_pos)
                    str_itr++;
                position = n_pos;
                p_itr = 0;
            }
        }
    if(pattern[p_itr] == '\0')
        return position;
    return n_pos;
}

unsigned String::replace(const char *word, const char* new_word)
{
    static unsigned counter = 0;
    unsigned template_position = this->find(word);
    if(template_position == n_pos)
    {
        unsigned temp = counter;
        counter = 0;
        return temp;
    }

    unsigned word_size = StrLen(word);
    unsigned new_word_size = StrLen(new_word);
    unsigned new_str_size = this->lenght() - word_size + new_word_size;

    char *new_str = new char[new_str_size];
    unsigned old_str_itr = 0;
    for(int new_str_itr = 0; new_str_itr < new_str_size; new_str_itr++)
    {
        if(new_str_itr == template_position)
        {
            for(int new_word_itr = 0; new_word_itr < new_word_size; new_word_itr++)
            {
                new_str[new_str_itr] = new_word[new_word_itr];
                new_str_itr++;
            }
            new_str_itr--;
            old_str_itr += word_size;
        }
        else
        {
            new_str[new_str_itr] = str_[old_str_itr];
            old_str_itr++;
        }
    }
    delete []str_;
    str_ = new_str;
    size_ = new_str_size;
    counter++;
    replace(word, new_word);
}


bool String::operator==(const String& other)
{
    return StrCmp(str_, other.str_);
}

bool String::operator!=(const String& other)
{
    return !(StrCmp(str_, other.str_));
}

bool String::operator> (const String& other)
{
    return (size_ > other.size_) ? true : false;
}

bool String::operator< (const String& other)
{
    return (size_ < other.size_) ? true : false;
}
bool String::operator>= (const String& other)
{
    return (size_ >= other.size_) ? true : false;
}
bool String::operator<= (const String& other)
{
    return (size_ <= other.size_) ? true : false;
}



}//namespace string
