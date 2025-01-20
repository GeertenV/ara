int main() {
    
    //test 4
    asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (32));
    asm volatile("NOP");
    asm volatile("NOP");
    asm volatile("NOP");
    asm volatile("NOP");
    asm volatile("NOP");
    asm volatile("NOP");
    asm volatile("NOP");
    asm volatile("NOP");
    asm volatile("NOP");
    asm volatile("NOP");
    asm volatile("NOP");
    asm volatile("NOP");
    asm volatile("NOP");
    asm volatile("NOP");
    asm volatile("NOP");
    asm volatile("NOP");
    asm volatile("vfadd.vv v2,v2,v2");
    asm volatile("vfadd.vv v2,v2,v2");

    //test 3
    // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (32));
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("vfadd.vv v2,v2,v2");
    // asm volatile("vfadd.vv v4,v4,v4");

    //test 2
    // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (32));
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("vle32.v v0,(a0)");
    // asm volatile("vle32.v v4,(a1)");
    // asm volatile("vfadd.vv v2,v2,v2");
    // asm volatile("vfadd.vv v2,v2,v2");

    //test 1
    // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (32));
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("NOP");
    // asm volatile("vle32.v v0,(a0)");
    // asm volatile("vle32.v v4,(a1)");
    // asm volatile("vfadd.vv v2,v4,v0");
    // asm volatile("vfadd.vv v2,v2,v2");

}