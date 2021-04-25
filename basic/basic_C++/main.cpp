#include <iostream>
#include <cstring>

enum
{
    MAX_STR_LENGTH = 1024
};

class book
{
private:
    unsigned mPages;
    char mAuthor[MAX_STR_LENGTH];
    char mPublishedDate[MAX_STR_LENGTH];
    unsigned mISBN;
    unsigned char mEdition;
    unsigned int* mCurrentPages;
    bool isRead;

public:
    book(const unsigned pages, const char* author, const char* pdate, const unsigned isbn, const unsigned char edition)
    {
        this->mPages = pages;
        strcpy(this->mAuthor, author);
        strcpy(this->mPublishedDate, pdate);
        this->mISBN = isbn;
        this->mEdition = edition;
        this->isRead = false;
    }

    ~book()
    {
        if(isRead)
        {
            free(this->mCurrentPages);
            this->mCurrentPages = NULL;  // free된 포인터를 다시 free하지 않도록 NULL로 설정 (free(NULL) 하면 오류가 난다)
        }
    }

    unsigned& getPages(void);
    char* getAuthor_p(void);
    char* getPublishedDate_p(void);
    unsigned& getISBN(void);
    unsigned char& getEditionNum(void);
    unsigned int* getCurrentPages_p(void);
    bool& getReadFlag(void);


    void setPages(const unsigned totalPages);
    void setAuthor(const char* name_p);
    void setPublishedDate(const char* date_p);
    void setISBN(const unsigned isbn);
    void setEditionNum(const unsigned char edition);
    void setCurrentPages(const unsigned currPages, const unsigned int maxPages);
    void setReadFlag(void);
    void resetReadFlag(void);

};

typedef struct book_t
{
    unsigned mPages;
    char mAuthor[MAX_STR_LENGTH];
    char mPublishedDate[MAX_STR_LENGTH];
    unsigned mISBN;
    unsigned char mEdition;
    unsigned int current_pages;
    bool isRead;
}book_t;

int main(void)
{
    char name[MAX_STR_LENGTH] = "Jasper";
    char date[MAX_STR_LENGTH] = "2021-04-11";
    unsigned isbn = 0x12345;
    unsigned char edition = 3;
    unsigned int reading_pages = 0;
    unsigned total_pages = 0;

    std::cout << "Enter the total pages of your book\n";
    std::cin >> total_pages;

    book myBook(total_pages, name,date,isbn, edition);

    book_t mybook_t;
    mybook_t.mPages = total_pages;
    strcpy(mybook_t.mAuthor, name);
    strcpy(mybook_t.mPublishedDate, date);
    mybook_t.mISBN = isbn;
    mybook_t.mEdition = edition;

    while(true)
    {
        std::cout << "Enter the Pages you are reading";
        std::cin >> reading_pages;

        if(reading_pages == 0 || reading_pages > total_pages)
        {
            break;
        }

        myBook.setReadFlag();
        mybook_t.isRead = true;

        myBook.setCurrentPages(reading_pages, total_pages);
        mybook_t.current_pages = reading_pages;

    }
    myBook.resetReadFlag();
    mybook_t.isRead = false;

    return 0;
}
unsigned& book::getPages(void)
{
    return this->mPages;
};

char* book::getAuthor_p(void)
{
    return this->mAuthor;
};

char* book::getPublishedDate_p(void)
{
    return this->mPublishedDate;
};

unsigned& book::getISBN(void)
{
    return this->mISBN;
};

unsigned char& book::getEditionNum(void)
{
    return this->mEdition;
};

unsigned int* book::getCurrentPages_p(void)
{
    return this->mCurrentPages;
};

bool& book::getReadFlag(void)
{
    return this->isRead;
};

void book::setPages(const unsigned totalPages)
{
    unsigned& pages = getPages();
    pages = totalPages;
};

void book::setAuthor(const char* name_p)
{
    char* name = getAuthor_p();
    strcpy(name, name_p);
};

void book::setPublishedDate(const char* date_p)
{
    char* date = getPublishedDate_p();
    strcpy(date, date_p);
};

void book::setISBN(const unsigned isbn)
{
    unsigned& code = getISBN();
    code = isbn;
};

void book::setEditionNum(const unsigned char edition)
{
    unsigned char& eNum = getEditionNum();
    eNum = edition;
};

void book::setCurrentPages(const unsigned currPages, const unsigned int maxPages)
{
    bool& readFlag = getReadFlag();
    readFlag = true;
    unsigned int* curr = getCurrentPages_p();
    curr = (unsigned int*)malloc(sizeof(unsigned int*));
    if(currPages > maxPages)
    {
        std::cout << "Impossible input";
        return;
    }
    *curr = currPages;
};

void book::setReadFlag(void)
{
    bool& readFlag = getReadFlag();
    readFlag = true;
};

void book::resetReadFlag(void)
{
    bool& readFlag = getReadFlag();
    readFlag = false;
};