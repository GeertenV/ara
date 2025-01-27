int main() {
    int img_height = 3;
    int img_width = 32;
    float input[img_height][img_width];

    for(int y=0;y<img_height;y++){
        for(int x=0;x<img_width;x++){
            input[y][x] = (float)((float)y*img_width)+(float)x;
        }
    }

    asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (8));
    asm volatile("vle32.v v0,(%0);" :: "r"(&input[0][0]));
    asm volatile("vle32.v v4,(%0);" :: "r"(&input[1][0]));
    asm volatile("FENCE");
    asm volatile("FENCE");
    asm volatile("FENCE");
    asm volatile("vfadd.vv v2,v4,v0");
}