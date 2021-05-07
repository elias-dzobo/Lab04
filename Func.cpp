

#include "headfiles.h"

rectBlocks::rectBlocks(){
    width = 1;
    height = 1;
    length  = 1;
}

rectBlocks::rectBlocks(int w, int h, int l) {
    width = w;
    height = h;
    length = l;
}

void rectBlocks::setWidth(int w) {
    width = w;
}

void rectBlocks::setHeight(int h) {
    height = h;
}

void rectBlocks::setLength(int l) {
    length = l;
}

int rectBlocks::getWidth() {
    return width;
}

int rectBlocks::getHeight() {
    return height;
}

int rectBlocks::getLength() {
    return length;
}

sqrBaseRectBlocks::sqrBaseRectBlocks(){
    width = 1;
    height = 1;
    length = 1;
}

cuboidBlocks::cuboidBlocks(){

}

cylindricalBlocks::cylindricalBlocks(){
    diameter = getWidth();
}

void cylindricalBlocks::setArea(float a) {
    surface_area =a;
}

void cylindricalBlocks::setDiameter(int a) {
    diameter = a;
}

float cylindricalBlocks::area(){
    float area = M_PI * pow(width, 2);
    return area;
}

float cylindricalBlocks::surfaceArea(){
    float sarea = 0;
    sarea = (2*M_PI*height*width) + (2*M_PI*pow(width, 2));
    return sarea;
}

int cylindricalBlocks::getDiameter(){
    return diameter;
}

void cylindricalBlocks::printOut(){
    cout << "Surface area: " << surfaceArea() << " Diameter: "<< getDiameter() << " Length: "<< length << " area: " << area() << "\n";

}

sphericalBlocks::sphericalBlocks(){
    diameter = getWidth();
}

void sphericalBlocks::setDiameter(int a) {
    diameter = a;
}

int sphericalBlocks::getDiameter() {
    return diameter;
}

float sphericalBlocks::volume() {
    float v = (4/3) * M_PI * pow(diameter, 3);
    return v;
}

void sphericalBlocks::printOut() {
    cout << " Diameter: "<< getDiameter() << " Volume: "<< volume() << "\n";

}


void populateRectArray(rectBlocks arr[10]) {


    int counts = 0;
    ifstream file;

    file.open("dataBlocks.dat");

    if (file.is_open()) {

        int dim[3];
        string line;


        while (getline(file, line)){


            string digits = "";
            int index = 0;

            for (char const &c: line) {
                if (c == ' '){
                    stringstream(digits) >> dim[index];
                    index ++;
                    digits = "";
                } else {
                    digits += c;
                }


            }
            stringstream(digits) >> dim[index];

            arr[counts].setWidth(dim[0]);
            arr[counts].setHeight(dim[1]);
            arr[counts].setLength(dim[2]);
            counts ++;


        }


    }


}

void populateSqr(rectBlocks arr[10], sqrBaseRectBlocks sqrblocks[10]) {
    int index = 0;
    for (int i = 0; i < 10; i++){
        if (arr[i].getWidth() == arr[i].getHeight()) {
            sqrblocks[index].setWidth(arr[i].getWidth());
            sqrblocks[index].setHeight(arr[i].getHeight());
            sqrblocks[index].setLength(arr[i].getLength());
            index++;
        } else {
        continue;
        }

    }

}


void populateCyl(sqrBaseRectBlocks sqrblocks[10], cylindricalBlocks cblocks[10]){

    for (int i = 0; i < 10; i ++) {

        cblocks[i].setWidth(sqrblocks[i].getWidth());
        cblocks[i].setHeight(sqrblocks[i].getHeight());
        cblocks[i].setLength(sqrblocks[i].getLength());
    }

}

void populateCub(sqrBaseRectBlocks sqrblocks[10], cuboidBlocks cublocks[10]) {
    int index = 0;
    for (int i = 0; i < 10; i ++) {

        if ((sqrblocks[i].getWidth() == sqrblocks[i].getLength()) && (sqrblocks[i].getWidth() == sqrblocks[i].getHeight())) {

            cublocks[index].setWidth(sqrblocks[i].getWidth());
            cublocks[index].setHeight(sqrblocks[i].getHeight());
            cublocks[index].setLength(sqrblocks[i].getLength());
            index++;

        } else {
            continue;
        }
    }
}

void populateSphere(cuboidBlocks cublocks[10], sphericalBlocks sblocks[10]) {

    for (int i = 0; i< 10; i++) {
        sblocks[i].setWidth(cublocks[i].getWidth());
        sblocks[i].setLength(cublocks[i].getLength());
        sblocks[i].setHeight(cublocks[i].getHeight());
    }
}

void sortSarrF(sphericalBlocks sblock[3]) {

    sort(sblock, sblock + 3);

}

void sortCarrF(cylindricalBlocks cblocks[3]) {

    sort(cblocks, cblocks + 7);

}





