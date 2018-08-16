#include "stdio.h"
#include "GetData.h"

int main()
{
    GetData getData;
    getData.setFile("DadosGPS26_07_2018_10.txt");
    getData.print();
    getData.getGPSData();
    return 0;
}
