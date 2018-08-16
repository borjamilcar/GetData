#include "GetData.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

GetData::GetData()
{
    //ctor
}

GetData::~GetData()
{
    //dtor
}

void GetData::setFile(char* file_name) {
    _file_content = readFile(file_name);
}

char* GetData::readFile(char* file_name){
    FILE *file_ptr;
    char c;
    char *str_ptr;
    size_t index = 0;

    if ((file_ptr = fopen(file_name, "r")) == NULL)
        return NULL;

    fseek(file_ptr, 0, SEEK_END);
    long file_size = ftell(file_ptr);
    fseek(file_ptr, 0, SEEK_SET);

    str_ptr = (char*)malloc(file_size);

    while ((c = fgetc(file_ptr)) != EOF)
        str_ptr[index++] = c;

    str_ptr[index] = '\0';

    return str_ptr;
}

void GetData::print() {
    for (unsigned i = 0; i < strlen(_file_content); i++)
        printf("%c", _file_content[i]);
}


char* GetData::getGPSData() {
    char *ptr;
    int i = 0;

    ptr = strtok(_file_content, ",");

    printf("\n");

    while (i < 14) {
        //char *a = atoi(ptr);
        printf("%s\n", ptr);

        if (i == 1) {
            _gps.date = ptr;
        } else if (i == 2) {
            _gps.lat = ptr;
        } else if (i == 4) {
            _gps.lon = ptr;
        }

        ptr = strtok(NULL, ",");
        i++;
    }

    printf("+++++++++++++++++++++++++++++++\n");
    printf("+ Data: %s\n", _gps.date);
    printf("+ Lat.: %s\n", _gps.lat);
    printf("+ Lon.: %s\n", _gps.lon);

    return 0;
}
