int main() {
    // 14jan was without these array declarations and then any value that is not divisable by 4 wouldnt work
    int img_height = 6;
    int img_width = 32;
    float input[img_height][img_width];

    // for 22jan tests data was added to the array
    for(int y=0;y<img_height;y++){
        for(int x=0;x<img_width;x++){
            input[y][x] = (float)((float)y*img_width)+(float)x;
        }
    }

    asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (33));
    // changed NOP's to a single FENCE for 21jan experiments
    // cranked it up to 3 FENCEs 22jan because traces had multiple loads when there should be one
    asm volatile("FENCE");
    asm volatile("FENCE");
    asm volatile("FENCE");
    // asm volatile("NOP");

    asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
    // asm volatile("vle32.v v0,(a0)");
}