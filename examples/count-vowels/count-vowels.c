#define EXTISM_ENABLE_LOW_LEVEL_API
#define EXTISM_IMPLEMENTATION
#include "../../extism-pdk.h"

#include <stdio.h>
#include <string.h>

void EXTISM_EXPORTED_FUNCTION(count_vowels) {
  uint64_t count = 0;
  uint8_t ch = 0;
  char buf[1024];
  int64_t nRead = 0;

  while ((nRead = extism_read(ExtismStreamInput, extism_handle(buf, 1024))) >
         0) {
    for (int64_t i = 0; i < nRead; i++) {
      ch = buf[i];
      count += (ch == 'A') + (ch == 'a') + (ch == 'E') + (ch == 'e') +
               (ch == 'I') + (ch == 'i') + (ch == 'O') + (ch == 'o') +
               (ch == 'U') + (ch == 'u');
    }
  }

  char out[128];
  int n = snprintf(out, 128, "{\"count\": %llu}", count);

  extism_write(ExtismStreamOutput, extism_handle(out, n));
}
