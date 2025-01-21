// Copyright 2020 ETH Zurich and University of Bologna.
//
// SPDX-License-Identifier: Apache-2.0
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Author: Matheus Cavalcante, ETH Zurich

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#include "runtime.h"
#include "util.h"

#ifndef SPIKE
#include "printf.h"
#endif


void fill_memory(int img_height, int img_width, float input[img_height][img_width]){
    for(int y=0;y<img_height;y++){
        for(int x=0;x<img_width;x++){
            input[y][x] = (float)((float)y*img_width)+(float)x;
        }
    }
}

void print_image(int img_height, int img_width, float input[img_height][img_width]){
    for(int y=0;y<img_height;y++){
        for(int x=0;x<img_width;x++){
            printf("%f\t\t",input[y][x]);
        }
        printf("\n");
    }
    printf("\n");
}


void test_function(int img_height, int img_width, float input[img_height][img_width], float output[img_height][img_width]) {
    asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (9));
    printf("A\n");
    printf("B\n");
    asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));

    // test 20 tm 23
    // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (32));
    // printf("A\n");
    // printf("B\n");
    // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
    // asm volatile("vle32.v v4,(%0);" :: "r"(&input[2][0]));
    // asm volatile("vfadd.vv v2,v4,v0");
    // asm volatile("vfadd.vv v2,v2,v2");
    // printf("A\n");
    // printf("B\n");
    // printf("A\n");
    // printf("B\n");
    // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
    // asm volatile("vle32.v v4,(%0);" :: "r"(&input[2][0]));
    // asm volatile("vfadd.vv v2,v2,v2");
    // asm volatile("vfadd.vv v2,v2,v2");
    // printf("A\n");
    // printf("B\n");
    // printf("A\n");
    // printf("B\n");
    // asm volatile("vfadd.vv v2,v2,v2");
    // asm volatile("vfadd.vv v4,v4,v4");

  // for(int i=8;i<129;i++){
  //   asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (i));
  //   asm volatile("li a3,4");
  //   asm volatile("fcvt.s.w fa4,a3");
  //   asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  //   asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  //   asm volatile("vfadd.vv v0,v4,v0");
  //   asm volatile("vfredosum.vs v0,v0,v8");
  //   asm volatile("vfmv.f.s fa5,v0");
  //   asm volatile("fdiv.s fa5,fa5,fa4");
  //   asm volatile("fsw fa5,0(%0)":: "r"(&output[0][i]));
  //   printf("A\n");
  // }
  // asm volatile("li a3,4");
  // asm volatile("fcvt.s.w fa4,a3");
  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (32));
  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (8));
  // // asm volatile("vfadd.vv v2,v4,v0");
  // // asm volatile("vfredosum.vs v0,v4,v8");
  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (9));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0);" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (10));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (11));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (12));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (13));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (14));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (15));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (16));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (17));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (18));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (19));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (20));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (21));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (22));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (23));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (24));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (25));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (26));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (27));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (28));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (29));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (30));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (31));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

  // asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (32));

  // asm volatile("vle32.v v0,(%0);" :: "r"(&input[1][0]));
  // asm volatile("vle32.v v4,(%0)" :: "r"(&input[2][0]));
  // asm volatile("vfadd.vv v2,v4,v0");

}

int main() {
  printf("\n");
  printf("=================\n");
  printf("=  vector test  =\n");
  printf("=================\n");
  printf("\n");
  printf("\n");

  int img_height = 6;
  int img_width = 32;
  float input[img_height][img_width];
  float output[img_height][img_width];
  //generate input
  fill_memory(img_height, img_width, input);

  start_timer();
  test_function(img_height, img_width, input, output);
  stop_timer();

  //performance
  int64_t runtime = get_timer();
  printf("The vector execution took %ld cycles.\n", runtime);

  // for(int i=8;i<33;i++){
  //   printf("%f\n",output[0][i]);
  // }

  return 0;
}
