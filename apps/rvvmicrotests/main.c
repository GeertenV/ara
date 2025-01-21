int main() {
    // 14jan was without array declarations, 20jan a repetition with those
    int img_height = 6;
    int img_width = 32;
    float input[img_height][img_width];

    // test 4
    // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (32));
    // asm volatile("FENCE");
    // asm volatile("FENCE");
    // asm volatile("vfadd.vv v2,v2,v2");
    // asm volatile("vfadd.vv v2,v2,v2");

    // test 3
    asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (32));
    asm volatile("FENCE");
    asm volatile("FENCE");
    asm volatile("vfadd.vv v2,v2,v2");
    asm volatile("vfadd.vv v4,v4,v4");

    // test 2
    // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (32));
    // asm volatile("FENCE");
    // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
    // asm volatile("vle32.v v4,(%0);" :: "r"(&input[2][0]));
    // asm volatile("vfadd.vv v2,v2,v2");
    // asm volatile("vfadd.vv v2,v2,v2");

    // test 1
    // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (32));
    // asm volatile("FENCE");
    // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
    // asm volatile("vle32.v v4,(%0);" :: "r"(&input[2][0]));
    // asm volatile("vfadd.vv v2,v4,v0");
    // asm volatile("vfadd.vv v2,v2,v2");

}