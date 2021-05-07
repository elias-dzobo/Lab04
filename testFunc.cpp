


#include "headfiles.h"

int main() {

    rectBlocks blocks[10];
    sqrBaseRectBlocks sqrBlocks[10];
    cuboidBlocks cublocks[10];
    cylindricalBlocks cblocks[10];
    sphericalBlocks sblocks[10];

    populateRectArray(blocks);
    populateSqr(blocks, sqrBlocks);
    populateCub(sqrBlocks, cublocks);
    populateCyl(sqrBlocks, cblocks);
    populateSphere(cublocks, sblocks);


    for (int i = 0; i < 3; i ++) {
        sblocks[i].setDiameter(sblocks[i].getWidth());
    }
    for (int i = 0; i < 7; i ++) {
        cblocks[i].setDiameter(sblocks[i].getWidth());
        cblocks[i].setArea(cblocks[i].surfaceArea());
    }

    sortSarrF(sblocks);
    sortCarrF(cblocks);

    for (int i = 0; i < 3; i++) {
        sblocks[i].printOut();
    }

    cout << "\n";

    for (int i = 0; i < 7; i++) {
        cblocks[i].printOut();
    }






}


