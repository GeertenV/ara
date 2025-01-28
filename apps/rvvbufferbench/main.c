int main() {
    int img_height = 6;
    int img_width = 32;
    float input[img_height][img_width];

    for(int y=0;y<img_height;y++){
        for(int x=0;x<img_width;x++){
            input[y][x] = (float)((float)y*img_width)+(float)x;
        }
    }


    asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (32));
    asm volatile("vle32.v v0,(%0);" :: "r"(&input[0][0]));
    asm volatile("FENCE");
    asm volatile("FENCE");
    asm volatile("FENCE");

    // single reg test
    // asm volatile("vle32.v v2,(%0);" :: "r"(&input[1][0]));
    // asm volatile("vfadd.vv v0,v2,v0");
    // asm volatile("vle32.v v2,(%0);" :: "r"(&input[2][0]));
    // asm volatile("vfadd.vv v0,v2,v0");
    // asm volatile("vle32.v v2,(%0);" :: "r"(&input[3][0]));
    // asm volatile("vfadd.vv v0,v2,v0");
    // asm volatile("vle32.v v2,(%0);" :: "r"(&input[4][0]));
    // asm volatile("vfadd.vv v0,v2,v0");
    // asm volatile("vle32.v v2,(%0);" :: "r"(&input[5][0]));
    // asm volatile("vfadd.vv v0,v2,v0");

    // double reg test
    // asm volatile("vle32.v v2,(%0);" :: "r"(&input[1][0]));
    // asm volatile("vfadd.vv v0,v2,v0");
    // asm volatile("vle32.v v4,(%0);" :: "r"(&input[2][0]));
    // asm volatile("vfadd.vv v0,v4,v0");
    // asm volatile("vle32.v v2,(%0);" :: "r"(&input[3][0]));
    // asm volatile("vfadd.vv v0,v2,v0");
    // asm volatile("vle32.v v4,(%0);" :: "r"(&input[4][0]));
    // asm volatile("vfadd.vv v0,v4,v0");
    // asm volatile("vle32.v v2,(%0);" :: "r"(&input[5][0]));
    // asm volatile("vfadd.vv v0,v2,v0");

    // triple reg test
    // asm volatile("vle32.v v2,(%0);" :: "r"(&input[1][0]));
    // asm volatile("vfadd.vv v0,v2,v0");
    // asm volatile("vle32.v v4,(%0);" :: "r"(&input[2][0]));
    // asm volatile("vfadd.vv v0,v4,v0");
    // asm volatile("vle32.v v6,(%0);" :: "r"(&input[3][0]));
    // asm volatile("vfadd.vv v0,v6,v0");
    // asm volatile("vle32.v v2,(%0);" :: "r"(&input[4][0]));
    // asm volatile("vfadd.vv v0,v2,v0");
    // asm volatile("vle32.v v4,(%0);" :: "r"(&input[5][0]));
    // asm volatile("vfadd.vv v0,v4,v0");

    // quad reg test
    // asm volatile("vle32.v v2,(%0);" :: "r"(&input[1][0]));
    // asm volatile("vfadd.vv v0,v2,v0");
    // asm volatile("vle32.v v4,(%0);" :: "r"(&input[2][0]));
    // asm volatile("vfadd.vv v0,v4,v0");
    // asm volatile("vle32.v v6,(%0);" :: "r"(&input[3][0]));
    // asm volatile("vfadd.vv v0,v6,v0");
    // asm volatile("vle32.v v8,(%0);" :: "r"(&input[4][0]));
    // asm volatile("vfadd.vv v0,v8,v0");
    // asm volatile("vle32.v v2,(%0);" :: "r"(&input[5][0]));
    // asm volatile("vfadd.vv v0,v2,v0");

    // penta reg test
    asm volatile("vle32.v v2,(%0);" :: "r"(&input[1][0]));
    asm volatile("vfadd.vv v0,v2,v0");
    asm volatile("vle32.v v4,(%0);" :: "r"(&input[2][0]));
    asm volatile("vfadd.vv v0,v4,v0");
    asm volatile("vle32.v v6,(%0);" :: "r"(&input[3][0]));
    asm volatile("vfadd.vv v0,v6,v0");
    asm volatile("vle32.v v8,(%0);" :: "r"(&input[4][0]));
    asm volatile("vfadd.vv v0,v8,v0");
    asm volatile("vle32.v v10,(%0);" :: "r"(&input[5][0]));
    asm volatile("vfadd.vv v0,v10,v0");
}