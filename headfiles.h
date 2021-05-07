

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

#ifndef HEADFILE
#define HEADFILE


class rectBlocks {

    public:
        int width;
        int height;
        int length;


    public:
        rectBlocks();
        rectBlocks(int w, int h, int l);
        void setWidth(int w);
        void setHeight(int h);
        void setLength(int l);
        int getWidth();
        int getHeight();
        int getLength();

};




class sqrBaseRectBlocks: public rectBlocks {

    public:
        sqrBaseRectBlocks();

};



class cuboidBlocks: public sqrBaseRectBlocks {

    public:
        cuboidBlocks();

};




class cylindricalBlocks: public sqrBaseRectBlocks{

    public:
        int diameter;
        float surface_area;
        void setArea(float a);
        void setDiameter(int a);
        cylindricalBlocks();
        float area();
        float surfaceArea();
        void printOut();
        int getDiameter();
        bool operator< (const cylindricalBlocks &other) const {
        return surface_area < other.surface_area;
    }


};



class sphericalBlocks: public cuboidBlocks{



    public:
        int diameter;
        sphericalBlocks();
        int getDiameter();
        void setDiameter(int a);
        float volume();
        void printOut();
        bool operator< (const sphericalBlocks &other) const {
        return diameter < other.diameter;
    }


};


#endif // HEADFILE

void populateRectArray(rectBlocks arr[]);
void populateSqr(rectBlocks arr[], sqrBaseRectBlocks sblock[]);
void populateCub(sqrBaseRectBlocks sblock[], cuboidBlocks cublock[]);
void populateCyl(sqrBaseRectBlocks sblock[], cylindricalBlocks cblock[]);
void populateSphere(cuboidBlocks cublock[], sphericalBlocks sblock[]);
void sortSarrF(sphericalBlocks sblock[3]);
void sortCarrF(cylindricalBlocks cblocks[7]);







