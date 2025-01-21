int main() {
    // 14jan was without these array declarations and then any value that is not divisable by 4 wouldnt work
    int img_height = 6;
    int img_width = 32;
    float input[img_height][img_width];


    asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (32));
    // changed NOP's to a single FENCE for 21jan experiments
    asm volatile("FENCE");
    // asm volatile("NOP");

    asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
    // asm volatile("vle32.v v0,(a0)");
}