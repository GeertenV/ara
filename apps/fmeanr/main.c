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

int verify_output(int img_height, int img_width, float output[img_height][img_width], float verification_output[img_height][img_width]){
    float error = 0.0;
    float margin = 0.1;
    int pass = 1;
    for(int y=0;y<img_height;y++){
        for(int x=0;x<img_width;x++){
            error = output[y][x] - verification_output[y][x];
            if(error > margin || error < -1*margin){
              printf("Error: output[%d][%d] = %f instead of %f\n", y,x,output[y][x], verification_output[y][x]);
              pass = 0;
            }
        }
    }
    return pass;
}

void fmeanr(int img_height, int img_width, int r, float input[img_height][img_width], float output[img_height][img_width]) {
    for(int y=0;y<img_height;y++){
        for(int x=0;x<img_width;x++){
            float sum = 0.0;
            int count = 0;
            for(int j = y-r < 0 ? -y : -r; j <= r && j + y < img_height; j++){
                for(int i = x-r < 0 ? -x : -r; i <= r && i + x < img_width; i++){
                    sum += input[y+j][x+i];
                    count++;
                }
            }
            output[y][x] = sum/count;
        }
    }
}

void vector_fmeanr(int img_height, int img_width, int r, float input[img_height][img_width], float output[img_height][img_width]) {
  asm volatile("vsetvli zero, %0, e32, m2, ta, ma" :: "r" (2*r+1));
  for(int y=r;y<img_height-r;y++){
    for(int x=r;x<img_width-r;x++){
      float* start_of_vector = &input[y-r][x-r];
      asm volatile("vle32.v v1,(%0);" :: "r"(start_of_vector));
      for(int j = -r+1; j <= r; j++){
        // asm volatile("vle32.v v2,(%0)" :: "r"(&input[y+j][x-r]));
        // asm volatile("vfadd.vv v1,v2,v1");

        // for(int i = x-r < 0 ? -x : -r; i <= r && i + x < img_width; i++){
        //     sum += input[y+j][x+i];
        //     count++;
        // }
      }
      // asm volatile("vfredosum.vs v3,v1,v0");
      // asm volatile("vfmv.f.s fa5,v3");
      // asm volatile("li x5,0x42440000"); //is 49 which is 7*7 which is size of a window when radius=3
      // asm volatile("fmv.w.x fa4,x5");
      // asm volatile("fdiv.s fa5,fa5,fa4");
      // asm volatile("fsw fa5,0(%0)":: "r"(&output[y][x]));
    }
  }
}

int main() {
  printf("\n");
  printf("=============\n");
  printf("=  FMEANR  =\n");
  printf("=============\n");
  printf("\n");
  printf("\n");

  int img_height = 22;
  int img_width = 22;
  int r = 3;
  float input[img_height][img_width];
  float output[img_height][img_width];
  //generate input
  fill_memory(img_height, img_width, input);

  start_timer();
  vector_fmeanr(img_height, img_width, r, input, output);
  stop_timer();

  //performance
  int64_t runtime = get_timer();
  printf("The execution took %ld cycles.\n", runtime);

  //verification
  float verification_output[img_height][img_width];
  fmeanr(img_height, img_width, r, input, verification_output);
  if (verify_output(img_height, img_width, output, verification_output)){
    printf("Passed.\n");
  } else {
    printf("Fail.\n");
  }

  return 0;
}
