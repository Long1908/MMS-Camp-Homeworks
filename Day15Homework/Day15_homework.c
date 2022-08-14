#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct Book {
    char name[150];
    char author[100];
    unsigned int page_count;
    double price; 
}Book;

void enterBook(Book* book, const char** bookName, const char ** authorName){
    for(int i = 0; i < COUNT; i++)
    {
        strcpy((book + i)->name, bookName[rand() % 5]);
        strcpy((book + i)->name, authorName[rand() % 5]);
        (book + i) -> page_count = (5 +  rand() % (2005 - 5));
        (book + i) -> price = (100 +  rand() % (100100 - 100));
    }
}
int main(int argc, char* argv[])
{
    srand(time(NULL));
    const char* bookName[] = {"awesomebook1", "awesomebook2", "awesomebook3", "awesomebook4", "veryawesomebook5"};
    const char* bookAuthor[] = {"awesomeauthor1", "awesomeauthor2", "awesomeauthor3", "awesomeauthor4", "veryawesomeauthor5"};
    Book books[COUNT];
    enterBook(books, bookName, bookAuthor);
    FILE* fb = fopen(argv[1], "wb");
    fwrite(books, (5 * sizeof(Book)), COUNT, fb);
    fclose(fb);
}