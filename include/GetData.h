#ifndef GETDATA_H
#define GETDATA_H

class GetData
{
    public:
        GetData();
        virtual ~GetData();

        char* getGPSData();
        char* readFile(char *file);
        void setFile(char* file);

        void print();
    protected:

    private:
        char* _file_content;
        struct GPS {
            char *date;
            char *lon;
            char *lat;
        } _gps;
};

#endif // GETDATA_H
